/*
 * drv_vcp.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include "drv_vcp.h"
#include "cbuf.h"
#include "usbd_cdc_if.h"
#include "events.h"
#include "usart.h"
#include "logger.h"
#include "tmr.h"

#define DRV_VCP_TX_BUF_SIZE 2048
#define DRV_VCP_RX_BUF_SIZE 2048

static uint8_t txBuf[DRV_VCP_TX_BUF_SIZE];
static uint8_t rxBuf[DRV_VCP_RX_BUF_SIZE];

static cbufHandle_t txBufHandle;
static cbufHandle_t rxBufHandle;

volatile bool txInProgress;

void VCP_Init(void)
{
  cbufInit(&txBufHandle, txBuf, DRV_VCP_TX_BUF_SIZE);
  cbufInit(&rxBufHandle, rxBuf, DRV_VCP_RX_BUF_SIZE);
}

void VCP_SendData(char *buf, uint16_t len)
{
  uint16_t spaceAvailable;

  while (len > cbufSpaceAvailable(&txBufHandle))
  {
    spaceAvailable = cbufSpaceAvailable(&txBufHandle);
    cbufWriteBlock(&txBufHandle, (uint8_t *)buf, spaceAvailable);

    VCP_Flush();
    VCP_Flush(); // 2nd call to make sure 1st one is done.

    buf += spaceAvailable;
    len -= spaceAvailable;
  }

  if (len > 0)
  {
    cbufWriteBlock(&txBufHandle, (uint8_t *)buf, len);
  }
}

bool VCP_GetByte(uint8_t *b)
{
  if (cbufBytesToRead(&rxBufHandle) > 0)
  {
    return (cbufReadBlock(&rxBufHandle, b, sizeof(uint8_t)) == sizeof(uint8_t));
  }

  return false;
}

void VCP_RxHandler(uint8_t *buf, uint16_t len)
{
  cbufWriteBlock(&rxBufHandle, buf, len);
}

void VCP_TxCompleteHandler(void)
{
  // TODO: implement event sending or remove this function
}

void VCP_Flush(void)
{
  uint16_t txLen = cbufBytesToRead(&txBufHandle);
  uint16_t bytesToEnd = txBufHandle.bufSz - txBufHandle.rdIdx;
  uint32_t start = tmrNow();

  if (txLen == 0)
  {
    return; // nothing to flush
  }

  while ((huart3.gState != HAL_UART_STATE_READY) && (CDC_IsBusy() && tmrElapsedMs(start) < 3000));

  if (txLen > bytesToEnd)
  {
    // wrap around necessary
    HAL_UART_Transmit_DMA(&huart3, cbufGetPointer(&txBufHandle, txBufHandle.rdIdx), txBufHandle.bufSz - txBufHandle.rdIdx);
    if (USBD_CDC_IsOpened())
    {
      CDC_Transmit_FS(cbufGetPointer(&txBufHandle, txBufHandle.rdIdx), txBufHandle.bufSz - txBufHandle.rdIdx);
    }

    txBufHandle.rdIdx = 0;
    // Send the rest after this TX completes
  }
  else
  {
    HAL_UART_Transmit_DMA(&huart3, cbufGetPointer(&txBufHandle, txBufHandle.rdIdx), txLen);
    if (USBD_CDC_IsOpened())
    {
      CDC_Transmit_FS(cbufGetPointer(&txBufHandle, txBufHandle.rdIdx), txLen);
    }
    
    txBufHandle.rdIdx += txLen;
  }
}

/*
 * drv_vcp.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include "drv_vcp.h"
#include "cbuf.h"
#include "usbd_cdc_msc.h"
#include "events.h"

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

void VCP_SendData(const char *buf, uint16_t len)
{
  while (len > cbufSpaceAvailable(&txBufHandle))
  {
    cbufWriteBlock(&txBufHandle, (uint8_t *)buf, cbufSpaceAvailable(&txBufHandle));
    VCP_Flush();

    buf += cbufSpaceAvailable(&txBufHandle);
    len -= cbufSpaceAvailable(&txBufHandle);
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

  if (USBD_CDC_IsOpened() == false)
  {
    return; // check back later
  }

  if (txLen > bytesToEnd)
  {
    // wrap around necessary
    if (CDC_Transmit_FS(&txBufHandle.pData[txBufHandle.rdIdx], txBufHandle.bufSz - txBufHandle.rdIdx) == USBD_OK)
    {
      txBufHandle.rdIdx = 0;
      // Send the rest after this TX completes
    }
  }
  else
  {
    if (CDC_Transmit_FS(&txBufHandle.pData[txBufHandle.rdIdx], txLen) == USBD_OK)
    {
      txBufHandle.rdIdx += txLen;
    }
  }
}

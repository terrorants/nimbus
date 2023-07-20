/*
 * cbuf.c
 *
 *  Created on: Jul 18, 2023
 *      Author: terence_kim
 */
#include "cbuf.h"

#define CBUF_NEXT_RD_IDX(handle) ((handle->rdIdx + 1 == handle->bufSz) ? 0 : handle->rdIdx + 1)
#define CBUF_NEXT_WR_IDX(handle) ((handle->wrIdx + 1 == handle->bufSz) ? 0 : handle->wrIdx + 1)

static inline uint16_t cbufIdxIncrement(cbufHandle_t *handle, uint16_t idx)
{
  if (++idx == handle->bufSz) { idx = 0; }

  return idx;
}

void cbufInit(cbufHandle_t *handle, uint8_t *buffer, uint16_t bufferSize)
{
  handle->pData = buffer;
  handle->bufSz = bufferSize;
  cbufReset(handle);
}

void cbufReset(cbufHandle_t *handle)
{
  handle->rdIdx = 0;
  handle->wrIdx = 0;
}

uint16_t cbufReadBlock(cbufHandle_t *handle, uint8_t *pOut, uint16_t readLength)
{
  uint16_t count = 0;

  while ((count < readLength) && (handle->rdIdx != handle->wrIdx))
  {
    *pOut = handle->pData[handle->rdIdx];
    handle->rdIdx = CBUF_NEXT_RD_IDX(handle);

    pOut++;
    count++;
  }

  return count;
}

uint16_t cbufWriteBlock(cbufHandle_t *handle, uint8_t *pData, uint16_t writeLength)
{
  uint16_t count = 0;

  while (count < writeLength)
  {
    handle->pData[handle->wrIdx] = *pData;
    handle->wrIdx = CBUF_NEXT_WR_IDX(handle);

    pData++;
    count++;
  }

  return count;
}

uint16_t cbufBytesToRead(cbufHandle_t *handle)
{
  return (handle->rdIdx <= handle->wrIdx) ? handle->wrIdx - handle->rdIdx : handle->bufSz - handle->rdIdx + handle->wrIdx;
}

uint16_t cbufSpaceAvailable(cbufHandle_t *handle)
{
  return handle->bufSz - cbufBytesToRead(handle) - 1;
}

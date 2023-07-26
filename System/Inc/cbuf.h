/*
 * cbuf.h
 *
 *  Created on: Jul 18, 2023
 *      Author: terence_kim
 */
#ifndef CBUF_H
#define CBUF_H

#include <stdint.h>

/**
 * @brief Buffer context
 */
typedef struct
{
  uint16_t rdIdx; /**< read index */
  uint16_t wrIdx; /**< write index */
  uint16_t bufSz; /**< buffer size */
  uint8_t  *pData; /**< buffer address */
} cbufHandle_t;

/**
 * @brief Initialize buffer handle.
 *
 * @param handle the handle for buffer context
 * @param buffer the allocated memory for the buffer
 * @param bufferSize the size of the buffer
 * @return None
 */
void cbufInit(cbufHandle_t *handle, uint8_t *buffer, uint16_t bufferSize);

/**
 * @brief Reset (re-initialize) buffer handle.
 *
 * @param handle the handle for buffer context
 * @return None
 */
void cbufReset(cbufHandle_t *handle);

/**
 * @brief Read a block of data out of buffer.
 *
 * @param handle the handle for buffer context
 * @param[out] pOut the buffer to populate with read content
 * @param readLength the number of bytes to read
 * @return uint16_t number of bytes actually read
 */
uint16_t cbufReadBlock(cbufHandle_t *handle, uint8_t *pOut, uint16_t readLength);

/**
 * @brief Write a block of data out of buffer.
 *
 * @param handle the handle for buffer context
 * @param pData the data to write
 * @param writeLength the number of bytes to write
 * @return uint16_t number of bytes actually written
 */
uint16_t cbufWriteBlock(cbufHandle_t *handle, const uint8_t *pData, uint16_t writeLength);

/**
 * @brief Return bytes available for read.
 *
 * @param handle the handle for buffer context
 * @return uint16_t number of bytes to read
 */
uint16_t cbufBytesToRead(cbufHandle_t *handle);

/**
 * @brief Return space available (in bytes).
 *
 * @param handle the handle for buffer context
 * @return uint16_t number of bytes available
 */
uint16_t cbufSpaceAvailable(cbufHandle_t *handle);

#endif // CBUF_H

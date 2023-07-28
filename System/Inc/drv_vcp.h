/*
 * drv_vcp.h
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */

#ifndef DRV_VCP_H_
#define DRV_VCP_H_

#include <stdint.h>
#include <stdbool.h>

void VCP_Init(void);

void VCP_SendData(const char *buf, uint16_t len);

bool VCP_GetByte(uint8_t *b);

void VCP_RxHandler(uint8_t *buf, uint16_t len);

void VCP_TxCompleteHandler(void);

void VCP_Flush(void);

#endif /* DRV_VCP_H_ */

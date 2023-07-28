/**
  ******************************************************************************
  * @file    usbd_customhid.h
  * @author  MCD Application Team
  * @brief   header file for the usbd_customhid.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V.
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CDC_MSC_H
#define __USBD_CDC_MSC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
 #include  "usbd_ioreq.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_CUSTOM_HID
  * @brief This file is the Header file for USBD_customhid.c
  * @{
  */


/** @defgroup USBD_CUSTOM_HID_Exported_Defines
  * @{
  */
#include "usbd_conf.h"
#define USB_ENDPOINT_IN(x)                   (x|0x80)
#define USB_ENDPOINT_OUT(x)                  (x)

#define USB_CDC_CMD_INTERFACE                0
#define USB_CDC_DATA_INTERFACE               1
#define USB_MSC_INTERFACE                    2
#define USB_MAX_NUM_INTERFACES               3

#define CDC_EPDAT_ADDR                       0x01U  /* EP1 for CDC data  */
#define CDC_EPCMD_ADDR                       0x82U  /* EP2 for CDC commands */

// override defines in usbd_msc.h
#undef MSC_EPIN_ADDR
#undef MSC_EPOUT_ADDR
#define MSC_EPIN_ADDR                        0x83U
#define MSC_EPOUT_ADDR                       0x03U

// override defines in usbd_cdc.h
#undef CDC_IN_EP
#undef CDC_OUT_EP
#undef CDC_CMD_EP
#define CDC_IN_EP                            0x81U  /* EP1 for data IN */
#define CDC_OUT_EP                           0x01U  /* EP1 for data OUT */
#define CDC_CMD_EP                           0x82U  /* EP2 for CDC commands */

#include "usbd_msc.h"
#include "usbd_cdc.h"

// #define CUSTOM_HID_EPIN_SIZE                 USBD_CUSTOMHID_OUTREPORT_BUF_SIZE
// #define CUSTOM_HID_EPOUT_SIZE                USBD_CUSTOMHID_OUTREPORT_BUF_SIZE

// #define USB_CUSTOM_HID_DESC_SIZ              9

// #define CUSTOM_HID_DESCRIPTOR_TYPE           0x21
// #define CUSTOM_HID_REPORT_DESC               0x22

// #ifndef CUSTOM_HID_FS_BINTERVAL
// #define CUSTOM_HID_FS_BINTERVAL             0x05U
// #endif /* CUSTOM_HID_FS_BINTERVAL */

// #define CUSTOM_HID_REQ_SET_PROTOCOL          0x0B
// #define CUSTOM_HID_REQ_GET_PROTOCOL          0x03

// #define CUSTOM_HID_REQ_SET_IDLE              0x0A
// #define CUSTOM_HID_REQ_GET_IDLE              0x02

// #define CUSTOM_HID_REQ_SET_REPORT            0x09
// #define CUSTOM_HID_REQ_GET_REPORT            0x01

// #define USB_HID_MAX_PACKET_SIZE              0x3f
// #define USB_HID_REPORT_ID                    0x02

/* CDC Endpoints parameters: you can fine tune these values depending on the needed baudrates and performance. */
#define CDC_DATA_HS_MAX_PACKET_SIZE                 512U  /* Endpoint IN & OUT Packet size */
#define CDC_DATA_FS_MAX_PACKET_SIZE                 64U  /* Endpoint IN & OUT Packet size */
#define CDC_CMD_PACKET_SIZE                         8U  /* Control Endpoint Packet size */

/**
  * @}
  */ 
#define USB_MAX_POWER                       500U      /* Control Endpoint Packet size */


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
// typedef enum
// {
//   CUSTOM_HID_IDLE = 0U,
//   CUSTOM_HID_BUSY,
// }
// CUSTOM_HID_StateTypeDef; 

typedef struct _USBD_CDC_MSC_Itf
{
  USBD_CDC_ItfTypeDef cdc;
  USBD_StorageTypeDef msc;
} USBD_CDC_MSC_ItfTypeDef;

typedef struct
{
  USBD_CDC_HandleTypeDef     cdc;
  USBD_MSC_BOT_HandleTypeDef msc;
} USBD_CDC_MSC_HandleTypeDef;
/**
  * @}
  */



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */
#define WBVAL(x) (x & 0xFF),((x >> 8) & 0xFF)
#define USB_CONFIGUARTION_DESC_SIZE             9
#define USB_INTERFACE_DESC_SIZE                 9
#define USB_ENDPOINT_DESC_SIZE                  7
#define USB_ENDPOINT_TYPE_BULK                  0x02
#define USB_ENDPOINT_TYPE_INTERRUPT             0x03

#define USB_CONFIG_BUS_POWERED                 0x80
#define USB_CONFIG_POWER_MA(mA)                ((mA)/2)

#define CDC_COMMUNICATION_INTERFACE_CLASS       0x02
#define CDC_DATA_INTERFACE_CLASS                0x0A
#define CDC_ABSTRACT_CONTROL_MODEL              0x02
#define CDC_CS_INTERFACE                        0x24
#define CDC_HEADER                              0x00
#define CDC_CALL_MANAGEMENT                     0x01
#define CDC_ABSTRACT_CONTROL_MANAGEMENT         0x02
#define CDC_UNION                               0x06

  /* ////////////////////////////////   CDC   //////////////////////////////// */
#define CDC_IF_DESC_SET_SIZE                    \
  ( USB_INTERFACE_DESC_SIZE + 0x05 + 0x05 + 0x04 + 0x05 + USB_ENDPOINT_DESC_SIZE + USB_INTERFACE_DESC_SIZE + (2 * USB_ENDPOINT_DESC_SIZE) )


#define CDC_IF_DESC_SET( comIfNum, datIfNum, comInEp, datEp)            \
  /* CDC Communication Interface Descriptor */                            \
      USB_INTERFACE_DESC_SIZE,                /* bLength */               \
      USB_DESC_TYPE_INTERFACE,                /* bDescriptorType */       \
      comIfNum,                               /* bInterfaceNumber */      \
      0x00,                                   /* bAlternateSetting */     \
      0x01,                                   /* bNumEndpoints */         \
      CDC_COMMUNICATION_INTERFACE_CLASS,      /* bInterfaceClass */       \
      CDC_ABSTRACT_CONTROL_MODEL,             /* bInterfaceSubClass */    \
      0x01,                                   /* bInterfaceProtocol */    \
      0x00,                                   /* iInterface */            \
  /* Header Functional Descriptor */                                      \
      0x05,                                   /* bLength */               \
      CDC_CS_INTERFACE,                       /* bDescriptorType */       \
      CDC_HEADER,                             /* bDescriptorSubtype */    \
      0x10,   /* bcdCDC: spec release number */                           \
        0x01,                                                             \
  /* Call Management Functional Descriptor */                             \
      0x05,                                   /* bFunctionLength */       \
      CDC_CS_INTERFACE,                       /* bDescriptorType */       \
      CDC_CALL_MANAGEMENT,                    /* bDescriptorSubtype */    \
      0x00,                                   /* bmCapabilities 0x03 */   \
      datIfNum,                               /* bDataInterface */        \
  /* Abstract Control Management Functional Descriptor */                 \
      0x04,                                   /* bFunctionLength */       \
      CDC_CS_INTERFACE,                       /* bDescriptorType */       \
      CDC_ABSTRACT_CONTROL_MANAGEMENT,        /* bDescriptorSubtype */    \
      0x02,                                   /* bmCapabilities */        \
  /* Union Functional Descriptor */                                       \
      0x05,                                   /* bFunctionLength */       \
      CDC_CS_INTERFACE,                       /* bDescriptorType */       \
      CDC_UNION,                              /* bDescriptorSubtype */    \
      comIfNum,                               /* bMasterInterface */      \
      datIfNum,                               /* bSlaveInterface0 */      \
  /* Endpoint, Interrupt IN */                /* event notification */    \
      USB_ENDPOINT_DESC_SIZE,                 /* bLength */               \
      USB_DESC_TYPE_ENDPOINT,                 /* bDescriptorType */       \
      USB_ENDPOINT_IN(comInEp),               /* bEndpointAddress */      \
      USB_ENDPOINT_TYPE_INTERRUPT,            /* bmAttributes */          \
      WBVAL(CDC_CMD_PACKET_SIZE),             /* wMaxPacketSize */        \
      0x10,                                   /* bInterval */             \
                                                                          \
  /* CDC Data Interface Descriptor */                                     \
      USB_INTERFACE_DESC_SIZE,                /* bLength */               \
      USB_DESC_TYPE_INTERFACE,                /* bDescriptorType */       \
      datIfNum,                               /* bInterfaceNumber */      \
      0x00,                                   /* bAlternateSetting */     \
      0x02,                                   /* bNumEndpoints */         \
      CDC_DATA_INTERFACE_CLASS,               /* bInterfaceClass */       \
      0x00,                                   /* bInterfaceSubClass */    \
      0x00,                                   /* bInterfaceProtocol */    \
      0x00,                                   /* iInterface */            \
  /* Endpoint, Bulk OUT */                                                \
      USB_ENDPOINT_DESC_SIZE,                 /* bLength */               \
      USB_DESC_TYPE_ENDPOINT,                 /* bDescriptorType */       \
      USB_ENDPOINT_OUT(datEp),                /* bEndpointAddress */      \
      USB_ENDPOINT_TYPE_BULK,                 /* bmAttributes */          \
      WBVAL(CDC_DATA_FS_MAX_PACKET_SIZE),     /* wMaxPacketSize */        \
      0x00,                                   /* bInterval */             \
  /* Endpoint, Bulk IN */                                                 \
      USB_ENDPOINT_DESC_SIZE,                 /* bLength */               \
      USB_DESC_TYPE_ENDPOINT,                 /* bDescriptorType */       \
      USB_ENDPOINT_IN(datEp),                 /* bEndpointAddress */      \
      USB_ENDPOINT_TYPE_BULK,                 /* bmAttributes */          \
      WBVAL(CDC_DATA_FS_MAX_PACKET_SIZE),     /* wMaxPacketSize */        \
      0x00                                    /* bInterval */

#define IAD_CDC_IF_DESC_SET_SIZE    ( 8 + CDC_IF_DESC_SET_SIZE )

#define CDC_DESCRIPTOR_SET( comIfNum, datIfNum, comInEp, datEp )        \
  /* Interface Association Descriptor */                                  \
      0x08,                                   /* bLength */               \
      0x0B,                                   /* bDescriptorType */       \
      comIfNum,                               /* bFirstInterface */       \
      0x02,                                   /* bInterfaceCount */       \
      CDC_COMMUNICATION_INTERFACE_CLASS,      /* bFunctionClass */        \
      CDC_ABSTRACT_CONTROL_MODEL,             /* bFunctionSubClass */     \
      0x01,                                   /* bFunctionProcotol */     \
      0x00,                                   /* iInterface */            \
  /* CDC Interface descriptor set */                                      \
      CDC_IF_DESC_SET( comIfNum, datIfNum, comInEp, datEp )

  /* ////////////////////////////////   MSC   //////////////////////////////// */

#define MSC_IF_DESC_SET_SIZE        23 // USB_INTERFACE_DESC_SIZE + 2 * USB_ENDPOINT_DESC_SIZE

#define MSC_DESCRIPTOR_SET( datIfNum, datEp )                        \
  /********************  Mass Storage interface ********************/ \
  0x09,                                            /* bLength: Interface Descriptor size */ \
  0x04,                                            /* bDescriptorType: */ \
  datIfNum,                                        /* bInterfaceNumber: Number of Interface */ \
  0x00,                                            /* bAlternateSetting: Alternate setting */ \
  0x02,                                            /* bNumEndpoints */ \
  0x08,                                            /* bInterfaceClass: MSC Class */ \
  0x06,                                            /* bInterfaceSubClass : SCSI transparent*/ \
  0x50,                                            /* nInterfaceProtocol */ \
  0x05,                                            /* iInterface: */ \
  /********************  Mass Storage Endpoints ********************/ \
  0x07,                                            /* Endpoint descriptor length = 7 */ \
  0x05,                                            /* Endpoint descriptor type */ \
  USB_ENDPOINT_IN(datEp),                          /* Endpoint address (IN, address 1) */ \
  0x02,                                            /* Bulk endpoint type */ \
  LOBYTE(MSC_MAX_FS_PACKET), \
  HIBYTE(MSC_MAX_FS_PACKET), \
  0x00,                                            /* Polling interval in milliseconds */ \
  \
  0x07,                                            /* Endpoint descriptor length = 7 */ \
  0x05,                                            /* Endpoint descriptor type */ \
  USB_ENDPOINT_OUT(datEp),                         /* Endpoint address (OUT, address 1) */ \
  0x02,                                            /* Bulk endpoint type */ \
  LOBYTE(MSC_MAX_FS_PACKET), \
  HIBYTE(MSC_MAX_FS_PACKET), \
  0x00                                             /* Polling interval in milliseconds */



/**
  * @}
  */

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */

extern USBD_ClassTypeDef      USBD_CDC_MSC;
#define USBD_CDC_MSC_CLASS    &USBD_CDC_MSC
/**
  * @}
  */

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
uint8_t  USBD_CDC_MSC_RegisterInterface  (USBD_HandleTypeDef   *pdev,
                                          USBD_CDC_MSC_ItfTypeDef *fops);

void USBD_MscEnable(bool enable);

bool USBD_IsMscEnabled(void);

bool USBD_CDC_IsOpened(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __USBD_CDC_MSC_H */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

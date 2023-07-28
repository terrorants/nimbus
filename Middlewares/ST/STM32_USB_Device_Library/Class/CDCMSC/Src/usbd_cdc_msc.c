/**
  ******************************************************************************
  * @file    usbd_customhid.c
  * @author  MCD Application Team
  * @brief   This file provides the CUSTOM_HID core functions.
  *
  * @verbatim
  *
  *          ===================================================================
  *                                CUSTOM_HID Class  Description
  *          ===================================================================
  *           This module manages the CUSTOM_HID class V1.11 following the "Device Class Definition
  *           for Human Interface Devices (CUSTOM_HID) Version 1.11 Jun 27, 2001".
  *           This driver implements the following aspects of the specification:
  *             - The Boot Interface Subclass
  *             - Usage Page : Generic Desktop
  *             - Usage : Vendor
  *             - Collection : Application
  *
  * @note     In HS mode and when the DMA is used, all variables and data structures
  *           dealing with the DMA during the transaction process should be 32-bit aligned.
  *
  *
  *  @endverbatim
  *
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

  /* BSPDependencies
  - "stm32xxxxx_{eval}{discovery}{nucleo_144}.c"
  - "stm32xxxxx_{eval}{discovery}_io.c"
  EndBSPDependencies */

/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc_msc.h"
#include "usbd_ctlreq.h"
#include "usbd_desc.h"
#include "drv_vcp.h"
#include "logger.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */


/** @defgroup USBD_CUSTOM_HID
  * @brief usbd core module
  * @{
  */

/** @defgroup USBD_CDC_MSC_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */


/** @defgroup USBD_CDC_MSC_Private_Defines
  * @{
  */

/**
  * @}
  */


/** @defgroup USBD_CDC_MSC_Private_Macros
  * @{
  */
#define MAX_USB_CDC_INTERFACES    1
#define MAX_USB_MSC_INTERFACES    1

#define MAXDESCRIPTORSIZE  (USB_CONFIGUARTION_DESC_SIZE + (MAX_USB_CDC_INTERFACES * IAD_CDC_IF_DESC_SET_SIZE) + (MAX_USB_MSC_INTERFACES * MSC_IF_DESC_SET_SIZE))


/**
  * @}
  */
/** @defgroup USBD_CDC_MSC_Private_FunctionPrototypes
  * @{
  */


static uint8_t  USBD_CDC_MSC_Init (USBD_HandleTypeDef *pdev,
                               uint8_t cfgidx);

static uint8_t  USBD_CDC_MSC_DeInit (USBD_HandleTypeDef *pdev,
                                 uint8_t cfgidx);

static uint8_t  USBD_CDC_MSC_Setup (USBD_HandleTypeDef *pdev,
                                    USBD_SetupReqTypedef *req);

static uint8_t  *USBD_CDC_MSC_GetCfgDesc (uint16_t *length);

static uint8_t  *USBD_CDC_MSC_GetDeviceQualifierDesc (uint16_t *length);

static uint8_t  USBD_CDC_MSC_DataIn (USBD_HandleTypeDef *pdev, uint8_t epnum);

static uint8_t  USBD_CDC_MSC_DataOut (USBD_HandleTypeDef *pdev, uint8_t epnum);
static uint8_t  USBD_CDC_MSC_EP0_RxReady (USBD_HandleTypeDef  *pdev);

/**
  * @}
  */

/** @defgroup USBD_CDC_MSC_Private_Variables
  * @{
  */

USBD_ClassTypeDef  USBD_CDC_MSC =
{
  USBD_CDC_MSC_Init,
  USBD_CDC_MSC_DeInit,
  USBD_CDC_MSC_Setup,
  NULL, /*EP0_TxSent*/
  USBD_CDC_MSC_EP0_RxReady, /*EP0_RxReady*/ /* STATUS STAGE IN */
  USBD_CDC_MSC_DataIn, /*DataIn*/
  USBD_CDC_MSC_DataOut,
  NULL, /*SOF */
  NULL,
  NULL,
  USBD_CDC_MSC_GetCfgDesc,     //Full Speed Cfg
  USBD_CDC_MSC_GetCfgDesc,     //High Speed Cfg
  USBD_CDC_MSC_GetCfgDesc,     //Other Speed Cfg
  USBD_CDC_MSC_GetDeviceQualifierDesc,
};

/* USB CUSTOM_HID device FS Configuration Descriptor */

/* USB CUSTOM_HID device Configuration Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CDC_MSC_CDC_CfgDesc[MAXDESCRIPTORSIZE] __ALIGN_END =
{
  /* Configuration 1 */
  USB_CONFIGUARTION_DESC_SIZE,       /* bLength */
  USB_DESC_TYPE_CONFIGURATION, /* bDescriptorType */
  LOBYTE(MAXDESCRIPTORSIZE),
  HIBYTE(MAXDESCRIPTORSIZE),
  USB_MAX_NUM_INTERFACES,            /* bNumInterfaces */
  0x01,                              /* bConfigurationValue: 0x01 is used to select this configuration */
  0x00,                              /* iConfiguration: no string to describe this configuration */
  USB_CONFIG_BUS_POWERED /*|*/       /* bmAttributes USB_CONFIG_REMOTE_WAKEUP*/,
  USB_CONFIG_POWER_MA(USB_MAX_POWER),/* bMaxPower, device power consumption is 350 mA */

  CDC_DESCRIPTOR_SET( USB_CDC_CMD_INTERFACE, USB_CDC_DATA_INTERFACE, CDC_EPCMD_ADDR, CDC_EPDAT_ADDR ),
  MSC_DESCRIPTOR_SET( USB_MSC_INTERFACE, MSC_EPOUT_ADDR ),
};

// /* USB CUSTOM_HID device Configuration Descriptor */
// __ALIGN_BEGIN static const uint8_t USBD_CDC_MSC_Desc[USB_CUSTOM_HID_DESC_SIZ] __ALIGN_END =
// {
//   /* 18 */
//   0x09,         /*bLength: CUSTOM_HID Descriptor size*/
//   CUSTOM_HID_DESCRIPTOR_TYPE, /*bDescriptorType: CUSTOM_HID*/
//   0x11,         /*bCUSTOM_HIDUSTOM_HID: CUSTOM_HID Class Spec release number*/
//   0x01,
//   0x00,         /*bCountryCode: Hardware target country*/
//   0x01,         /*bNumDescriptors: Number of CUSTOM_HID class descriptors to follow*/
//   0x22,         /*bDescriptorType*/
//   USBD_CDC_MSC_REPORT_DESC_SIZE,/*wItemLength: Total length of Report descriptor*/
//   0x00,
// };

/* USB Standard Device Descriptor */
__ALIGN_BEGIN static uint8_t USBD_CDC_MSC_DeviceQualifierDesc[USB_LEN_DEV_QUALIFIER_DESC] __ALIGN_END =
{
  USB_LEN_DEV_QUALIFIER_DESC,
  USB_DESC_TYPE_DEVICE_QUALIFIER,
  0x00,
  0x02,
  0x00,
  0x00,
  0x00,
  MSC_MAX_FS_PACKET,
  0x01,
  0x00,
};

static uint8_t MSCInEpAdd  = MSC_EPIN_ADDR;
static uint8_t MSCOutEpAdd = MSC_EPOUT_ADDR;

static uint8_t CDCInEpAdd = CDC_IN_EP;
static uint8_t CDCOutEpAdd = CDC_OUT_EP;
static uint8_t CDCCmdEpAdd = CDC_CMD_EP;

/**
  * @}
  */

static bool mscEnabled = true;
static bool cdcIsOpened = false;

/** @defgroup USBD_CDC_MSC_Private_Functions
  * @{
  */

/**
  * @brief  USBD_CDC_Setup
  *         Handle the CDC specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
static uint8_t USBD_CDC_Setup(USBD_HandleTypeDef *pdev,
                              USBD_SetupReqTypedef *req)
{
  USBD_CDC_HandleTypeDef *hcdc = &((USBD_CDC_MSC_HandleTypeDef *)pdev->pClassDataCmsit[pdev->classId])->cdc;
  uint16_t len;
  uint8_t ifalt = 0U;
  uint16_t status_info = 0U;
  USBD_StatusTypeDef ret = USBD_OK;

  if (hcdc == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  switch (req->bmRequest & USB_REQ_TYPE_MASK)
  {
    case USB_REQ_TYPE_CLASS:
      if (req->wLength != 0U)
      {
        if ((req->bmRequest & 0x80U) != 0U)
        {
          ((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->cdc.Control(req->bRequest,
                                                                           (uint8_t *)hcdc->data,
                                                                           req->wLength);

          len = MIN(CDC_REQ_MAX_DATA_SIZE, req->wLength);
          (void)USBD_CtlSendData(pdev, (uint8_t *)hcdc->data, len);
        }
        else
        {
          hcdc->CmdOpCode = req->bRequest;
          hcdc->CmdLength = (uint8_t)MIN(req->wLength, USB_MAX_EP0_SIZE);

          (void)USBD_CtlPrepareRx(pdev, (uint8_t *)hcdc->data, hcdc->CmdLength);
        }
      }
      else
      {
        cdcIsOpened = false;
        if (req->wValue == 0x03)
        {
          static const char prompt[] = "\n\U00002601] ";

          //PRINTSYSTEM(INFO,"Open Comms");
          //Simulate NL
          cdcIsOpened = true;
          VCP_SendData(prompt, sizeof(prompt));
        }
        ((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->cdc.Control(req->bRequest,
                                                                         (uint8_t *)req, 0U);
      }
      break;

    case USB_REQ_TYPE_STANDARD:
      switch (req->bRequest)
      {
        case USB_REQ_GET_STATUS:
          if (pdev->dev_state == USBD_STATE_CONFIGURED)
          {
            (void)USBD_CtlSendData(pdev, (uint8_t *)&status_info, 2U);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case USB_REQ_GET_INTERFACE:
          if (pdev->dev_state == USBD_STATE_CONFIGURED)
          {
            (void)USBD_CtlSendData(pdev, &ifalt, 1U);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case USB_REQ_SET_INTERFACE:
          if (pdev->dev_state != USBD_STATE_CONFIGURED)
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case USB_REQ_CLEAR_FEATURE:
          break;

        default:
          USBD_CtlError(pdev, req);
          ret = USBD_FAIL;
          break;
      }
      break;

    default:
      USBD_CtlError(pdev, req);
      ret = USBD_FAIL;
      break;
  }

  return (uint8_t)ret;
}

/**
  * @brief  USBD_MSC_Setup
  *         Handle the MSC specific requests
  * @param  pdev: device instance
  * @param  req: USB request
  * @retval status
  */
static uint8_t USBD_MSC_Setup(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req)
{
  USBD_MSC_BOT_HandleTypeDef *hmsc = &((USBD_CDC_MSC_HandleTypeDef *)pdev->pClassDataCmsit[pdev->classId])->msc;
  USBD_StatusTypeDef ret = USBD_OK;
  uint16_t status_info = 0U;

#ifdef USE_USBD_COMPOSITE
  /* Get the Endpoints addresses allocated for this class instance */
  MSCInEpAdd  = USBD_CoreGetEPAdd(pdev, USBD_EP_IN, USBD_EP_TYPE_BULK);
  MSCOutEpAdd = USBD_CoreGetEPAdd(pdev, USBD_EP_OUT, USBD_EP_TYPE_BULK);
#endif /* USE_USBD_COMPOSITE */

  if (hmsc == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  switch (req->bmRequest & USB_REQ_TYPE_MASK)
  {
    /* Class request */
    case USB_REQ_TYPE_CLASS:
      switch (req->bRequest)
      {
        case BOT_GET_MAX_LUN:
          if ((req->wValue  == 0U) && (req->wLength == 1U) &&
              ((req->bmRequest & 0x80U) == 0x80U))
          {
            hmsc->max_lun = (uint32_t)((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->msc.GetMaxLun();
            (void)USBD_CtlSendData(pdev, (uint8_t *)&hmsc->max_lun, 1U);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case BOT_RESET :
          if ((req->wValue  == 0U) && (req->wLength == 0U) &&
              ((req->bmRequest & 0x80U) != 0x80U))
          {
            MSC_BOT_Reset(pdev);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        default:
          USBD_CtlError(pdev, req);
          ret = USBD_FAIL;
          break;
      }
      break;
    /* Interface & Endpoint request */
    case USB_REQ_TYPE_STANDARD:
      switch (req->bRequest)
      {
        case USB_REQ_GET_STATUS:
          if (pdev->dev_state == USBD_STATE_CONFIGURED)
          {
            (void)USBD_CtlSendData(pdev, (uint8_t *)&status_info, 2U);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case USB_REQ_GET_INTERFACE:
          if (pdev->dev_state == USBD_STATE_CONFIGURED)
          {
            (void)USBD_CtlSendData(pdev, (uint8_t *)&hmsc->interface, 1U);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case USB_REQ_SET_INTERFACE:
          if (pdev->dev_state == USBD_STATE_CONFIGURED)
          {
            hmsc->interface = (uint8_t)(req->wValue);
          }
          else
          {
            USBD_CtlError(pdev, req);
            ret = USBD_FAIL;
          }
          break;

        case USB_REQ_CLEAR_FEATURE:
          if (pdev->dev_state == USBD_STATE_CONFIGURED)
          {
            if (req->wValue == USB_FEATURE_EP_HALT)
            {
              /* Flush the FIFO */
              (void)USBD_LL_FlushEP(pdev, (uint8_t)req->wIndex);

              /* Handle BOT error */
              MSC_BOT_CplClrFeature(pdev, (uint8_t)req->wIndex);
            }
          }
          break;

        default:
          USBD_CtlError(pdev, req);
          ret = USBD_FAIL;
          break;
      }
      break;

    default:
      USBD_CtlError(pdev, req);
      ret = USBD_FAIL;
      break;
  }

  return (uint8_t)ret;
}

/**
  * @brief  USBD_CDC_MSC_Init
  *         Initialize the CUSTOM_HID interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t  USBD_CDC_MSC_Init (USBD_HandleTypeDef *pdev,
                               uint8_t cfgidx)
{
  UNUSED(cfgidx);
  USBD_CDC_MSC_HandleTypeDef     *hCdcMsc;
  USBD_CDC_HandleTypeDef         *hcdc;

  hCdcMsc = (USBD_CDC_MSC_HandleTypeDef *)USBD_malloc(sizeof (USBD_CDC_MSC_HandleTypeDef));

  if (hCdcMsc == NULL)
  {
    pdev->pClassDataCmsit[pdev->classId] = NULL;
    return (uint8_t)USBD_EMEM;
  }

  pdev->pClassDataCmsit[pdev->classId] = (void *)hCdcMsc;
  pdev->pClassData = pdev->pClassDataCmsit[pdev->classId];

  hcdc = &hCdcMsc->cdc;
  // USBD_MSC_BOT_HandleTypeDef *hmsc = &hCdcMsc->msc;

  /**
   * CDC
   */
  (void)USBD_memset(hcdc, 0, sizeof(USBD_CDC_HandleTypeDef));

  if (pdev->dev_speed == USBD_SPEED_HIGH)
  {
    /* Open EP IN */
    (void)USBD_LL_OpenEP(pdev, CDCInEpAdd, USBD_EP_TYPE_BULK,
                         CDC_DATA_HS_IN_PACKET_SIZE);

    pdev->ep_in[CDCInEpAdd & 0xFU].is_used = 1U;

    /* Open EP OUT */
    (void)USBD_LL_OpenEP(pdev, CDCOutEpAdd, USBD_EP_TYPE_BULK,
                         CDC_DATA_HS_OUT_PACKET_SIZE);

    pdev->ep_out[CDCOutEpAdd & 0xFU].is_used = 1U;

    /* Set bInterval for CDC CMD Endpoint */
    pdev->ep_in[CDCCmdEpAdd & 0xFU].bInterval = CDC_HS_BINTERVAL;
  }
  else
  {
    /* Open EP IN */
    (void)USBD_LL_OpenEP(pdev, CDCInEpAdd, USBD_EP_TYPE_BULK,
                         CDC_DATA_FS_IN_PACKET_SIZE);

    pdev->ep_in[CDCInEpAdd & 0xFU].is_used = 1U;

    /* Open EP OUT */
    (void)USBD_LL_OpenEP(pdev, CDCOutEpAdd, USBD_EP_TYPE_BULK,
                         CDC_DATA_FS_OUT_PACKET_SIZE);

    pdev->ep_out[CDCOutEpAdd & 0xFU].is_used = 1U;

    /* Set bInterval for CMD Endpoint */
    pdev->ep_in[CDCCmdEpAdd & 0xFU].bInterval = CDC_FS_BINTERVAL;
  }

  /* Open Command IN EP */
  (void)USBD_LL_OpenEP(pdev, CDCCmdEpAdd, USBD_EP_TYPE_INTR, CDC_CMD_PACKET_SIZE);
  pdev->ep_in[CDCCmdEpAdd & 0xFU].is_used = 1U;

  hcdc->RxBuffer = NULL;

  /* Init  physical Interface components */
  ((USBD_CDC_ItfTypeDef *)pdev->pUserData[pdev->classId])->Init();

  /* Init Xfer states */
  hcdc->TxState = 0U;
  hcdc->RxState = 0U;

  if (hcdc->RxBuffer == NULL)
  {
    return (uint8_t)USBD_EMEM;
  }

  if (pdev->dev_speed == USBD_SPEED_HIGH)
  {
    /* Prepare Out endpoint to receive next packet */
    (void)USBD_LL_PrepareReceive(pdev, CDCOutEpAdd, hcdc->RxBuffer,
                                 CDC_DATA_HS_OUT_PACKET_SIZE);
  }
  else
  {
    /* Prepare Out endpoint to receive next packet */
    (void)USBD_LL_PrepareReceive(pdev, CDCOutEpAdd, hcdc->RxBuffer,
                                 CDC_DATA_FS_OUT_PACKET_SIZE);
  }

  if (USBD_IsMscEnabled())
  {
    /**
     * MASS STORAGE
     */
    if (pdev->dev_speed == USBD_SPEED_HIGH)
    {
      /* Open EP OUT */
      (void)USBD_LL_OpenEP(pdev, MSCOutEpAdd, USBD_EP_TYPE_BULK, MSC_MAX_HS_PACKET);
      pdev->ep_out[MSCOutEpAdd & 0xFU].is_used = 1U;

      /* Open EP IN */
      (void)USBD_LL_OpenEP(pdev, MSCInEpAdd, USBD_EP_TYPE_BULK, MSC_MAX_HS_PACKET);
      pdev->ep_in[MSCInEpAdd & 0xFU].is_used = 1U;
    }
    else
    {
      /* Open EP OUT */
      (void)USBD_LL_OpenEP(pdev, MSCOutEpAdd, USBD_EP_TYPE_BULK, MSC_MAX_FS_PACKET);
      pdev->ep_out[MSCOutEpAdd & 0xFU].is_used = 1U;

      /* Open EP IN */
      (void)USBD_LL_OpenEP(pdev, MSCInEpAdd, USBD_EP_TYPE_BULK, MSC_MAX_FS_PACKET);
      pdev->ep_in[MSCInEpAdd & 0xFU].is_used = 1U;
    }

    /* Init the BOT  layer */
    MSC_BOT_Init(pdev);
  }

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CDC_MSC_Init
  *         DeInitialize the CUSTOM_HID layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t  USBD_CDC_MSC_DeInit (USBD_HandleTypeDef *pdev,
                                 uint8_t cfgidx)
{
  UNUSED(cfgidx);

  /**
   * CDC
   */

  /* Close EP IN */
  (void)USBD_LL_CloseEP(pdev, CDCInEpAdd);
  pdev->ep_in[CDCInEpAdd & 0xFU].is_used = 0U;

  /* Close EP OUT */
  (void)USBD_LL_CloseEP(pdev, CDCOutEpAdd);
  pdev->ep_out[CDCOutEpAdd & 0xFU].is_used = 0U;

  /* Close Command IN EP */
  (void)USBD_LL_CloseEP(pdev, CDCCmdEpAdd);
  pdev->ep_in[CDCCmdEpAdd & 0xFU].is_used = 0U;
  pdev->ep_in[CDCCmdEpAdd & 0xFU].bInterval = 0U;

  /* DeInit  physical Interface components */
  if (pdev->pClassDataCmsit[pdev->classId] != NULL)
  {
    ((USBD_CDC_ItfTypeDef *)pdev->pUserData[pdev->classId])->DeInit();
    (void)USBD_free(pdev->pClassDataCmsit[pdev->classId]);
    pdev->pClassDataCmsit[pdev->classId] = NULL;
    pdev->pClassData = NULL;
  }

  /**
   * Mass Storage
   */
  if (USBD_IsMscEnabled())
  {
    /* Close MSC EPs */
    (void)USBD_LL_CloseEP(pdev, MSCOutEpAdd);
    pdev->ep_out[MSCOutEpAdd & 0xFU].is_used = 0U;

    /* Close EP IN */
    (void)USBD_LL_CloseEP(pdev, MSCInEpAdd);
    pdev->ep_in[MSCInEpAdd & 0xFU].is_used = 0U;

    /* Free MSC Class Resources */
    if (pdev->pClassDataCmsit[pdev->classId] != NULL)
    {
      /* De-Init the BOT layer */
      MSC_BOT_DeInit(pdev);

      (void)USBD_free(pdev->pClassDataCmsit[pdev->classId]);
      pdev->pClassDataCmsit[pdev->classId]  = NULL;
      pdev->pClassData = NULL;
    }
  }

  return (uint8_t)USBD_OK;
}

static uint8_t USBD_CDC_MSC_Setup(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req)
{
  LOG(USB, DEBUG, "%s:", __FUNCTION__);
  LOG(USB, DEBUG, "\tbmRequest = 0x%X", req->bmRequest);
  LOG(USB, DEBUG, "\tbRequest  = 0x%X", req->bRequest);
  LOG(USB, DEBUG, "\twValue    = 0x%X", req->wValue);
  LOG(USB, DEBUG, "\twIndex    = 0x%X", req->wIndex);
  LOG(USB, DEBUG, "\twLength   = 0x%X", req->wLength);
  if (LOBYTE(req->wIndex) == USB_MSC_INTERFACE)
  {
    USBD_MSC_Setup(pdev, req);
  }
  else
  {
    USBD_CDC_Setup(pdev, req);
  }
  return USBD_OK;
}

/**
  * @brief  USBD_CDC_MSC_GetCfgDesc
  *         return other speed configuration descriptor
  * @param  speed : current device speed
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t  *USBD_CDC_MSC_GetCfgDesc (uint16_t *length)
{
  uint16_t DescriptorSize;
  if (USBD_IsMscEnabled())
  {
    // 1 HID + 1 CDC
    DescriptorSize = (USB_CONFIGUARTION_DESC_SIZE + (1 * MSC_IF_DESC_SET_SIZE) + (1 * IAD_CDC_IF_DESC_SET_SIZE));
    USBD_CDC_MSC_CDC_CfgDesc[4] =  1 + (2*1);
  }
  else
  {
    // 1 HID
    DescriptorSize = (USB_CONFIGUARTION_DESC_SIZE + (0 * MSC_IF_DESC_SET_SIZE) + (1 * IAD_CDC_IF_DESC_SET_SIZE));
    USBD_CDC_MSC_CDC_CfgDesc[4] =  0 + (2*1);
  }
  USBD_CDC_MSC_CDC_CfgDesc[2] = LOBYTE(DescriptorSize);
  USBD_CDC_MSC_CDC_CfgDesc[3] = HIBYTE(DescriptorSize);
  *length = DescriptorSize;
  return ((uint8_t *)USBD_CDC_MSC_CDC_CfgDesc);
}

/**
  * @brief  USBD_CDC_MSC_DataIn
  *         handle data IN Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t  USBD_CDC_MSC_DataIn (USBD_HandleTypeDef *pdev,
                              uint8_t epnum)
{
  if (epnum == CDC_EPDAT_ADDR)
  {
    USBD_CDC_HandleTypeDef *hcdc;
    PCD_HandleTypeDef *hpcd = (PCD_HandleTypeDef *)pdev->pData;

    if (pdev->pClassDataCmsit[pdev->classId] == NULL)
    {
      return (uint8_t)USBD_FAIL;
    }

    hcdc = &((USBD_CDC_MSC_HandleTypeDef *)pdev->pClassDataCmsit[pdev->classId])->cdc;

    if ((pdev->ep_in[epnum & 0xFU].total_length > 0U) &&
        ((pdev->ep_in[epnum & 0xFU].total_length % hpcd->IN_ep[epnum & 0xFU].maxpacket) == 0U))
    {
      /* Update the packet total length */
      pdev->ep_in[epnum & 0xFU].total_length = 0U;

      /* Send ZLP */
      (void)USBD_LL_Transmit(pdev, epnum, NULL, 0U);
    }
    else
    {
      hcdc->TxState = 0U;

      if (((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->cdc.TransmitCplt != NULL)
      {
        ((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->cdc.TransmitCplt(hcdc->TxBuffer, &hcdc->TxLength, epnum);
      }
    }
  }
  else if (epnum == MSC_EPOUT_ADDR)
  {
    MSC_BOT_DataIn(pdev, epnum);
  }

  return (uint8_t)USBD_OK;
}

/**
  * @brief  USBD_CDC_MSC_DataOut
  *         handle data OUT Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t  USBD_CDC_MSC_DataOut (USBD_HandleTypeDef *pdev,
                              uint8_t epnum)
{
  if (epnum == USB_ENDPOINT_OUT(CDC_EPDAT_ADDR))
  {
    USBD_CDC_HandleTypeDef *hcdc = &((USBD_CDC_MSC_HandleTypeDef *)pdev->pClassDataCmsit[pdev->classId])->cdc;

    if (pdev->pClassDataCmsit[pdev->classId] == NULL)
    {
      return (uint8_t)USBD_FAIL;
    }

    /* Get the received data length */
    hcdc->RxLength = USBD_LL_GetRxDataSize(pdev, epnum);

    /* USB data will be immediately processed, this allow next USB traffic being
    NAKed till the end of the application Xfer */

    ((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->cdc.Receive(hcdc->RxBuffer, &hcdc->RxLength);
  }
  else if (epnum == MSC_EPOUT_ADDR)
  {
    MSC_BOT_DataOut(pdev, epnum);
  }
  
  return USBD_OK;
}

/**
  * @brief  USBD_CDC_MSC_EP0_RxReady
  *         Handles control request data.
  * @param  pdev: device instance
  * @retval status
  */
static uint8_t USBD_CDC_MSC_EP0_RxReady(USBD_HandleTypeDef *pdev)
{
  USBD_CDC_HandleTypeDef *hcdc = &((USBD_CDC_MSC_HandleTypeDef *)pdev->pClassDataCmsit[pdev->classId])->cdc;

  if (hcdc == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  if ((pdev->pUserData[pdev->classId] != NULL) && (hcdc->CmdOpCode != 0xFFU))
  {
    ((USBD_CDC_MSC_ItfTypeDef *)pdev->pUserData[pdev->classId])->cdc.Control(hcdc->CmdOpCode,
                                                                     (uint8_t *)hcdc->data,
                                                                     (uint16_t)hcdc->CmdLength);
    hcdc->CmdOpCode = 0xFFU;
  }

  return (uint8_t)USBD_OK;

  return USBD_OK;
}

/**
* @brief  DeviceQualifierDescriptor
*         return Device Qualifier descriptor
* @param  length : pointer data length
* @retval pointer to descriptor buffer
*/
static uint8_t  *USBD_CDC_MSC_GetDeviceQualifierDesc(uint16_t *length)
{
  *length = (uint16_t)sizeof(USBD_CDC_MSC_DeviceQualifierDesc);

  return USBD_CDC_MSC_DeviceQualifierDesc;
}

/**
* @brief  USBD_CDC_MSC_RegisterInterface
  * @param  pdev: device instance
  * @param  fops: CUSTOMHID Interface callback
  * @retval status
  */
uint8_t  USBD_CDC_MSC_RegisterInterface  (USBD_HandleTypeDef   *pdev,
                                          USBD_CDC_MSC_ItfTypeDef *fops)
{
  if (fops == NULL)
  {
    return (uint8_t)USBD_FAIL;
  }

  pdev->pUserData[pdev->classId] = fops;

  return (uint8_t)USBD_OK;
}

void USBD_MscEnable(bool enable)
{
  mscEnabled = enable;
}

bool USBD_IsMscEnabled(void)
{
  return mscEnabled;
}

bool USBD_CDC_IsOpened(void)
{
  return cdcIsOpened;
}
/**
  * @}
  */


/**
  * @}
  */


/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

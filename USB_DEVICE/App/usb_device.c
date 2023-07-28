/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usb_device.c
  * @version        : v1.0_Cube
  * @brief          : This file implements the USB Device
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"

/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include "usbd_storage_if.h"
#include "usbd_cdc_msc.h"
#include "logger.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USB Device Core handle declaration. */
USBD_HandleTypeDef hUsbDeviceFS;

static USBD_CDC_MSC_ItfTypeDef USBD_fops_FS;

/*
 * -- Insert your variables declaration here --
 */
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*
 * -- Insert your external function declaration here --
 */
/* USER CODE BEGIN 1 */
typedef struct
{
  bool initialized;
  bool deviceDataConnection;
} usb_device_status_t;

usb_device_status_t usbStatus = {false, false};

void usb_device_init(void)
{
  LOG(USB, INFO, "%s: initialized=%d, dataConnection=%d", __FUNCTION__, usbStatus.initialized, usbStatus.deviceDataConnection);

  if (usbStatus.initialized == false)
  {
    MX_USB_DEVICE_Init();

    usbStatus.initialized = true;
    
    /* Peripheral interrupt init*/
    HAL_NVIC_SetPriority(OTG_FS_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(OTG_FS_IRQn);
  }
}

void usb_device_deinit(void)
{
  if(usbStatus.initialized)
  {
    USBD_DeInit(&hUsbDeviceFS);
    HAL_NVIC_ClearPendingIRQ(OTG_FS_IRQn);
    usbStatus.initialized = false;
  }
  usbStatus.deviceDataConnection = false;
}

void usb_device_connection_set_status(bool status)
{
  usbStatus.deviceDataConnection = status;
}

bool usb_device_connection_get_status(void)
{
  return usbStatus.deviceDataConnection;
}

bool usb_device_initialized(void)
{
  return usbStatus.initialized;
}
/* USER CODE END 1 */

/**
  * Init USB device Library, add supported class and start the library
  * @retval None
  */
void MX_USB_DEVICE_Init(void)
{
  /* USER CODE BEGIN USB_DEVICE_Init_PreTreatment */
  USBD_fops_FS.cdc = USBD_Interface_fops_FS;
  USBD_fops_FS.msc = USBD_Storage_Interface_fops_FS;

  if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CDC_MSC) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_CDC_MSC_RegisterInterface(&hUsbDeviceFS, &USBD_fops_FS) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
  {
    Error_Handler();
  }
  #if 0
  /* USER CODE END USB_DEVICE_Init_PreTreatment */

  /* Init Device Library, add supported class and start the library. */
  if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_MSC) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_MSC_RegisterStorage(&hUsbDeviceFS, &USBD_Storage_Interface_fops_FS) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN USB_DEVICE_Init_PostTreatment */
  #endif
  /* USER CODE END USB_DEVICE_Init_PostTreatment */
}

/**
  * @}
  */

/**
  * @}
  */


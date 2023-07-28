/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file   fatfs.c
  * @brief  Code for fatfs applications
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
#include "logger.h"
#include "main.h"
#include "sdio.h"
/* USER CODE END Header */
#include "fatfs.h"

uint8_t retSD;    /* Return value for SD */
char SDPath[4];   /* SD logical drive path */
FATFS SDFatFS;    /* File system object for SD logical drive */
FIL SDFile;       /* File object for SD */

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

void MX_FATFS_Init(void)
{
  /*## FatFS: Link the SD driver ###########################*/
  retSD = FATFS_LinkDriver(&SD_Driver, SDPath);

  /* USER CODE BEGIN Init */
  /* additional user code for init */
#if 0
  FRESULT fres; //Result after operations

  //Open the file system
  fres = f_mount(&SDFatFS, SDPath, 0); //1=mount now
  //if (fres != FR_OK)
  {
    LOG(STOR, ERROR, "f_mount error (%d)\r", fres);
    // return;
  }

  fres = f_open(&SDFile, "README.txt", FA_READ);
  //if (fres != FR_OK)
  {
    LOG(STOR, ERROR, "f_open error (%d)\r", fres);
    // return;
  }

  uint8_t rtext[100];
  uint32_t bytesread;

  fres = f_read(&SDFile, rtext, sizeof(rtext), (UINT*)&bytesread);
  //if (fres != FR_OK)
  {
    LOG(STOR, ERROR, "f_read error (%d) - %s (%d)\r", fres, rtext, bytesread);
    // return;
  }

  f_close(&SDFile);
#else
  FRESULT fres;                                          /* FatFs function common result code */
  uint32_t byteswritten, bytesread;                     /* File write/read counts */
  uint8_t wtext[] = "This is STM32 working with FatFs"; /* File write buffer */
  uint8_t rtext[100];                                   /* File read buffer */
  uint8_t buffer[_MAX_SS];
  FIL MyFile;

  LOG(STOR, INFO, "retSD = %d, SDPath = %s", retSD, SDPath);
  /*##-2- Register the file system object to the FatFs module ##############*/
  if((fres = f_mount(&SDFatFS, (TCHAR const*)SDPath, 1)) != FR_OK)
  {
    /* FatFs Initialization Error */
    LOG(STOR, ERROR, "00 F_error (%d)", fres);
  }
  else
  {
    HAL_SD_CardInfoTypeDef cardInfo;
    HAL_SD_GetCardInfo(&hsd, &cardInfo);

    LOG(STOR, DEBUG, "CardType = %d", cardInfo.CardType);                     /*!< Specifies the card Type                         */
  
    LOG(STOR, DEBUG, "CardVersion = %d", cardInfo.CardVersion);                  /*!< Specifies the card version                      */

    LOG(STOR, DEBUG, "Class = %d", cardInfo.Class);                        /*!< Specifies the class of the card class           */

    LOG(STOR, DEBUG, "RelCardAdd = %d", cardInfo.RelCardAdd);                   /*!< Specifies the Relative Card Address             */
  
    LOG(STOR, DEBUG, "BlockNbr = %d", cardInfo.BlockNbr);                     /*!< Specifies the Card Capacity in blocks           */

    LOG(STOR, DEBUG, "BlockSize = %d", cardInfo.BlockSize);                    /*!< Specifies one block size in bytes               */
  
    LOG(STOR, DEBUG, "LogBlockNbr = %d", cardInfo.LogBlockNbr);                  /*!< Specifies the Card logical Capacity in blocks   */

    LOG(STOR, DEBUG, "LogBlockSize = %d", cardInfo.LogBlockSize);                 /*!< Specifies logical block size in bytes           */

    return;
    /*##-3- Create a FAT file system (format) on the logical drive #########*/
    /* WARNING: Formatting the uSD card will delete all content on the device */
    if((fres = f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, buffer, sizeof(buffer))) != FR_OK)
    {
      /* FatFs Format Error */
      LOG(STOR, ERROR, "01 F_error (%d)", fres);
    }
    else
    {       
      /*##-4- Create and Open a new text file object with write access #####*/
      if((fres = f_open(&MyFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE)) != FR_OK)
      {
        /* 'STM32.TXT' file Open for write Error */
        LOG(STOR, ERROR, "02 F_error (%d)", fres);
      }
      else
      {
        /*##-5- Write data to the text file ################################*/
        fres = f_write(&MyFile, wtext, sizeof(wtext), (void *)&byteswritten);

        /*##-6- Close the open text file #################################*/
        if ((fres = f_close(&MyFile)) != FR_OK )
        {
          LOG(STOR, ERROR, "03 F_error (%d)", fres);
        }
        
        if((byteswritten == 0) || (fres != FR_OK))
        {
          /* 'STM32.TXT' file Write or EOF Error */
          LOG(STOR, ERROR, "04 F_error (%d)", fres);
        }
        else
        {      
          /*##-7- Open the text file object with read access ###############*/
          if((fres = f_open(&MyFile, "STM32.TXT", FA_READ)) != FR_OK)
          {
            /* 'STM32.TXT' file Open for read Error */
            LOG(STOR, ERROR, "05 F_error (%d)", fres);
          }
          else
          {
            /*##-8- Read data from the text file ###########################*/
            fres = f_read(&MyFile, rtext, sizeof(rtext), (UINT*)&bytesread);
            
            if((bytesread == 0) || (fres != FR_OK))
            {
              /* 'STM32.TXT' file Read or EOF Error */
              LOG(STOR, ERROR, "06 F_error (%d)", fres);
            }
            else
            {
              /*##-9- Close the open text file #############################*/
              f_close(&MyFile);
              
              /*##-10- Compare read data with the expected data ############*/
              if((bytesread != byteswritten))
              {                
                /* Read data is different from the expected data */
                LOG(STOR, ERROR, "07 F_error (%d)", fres);
              }
              else
              {
                /* Success of the demo: no error occurrence */
                //BSP_LED_On(LED1);
              }
            }
          }
        }
      }
    }
  }
#endif
  /* USER CODE END Init */
}

/**
  * @brief  Gets Time from RTC
  * @param  None
  * @retval Time in DWORD
  */
DWORD get_fattime(void)
{
  /* USER CODE BEGIN get_fattime */
  return 0;
  /* USER CODE END get_fattime */
}

/* USER CODE BEGIN Application */

/* USER CODE END Application */

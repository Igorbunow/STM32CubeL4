/**
  ******************************************************************************
  * @file    usbd_msc_data.c
  * @author  MCD Application Team
  * @brief   This file provides all the vital inquiry pages and sense data.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                      www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* BSPDependencies
- "stm32xxxxx_{eval}{discovery}{nucleo_144}.c"
- "stm32xxxxx_{eval}{discovery}_io.c"
- "stm32xxxxx_{eval}{discovery}{adafruit}_sd.c"
EndBSPDependencies */

/* Includes ------------------------------------------------------------------*/
#include "usbd_msc_data.h"


/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */


/** @defgroup MSC_DATA
  * @brief Mass storage info/data module
  * @{
  */

/** @defgroup MSC_DATA_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */


/** @defgroup MSC_DATA_Private_Defines
  * @{
  */
/**
  * @}
  */

/** @defgroup MSC_DATA_Private_Macros
  * @{
  */
/**
  * @}
  */


/** @defgroup MSC_DATA_Private_Variables
  * @{
  */

/* USB Mass storage Page 0 Inquiry Data */
uint8_t MSC_Page00_Inquiry_Data[LENGTH_INQUIRY_PAGE00] =
{
  0x00,
  0x00,
  0x00,
  (LENGTH_INQUIRY_PAGE00 - 4U),
  0x00,
  0x80
};

/* USB Mass storage VPD Page 0x80 Inquiry Data for Unit Serial Number */
uint8_t MSC_Page80_Inquiry_Data[LENGTH_INQUIRY_PAGE80] =
{
  0x00,
  0x80,
  0x00,
  LENGTH_INQUIRY_PAGE80,
  0x20,     /* Put Product Serial number */
  0x20,
  0x20,
  0x20
};

/* USB Mass storage sense 6 Data */
uint8_t MSC_Mode_Sense6_data[MODE_SENSE6_LEN] =
{
  0x03,     /* MODE DATA LENGTH. The number of bytes that follow. */
  0x00,     /* MEDIUM TYPE. 00h for SBC devices. */
  0x00,     /* DEVICE-SPECIFIC PARAMETER. For SBC devices: 
             *   bit 7: WP. Set to 1 if the media is write-protected.
             *   bits 6..4: reserved
             *   bit 4: DPOFUA. Set to 1 if the device supports the DPO and FUA bits (used in caching)
             *   bits 3..0: reserved*/
  0x00      /* Put Product Serial number */
};


/* USB Mass storage sense 10  Data */
uint8_t MSC_Mode_Sense10_data[MODE_SENSE10_LEN] =
{
  0x07,     /* MODE DATA LENGTH. The number of bytes that follow. */
  0x00,     /* MEDIUM TYPE. 00h for SBC devices. */
  0x00,     /* DEVICE-SPECIFIC PARAMETER. For SBC devices: 
             *   bit 7: WP. Set to 1 if the media is write-protected.
             *   bits 6..4: reserved
             *   bit 4: DPOFUA. Set to 1 if the device supports the DPO and FUA bits (used in caching)
             *   bits 3..0: reserved*/
  0x00,     /* Reserved */
  0x00,     /* Reserved */
  0x00,     /* Reserved */
  0x00,     /* Reserved */
  0x00      /* BLOCK DESCRIPTOR LENGTH. The length in bytes of all block descriptors in the
             *   mode parameter list. */
};


/* USB Mass storage TOC 10  Data */
uint8_t MSC_TOC10_data[READ_TOC10_LEN] =
{
  0x00,                /* TOC Data Length MSB */
  READ_TOC10_LEN - 2,  /* TOC Data Length LSB */
  0x01,                /* First Complete Session Number */
  0x01,                /* Last Complete Session Number */
  0x00,                /* Reserved */
  0x14,                /* ADR/CTL */
  0x01,                /* First Track Number in Last Complete Session */
  0x00,                /* Reserved */
  0x00,                /* Logical Block Address of First Track in Last Session MSB */
  0x00,                /* Logical Block Address of First Track in Last Session */
  0x00,                /* Logical Block Address of First Track in Last Session */
  0x00                 /* Logical Block Address of First Track in Last Session LSB*/
};


/* USB Mass storage Disc Information 10  Data */
uint8_t MSC_Disc_Information10_data[READ_DISC_INFORMATION10_LEN] =
{
  0x00,                             /* Data Length MSB */
  READ_DISC_INFORMATION10_LEN - 2,  /* Data Length LSB */
  0x0e,               /* 7:5 Reserved, 4 Erasable, 3:2 State of last Session, 1:0 disk status */
  0x01,                             /* Number of First Track on Disc */
  0x01,                             /* Number of Sessions */
  0x01,                             /* First Track Number in Last Session */
  0x01,                             /* Last Track Number in Last Session */
  0x00,                             /* 7: DID_V, 6:DBC_V, 5:URU */
  0x00,                             /* Disc Type */
  0x00,                             /* Reserved */
  0x00,                             /* Reserved */
  0x00,                             /* Reserved */
  0x00,                             /* Disc Identification MSB*/
  0x00,                             /* Disc Identification */
  0x00,                             /* Disc Identification */
  0x00,                             /* Disc Identification LSB*/
  0xff,                             /* Last Session lead-in Start Time MSF MSB */
  0xff,                             /* Last Session lead-in Start Time MSF */
  0xff,                             /* Last Session lead-in Start Time MSF */
  0xff,                             /* Last Session lead-in Start Time MSF LSB */
  0xff,                             /* Last Possible Start Time for Start of lead-out MSF MSB */
  0xff,                             /* Last Possible Start Time for Start of lead-out MSF */
  0xff,                             /* Last Possible Start Time for Start of lead-out MSF */
  0xff,                             /* Last Possible Start Time for Start of lead-out MSF LSB */
  0x00,                             /* Disc Bar Code MSB */
  0x00,                             /* Disc Bar Code */
  0x00,                             /* Disc Bar Code */
  0x00,                             /* Disc Bar Code */
  0x00,                             /* Disc Bar Code */
  0x00,                             /* Disc Bar Code */
  0x00,                             /* Disc Bar Code */
  0x00,                             /* Disc Bar Code LSB */
  0x00,                             /* Reserved */
  0x00                              /* Number of OPC Table Entries */
};







/* USB Mass storage Track Information 10  Data */
uint8_t MSC_Track_Information10_data[READ_TRACK_INFORMATION10_LEN] =
{
  0x00,                             /* Data Length MSB */
  READ_TRACK_INFORMATION10_LEN - 2, /* Data Length LSB */
  0x01,                             /* Track Number (LSB) */
  0x01,                             /* Session Number (LSB) */
  0x00,                             /* Reserved */
  0x04,                             /* 5 Damage, 4 Copy, 3:0 Track Mode */
  0x01,                             /* 7 RT, 6 Blank, 5 Packet/Inc, 4 FP, 3:0 Data Mode */
  0x00,                             /* 1 LRA_V, 0 NWA_V */
  0x00,                             /* Track Start Address MSB */
  0x00,                             /* Track Start Address */
  0x00,                             /* Track Start Address */
  0x00,                             /* Track Start Address LSB */
  0xff,                             /* Next Writable Address MSB */
  0xff,                             /* Next Writable Address */
  0xff,                             /* Next Writable Address */
  0xff,                             /* Next Writable Address LSB */
  0x00,                             /* Free Blocks MSB */
  0x00,                             /* Free Blocks */
  0x00,                             /* Free Blocks */
  0x00,                             /* Free Blocks LSB */
  0x00,                             /* Fixed Packet Size/Blocking Factor MSB */
  0x00,                             /* Fixed Packet Size/Blocking Factor */
  0x00,                             /* Fixed Packet Size/Blocking Factor */
  0x00,                             /* Fixed Packet Size/Blocking Factor LSB */
  0x00,                             /* Track Size MSB */
  0x00,                             /* Track Size */
  0x5b,                             /* Track Size */
  0xac,                             /* Track Size LSB */
  0x00,                             /* Last Recorded Address MSB */
  0x00,                             /* Last Recorded Address */
  0x00,                             /* Last Recorded Address */
  0x00,                             /* Last Recorded Address LSB */
  0x00,                             /* Track Number (MSB) */
  0x00,                             /* Session Number (MSB) */
  0x00,                             /* Reserved */
  0x00                              /* Reserved */
};


/* USB Mass storage Event Status 10  Data */
uint8_t MSC_Event_Status10_data[GET_EVENT_STATUS_LEN] =
{
  0x00,                             /*  Data Length MSB */
  GET_EVENT_STATUS_LEN - 2,         /*  Data Length LSB */
  0x04,                             /* Reserved */
  0x5e,                             /* Reserved */
  0x00,                             /* Reserved */
  0x02,                             /* Reserved */
  0x00,                             /* Reserved */
  0x00,                             /* Reserved */
};

/* USB Mass storage Event Status 10  Data */
uint8_t MSC_ModeSelect6_data[MODE_SELECT6_LEN] =
{
  0x00,                             /*  Data Length MSB */
  MODE_SELECT6_LEN - 2,             /*  Data Length LSB */
  0x00,                             /* Obsolete (Medium Type Code) */
  0x00,                             /* Reserved */
  0x00,                             /* Reserved */
  0x00,                             /* Reserved */
  0x02,                             /* Block Descriptor Length 0 (8 for legacy SCSI Logical Units) */
  0x00                              /* Block Descriptor Length 0 (8 for legacy SCSI Logical Units) */
};

/* USB Mass storage Event Status 10  Data */
uint8_t MSC_GetConfiguration10_data[GET_CONFIGURATION10_LEN] =
{
  0x00,                             /*  Data Length MSB */
  0x00,                             /*  Data Length */
  0x00,                             /*  Data Length */
  GET_CONFIGURATION10_LEN - 2,      /*  Data Length LSB */
  0x00,                             /* Reserved */
  0x00,                             /* Reserved */
  0x00,                             /* Current Profile MSB */
  0x00,                             /* Current Profile LSB */
};
/**SCSI_READ_DISC_INFORMATION
  * @}
  */


/** @defgroup MSC_DATA_Private_FunctionPrototypes
  * @{
  */
/**
  * @}
  */


/** @defgroup MSC_DATA_Private_Functions
  * @{
  */

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

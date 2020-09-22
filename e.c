/*****************************************************************************
 * FileName:        e.c
 * Processor:       PIC24F, PIC24H, dsPIC
 * Compiler:        MPLAB C30/XC16 (see release notes for tested revision)
 * Linker:          MPLAB LINK30/XC16
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright(c) 2012 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * AUTO-GENERATED CODE:  Graphics Resource Converter version: 3.29.06
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Includes
 *****************************************************************************/
#include <Graphics/Graphics.h>
#include "HardwareProfile.h"

/*****************************************************************************
 * SECTION:  Graphics Library Firmware Check
 *****************************************************************************/
#if(GRAPHICS_LIBRARY_VERSION != 0x0306)
#warning "It is suggested to use Graphics Library version 3.06 with this version of GRC."
#endif

/*****************************************************************************
 * SECTION:  Graphics Bitmap Padding Check
 *****************************************************************************/
#ifdef USE_BITMAP_NO_PADDING_LINE
#error These bitmap resources have been converted with padding of the horizontal lines, but USE_BITMAP_NO_PADDING_LINE is defined in GraphicsConfig.h.
#endif

/*****************************************************************************
 * Converted Resources
 * -------------------
 *
 * Bitmaps
 * -------
 * e - 100x100 pixels, 1-bits per pixel
 * e_1 - 50x50 pixels, 1-bits per pixel
 * e_2 - 50x50 pixels, 1-bits per pixel
 * e_3 - 50x50 pixels, 1-bits per pixel
 * e_4 - 50x50 pixels, 1-bits per pixel
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  BITMAPS
 *****************************************************************************/

/*********************************
 * Bitmap Structure
 * Label: e
 * Description:  100x100 pixels, 1-bits per pixel
 ***********************************/
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

extern FLASH_BYTE __e[] __attribute__((section("grc_images"), aligned(2)));
const IMAGE_FLASH e =
{
    (FLASH | IMAGE_MBITMAP | COMP_NONE),
    (FLASH_BYTE *)__e
};
asm(".section grc_images, code");
asm(".global ___e");
asm(".align 2");
asm("___e:");
/****************************************
 * Bitmap header
 ****************************************/
asm(".byte 0x00");           // Compresssion
asm(".byte 0x01");           // Color Depth
asm(".byte 0x64, 0x00");     // Height
asm(".byte 0x64, 0x00");     // Width
/***********************************
 * Color Palette for the image
 **********************************/
asm(".byte 0x00, 0x00");
asm(".byte 0xFF, 0xFF");
/********************************
 * Bitmap Image Body
 *********************************/
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x3F, 0xFC, 0x1F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF");
asm(".byte 0xFF, 0xE1, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0x9F, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x7F, 0xFE, 0xFF, 0xFF, 0xFF");
asm(".byte 0x0F, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF");
asm(".byte 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xBF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF");
asm(".byte 0xFF, 0x0F, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0x0F, 0xFF");
asm(".byte 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xEF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF");
asm(".byte 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0x0F");
asm(".byte 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFD");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x7F, 0xFF, 0xFF, 0x0F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF");
asm(".byte 0x0F, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x0F, 0xFF, 0xBF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x0F, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD");
asm(".byte 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF");
asm(".byte 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFB, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x0F");
asm(".byte 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFB, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF");
asm(".byte 0x0F, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0x0F, 0xFF, 0xDF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD");
asm(".byte 0xFF, 0x0F, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0x0F, 0xFF");
asm(".byte 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x0F, 0xFF, 0xBF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x0F, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x0F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F");
asm(".byte 0xFF, 0xFF, 0x0F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x0F");
asm(".byte 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFD");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xEF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF");
asm(".byte 0x0F, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF");
asm(".byte 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFE, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF");
asm(".byte 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xF7");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xF9, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x7F, 0xFE, 0xFF");
asm(".byte 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xFF, 0xE1, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x3F, 0xFC, 0x1F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x0F");
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

/*********************************
 * Bitmap Structure
 * Label: e_1
 * Description:  50x50 pixels, 1-bits per pixel
 ***********************************/
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

extern FLASH_BYTE __e_1[] __attribute__((section("grc_images"), aligned(2)));
const IMAGE_FLASH e_1 =
{
    (FLASH | IMAGE_MBITMAP | COMP_NONE),
    (FLASH_BYTE *)__e_1
};
asm(".section grc_images, code");
asm(".global ___e_1");
asm(".align 2");
asm("___e_1:");
/****************************************
 * Bitmap header
 ****************************************/
asm(".byte 0x00");           // Compresssion
asm(".byte 0x01");           // Color Depth
asm(".byte 0x32, 0x00");     // Height
asm(".byte 0x32, 0x00");     // Width
/***********************************
 * Color Palette for the image
 **********************************/
asm(".byte 0x00, 0x00");
asm(".byte 0xFF, 0xFF");
/********************************
 * Bitmap Image Body
 *********************************/
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xFC, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xC3, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x3F");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xDF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFE, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x7F, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

/*********************************
 * Bitmap Structure
 * Label: e_2
 * Description:  50x50 pixels, 1-bits per pixel
 ***********************************/
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

extern FLASH_BYTE __e_2[] __attribute__((section("grc_images"), aligned(2)));
const IMAGE_FLASH e_2 =
{
    (FLASH | IMAGE_MBITMAP | COMP_NONE),
    (FLASH_BYTE *)__e_2
};
asm(".section grc_images, code");
asm(".global ___e_2");
asm(".align 2");
asm("___e_2:");
/****************************************
 * Bitmap header
 ****************************************/
asm(".byte 0x00");           // Compresssion
asm(".byte 0x01");           // Color Depth
asm(".byte 0x32, 0x00");     // Height
asm(".byte 0x32, 0x00");     // Width
/***********************************
 * Color Palette for the image
 **********************************/
asm(".byte 0x00, 0x00");
asm(".byte 0xFF, 0xFF");
/********************************
 * Bitmap Image Body
 *********************************/
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x7F, 0xF8");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x9F, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0x7F, 0xFE, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0x7F");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xEF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xDF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0x7F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03");
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

/*********************************
 * Bitmap Structure
 * Label: e_3
 * Description:  50x50 pixels, 1-bits per pixel
 ***********************************/
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

extern FLASH_BYTE __e_3[] __attribute__((section("grc_images"), aligned(2)));
const IMAGE_FLASH e_3 =
{
    (FLASH | IMAGE_MBITMAP | COMP_NONE),
    (FLASH_BYTE *)__e_3
};
asm(".section grc_images, code");
asm(".global ___e_3");
asm(".align 2");
asm("___e_3:");
/****************************************
 * Bitmap header
 ****************************************/
asm(".byte 0x00");           // Compresssion
asm(".byte 0x01");           // Color Depth
asm(".byte 0x32, 0x00");     // Height
asm(".byte 0x32, 0x00");     // Width
/***********************************
 * Color Palette for the image
 **********************************/
asm(".byte 0x00, 0x00");
asm(".byte 0xFF, 0xFF");
/********************************
 * Bitmap Image Body
 *********************************/
asm(".byte 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xBF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFB, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xEF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0xCF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xFC, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

/*********************************
 * Bitmap Structure
 * Label: e_4
 * Description:  50x50 pixels, 1-bits per pixel
 ***********************************/
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif

extern FLASH_BYTE __e_4[] __attribute__((section("grc_images"), aligned(2)));
const IMAGE_FLASH e_4 =
{
    (FLASH | IMAGE_MBITMAP | COMP_NONE),
    (FLASH_BYTE *)__e_4
};
asm(".section grc_images, code");
asm(".global ___e_4");
asm(".align 2");
asm("___e_4:");
/****************************************
 * Bitmap header
 ****************************************/
asm(".byte 0x00");           // Compresssion
asm(".byte 0x01");           // Color Depth
asm(".byte 0x32, 0x00");     // Height
asm(".byte 0x32, 0x00");     // Width
/***********************************
 * Color Palette for the image
 **********************************/
asm(".byte 0x00, 0x00");
asm(".byte 0xFF, 0xFF");
/********************************
 * Bitmap Image Body
 *********************************/
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFE, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0xBF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFB, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFE");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xE7, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x7F, 0xFE");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xE7, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0x7F, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF");
asm(".byte 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
asm(".byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03");
#if defined (__C30__) && (__C30_VERSION__ <= 325)
asm(".section .const, psv");
#else
asm(".section .const, psv, page");
#endif


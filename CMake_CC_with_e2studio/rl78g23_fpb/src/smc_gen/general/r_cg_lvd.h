/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_lvd.h
* Version      : 1.0.2
* Device(s)    : R7F100GLGxFB
* Description  : General header file for LVD peripheral.
***********************************************************************************************************************/

#ifndef LVD_H
#define LVD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Voltage Detection Register (LVIM)
*/
/* LVIS register rewrite enable/disable control (LVISEN) */
#define _00_LVD_REWRITE_LVIS_DISABLE    (0x00U)    /* disabling rewriting */
#define _80_LVD_REWRITE_LVIS_ENABLE     (0x80U)    /* enabling rewriting */
/* LVD1 detection interrupt flag (DLVD1F) */
#define _00_LVD1_INTERRUPT_NOT_DETECTED (0x00U)    /* the given LVD1 interrupt has not been detected */
#define _08_LVD1_INTERRUPT_DETECTED     (0x08U)    /* the given LVD1 interrupt has been detected */
/* LVD0 detection interrupt flag (DLVD0F) */
#define _00_LVD0_INTERRUPT_NOT_DETECTED (0x00U)    /* the given LVD0 interrupt has not been detected */
#define _04_LVD0_INTERRUPT_DETECTED     (0x04U)    /* the given LVD0 interrupt has been detected */
/* Voltage detection flag (LVD1F) */
#define _00_LVD1_FLAG_OVER              (0x00U)    /* supply voltage (VDD) >= detection voltage (VLVD1), or LVD is off */
#define _02_LVD1_FLAG_LESS              (0x02U)    /* supply voltage (VDD) < detection voltage (VLVD1) */
/* Voltage detection flag (LVD0F) */
#define _00_LVD0_FLAG_OVER              (0x00U)    /* supply voltage (VDD) >= detection voltage (VLVD0), or LVD is off */
#define _02_LVD0_FLAG_LESS              (0x01U)    /* supply voltage (VDD) < detection voltage (VLVD0) */

/*
    LVD Detection Flag Clearing Register (LVDFCLR)
*/
/* Clearing DLVD1F(DLVD1FCLR) */
#define _00_LVD1_NO_EFFECT              (0x00U)    /* writing 0 has no effect */
#define _08_LVD1_DLVD1F_CLEAR           (0x08U)    /* writing 1 to this bit clears the DLVD1F flag */
/* Clearing DLVD0F(DLVD0FCLR) */
#define _00_LVD0_NO_EFFECT              (0x00U)    /* writing 0 has no effect */
#define _04_LVD0_DLVD0F_CLEAR           (0x04U)    /* writing 1 to this bit clears the DLVD0F flag */

/*
    Voltage Detection Level Register (LVIS)
*/
/* Operation enable of voltage detection (LVD1EN) */
#define _00_LVD_OPERATION_DISABLE       (0x00U)    /* operation disable */
#define _80_LVD_OPERATION_ENABLE        (0x80U)    /* operation enable */
/* Operation mode of voltage detection (LVD1SEL) */
#define _00_LVD_MODE_INT                (0x00U)    /* interrupt mode */
#define _40_LVD_MODE_RESET              (0x80U)    /* reset mode */
/* LVD detection level (LVD1V4 - LVD1V0) */
#define _1F_LVD_LEVEL_163               (0x1FU)    /* 1.63 */
#define _1E_LVD_LEVEL_174               (0x1EU)    /* 1.74 */
#define _1D_LVD_LEVEL_184               (0x1DU)    /* 1.84 */
#define _1C_LVD_LEVEL_194               (0x1CU)    /* 1.94 */
#define _1B_LVD_LEVEL_204               (0x1BU)    /* 2.04 */
#define _1A_LVD_LEVEL_215               (0x1AU)    /* 2.15 */
#define _19_LVD_LEVEL_225               (0x19U)    /* 2.25 */
#define _18_LVD_LEVEL_235               (0x18U)    /* 2.35 */
#define _17_LVD_LEVEL_245               (0x17U)    /* 2.45 */
#define _16_LVD_LEVEL_260               (0x16U)    /* 2.60 */
#define _15_LVD_LEVEL_276               (0x15U)    /* 2.76 */
#define _14_LVD_LEVEL_291               (0x14U)    /* 2.91 */
#define _13_LVD_LEVEL_306               (0x13U)    /* 3.06 */
#define _12_LVD_LEVEL_327               (0x12U)    /* 3.27 */
#define _11_LVD_LEVEL_347               (0x11U)    /* 3.47 */
#define _10_LVD_LEVEL_367               (0x10U)    /* 3.67 */
#define _0F_LVD_LEVEL_388               (0x0FU)    /* 3.88 */
#define _0E_LVD_LEVEL_408               (0x0EU)    /* 4.08 */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

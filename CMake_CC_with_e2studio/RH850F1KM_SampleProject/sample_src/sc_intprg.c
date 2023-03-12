/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : sc_intprg-S1.c
* Version      : V1.00.00.00 (File version)
* Device(s)    : RH850/F1KM-S1
* Description  : This is the sample code of interrupt function.
* Creation Date: Apr.2018
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "iodefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/


/******************************************************************************
	Table Reference Method
******************************************************************************/
/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint0(enable=false, channel=0, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint0(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint1(enable=false, channel=1, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint1(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint2(enable=false, channel=2, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint2(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint3(enable=false, channel=3, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint3(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint4(enable=false, channel=4, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint4(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint5(enable=false, channel=5, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint5(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint6(enable=false, channel=6, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint6(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint7(enable=false, channel=7, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint7(void){
}

/* Interrupt for CH0 of TAUD0/CSIH2 communication status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint8(enable=false, channel=8, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint8(void){
}

/* Interrupt for CH3 of TAUD0/CSIH3 communication status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint9(enable=false, channel=9, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint9(void){
}

/* Interrupt for CH4 of TAUD0/CSIH2 receive status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint10(enable=false, channel=10, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint10(void){
}

/* Interrupt for CH6 of TAUD0/CSIH2 communication error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint11(enable=false, channel=11, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint11(void){
}

/* Interrupt for CH8 of TAUD0/CSIH2 job completion interrupt */
#ifdef __CCRH__
#pragma interrupt eiint12(enable=false, channel=12, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint12(void){
}

/* Interrupt for CH10 of TAUD0/CSIH3 receive status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint13(enable=false, channel=13, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint13(void){
}

/* Interrupt for CH12 of TAUD0/CSIH3 communication error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint14(enable=false, channel=14, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint14(void){
}

/* Interrupt for CH14 of TAUD0/CSIH3 job completion interrupt */
#ifdef __CCRH__
#pragma interrupt eiint15(enable=false, channel=15, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint15(void){
}

/* TAPA0 peak interrupt 0/CSIH1 communication status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint16(enable=false, channel=16, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint16(void){
}

/* TAPA0 valley interrupt 0/CSIH1 receive status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint17(enable=false, channel=17, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint17(void){
}

/* ADCA0 SG1 end interrupt */
#ifdef __CCRH__
#pragma interrupt eiint18(enable=false, channel=18, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint18(void){
}

/* ADCA0 SG2 end interrupt */
#ifdef __CCRH__
#pragma interrupt eiint19(enable=false, channel=19, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint19(void){
}

/* ADCA0 SG3 end interrupt/6 CSIH0 job completion interrupt */
#ifdef __CCRH__
#pragma interrupt eiint20(enable=false, channel=20, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint20(void){
}

/* Dedicated interrupt for on-chip debug function */
#ifdef __CCRH__
#pragma interrupt eiint21(enable=false, channel=21, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint21(void){
}

/* CAN global error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint22(enable=false, channel=22, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint22(void){
}

/* CAN receive FIFO interrupt */
#ifdef __CCRH__
#pragma interrupt eiint23(enable=false, channel=23, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint23(void){
}

/* CAN0 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint24(enable=false, channel=24, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint24(void){
}

/* CAN0 transmit/receive FIFO receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint25(enable=false, channel=25, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint25(void){
}

/* CAN0 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint26(enable=false, channel=26, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint26(void){
}

/* CSIG0 communication status interrupt/CSIH1 communication error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint27(enable=false, channel=27, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint27(void){
}

/* CSIG0 receive status interrupt/CSIH1 job interrupt */
#ifdef __CCRH__
#pragma interrupt eiint28(enable=false, channel=28, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint28(void){
}

/* CSIH0 communication status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint29(enable=false, channel=29, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint29(void){
}

/* CSIH0 receive status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint30(enable=false, channel=30, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint30(void){
}

/* CSIH0 communication error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint31(enable=false, channel=31, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint31(void){
}

/* CSIH0 job completion interrupt/ADCA0 SG3 end interrupt */
#ifdef __CCRH__
#pragma interrupt eiint32(enable=false, channel=32, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint32(void){
}

/* RLIN30 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint33(enable=false, channel=33, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint33(void){
}

/* RLIN30 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint34(enable=false, channel=34, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint34(void){
}

/* RLIN30 receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint35(enable=false, channel=35, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint35(void){
}

/* RLIN30 status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint36(enable=false, channel=36, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint36(void){
}

/* External interrupt(INTP0) */
#ifdef __CCRH__
#pragma interrupt eiint37(enable=false, channel=37, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint37(void){
}

/* External interrupt(INTP1) */
#ifdef __CCRH__
#pragma interrupt eiint38(enable=false, channel=38, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint38(void){
}

/* External interrupt(INTP2) */
#ifdef __CCRH__
#pragma interrupt eiint39(enable=false, channel=39, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint39(void){
}

/* WDTA0 75% interrupt */
#ifdef __CCRH__
#pragma interrupt eiint40(enable=false, channel=40, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint40(void){
}

/* WDTA1 75% interrupt */
#ifdef __CCRH__
#pragma interrupt eiint41(enable=false, channel=41, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint41(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint42(enable=false, channel=42, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint42(void){
}

/* External interrupt(INTP3) */
#ifdef __CCRH__
#pragma interrupt eiint43(enable=false, channel=43, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint43(void){
}

/* External interrupt(INTP4) */
#ifdef __CCRH__
#pragma interrupt eiint44(enable=false, channel=44, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint44(void){
}

/* External interrupt(INTP5) */
#ifdef __CCRH__
#pragma interrupt eiint45(enable=false, channel=45, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint45(void){
}

/* External interrupt(INTP10) */
#ifdef __CCRH__
#pragma interrupt eiint46(enable=false, channel=46, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint46(void){
}

/* External interrupt(INTP11) */
#ifdef __CCRH__
#pragma interrupt eiint47(enable=false, channel=47, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint47(void){
}

/* Interrupt for TAUD0 channel 1 */
#ifdef __CCRH__
#pragma interrupt eiint48(enable=false, channel=48, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint48(void){
}

/* Interrupt for TAUD0 channel 3 */
#ifdef __CCRH__
#pragma interrupt eiint49(enable=false, channel=49, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint49(void){
}

/* Interrupt for TAUD0 channel 5 */
#ifdef __CCRH__
#pragma interrupt eiint50(enable=false, channel=50, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint50(void){
}

/* Interrupt for TAUD0 channel 7 */
#ifdef __CCRH__
#pragma interrupt eiint51(enable=false, channel=51, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint51(void){
}

/* Interrupt for TAUD0 channel 9 */
#ifdef __CCRH__
#pragma interrupt eiint52(enable=false, channel=52, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint52(void){
}

/* Interrupt for TAUD0 channel 11 */
#ifdef __CCRH__
#pragma interrupt eiint53(enable=false, channel=53, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint53(void){
}

/* Interrupt for TAUD0 channel 13 */
#ifdef __CCRH__
#pragma interrupt eiint54(enable=false, channel=54, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint54(void){
}

/* Interrupt for TAUD0 channel 15 */
#ifdef __CCRH__
#pragma interrupt eiint55(enable=false, channel=55, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint55(void){
}

/* ADCA0 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint56(enable=false, channel=56, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint56(void){
}

/* CSIG0 receive error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint57(enable=false, channel=57, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint57(void){
}

/* RLIN20 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint58(enable=false, channel=58, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint58(void){
}

/* RLIN21 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint59(enable=false, channel=59, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint59(void){
}

/* DMA0 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint60(enable=false, channel=60, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint60(void){
}

/* DMA1 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint61(enable=false, channel=61, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint61(void){
}

/* DMA2 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint62(enable=false, channel=62, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint62(void){
}

/* DMA3 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint63(enable=false, channel=63, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint63(void){
}

/* DMA4 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint64(enable=false, channel=64, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint64(void){
}

/* DMA5 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint65(enable=false, channel=65, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint65(void){
}

/* DMA6 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint66(enable=false, channel=66, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint66(void){
}

/* DMA7 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint67(enable=false, channel=67, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint67(void){
}

/* DMA10 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint68(enable=false, channel=68, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint68(void){
}

/* DMA11 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint69(enable=false, channel=69, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint69(void){
}

/* DMA12 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint70(enable=false, channel=70, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint70(void){
}

/* DMA13 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint71(enable=false, channel=71, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint71(void){
}

/* DMA14 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint72(enable=false, channel=72, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint72(void){
}

/* DMA15 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint73(enable=false, channel=73, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint73(void){
}

/* DMA16 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint74(enable=false, channel=74, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint74(void){
}

/* DMA17 transfer completion */
#ifdef __CCRH__
#pragma interrupt eiint75(enable=false, channel=75, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint75(void){
}

/* RIIC transmit data empty interrupt */
#ifdef __CCRH__
#pragma interrupt eiint76(enable=false, channel=76, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint76(void){
}

/* RIIC receive error/event interrupt */
#ifdef __CCRH__
#pragma interrupt eiint77(enable=false, channel=77, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint77(void){
}

/* RIIC0 receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint78(enable=false, channel=78, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint78(void){
}

/* RIIC0 transmit complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint79(enable=false, channel=79, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint79(void){
}

/* Interrupt for TAUJ0 channel 0 */
#ifdef __CCRH__
#pragma interrupt eiint80(enable=false, channel=80, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint80(void){
}

/* Interrupt for TAUJ0 channel 1 */
#ifdef __CCRH__
#pragma interrupt eiint81(enable=false, channel=81, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint81(void){
}

/* Interrupt for TAUJ0 channel 2 */
#ifdef __CCRH__
#pragma interrupt eiint82(enable=false, channel=82, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint82(void){
}

/* Interrupt for TAUJ0 channel 3 */
#ifdef __CCRH__
#pragma interrupt eiint83(enable=false, channel=83, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint83(void){
}

/* OSTM0 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint84(enable=false, channel=84, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint84(void){
}

/* ENCA0 overflow interrupt */
#ifdef __CCRH__
#pragma interrupt eiint85(enable=false, channel=85, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint85(void){
}

/* ENCA0 underflow interrupt */
#ifdef __CCRH__
#pragma interrupt eiint86(enable=false, channel=86, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint86(void){
}

/* ENCA0 match or capture interrupt 0 */
#ifdef __CCRH__
#pragma interrupt eiint87(enable=false, channel=87, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint87(void){
}

/* ENCA0 match or capture interrupt 1 */
#ifdef __CCRH__
#pragma interrupt eiint88(enable=false, channel=88, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint88(void){
}

/* ENCA0 encoder clear interrupt */
#ifdef __CCRH__
#pragma interrupt eiint89(enable=false, channel=89, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint89(void){
}

/* KR0 key interrupt */
#ifdef __CCRH__
#pragma interrupt eiint90(enable=false, channel=90, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint90(void){
}

/* PWSA queue full interrupt */
#ifdef __CCRH__
#pragma interrupt eiint91(enable=false, channel=91, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint91(void){
}

/* PWGA0 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint92(enable=false, channel=92, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint92(void){
}

/* PWGA1 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint93(enable=false, channel=93, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint93(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint94(enable=false, channel=94, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint94(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint95(enable=false, channel=95, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint95(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint96(enable=false, channel=96, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint96(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint97(enable=false, channel=97, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint97(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint98(enable=false, channel=98, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint98(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint99(enable=false, channel=99, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint99(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint100(enable=false, channel=100, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint100(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint101(enable=false, channel=101, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint101(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint102(enable=false, channel=102, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint102(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint103(enable=false, channel=103, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint103(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint104(enable=false, channel=104, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint104(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint105(enable=false, channel=105, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint105(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint106(enable=false, channel=106, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint106(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint107(enable=false, channel=107, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint107(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint108(enable=false, channel=108, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint108(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint109(enable=false, channel=109, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint109(void){
}

/* Flash sequencer end error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint110(enable=false, channel=110, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint110(void){
}

/* Flash sequencer end interrupt */
#ifdef __CCRH__
#pragma interrupt eiint111(enable=false, channel=111, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint111(void){
}

/* LPS port polling end interrupt */
#ifdef __CCRH__
#pragma interrupt eiint112(enable=false, channel=112, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint112(void){
}

/* CAN1 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint113(enable=false, channel=113, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint113(void){
}

/* CAN1 transmit/receive FIFO receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint114(enable=false, channel=114, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint114(void){
}

/* CAN1 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint115(enable=false, channel=115, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint115(void){
}

/* CSIH1 communication status interrupt/TAPA0 peak interrupt 0 */
#ifdef __CCRH__
#pragma interrupt eiint116(enable=false, channel=116, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint116(void){
}

/* CSIH1 receive status interrupt/TAPA0 valley interrupt 0 */
#ifdef __CCRH__
#pragma interrupt eiint117(enable=false, channel=117, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint117(void){
}

/* CSIH1 communication error interrupt/CSIG0 communication status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint118(enable=false, channel=118, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint118(void){
}

/* CSIH1 job interrupt/CSIG0 receive status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint119(enable=false, channel=119, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint119(void){
}

/* RLIN31 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint120(enable=false, channel=120, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint120(void){
}

/* RLIN31 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint121(enable=false, channel=121, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint121(void){
}

/* RLIN31 receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint122(enable=false, channel=122, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint122(void){
}

/* RLIN31 status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint123(enable=false, channel=123, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint123(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint124(enable=false, channel=124, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint124(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint125(enable=false, channel=125, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint125(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint126(enable=false, channel=126, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint126(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint127(enable=false, channel=127, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint127(void){
}

/* External interrupt(INTP6) */
#ifdef __CCRH__
#pragma interrupt eiint128(enable=false, channel=128, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint128(void){
}

/* External interrupt(INTP7) */
#ifdef __CCRH__
#pragma interrupt eiint129(enable=false, channel=129, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint129(void){
}

/* External interrupt(INTP8) */
#ifdef __CCRH__
#pragma interrupt eiint130(enable=false, channel=130, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint130(void){
}

/* External interrupt(INTP12) */
#ifdef __CCRH__
#pragma interrupt eiint131(enable=false, channel=131, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint131(void){
}

/* CSIH2 communication status interrupt/Interrupt for TAUD0 channel 0 */
#ifdef __CCRH__
#pragma interrupt eiint132(enable=false, channel=132, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint132(void){
}

/* CSIH2 communication status interrupt/Interrupt for TAUD0 channel 4 */
#ifdef __CCRH__
#pragma interrupt eiint133(enable=false, channel=133, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint133(void){
}

/* CSIH2 communication error interrupt/Interrupt for TAUD0 channel 6 */
#ifdef __CCRH__
#pragma interrupt eiint134(enable=false, channel=134, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint134(void){
}

/* CSIH2 job completion interrupt/Interrupt for TAUD0 channel 8 */
#ifdef __CCRH__
#pragma interrupt eiint135(enable=false, channel=135, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint135(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint136(enable=false, channel=136, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint136(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint137(enable=false, channel=137, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint137(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint138(enable=false, channel=138, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint138(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint139(enable=false, channel=139, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint139(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint140(enable=false, channel=140, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint140(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint141(enable=false, channel=141, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint141(void){
}

/* Interrupt for TAUB0 channel 0 */
#ifdef __CCRH__
#pragma interrupt eiint142(enable=false, channel=142, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint142(void){
}

/* Interrupt for TAUB0 channel 1 */
#ifdef __CCRH__
#pragma interrupt eiint143(enable=false, channel=143, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint143(void){
}

/* Interrupt for TAUB0 channel 2 */
#ifdef __CCRH__
#pragma interrupt eiint144(enable=false, channel=144, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint144(void){
}

/* Interrupt for TAUB0 channel 3 */
#ifdef __CCRH__
#pragma interrupt eiint145(enable=false, channel=145, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint145(void){
}

/* Interrupt for TAUB0 channel 4 */
#ifdef __CCRH__
#pragma interrupt eiint146(enable=false, channel=146, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint146(void){
}

/* Interrupt for TAUB0 channel 5 */
#ifdef __CCRH__
#pragma interrupt eiint147(enable=false, channel=147, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint147(void){
}

/* Interrupt for TAUB0 channel 6 */
#ifdef __CCRH__
#pragma interrupt eiint148(enable=false, channel=148, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint148(void){
}

/* Interrupt for TAUB0 channel 7 */
#ifdef __CCRH__
#pragma interrupt eiint149(enable=false, channel=149, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint149(void){
}

/* Interrupt for TAUB0 channel 8 */
#ifdef __CCRH__
#pragma interrupt eiint150(enable=false, channel=150, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint150(void){
}

/* Interrupt for TAUB0 channel 9 */
#ifdef __CCRH__
#pragma interrupt eiint151(enable=false, channel=151, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint151(void){
}

/* Interrupt for TAUB0 channel 10 */
#ifdef __CCRH__
#pragma interrupt eiint152(enable=false, channel=152, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint152(void){
}

/* Interrupt for TAUB0 channel 11 */
#ifdef __CCRH__
#pragma interrupt eiint153(enable=false, channel=153, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint153(void){
}

/* Interrupt for TAUB0 channel 12 */
#ifdef __CCRH__
#pragma interrupt eiint154(enable=false, channel=154, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint154(void){
}

/* Interrupt for TAUB0 channel 13 */
#ifdef __CCRH__
#pragma interrupt eiint155(enable=false, channel=155, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint155(void){
}

/* Interrupt for TAUB0 channel 14 */
#ifdef __CCRH__
#pragma interrupt eiint156(enable=false, channel=156, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint156(void){
}

/* Interrupt for TAUB0 channel 15 */
#ifdef __CCRH__
#pragma interrupt eiint157(enable=false, channel=157, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint157(void){
}

/* CSIH3 communication status interrupt/Interrupt for TAUD0 channel 2 */
#ifdef __CCRH__
#pragma interrupt eiint158(enable=false, channel=158, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint158(void){
}

/* CSIH3 receive status interrupt/Interrupt for TAUD0 channel 10 */
#ifdef __CCRH__
#pragma interrupt eiint159(enable=false, channel=159, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint159(void){
}

/* CSIH3 communication error interrupt/Interrupt for TAUD0 channel 12 */
#ifdef __CCRH__
#pragma interrupt eiint160(enable=false, channel=160, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint160(void){
}

/* CSIH3 job completion interrupt/Interrupt for TAUD0 channel 14 */
#ifdef __CCRH__
#pragma interrupt eiint161(enable=false, channel=161, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint161(void){
}

/* RLIN22 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint162(enable=false, channel=162, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint162(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint163(enable=false, channel=163, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint163(void){
}

/* RLIN32 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint164(enable=false, channel=164, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint164(void){
}

/* RLIN32 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint165(enable=false, channel=165, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint165(void){
}

/* RLIN32 receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint166(enable=false, channel=166, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint166(void){
}

/* RLIN32 status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint167(enable=false, channel=167, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint167(void){
}

/* Interrupt for TAUJ1 channel 0 */
#ifdef __CCRH__
#pragma interrupt eiint168(enable=false, channel=168, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint168(void){
}

/* Interrupt for TAUJ1 channel 1 */
#ifdef __CCRH__
#pragma interrupt eiint169(enable=false, channel=169, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint169(void){
}

/* Interrupt for TAUJ1 channel 2 */
#ifdef __CCRH__
#pragma interrupt eiint170(enable=false, channel=170, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint170(void){
}

/* Interrupt for TAUJ1 channel 3 */
#ifdef __CCRH__
#pragma interrupt eiint171(enable=false, channel=171, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint171(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint172(enable=false, channel=172, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint172(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint173(enable=false, channel=173, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint173(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint174(enable=false, channel=174, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint174(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint175(enable=false, channel=175, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint175(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint176(enable=false, channel=176, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint176(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint177(enable=false, channel=177, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint177(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint178(enable=false, channel=178, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint178(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint179(enable=false, channel=179, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint179(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint180(enable=false, channel=180, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint180(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint181(enable=false, channel=181, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint181(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint182(enable=false, channel=182, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint182(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint183(enable=false, channel=183, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint183(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint184(enable=false, channel=184, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint184(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint185(enable=false, channel=185, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint185(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint186(enable=false, channel=186, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint186(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint187(enable=false, channel=187, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint187(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint188(enable=false, channel=188, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint188(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint189(enable=false, channel=189, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint189(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint190(enable=false, channel=190, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint190(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint191(enable=false, channel=191, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint191(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint192(enable=false, channel=192, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint192(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint193(enable=false, channel=193, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint193(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint194(enable=false, channel=194, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint194(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint195(enable=false, channel=195, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint195(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint196(enable=false, channel=196, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint196(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint197(enable=false, channel=197, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint197(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint198(enable=false, channel=198, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint198(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint199(enable=false, channel=199, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint199(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint200(enable=false, channel=200, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint200(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint201(enable=false, channel=201, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint201(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint202(enable=false, channel=202, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint202(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint203(enable=false, channel=203, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint203(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint204(enable=false, channel=204, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint204(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint205(enable=false, channel=205, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint205(void){
}

/* External interrupt(INTP13) */
#ifdef __CCRH__
#pragma interrupt eiint206(enable=false, channel=206, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint206(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint207(enable=false, channel=207, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint207(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint208(enable=false, channel=208, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint208(void){
}

/* RTCA0 1-second interval interrupt */
#ifdef __CCRH__
#pragma interrupt eiint209(enable=false, channel=209, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint209(void){
}

/* RTCA0 alarm interrupt */
#ifdef __CCRH__
#pragma interrupt eiint210(enable=false, channel=210, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint210(void){
}

/* RTCA0 fixed interval interrupt */
#ifdef __CCRH__
#pragma interrupt eiint211(enable=false, channel=211, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint211(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint212(enable=false, channel=212, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint212(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint213(enable=false, channel=213, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint213(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint214(enable=false, channel=214, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint214(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint215(enable=false, channel=215, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint215(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint216(enable=false, channel=216, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint216(void){
}

/* CAN2 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint217(enable=false, channel=217, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint217(void){
}

/* CAN2 transmit/receive FIFO receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint218(enable=false, channel=218, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint218(void){
}

/* CAN2 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint219(enable=false, channel=219, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint219(void){
}

/* CAN3 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint220(enable=false, channel=220, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint220(void){
}

/* CAN3 transmit/receive FIFO receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint221(enable=false, channel=221, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint221(void){
}

/* CAN3 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint222(enable=false, channel=222, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint222(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint223(enable=false, channel=223, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint223(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint224(enable=false, channel=224, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint224(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint225(enable=false, channel=225, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint225(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint226(enable=false, channel=226, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint226(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint227(enable=false, channel=227, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint227(void){
}

/* RLIN33 interrupt */
#ifdef __CCRH__
#pragma interrupt eiint228(enable=false, channel=228, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint228(void){
}

/* RLIN33 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint229(enable=false, channel=229, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint229(void){
}

/* RLIN33 receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint230(enable=false, channel=230, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint230(void){
}

/* RLIN33 status interrupt */
#ifdef __CCRH__
#pragma interrupt eiint231(enable=false, channel=231, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint231(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint232(enable=false, channel=232, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint232(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint233(enable=false, channel=233, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint233(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint234(enable=false, channel=234, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint234(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint235(enable=false, channel=235, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint235(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint236(enable=false, channel=236, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint236(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint237(enable=false, channel=237, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint237(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint238(enable=false, channel=238, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint238(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint239(enable=false, channel=239, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint239(void){
}

/* RIIC1 transmit data empty interrupt */
#ifdef __CCRH__
#pragma interrupt eiint240(enable=false, channel=240, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint240(void){
}

/* RIIC1 receive error/event interrupt */
#ifdef __CCRH__
#pragma interrupt eiint241(enable=false, channel=241, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
void eiint241(void){
}

/* RIIC1 receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint242(enable=false, channel=242, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint242(void){
}

/* RIIC1 transmit complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint243(enable=false, channel=243, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint243(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint244(enable=false, channel=244, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint244(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint245(enable=false, channel=245, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint245(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint246(enable=false, channel=246, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint246(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint247(enable=false, channel=247, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint247(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint248(enable=false, channel=248, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint248(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint249(enable=false, channel=249, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint249(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint250(enable=false, channel=250, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint250(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint251(enable=false, channel=251, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint251(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint252(enable=false, channel=252, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint252(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint253(enable=false, channel=253, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint253(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint254(enable=false, channel=254, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint254(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint255(enable=false, channel=255, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint255(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint256(enable=false, channel=256, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint256(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint257(enable=false, channel=257, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint257(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint258(enable=false, channel=258, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint258(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint259(enable=false, channel=259, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint259(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint260(enable=false, channel=260, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint260(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint261(enable=false, channel=261, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint261(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint262(enable=false, channel=262, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint262(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint263(enable=false, channel=263, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint263(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint264(enable=false, channel=264, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint264(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint265(enable=false, channel=265, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint265(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint266(enable=false, channel=266, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint266(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint267(enable=false, channel=267, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint267(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint268(enable=false, channel=268, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint268(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint269(enable=false, channel=269, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint269(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint270(enable=false, channel=270, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint270(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint271(enable=false, channel=271, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint271(void){
}

/* CAN4 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint272(enable=false, channel=272, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint272(void){
}

/* CAN4 transmit/receive FIFO receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint273(enable=false, channel=273, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint273(void){
}

/* CAN4 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint274(enable=false, channel=274, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint274(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint275(enable=false, channel=275, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint275(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint276(enable=false, channel=276, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint276(void){
}

/* Interrupt for TAUJ2 channel 0 */
#ifdef __CCRH__
#pragma interrupt eiint277(enable=false, channel=277, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint277(void){
}

/* Interrupt for TAUJ2 channel 1 */
#ifdef __CCRH__
#pragma interrupt eiint278(enable=false, channel=278, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint278(void){
}

/* Interrupt for TAUJ2 channel 2 */
#ifdef __CCRH__
#pragma interrupt eiint279(enable=false, channel=279, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint279(void){
}

/* Interrupt for TAUJ2 channel 3 */
#ifdef __CCRH__
#pragma interrupt eiint280(enable=false, channel=280, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint280(void){
}

/* Interrupt for TAUJ3 channel 0 */
#ifdef __CCRH__
#pragma interrupt eiint281(enable=false, channel=281, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint281(void){
}

/* Interrupt for TAUJ3 channel 1 */
#ifdef __CCRH__
#pragma interrupt eiint282(enable=false, channel=282, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint282(void){
}

/* Interrupt for TAUJ3 channel 2 */
#ifdef __CCRH__
#pragma interrupt eiint283(enable=false, channel=283, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint283(void){
}

/* Interrupt for TAUJ3 channel 3 */
#ifdef __CCRH__
#pragma interrupt eiint284(enable=false, channel=284, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint284(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint285(enable=false, channel=285, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint285(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint286(enable=false, channel=286, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint286(void){
}

/* CAN5 error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint287(enable=false, channel=287, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint287(void){
}

/* CAN5 transmit/receive FIFO receive complete interrupt */
#ifdef __CCRH__
#pragma interrupt eiint288(enable=false, channel=288, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint288(void){
}

/* CAN5 transmit interrupt */
#ifdef __CCRH__
#pragma interrupt eiint289(enable=false, channel=289, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint289(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint290(enable=false, channel=290, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint290(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint291(enable=false, channel=291, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint291(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint292(enable=false, channel=292, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint292(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint293(enable=false, channel=293, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint293(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint294(enable=false, channel=294, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint294(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint295(enable=false, channel=295, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint295(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint296(enable=false, channel=296, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint296(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint297(enable=false, channel=297, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint297(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint298(enable=false, channel=298, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint298(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint299(enable=false, channel=299, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint299(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint300(enable=false, channel=300, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint300(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint301(enable=false, channel=301, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint301(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint302(enable=false, channel=302, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint302(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint303(enable=false, channel=303, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint303(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint304(enable=false, channel=304, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint304(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint305(enable=false, channel=305, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint305(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint306(enable=false, channel=306, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint306(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint307(enable=false, channel=307, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint307(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint308(enable=false, channel=308, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint308(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint309(enable=false, channel=309, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint309(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint310(enable=false, channel=310, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint310(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint311(enable=false, channel=311, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint311(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint312(enable=false, channel=312, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint312(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint313(enable=false, channel=313, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint313(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint314(enable=false, channel=314, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint314(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint315(enable=false, channel=315, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint315(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint316(enable=false, channel=316, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint316(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint317(enable=false, channel=317, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint317(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint318(enable=false, channel=318, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint318(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint319(enable=false, channel=319, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint319(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint320(enable=false, channel=320, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint320(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint321(enable=false, channel=321, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint321(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint322(enable=false, channel=322, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint322(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint323(enable=false, channel=323, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint323(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint324(enable=false, channel=324, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint324(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint325(enable=false, channel=325, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint325(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint326(enable=false, channel=326, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint326(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint327(enable=false, channel=327, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint327(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint328(enable=false, channel=328, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint328(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint329(enable=false, channel=329, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint329(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint330(enable=false, channel=330, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint330(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint331(enable=false, channel=331, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint331(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint332(enable=false, channel=332, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint332(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint333(enable=false, channel=333, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint333(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint334(enable=false, channel=334, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint334(void){
}

/* Transfer interrupt for CXP10 */
#ifdef __CCRH__
#pragma interrupt eiint335(enable=false, channel=335, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint335(void){
}

/* Receive interrupt for CXP10 */
#ifdef __CCRH__
#pragma interrupt eiint336(enable=false, channel=336, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint336(void){
}

/* Status interrupt for CXP10 */
#ifdef __CCRH__
#pragma interrupt eiint337(enable=false, channel=337, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint337(void){
}

/* Transfer interrupt for CXP11 */
#ifdef __CCRH__
#pragma interrupt eiint338(enable=false, channel=338, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint338(void){
}

/* Receive interrupt for CXP11 */
#ifdef __CCRH__
#pragma interrupt eiint339(enable=false, channel=339, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint339(void){
}

/* Status interrupt for CXP11 */
#ifdef __CCRH__
#pragma interrupt eiint340(enable=false, channel=340, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint340(void){
}

/* Transfer interrupt for CXP12 */
#ifdef __CCRH__
#pragma interrupt eiint341(enable=false, channel=341, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint341(void){
}

/* Receive interrupt for CXP12 */
#ifdef __CCRH__
#pragma interrupt eiint342(enable=false, channel=342, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint342(void){
}

/* Status interrupt for CXP12 */
#ifdef __CCRH__
#pragma interrupt eiint343(enable=false, channel=343, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint343(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint344(enable=false, channel=344, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint344(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint345(enable=false, channel=345, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint345(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint346(enable=false, channel=346, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint346(void){
}

/* Status interrupt for RSENT0 */
#ifdef __CCRH__
#pragma interrupt eiint347(enable=false, channel=347, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint347(void){
}

/* Receive interrupt for RSENT0 */
#ifdef __CCRH__
#pragma interrupt eiint348(enable=false, channel=348, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint348(void){
}

/* Status interrupt for RSENT1 */
#ifdef __CCRH__
#pragma interrupt eiint349(enable=false, channel=349, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint349(void){
}

/* Receive interrupt for RSENT1 */
#ifdef __CCRH__
#pragma interrupt eiint350(enable=false, channel=350, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint350(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint351(enable=false, channel=351, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint351(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint352(enable=false, channel=352, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint352(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint353(enable=false, channel=353, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint353(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint354(enable=false, channel=354, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint354(void){
}

/* Reserved */
#ifdef __CCRH__
#pragma interrupt eiint355(enable=false, channel=355, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint355(void){
}

/* LPS digital port error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint356(enable=false, channel=356, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint356(void){
}

/* LPS analog port error interrupt */
#ifdef __CCRH__
#pragma interrupt eiint357(enable=false, channel=357, fpu=true, callt=false)
#endif
#ifdef __ghs__
#pragma ghs interrupt
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma type_attribute=__interrupt
#endif
void eiint357(void){
}

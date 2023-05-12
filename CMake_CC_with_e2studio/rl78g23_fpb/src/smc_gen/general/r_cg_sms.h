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
* File Name    : r_cg_sms.h
* Version      : 1.0.101
* Device(s)    : R7F100GLGxFB
* Description  : General header file for SMS peripheral.
* Creation Date: 2021-05-25
***********************************************************************************************************************/

#ifndef SMS_H
#define SMS_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 1 (PER1)
*/
/* Control of SMS input clock supply (SMSEN) */
#define _00_SMS_CLOCK_STOP                     (0x00U)    /* stop supply of input clock */
#define _40_SMS_CLOCK_SUPPLY                   (0x40U)    /* supply input clock */

/*
    Peripheral Reset Register 1 (PRR1)
*/
/* Reset control for SMS (SMSRES) */
#define _00_SMS_RESET_RELEASE                  (0x00U)    /* SMS is released from the reset state */
#define _40_SMS_RESET_SET                      (0x40U)    /* SMS is in the reset state */
/*
    Interval timer status register (ITLS0)
*/
/* Clear INTITL signal (SMSSTART) */
#define _00_INTITL_CLEAR                       (0x00U)    /* clear INTITL signal */
/*
    Sequencer control register (SMSC)
*/
/* SNOOZE mode sequencer start (SMSSTART) */
#define _80_SMS_START                          (0x80U)    /* start SMS operation control */
/* SNOOZE mode sequencer stop (SMSSTOP) */
#define _40_SMS_STOP                           (0x40U)    /* stop SMS operation control */
/* SNOOZE mode sequencer holds the activating trigger pending (SMSTRGWAIT) */
#define _00_SMS_HOLD_PENDING_DISABLE           (0x00U)    /* disable holding the activating trigger pending */
#define _20_SMS_HOLD_PENDING_ENABLE            (0x20U)    /* enable holding the activating trigger pending */
/* Status flag indicating the clock source with the wait command (LONGWAIT) */
#define _00_SMS_REQUEST_LOCO_DISABLE           (0x00U)    /* no request for the supply of the LOCO clock */
#define _10_SMS_REQUEST_LOCO_ENABLE            (0x10U)    /* a request for the supply of the LOCO clock */
/* Activating trigger for the SNOOZE mode sequencer (SMSTRGSEL3 - SMSTRGSEL0) */
#define _00_SMS_TRIGGER_INTITL                 (0x00U)    /* select INTITL as SMS activated trigger */
#define _01_SMS_TRIGGER_INTP3                  (0x01U)    /* select INTP3 as SMS activated trigger */
#define _02_SMS_TRIGGER_INTSR0                 (0x02U)    /* select INTSR0 as SMS activated trigger */
#define _03_SMS_TRIGGER_INTCSI00               (0x03U)    /* select INTCSI00 as SMS activated trigger */
#define _04_SMS_TRIGGER_INTAD                  (0x04U)    /* select INTAD as SMS activated trigger */
#define _05_SMS_TRIGGER_ELCL                   (0x05U)    /* select ELCL output signal as SMS activated trigger */
#define _06_SMS_TRIGGER_INTUR0                 (0x06U)    /* select INTUR0 as SMS activated trigger */
#define _07_SMS_TRIGGER_INTTM02                (0x07U)    /* select INTTM02 as SMS activated trigger */
#define _08_SMS_TRIGGER_INTIICA0               (0x08U)    /* select INTIICA0 as SMS activated trigger */
#define _09_SMS_TRIGGER_INTLVI                 (0x09U)    /* select INTLVI as SMS activated trigger */
#define _0A_SMS_TRIGGER_INTKR                  (0x0AU)    /* select INTKR as SMS activated trigger */

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


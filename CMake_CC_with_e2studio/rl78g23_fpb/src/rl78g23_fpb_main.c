/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
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
* Copyright (C) 2015, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/*******************************************************************************
* File Name : tb_rx65n_main.c
* Version : 1.02
* Device(s) : R5F565NEDDFP
* Tool-Chain : CC-RX v2.07.00
* Smart Configurator : v1.2.0
* H/W Platform : Target Board for RX65N
* Description : The function of this program selects either the user switch
*               interrupt or the timer interrupt according to the mode
*               selection at startup and controls the lighting of the LED by
*               using the interrupt.
* Operation : Auto mode : (1-1) Power on reset.
*                         (1-2) LED1, LED2 blink alternate.(interval 500 ms)
*             Manual mode : (2-1) Press down SW1 button with reset.
*                           (2-2) When SW1 is clicked, LED1, LED2 blink
*                                 alternately.
******************************************************************************/

/*****************************************************************************
* History : 01.08.2017 Version Description
* : 01.08.2017 1.00 First Release
* : 14.09.2017 1.01 Header information fix.
*                   Adds Include File [tbrx651def.h].
*                   Changed to processing using include file declaration.
* : 27.09.2017 1.02 Changed device RX651 -> RX65N.
*                   Fix user define file location.
*                   (Config_CMT0_user.c, Config_ICU_user.c)
*
******************************************************************************/
#include "r_smc_entry.h"
#include "rl78g23fpbdef.h"
#include "sample_lib1.h"
#include "sample_lib2.h"
#include "sample_lib3.h"

void main(void);
float f, g, h; /* for linking runtime library forcibly */

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void main(void)
{
    EI();

    f = g + h;
    sample_lib1a_c( sample_lib2a_c( 1, 2 ), sample_lib3a_c( 3, 4 ) );
    sample_lib1b_c( sample_lib2b_c( 5, 6 ), sample_lib3a_c( 7, 8 ) );

    LED1 = LED_OFF;
    LED2 = LED_OFF;

    if (SW1_PUSH == SW1) /*SW1_PUSH = Manual Mode,  Other = Auto Mode*/
    {
        R_Config_INTC_INTP0_Start();
    }
    else
    {
        R_ITL_Start_Interrupt();
        R_Config_ITL0_Start();
    }
    while(1)
    {
        /* Blink LED1, LED2 Alternately by Interrupt */
        /* Wait for interrupt in HALT mode           */
        HALT();
    }
}

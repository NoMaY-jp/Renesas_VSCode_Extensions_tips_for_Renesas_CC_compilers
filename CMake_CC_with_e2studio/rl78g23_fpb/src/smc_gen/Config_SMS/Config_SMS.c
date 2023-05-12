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
* File Name    : Config_SMS.c
* Version      : 1.0.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements SMS setting.
* Creation Date: 2021-05-25
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_SMS.h"
#include "Config_SMS_ASM.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint8_t g_sms_wakeup_flag;
unsigned short sms_greg1[] = {sms_greg1_initializer};
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Create
* Description  : This function initializes the SMS module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Create(void)
{
    int i;
    unsigned short* dst = (unsigned short*)0x0380; /* Address of SMSI0 */
    static const unsigned short iregs[SIZEOF_sms_program1] = {
    sms_program1
    };
    SMSEN = 1U;
    /* Copy the SMS instruction */
    for (i = 0; i < SIZEOF_sms_program1; ++i) {
        *dst = iregs[i];
        ++dst;
    }
    /* Copy the SMS instruction */
    dst = (unsigned short*)0x03C0; /* Address of SMSG0 */
    for (i = 0; i < sizeof(sms_greg1)/sizeof(sms_greg1[0]); ++i) {
        *dst = sms_greg1[i];
        ++dst;
    }
    SMSC |= _00_SMS_TRIGGER_INTITL;
    R_Config_SMS_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Start
* Description  : This function starts SMS module operation.
* Arguments    : argn -
*                    The pass argument to SMS. 'argn' was defined in SMS start block.
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Start(uint16_t val_ram_d, uint16_t val_ram_s, uint16_t val_ram_e)
{
    /* Set the sms data from arguments */
    SMSG1 = val_ram_d;
    SMSG3 = val_ram_s;
    SMSG2 = val_ram_e;
    /* Disable related interrupts */
    ITLMK = 1U;
    TMMK01 = 1U;
    /* Start sms */
    SMSEIF = 0U; /* clear INTSMSE interrupt flag */
    SMSEMK = 0U; /* enable INTSMSE interrupt */
    g_sms_wakeup_flag = 0U;
    ITLS0 = _00_INTITL_CLEAR;
    SMSSTART = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Stop
* Description  : This function stops SMS module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Stop(void)
{
    SMSSTOP = 1;
    SMSEMK = 1U; /* disable INTSMSE interrupt */
    SMSEIF = 0U; /* clear INTSMSE interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_GetStatus
* Description  : This function returns SMS status.
* Arguments    : None
* Return Value : g_sms_wakeup_flag -
*                    SMS wake up flag
***********************************************************************************************************************/
uint8_t R_Config_SMS_GetStatus(void)
{
    return g_sms_wakeup_flag;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_GetReturn
* Description  : This function returns SMS result.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_GetReturn(void)
{
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_TriggerWait_Disable
* Description  : This function disables trigger wait operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_TriggerWait_Disable(void)
{
    SMSTRGWAIT = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_TriggerWait_Enable
* Description  : This function enables trigger wait operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_TriggerWait_Enable(void)
{
    SMSTRGWAIT = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Set_PowerOn
* Description  : This function starts the clock supply for SMS module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Set_PowerOn(void)
{
    SMSEN = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Set_PowerOff
* Description  : This function stops the clock supply for SMS module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Set_PowerOff(void)
{
    SMSEN = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Set_Reset
* Description  : This function sets SMS module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Set_Reset(void)
{
    SMSRES = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SMS_Release_Reset
* Description  : This function releases SMS module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_SMS_Release_Reset(void)
{
    SMSRES = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


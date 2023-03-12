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
* Copyright (C) 2016, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_smc_interrupt.h
* Version      : 1.1.0
* Device(s)    : R7F701645
* Description  : This file implements interrupt priority setting.
***********************************************************************************************************************/

#ifndef SMC_INTC_H
#define SMC_INTC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define INTC_TAUD0_INTTAUD0I0_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I2_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I4_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I6_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I8_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I10_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I12_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I14_PRIORITY              _INT_PRIORITY_15
#define INTC_TAPA0_INTTAPA0IPEK0_PRIORITY            _INT_PRIORITY_15
#define INTC_TAPA0_INTTAPA0IVLY0_PRIORITY            _INT_PRIORITY_15
#define INTC_ADCA0_INTADCA0I0_PRIORITY               _INT_PRIORITY_15
#define INTC_ADCA0_INTADCA0I1_PRIORITY               _INT_PRIORITY_15
#define INTC_ADCA0_INTADCA0I2_PRIORITY               _INT_PRIORITY_15
#define INTC_Port_INTDCUTDI_PRIORITY                 _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCANGERR0_PRIORITY            _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCANGRECC0_PRIORITY           _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN0ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN0REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN0TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_CSIG0_INTCSIG0IC_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIG0_INTCSIG0IR_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH0_INTCSIH0IC_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH0_INTCSIH0IR_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH0_INTCSIH0IRE_PRIORITY              _INT_PRIORITY_15
#define INTC_CSIH0_INTCSIH0IJC_PRIORITY              _INT_PRIORITY_15
#define INTC_RLIN30_INTRLIN30_PRIORITY               _INT_PRIORITY_15
#define INTC_RLIN30_INTRLIN30UR0_PRIORITY            _INT_PRIORITY_15
#define INTC_RLIN30_INTRLIN30UR1_PRIORITY            _INT_PRIORITY_15
#define INTC_RLIN30_INTRLIN30UR2_PRIORITY            _INT_PRIORITY_15
#define INTC_Port_INTP0_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP1_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP2_PRIORITY                     _INT_PRIORITY_15
#define INTC_WDTA0_INTWDTA0_PRIORITY                 _INT_PRIORITY_15
#define INTC_WDTA1_INTWDTA1_PRIORITY                 _INT_PRIORITY_15
#define INTC_Port_INTP3_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP4_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP5_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP10_PRIORITY                    _INT_PRIORITY_15
#define INTC_Port_INTP11_PRIORITY                    _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I1_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I3_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I5_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I7_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I9_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I11_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I13_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUD0_INTTAUD0I15_PRIORITY              _INT_PRIORITY_15
#define INTC_ADCA0_INTADCA0ERR_PRIORITY              _INT_PRIORITY_15
#define INTC_CSIG0_INTCSIG0IRE_PRIORITY              _INT_PRIORITY_15
#define INTC_RLIN240_INTRLIN20_PRIORITY              _INT_PRIORITY_15
#define INTC_RLIN240_INTRLIN21_PRIORITY              _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA0_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA1_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA2_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA3_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA4_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA5_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA6_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC0_INTDMA7_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA8_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA9_PRIORITY                  _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA10_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA11_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA12_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA13_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA14_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC1_INTDMA15_PRIORITY                 _INT_PRIORITY_15
#define INTC_RIIC0_INTRIIC0TI_PRIORITY               _INT_PRIORITY_15
#define INTC_RIIC0_INTRIIC0EE_PRIORITY               _INT_PRIORITY_15
#define INTC_RIIC0_INTRIIC0RI_PRIORITY               _INT_PRIORITY_15
#define INTC_RIIC0_INTRIIC0TEI_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUJ0_INTTAUJ0I0_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ0_INTTAUJ0I1_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ0_INTTAUJ0I2_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ0_INTTAUJ0I3_PRIORITY               _INT_PRIORITY_15
#define INTC_OSTM0_INTOSTM0_PRIORITY                 _INT_PRIORITY_15
#define INTC_ENCA0_INTENCA0IOV_PRIORITY              _INT_PRIORITY_15
#define INTC_ENCA0_INTENCA0IUD_PRIORITY              _INT_PRIORITY_15
#define INTC_ENCA0_INTENCA0I0_PRIORITY               _INT_PRIORITY_15
#define INTC_ENCA0_INTENCA0I1_PRIORITY               _INT_PRIORITY_15
#define INTC_ENCA0_INTENCA0IEC_PRIORITY              _INT_PRIORITY_15
#define INTC_KR0_INTKR0_PRIORITY                     _INT_PRIORITY_15
#define INTC_PWSA0_INTQFULL_PRIORITY                 _INT_PRIORITY_15
#define INTC_PWGA0_31_INTPWGAG00_PRIORITY            _INT_PRIORITY_15
#define INTC_PWGA32_63_INTPWGAG01_PRIORITY           _INT_PRIORITY_15
#define INTC_FACI_INTFLERR_PRIORITY                  _INT_PRIORITY_15
#define INTC_FACI_INTFLENDNM_PRIORITY                _INT_PRIORITY_15
#define INTC_LPS0_INTCWEND_PRIORITY                  _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN1ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN1REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN1TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_CSIH1_INTCSIH1IC_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH1_INTCSIH1IR_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH1_INTCSIH1IRE_PRIORITY              _INT_PRIORITY_15
#define INTC_CSIH1_INTCSIH1IJC_PRIORITY              _INT_PRIORITY_15
#define INTC_RLIN31_INTRLIN31_PRIORITY               _INT_PRIORITY_15
#define INTC_RLIN31_INTRLIN31UR0_PRIORITY            _INT_PRIORITY_15
#define INTC_RLIN31_INTRLIN31UR1_PRIORITY            _INT_PRIORITY_15
#define INTC_RLIN31_INTRLIN31UR2_PRIORITY            _INT_PRIORITY_15
#define INTC_Port_INTP6_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP7_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP8_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP12_PRIORITY                    _INT_PRIORITY_15
#define INTC_CSIH2_INTCSIH2IC_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH2_INTCSIH2IR_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH2_INTCSIH2IRE_PRIORITY              _INT_PRIORITY_15
#define INTC_CSIH2_INTCSIH2IJC_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I0_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I1_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I2_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I3_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I4_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I5_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I6_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I7_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I8_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I9_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I10_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I11_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I12_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I13_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I14_PRIORITY              _INT_PRIORITY_15
#define INTC_TAUB0_INTTAUB0I15_PRIORITY              _INT_PRIORITY_15
#define INTC_CSIH3_INTCSIH3IC_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH3_INTCSIH3IR_PRIORITY               _INT_PRIORITY_15
#define INTC_CSIH3_INTCSIH3IRE_PRIORITY              _INT_PRIORITY_15
#define INTC_CSIH3_INTCSIH3IJC_PRIORITY              _INT_PRIORITY_15
#define INTC_RLIN240_INTRLIN22_PRIORITY              _INT_PRIORITY_15
#define INTC_RLIN32_INTRLIN32_PRIORITY               _INT_PRIORITY_15
#define INTC_RLIN32_INTRLIN32UR0_PRIORITY            _INT_PRIORITY_15
#define INTC_RLIN32_INTRLIN32UR1_PRIORITY            _INT_PRIORITY_15
#define INTC_RLIN32_INTRLIN32UR2_PRIORITY            _INT_PRIORITY_15
#define INTC_TAUJ1_INTTAUJ1I0_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ1_INTTAUJ1I1_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ1_INTTAUJ1I2_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ1_INTTAUJ1I3_PRIORITY               _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0FDA_PRIORITY              _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0FW_PRIORITY               _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0IQE_PRIORITY              _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0IQF_PRIORITY              _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0OT_PRIORITY               _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0OW_PRIORITY               _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0LINE0_PRIORITY            _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0LINE1_PRIORITY            _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0TIM0_PRIORITY             _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0TIM1_PRIORITY             _INT_PRIORITY_15
#define INTC_FLXA0_INTFLXA0TIM2_PRIORITY             _INT_PRIORITY_15
#define INTC_Port_INTP9_PRIORITY                     _INT_PRIORITY_15
#define INTC_Port_INTP13_PRIORITY                    _INT_PRIORITY_15
#define INTC_RTCA0_INTRTCA01S_PRIORITY               _INT_PRIORITY_15
#define INTC_RTCA0_INTRTCA0AL_PRIORITY               _INT_PRIORITY_15
#define INTC_RTCA0_INTRTCA0R_PRIORITY                _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN2ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN2REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN2TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN3ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN3REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN3TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_RIIC1_INTRIIC1TI_PRIORITY               _INT_PRIORITY_15
#define INTC_RIIC1_INTRIIC1EE_PRIORITY               _INT_PRIORITY_15
#define INTC_RIIC1_INTRIIC1RI_PRIORITY               _INT_PRIORITY_15
#define INTC_RIIC1_INTRIIC1TEI_PRIORITY              _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN4ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN4REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN4TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_TAUJ2_INTTAUJ2I0_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ2_INTTAUJ2I1_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ2_INTTAUJ2I2_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ2_INTTAUJ2I3_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ3_INTTAUJ3I0_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ3_INTTAUJ3I1_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ3_INTTAUJ3I2_PRIORITY               _INT_PRIORITY_15
#define INTC_TAUJ3_INTTAUJ3I3_PRIORITY               _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN5ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN5REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN5TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA16_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA17_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA18_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA19_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA20_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA21_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA22_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC2_INTDMA23_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA24_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA25_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA26_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA27_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA28_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA29_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA30_PRIORITY                 _INT_PRIORITY_15
#define INTC_DMAC3_INTDMA31_PRIORITY                 _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN6ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN6REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN6TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN7ERR_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN7REC_PRIORITY             _INT_PRIORITY_15
#define INTC_RCFDC0_INTRCAN7TRX_PRIORITY             _INT_PRIORITY_15
#define INTC_RSENT1_INTSENT1SI_PRIORITY              _INT_PRIORITY_15
#define INTC_RSENT1_INTSENT1RI_PRIORITY              _INT_PRIORITY_15
#define INTC_LPS0_INTDPE_PRIORITY                    _INT_PRIORITY_15
#define INTC_LPS0_INTAPE_PRIORITY                    _INT_PRIORITY_15
#define INTC_GRZF_INTGRZF_PRIORITY                   _INT_PRIORITY_15

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Interrupt_Create(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

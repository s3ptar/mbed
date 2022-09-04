/***********************************************************************
*! \file:                   main.c
*  \projekt:                BarkControl
*  \created on:             2022 07 25
*  \author:                 R. Gräber
*  \version:                0
*  \history:                -
*  \brief
***********************************************************************/

/***********************************************************************
* Includes
***********************************************************************/
#include <mbed.h>
/***********************************************************************
* Informations
***********************************************************************/
//https://os.mbed.com/platforms/ST-Nucleo-L476RG/
//https://www.allegromicro.com/en/Products/Motor-Drivers/Brush-DC-Motor-Drivers/A4988
/***********************************************************************
* Declarations
***********************************************************************/

DigitalOut myled(LED1);
DigitalOut A4988_Direction(PC_14);
DigitalOut A4988_nSleep(PC_15);
DigitalOut A4988_nReset(PH_0);
DigitalOut A4988_nEnable(PH_1);
PwmOut A4988_Step(PB_7);
BusOut A4988_Microsteps(PA_13, PA_14, PA_15);

/***********************************************************************
* Global Variable
***********************************************************************/
 
/***********************************************************************
* Constant
***********************************************************************/
 
#define LED_BlinkTime 2000

/***********************************************************************
* Local Funtions
***********************************************************************/


/***********************************************************************
*! \fn          int main()
*  \brief       startup function
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
int main() {

    // put your setup code here, to run once:

    //init A4988
    A4988_nSleep = 1;
    A4988_nReset = 0;
    A4988_nEnable = 1;
    A4988_Step.period_ms(250);
    A4988_Step = 0.5;
    A4988_Direction = 1;
    A4988_Microsteps = 0;

    //thread_sleep_for(1000);
    A4988_nReset = 1;
    //thread_sleep_for(1000);
    A4988_nEnable = 0;

    while(1) {
        // put your main code here, to run repeatedly:while(1) {

        myled = !myled;
        //wait_us(1000000);
        thread_sleep_for(LED_BlinkTime);
        //myled = 0;
        //wait_us(1000000);s
    }
}
//**************************************************************************************************
// Name: Gabriel Olszewski, Anthony Mauro, Logeswaran Ganesan, Alexander Castromonte
// Date: 10/2/2023
// Course: ELEC3371-01
// Description: This program has 4 objectives. The objectives are commented and separated.
//              Objective 1 turns on LEDS on PORTD when pressing PA4 and has a counter for number of presses.
//              Objective 2 - Press PA0 and all lights on PORTD turn on, and when released turn off.
//              Objective 3 - State machine with three states that changes every 10 button presses using PA3
//              Objective 4  - PA5 is used to manually switch between lighting states
//**************************************************************************************************

//FOTH BOTH DISPLAY = 0x01000000
//FOR SWITCH  = 0x00010000
//For 0 = 0x00000100
//For 1 = 0x10000100
//For 2 = 0x00100100
//For 3 = 0x10100100
//For 4 = 0x00001100
//For 5 = 0x10001100
//For 6 = 0x00101100
//For 7 = 0x10101100
//For 8 = 0x00000110
//For 9 = 0x10000110

//int num1 = 0xA500;     //Variable for the MET1155 display
int num1 = 0b1010010100000000;     //Variable for the MET1155 display

unsigned long int pa0state = 0;

void main() {

  RCC_APB2ENR |= 1 << 2;  // Enable GPIOA clock - necessary to use GPIOA
  RCC_APB2ENR |= 1 << 6;  // Enable GPIOE clock - necessary to use GPIOE
  RCC_APB2ENR |= 1 << 5;  // Enable GPIOE clock - necessary to use GPIOE

  GPIOE_CRH = 0x33333333; //SETS GPIOE HIGH

  GPIOA_CRL = 0x44444444; //SETS GPIOA LOW as input
  GPIOA_CRH = 0x33333333; //SETS GPIOA HIGH as output


 

 for(;;){
 //****************************************************************************
  //Objective 2
  GPIOE_ODR = num1;
//*****************************************************************************
      
 //****************************************************************************
//Objective 3 (Not Working Yet Probably - Have not tested)
     if(GPIOA_IDR.B0 == 1 & pa0state == 0){      // Wait until PB0 is pressed
                          pa0state = 1;
          }

     if(GPIOA_IDR.B0 == 0 & pa0state == 1){// Falling edge, previously pressed, currently not pressed
                pa0state = 0;
                GPIOE_ODR.B11 = 1;
                }
 //****************************************************************************


 //****************************************************************************
//Objective 4  (Unfinished)
     if(GPIOD_IDR.B0 == 1 & pa0state == 0){      // Wait until PB0 is pressed
                          pa0state = 1;
          }

     if(GPIOD_IDR.B0 == 0 & pa0state == 1){// Falling edge, previously pressed, currently not pressed
                pa0state = 0;
                GPIOE_ODR.B11 = 1;
                }
 //****************************************************************************

    }
}
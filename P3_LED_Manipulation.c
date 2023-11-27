//**************************************************************************************************
// Name: Gabriel Olszewski, Anthony Mauro, Alexander Castromonte
// Date: 10/18/2023
// Course: ELEC3371-01
// Description: This program has 4 (3 are programming) objectives. The objectives are commented and separated.
//              Objective 2 - Create Variable to display a number on the 7segment display.
//              Objective 3 - Using PORTA push button PAO toggle between displays on falling Edge
//              Objective 4  - Using PORTD PUSH button PD0 increment the number displayed RISING EDGE
//                             Using PORTD PUSH BUTTON PD4 decrement the number displayed RISING EDGE
//**************************************************************************************************


unsigned long int displayNumber = 0b1011010000000000;   //Binary code for 9 to be displayed on MET1155 PCB
unsigned long int pa0state = 0;
unsigned long int pd0state = 0;
unsigned long int pd4state = 0;
unsigned char type;




void main(){
    RCC_APB2ENR |= 1 << 2;  // Enable GPIOA clock - necessary to use GPIOA
    RCC_APB2ENR |= 1 << 6;  // Enable GPIOE clock - necessary to use GPIOE
    RCC_APB2ENR |= 1 << 5;  // Enable GPIOE clock - necessary to use GPIOE

    GPIOD_CRL = 0x44444444; //SETS GPIOD LOW AS  INPUT
    GPIOD_CRH = 0x44444444; //SETS GPIOD HIGH AS INPUT
    GPIOA_CRL = 0x44444444; //SETS GPIOA LOW AS  INPUT
    GPIOA_CRH = 0x44444444; //SETS GPIOA HIGH AS INPUT
    GPIOE_CRH = 0x33333333; //SETS GPIOE HIGH AS OUTPUT


    GPIOE_ODR = displayNumber; //Call VARIABLE TO DISPLAY 9 (OBJECTIVE 2)



     for(;;){

     //Objective 3

           if(GPIOA_IDR.B0 == 1 & pa0State == 0){         //When Button Pressed set pa0state to 1
            pa0state = 1;

           }
           if(GPIOA_IDR.B0 == 0 & pa0state == 1){         //When Button Released and pa0state is 1
                           if(GPIOE_ODR.B11 == 0){        //Checks to see if Switch button is enabled
                            GPIOE_ODR.B11 = 1;            //If Not enabled set B11 to 1
                           } else if(GPIOE_ODR.B11 == 1){ //IF Enable set B11 to 0
                             GPIOE_ODR.B11 = 0;
                           }                              //Nested If statements allowed to transition between the displays
                           pa0state = 0;                  //Set pa0state to 0 (Falling Edge)
           }


     //Objective 4
                           if(GPIOD_IDR.B0 ==1 & pd0state == 0){
                          if(GPIOE_ODR.B11 == 0){
                                  if(GPIOE_ODR == 0XE100){                                //If 9 go to 0
                                          pd0state = 1;
                                          GPIOE_ODR = 0XA000;
                                  }  else if(GPIOE_ODR == 0XA000 & pd0state == 0){        //If 0 go to 1
                                              pd0state = 1;
                                              GPIOE_ODR = 0XA100;
                                  }  else if(GPIOE_ODR == 0XA100 & pd0state == 0){        //If 1 go to 2
                                              pd0state = 1;
                                              GPIOE_ODR = 0XA400;
                                  } else if(GPIOE_ODR == 0XA400 & pd0state == 0){         //If 2 go to 3
                                              pd0state = 1;
                                              GPIOE_ODR = 0XA500;
                                  }   else if(GPIOE_ODR == 0XA500 & pd0state == 0){       //If 3 go to 4
                                              pd0state = 1;
                                              GPIOE_ODR = 0XB000;
                                  }   else if(GPIOE_ODR == 0XB000 & pd0state == 0){         //If 4 go to 5
                                              pd0state = 1;
                                              GPIOE_ODR = 0XB100;
                                  }   else if(GPIOE_ODR == 0XB100 & pd0state == 0){         //If 5 go to 6
                                              pd0state = 1;
                                              GPIOE_ODR = 0XB400;
                                  }   else if(GPIOE_ODR == 0XB400 & pd0state == 0){         //If 6 go to 7
                                              pd0state = 1;
                                              GPIOE_ODR = 0XB500;
                                  }   else if(GPIOE_ODR == 0XB500 & pd0state == 0){         //If 7 go to 8
                                                                      pd0state = 1;
                                                                      GPIOE_ODR = 0XE000;
                                  }   else if(GPIOE_ODR == 0XE000 & pd0state == 0){         //If 8 go to 9
                                                  pd0state = 1;
                                                  GPIOE_ODR = 0XE100;
                                  }

                          } else if(GPIOE_ODR.B11 == 1){
                                      if(GPIOE_ODR == 0XE900){                    //If 9 go to 0
                                                              pd0state = 1;
                                                              GPIOE_ODR = 0XA800;
                                                 } else if(GPIOE_ODR == 0XA800 & pd0state == 0){      //If 0 go to 1
                                                                     pd0state = 1;
                                                                     GPIOE_ODR = 0XA900;
                                                 } else if(GPIOE_ODR == 0XA900 & pd0state == 0){      //If 1 go to 2
                                                                     pd0state = 1;
                                                                     GPIOE_ODR = 0XAC00;
                                                 }  else if(GPIOE_ODR == 0XAC00 & pd0state == 0){     //If 2 go to 3
                                                                      pd0state = 1;
                                                                      GPIOE_ODR = 0XAD00;
                                                 }  else if(GPIOE_ODR == 0XAD00 & pd0state == 0){     //If 3 go to 4
                                                                      pd0state = 1;
                                                                      GPIOE_ODR = 0XB800;
                                                 }else if(GPIOE_ODR == 0XB800 & pd0state == 0){       //If 4 go to 5
                                                                      pd0state = 1;
                                                                      GPIOE_ODR = 0XB900;
                                                 }else if(GPIOE_ODR == 0XB900 & pd0state == 0){       //If 5 go to 6
                                                                      pd0state = 1;
                                                                      GPIOE_ODR = 0XBC00;
                                                 }else if(GPIOE_ODR == 0XBC00 & pd0state == 0){       //If 6 go to 7
                                                                      pd0state = 1;
                                                                      GPIOE_ODR = 0XBD00;
                                                 }else if(GPIOE_ODR == 0XBD00 & pd0state == 0){       //If 7 go to 8
                                                                        pd0state = 1;
                                                                        GPIOE_ODR = 0XE800;
                                                 }else if(GPIOE_ODR == 0XE800 & pd0state == 0){       //if 8 go to 9
                                                                        pd0state = 1;
                                                                        GPIOE_ODR = 0XE900;
                                                 } else {
                                                   GPIOE_ODR = 0;
                                                 }
                          }

                      }

              if(GPIOD_IDR.B0 == 0 & pd0state == 1){              //Button Release set pd0state back to 0
                          pd0state = 0;
              }


              if(GPIOD_IDR.B4 ==1 & pd4state == 0){          //Rising Edge Detection Decrement
                           if(GPIOE_ODR.B11 == 0){                                //if the display is on DS2
                           if(GPIOE_ODR == 0XE100) {                               //If 9 go to 8
                                        pd4state = 1;
                                        GPIOE_ODR = 0XE000;
                           } else if(GPIOE_ODR == 0XE000 & pd4state == 0){        //If 8 go to 7
                                               pd4state = 1;
                                               GPIOE_ODR = 0XB500;
                           } else if(GPIOE_ODR == 0XB500 & pd4state == 0){        //If 7 go to 6
                                               pd4state = 1;
                                               GPIOE_ODR = 0XB400;
                           }  else if(GPIOE_ODR == 0XB400 & pd4state == 0){       //If 6 go to 5
                                                pd4state = 1;
                                                GPIOE_ODR = 0XB100;
                           }  else if(GPIOE_ODR == 0XB100 & pd4state == 0){       //If 5 go to 4
                                                pd4state = 1;
                                                GPIOE_ODR = 0XB000;
                           }else if(GPIOE_ODR == 0XB000 & pd4state == 0){         //If 4 go to 3
                                                pd4state = 1;
                                                GPIOE_ODR = 0XA500;
                           }else if(GPIOE_ODR == 0XA500 & pd4state == 0){         //If 3 go to 2
                                                pd4state = 1;
                                                GPIOE_ODR = 0XA400;
                           }else if(GPIOE_ODR == 0XA400 & pd4state == 0){         //If 2 go to 1
                                                pd4state = 1;
                                                GPIOE_ODR = 0XA100;
                           }else if(GPIOE_ODR == 0XA100 & pd4state == 0){         //If 1 go to 0
                                                pd4state = 1;
                                                GPIOE_ODR = 0XA000;
                           }else if(GPIOE_ODR == 0XA000 & pd4state == 0){         //If 0 go to 9
                                                pd4state = 1;
                                                GPIOE_ODR = 0XE100;
                           }

                        } else if(GPIOE_ODR.B11 == 1){                       //IF display is on DS1
                                    if(GPIOE_ODR == 0XE900){                    //If 9 go to 8
                                        pd4state = 1;
                                        GPIOE_ODR = 0XE800;
                           } else if(GPIOE_ODR == 0XE800 & pd4state == 0){      //If 8 go to 7
                                               pd4state = 1;
                                               GPIOE_ODR = 0XBD00;
                           } else if(GPIOE_ODR == 0XBD00 & pd4state == 0){      //If 7 go to 6
                                               pd4state = 1;
                                               GPIOE_ODR = 0XBC00;
                           }  else if(GPIOE_ODR == 0XBC00 & pd4state == 0){     //If 6 go to  5
                                                pd4state = 1;
                                                GPIOE_ODR = 0XB900;
                           }  else if(GPIOE_ODR == 0XB900 & pd4state == 0){     //If 5 go to 4
                                                pd4state = 1;
                                                GPIOE_ODR = 0XB800;
                           }else if(GPIOE_ODR == 0XB800 & pd4state == 0){       //If 4 go to 3
                                                pd4state = 1;
                                                GPIOE_ODR = 0XAD00;
                           }else if(GPIOE_ODR == 0XAD00 & pd4state == 0){       //If 3 go to 2
                                                pd4state = 1;
                                                GPIOE_ODR = 0XAC00;
                           }else if(GPIOE_ODR == 0XAC00 & pd4state == 0){       //If 2 go to 1
                                                pd4state = 1;
                                                GPIOE_ODR = 0XA900;
                           }else if(GPIOE_ODR == 0XA900 & pd4state == 0){       //If 1 go to 0
                                                  pd4state = 1;
                                                  GPIOE_ODR = 0XA800;
                           }else if(GPIOE_ODR == 0XA800 & pd4state == 0){       //if 0 go to 9
                                                  pd4state = 1;
                                                  GPIOE_ODR = 0XE900;
                           }

                        }
                    }


                            if(GPIOD_IDR.B4 == 0 & pd4state == 1){              //Button Release set pd4state back to 0
                          pd4state = 0;
              }







         }





   }

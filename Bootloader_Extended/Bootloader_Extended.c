#include "Bootloader_Extended.h"

uint32_t BC_Register; 
uint32_t BS_Register;

void Vector_Init_Setting(uint32_t addr)                                         //The interrupt vector transfer
{                                                                              
    __disable_irq(); 
  SCB->VTOR = addr;
    __DSB();
    __enable_irq(); 
    __ISB();
}

void Boot_Main_Program(void)
{
 typedef void (*pFunction)(void);                                               //The declaration of a pointer to the jump address
                pFunction Main_Program_Jump;

  __disable_irq();                                                              //interrupt disable 
 
  HAL_SuspendTick();                                                            //SysTick shutdown
  HAL_DeInit();                                                                 //Periphery DeInit
  HAL_RCC_DeInit();                                                             //Clock DeInit
  Main_Program_Jump = (pFunction) (*(uint32_t*) (MAIN_PROGRAM_START_ADDR + 4)); //pointer to jump to Reset_Handler

  __set_MSP(*(volatile uint32_t*) MAIN_PROGRAM_START_ADDR);                     //Init Main_Program stack 
  __DSB();
  Main_Program_Jump();                                                          //JUMP
}

void Boot_Bootloader(void)
{
 typedef void (*pFunction)(void);                                                       //The declaration of a pointer to the jump address
                pFunction Bootloader_Jump;                                              
                                                                                        
  __disable_irq();                                                                      //interrupt disable
                                                                                        
  HAL_SuspendTick();                                                                    //SysTick shutdown
  HAL_DeInit();                                                                         //Periphery DeInit
  HAL_RCC_DeInit();                                                                     //Clock DeInit
  Bootloader_Jump = (pFunction) (*(uint32_t*) (BOOTLOADER_EXTENDED_START_ADDR + 4));    //pointer to jump to Reset_Handler
                                                                                        
  __set_MSP(*(volatile uint32_t*) BOOTLOADER_EXTENDED_START_ADDR);                      //Init Bootloader stack 
  __DSB();                                                                              
  Bootloader_Jump();                                                                    //JUMP
}  
  
void Erase_Main_Program(void)
{

}

void Write_Main_Program(void)
{

}

void Validate_Received_Program(void)
{

}
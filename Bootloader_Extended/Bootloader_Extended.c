#include "Bootloader_Extended.h"

uint32_t BC_Register; 
uint32_t BS_Register;

void Vector_Init_Setting(uint32_t addr)                                         //перенос вектора прерываний
{                                                                              
    __disable_irq(); 
  SCB->VTOR = addr;
    __DSB();
    __enable_irq(); 
    __ISB();
}

void Boot_Main_Program(void)
{
 typedef void (*pFunction)(void);                                               //Объявление указателя на адрес прыжка
                pFunction Main_Program_Jump;

  __disable_irq();                                                              //Выключение прерывания
 
  HAL_SuspendTick();                                                            //Выключение SysTick таймер
  HAL_DeInit();                                                                 //Деинициализация периферии
  HAL_RCC_DeInit();                                                             //Деинициализация тактирования
  Main_Program_Jump = (pFunction) (*(uint32_t*) (MAIN_PROGRAM_START_ADDR + 4)); //указатель на прыжок в Reset_Handler

  __set_MSP(*(volatile uint32_t*) MAIN_PROGRAM_START_ADDR);                     //Инициализация Main_Program стека 
  __DSB();
  Main_Program_Jump();                                                          //Прыжок
}

void Boot_Bootloader(void)
{
 typedef void (*pFunction)(void);                                                       //Объявление указателя на адрес прыжка
                pFunction Bootloader_Jump; 

  __disable_irq();                                                                      //Выключение прерывания
  
  HAL_SuspendTick();                                                                    //Выключение SysTick таймер
  HAL_DeInit();                                                                         //Деинициализация периферии
  HAL_RCC_DeInit();                                                                     //Деинициализация тактирования
  Bootloader_Jump = (pFunction) (*(uint32_t*) (BOOTLOADER_EXTENDED_START_ADDR + 4));    //указатель на прыжок в Reset_Handler

  __set_MSP(*(volatile uint32_t*) BOOTLOADER_EXTENDED_START_ADDR);                      //Инициализация Bootloader стека 
  __DSB();
  Bootloader_Jump();                                                                    //Прыжок
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
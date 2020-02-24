#include "Bootloader_Extended.h"

uint32_t BC_Register; 
uint32_t BS_Register;

void Vector_Init_Setting(uint32_t addr)                                         //������� ������� ����������
{                                                                              
    __disable_irq(); 
  SCB->VTOR = addr;
    __DSB();
    __enable_irq(); 
    __ISB();
}

void Boot_Main_Program(void)
{
 typedef void (*pFunction)(void);                                               //���������� ��������� �� ����� ������
                pFunction Main_Program_Jump;

  __disable_irq();                                                              //���������� ����������
 
  HAL_SuspendTick();                                                            //���������� SysTick ������
  HAL_DeInit();                                                                 //��������������� ���������
  HAL_RCC_DeInit();                                                             //��������������� ������������
  Main_Program_Jump = (pFunction) (*(uint32_t*) (MAIN_PROGRAM_START_ADDR + 4)); //��������� �� ������ � Reset_Handler

  __set_MSP(*(volatile uint32_t*) MAIN_PROGRAM_START_ADDR);                     //������������� Main_Program ����� 
  __DSB();
  Main_Program_Jump();                                                          //������
}

void Boot_Bootloader(void)
{
 typedef void (*pFunction)(void);                                                       //���������� ��������� �� ����� ������
                pFunction Bootloader_Jump; 

  __disable_irq();                                                                      //���������� ����������
  
  HAL_SuspendTick();                                                                    //���������� SysTick ������
  HAL_DeInit();                                                                         //��������������� ���������
  HAL_RCC_DeInit();                                                                     //��������������� ������������
  Bootloader_Jump = (pFunction) (*(uint32_t*) (BOOTLOADER_EXTENDED_START_ADDR + 4));    //��������� �� ������ � Reset_Handler

  __set_MSP(*(volatile uint32_t*) BOOTLOADER_EXTENDED_START_ADDR);                      //������������� Bootloader ����� 
  __DSB();
  Bootloader_Jump();                                                                    //������
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
#ifndef __Bootloader_Extended
#define __Bootloader_Extended

#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

#define MEMORY_PAGE_SIZE 1024

#define BOOTLOADER_EXTENDED_START_ADDR 0x08000000
#define MAIN_PROGRAM_START_ADDR        0x08010000
#define MAIN_PROGRAM_END_ADDR          0x0801FFFF

extern uint32_t BC_Register; 
//Bootloader Control Register;
/*
bit 00 - reserved
bit 01 - reserved
bit 02 - reserved
bit 03 - reserved
bit 04 - reserved
bit 05 - reserved
bit 06 - reserved
bit 07 - reserved
bit 08 - reserved
bit 09 - reserved
bit 10 - reserved
bit 11 - reserved
bit 12 - reserved
bit 13 - reserved
bit 14 - reserved
bit 15 - reserved
bit 16 - reserved
bit 17 - reserved
bit 18 - reserved
bit 19 - reserved
bit 20 - reserved
bit 21 - reserved
bit 22 - reserved
bit 23 - reserved
bit 24 - reserved
bit 25 - reserved
bit 26 - reserved
bit 27 - reserved
bit 28 - reserved
bit 29 - reserved
bit 30 - reserved
bit 31 - reserved
*/
extern uint32_t BS_Register; 
//Bootloader Status Register;
/*
bit 00 - reserved
bit 01 - reserved
bit 02 - reserved
bit 03 - reserved
bit 04 - reserved
bit 05 - reserved
bit 06 - reserved
bit 07 - reserved
bit 08 - reserved
bit 09 - reserved
bit 10 - reserved
bit 11 - reserved
bit 12 - reserved
bit 13 - reserved
bit 14 - reserved
bit 15 - reserved
bit 16 - reserved
bit 17 - reserved
bit 18 - reserved
bit 19 - reserved
bit 20 - reserved
bit 21 - reserved
bit 22 - reserved
bit 23 - reserved
bit 24 - reserved
bit 25 - reserved
bit 26 - reserved
bit 27 - reserved
bit 28 - reserved
bit 29 - reserved
bit 30 - reserved
bit 31 - reserved
*/

/*Перенос вектора прерываний*/
extern void Vector_Init_Setting(uint32_t addr);
/*
Примечание:
Если не перенести вектор прерываний, 
то при их использовании программа откажет.
Вызывать в самом начале main();
*/
/*Переход в программу*/
extern void Boot_Main_Program(void);
/*Переход в загрузчик*/
extern void Boot_Bootloader(void);
/*Стирание программы*/
extern void Erase_Main_Program(void);
/*Запись программы*/
extern void Write_Main_Program(void);
/*Валидатор программы перед записью*/
extern void Validate_Received_Program(void);



#endif /*__Bootloader_Extended*/
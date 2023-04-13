#include <avr/io.h>

#ifndef DISPLAY_H
#define DISPLAY_H
#define CMD                 0
#define DATA                1
#define BIT_H               0
#define BIT_V               1
#define BIT_P               2
#define BIT_E               0
#define BIT_D               2
#define BIT_TC0             0
#define BIT_TC1             1
#define BIT_V_OP0           0
#define BIT_V_OP1           1
#define BIT_V_OP2           2
#define BIT_V_OP3           3
#define BIT_V_OP4           4
#define BIT_V_OP5           5
#define BIT_V_OP6           6
#define FUNC_SET            0b00100000
#define DISP_CONTR          0b00001000
#define SET_Y_ADDR          0b01000000
#define SET_X_ADDR          0b10000000
#define SET_TEMP_CONTROL    0b00000100
#define SET_V_OP            0b10000000

#define LCD_X_RES                  84
#define LCD_Y_RES                  48
#define LCD_CACHE_SIZE             ((LCD_X_RES * LCD_Y_RES) / 8)


/* Function prototypes */
void LCD_Init(void);
void LCD_Clear(void);
void LCD_Send(uint8_t dc, uint8_t data);
void Delay(uint16_t delay);

#endif
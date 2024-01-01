#include <avr/io.h>
#include "display.h"
#include "main.h"
#include "ports.h"
#include "picture.h"

int main(void) 
{
  Ports_Init();
  PORTD &=~((1<<DSPL_RST));
  Delay(300);
  PORTD |=((1<<DSPL_RST));
  LCD_Init();
  Delay(300);
  LCD_Clear();
  Delay(2000);
  
  // LCD_Send(CMD, (DISP_CONTR|(1<<BIT_E)));
  // LCD_Send(CMD, (DISP_CONTR));
  int8_t k = 0;
  int8_t row = 1;
  int8_t column = 15;
  LCD_Send(CMD,SET_X_ADDR+column);
  LCD_Send(CMD,SET_Y_ADDR);
  
  for (int16_t i = 0; i < sizeof(picture1); i++)
  {
    LCD_Send(DATA,picture1[i]);
    k++;
    if (k == 60)
    {
    LCD_Send(CMD,SET_X_ADDR+column);
    LCD_Send(CMD,SET_Y_ADDR+row);
    k = 0x0;
    row++;
    }
  }
  
  while (1)
  {
    /* code */
  }
  
  return 0;
}


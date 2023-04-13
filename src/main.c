#include <avr/io.h>
#include "display.h"
#include "main.h"
#include "ports.h"
#include "picture.h"

void main(void) 
{
  Ports_Init();
  PORTD &=~((1<<DSPL_RST));
  Delay(300);
  PORTD |=((1<<DSPL_RST));
  LCD_Init();
  // LCD_Clear();
  // LCD_Send(CMD, (DISP_CONTR|(1<<BIT_E)));
  // LCD_Send(CMD, (DISP_CONTR));
  for (int8_t i = 0; i < sizeof(picture); i++)
  {
    LCD_Send(DATA,picture[i]);
  }
  
  while (1)
  {
    /* code */
  }
  
  return 0;
}


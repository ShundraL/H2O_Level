#include <avr/io.h>
#include <avr/pgmspace.h>
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
  Delay(300);
  LCD_Init();
  Delay(300);
  LCD_Clear();
  
  Delay(1000);
  
  // LCD_Send(CMD, (DISP_CONTR|(1<<BIT_E)));
  // LCD_Send(CMD, (DISP_CONTR));
 
  LCD_Send(CMD,SET_X_ADDR);
  LCD_Send(CMD,SET_Y_ADDR);
  Send_string((char *)hello);
  Delay(5000);
  LCD_Clear();

  LCD_Show_Img((uint8_t const *)picture1, (int16_t)sizeof(picture1), picture1_width, 1, 13);         
  LCD_Send(CMD, 0x0C );  // LCD in normal mode.



  
  while (1)
  {
    /* code */
  }
  
  return 0;
}


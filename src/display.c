#include <avr/io.h>
#include "main.h"
#include "ports.h"
#include "display.h"

void LCD_Init(void)
{
   LCD_Send(CMD, 0x21 );  // LCD Extended Commands.
   LCD_Send(CMD, 0xBA );  // Set LCD Vop (Contrast).
   LCD_Send(CMD, 0x04 );  // Set Temp coefficent. //0x04
   LCD_Send(CMD, 0x14 );  // LCD bias mode 1:48. //0x13
   LCD_Send(CMD, 0x20 );  // LCD Basic Commands
   LCD_Send(CMD, 0x0C );  // LCD in normal mode.
};

void LCD_Send(uint8_t dc, uint8_t data)
{
     uint8_t i;
   if (dc == DATA)
      PORTD |= (1<<DSPL_DC);
   else
      PORTD &= ~(1<<DSPL_DC);

   PORTB &=~(1<<DSPL_CLK);
   PORTD &=~(1<<DSPL_CE);
   for (i=0; i<8; i++)
   {
      PORTB =(data & 0x80) ? PORTB | (1<<DSPL_DATA) : PORTB & ~(1<<DSPL_DATA);

      data=(data<<1);

      PORTB |=(1<<DSPL_CLK);
      PORTB &=~(1<<DSPL_CLK);
   };

   PORTD |=(1<<DSPL_CE);
}

uint16_t CMDodes[][4][7] = 
{

};

void Delay(uint16_t delay)
{
  for (uint16_t i = delay; i >0 ; i--)
  {
   //  for (uint8_t k = 255; k >0 ; k--)
   //  {
          
   //  }
  }
};

void LCD_Clear(void)
{
   for (uint8_t i = 0; i < 504; i++)
   {
      LCD_Send(DATA,0x0);
   }
   
}
;

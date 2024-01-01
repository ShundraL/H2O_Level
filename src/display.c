#include <avr/io.h>
#include <avr/pgmspace.h>
#include "main.h"
#include "ports.h"
#include "display.h"
#include "picture.h"

void LCD_Init(void)
{
   LCD_Send(CMD, 0x21 );  // LCD Extended Commands.
   LCD_Send(CMD, 0xBA );  // Set LCD Vop (Contrast).
   LCD_Send(CMD, 0x04 );  // Set Temp coefficent. //0x04
   LCD_Send(CMD, 0x14 );  // LCD bias mode 1:48. //0x13
   LCD_Send(CMD, 0x20 );  // LCD Basic Commands
   LCD_Send(CMD, 0x0C );  // LCD in normal mode.
};

void LCD_Show_Img(const uint8_t *img_ptr, int16_t img_size, uint8_t picture_width, int8_t row, int8_t column)
{
   uint8_t img_data;
   int8_t img_current_column = 0;

   LCD_Send(CMD,SET_X_ADDR+column);
   LCD_Send(CMD,SET_Y_ADDR);

  for (int16_t i = 0; i < img_size; i++)
  {
      img_data = pgm_read_byte((uint8_t *)img_ptr);
      PORTD |= (1<<DSPL_DC);

      PORTB &=~(1<<DSPL_CLK);
      PORTD &=~(1<<DSPL_CE);
      for (int8_t i=0; i<8; i++)
      {
         if (img_data & 0x80)
            PORTB |=(1<<DSPL_DATA);
         else
            PORTB &=~(1<<DSPL_DATA);

         img_data=(img_data<<1);

         PORTB |=(1<<DSPL_CLK);
         PORTB &=~(1<<DSPL_CLK);
      };

      PORTD |=(1<<DSPL_CE);

      img_current_column++;
      img_ptr++;
      if (img_current_column == picture_width)
      {
         LCD_Send(CMD,SET_X_ADDR+column);
         LCD_Send(CMD,SET_Y_ADDR+row);
         img_current_column = 0x0;
         row++;
      }
   };
};

void LCD_Send(int8_t dc, uint8_t data)
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
      // PORTB =(data & 0x80) ? PORTB | (1<<DSPL_DATA) : PORTB & ~(1<<DSPL_DATA);
      if (data & 0x80)
         PORTB |=(1<<DSPL_DATA);
      else
         PORTB &=~(1<<DSPL_DATA);

      data=(data<<1);

      PORTB |=(1<<DSPL_CLK);
      PORTB &=~(1<<DSPL_CLK);
   };

   PORTD |=(1<<DSPL_CE);
};

void Delay(int16_t delay)
{
//   for (int16_t i = delay; i >0 ; i--)
   while(delay)
  {
    for (uint8_t k = 255; k >0 ; k--)
    {
      asm volatile("nop\n\t");          
    }
   // asm volatile("nop\n\t");
   delay--;
  }
};

void LCD_Clear(void)
{
   LCD_Send(CMD,SET_X_ADDR+0);
   LCD_Send(CMD,SET_Y_ADDR+0);

   for (int16_t i = 0; i < LCD_CACHE_SIZE; i++)
   {
      LCD_Send(DATA,0x00);
   }
};

void Send_string(char* pointer)
{
   uint8_t temp;
   uint8_t letter_code;
   while( (temp = pgm_read_byte(pointer)) != '\0')
   {
      letter_code = temp-0x20;
      for (int8_t i = 0; i < 5; i++)
      {
         LCD_Send(DATA,pgm_read_byte(&(FontLookup[letter_code][i])));
      }
      pointer++;         
   }
}
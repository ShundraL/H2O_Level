#include <avr/io.h>
#include "main.h"
#include "display.h"
#include "ports.h"

void Ports_Init(void)
{
    DDRB  = ((1<<DSPL_DATA)|(1<<DSPL_CLK)|(1<<RF_CE)|(1<<RF_MO)|(1<<RF_SCK)); 
    PORTB = ((1<<DSPL_DATA)|(1<<DSPL_CLK)|(1<<RF_CE)|(1<<RF_MO)|(1<<RF_MI)|(1<<RF_SCK)); 

    DDRD  = ((1<<DSPL_RST)|(1<<DSPL_CE)|(1<<DSPL_DC));
    PORTD = ((1<<DSPL_RST)|(1<<DSPL_CE)|(1<<DSPL_DC)|(1<<RF_INT));

    DDRC  = ((1<<DSPL_BACK_LIGHT)|(1<<TEMP_IO)|(1<<PR_SCK));
    PORTC = ((1<<DSPL_BACK_LIGHT)|(1<<TEMP_IO)|(1<<PR_SCK)|(1<<PR_DATA));
}

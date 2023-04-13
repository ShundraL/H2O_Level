#include <avr/io.h>

#ifndef PORTS_H
#define PORTS_H

/* Function prototypes */
void Ports_Init(void);

/* Registers definitions */

/* Port B */
#define DSPL_DATA   0
#define DSPL_CLK    1
#define RF_CE       2
#define RF_MO       3
#define RF_MI       4
#define RF_SCK      5

/* Port D */
#define DSPL_RST    5
#define DSPL_CE     6
#define DSPL_DC     7
#define RF_INT      2

/* Port C */
#define DSPL_BACK_LIGHT     0
#define TEMP_IO     2
#define PR_SCK      3
#define PR_DATA     5

#endif
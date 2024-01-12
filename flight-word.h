/**************************************************************
 *
 *                     flight-word.h
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#ifndef __FLIGHT_WORD__H
#define __FLIGHT_WORD__H

#include <stdlib.h>
#include <assert.h>

/* expanded uint128_t */
typedef struct Flight_Word
{
    
} *Flight_Word;

Flight_Word Flight_Word_new(unsigned no_flights);
void Flight_Word_free(Flight_Word *word);

#endif

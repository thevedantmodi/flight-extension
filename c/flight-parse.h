/**************************************************************
 *
 *                     flight-parse.h
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#ifndef __FLIGHT_PARSE__H
#define __FLIGHT_PARSE__H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "flight-word.h"


Flight_Word parse_all_flights(FILE *input, unsigned no_flights);

#endif

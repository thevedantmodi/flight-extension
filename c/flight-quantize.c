/**************************************************************
 *
 *                     flight-quantize.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include "flight-quantize.h"

/*
    No. of bits
    3 (always for no. flights)

    For each flight (128 bits)
    10
    14
    15
    15

    7
    5
    4
    5
    6
    10

    7
    5
    4
    5
    6
    10


 */

/*  file format
    magic number of #flights (plaintext)
    128 bits of flight
    128 bits of flight
    .
    .
    .

 */

unsigned char_to_digit(char input) {
    return input - 65;
}

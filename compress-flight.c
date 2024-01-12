/**************************************************************
 *
 *                     compress-itin.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include "compress-flight.h"
#include "bitpack.h"
// #include "flight-word.h"
#include <assert.h>

#define MIN_NUM_FLIGHTS 0
#define MAX_NUM_FLIGHTS 255


void compress_flight(FILE *input)
{
    assert(input != NULL);
    unsigned num_flights;
    /* Read in number of flights in file */
    fscanf(input, "%u", &num_flights);
    assert(num_flights >= MIN_NUM_FLIGHTS);
    assert(num_flights <= MAX_NUM_FLIGHTS);

    /* alloc 128 bytes * number of flights */
    


    /* TODO:
        To proceed need
        An unboxed array to store the words of each flight
        A type that can hold 128 bytes
     */

    printf("Size of uint128_t is %lu", sizeof(__uint128_t));


    putchar(num_flights); /* Output the number of flights */

    /* Free number of flights array */
}

void decompress_flight(FILE *input)
{
    char num_flights;
    fscanf(input, "%c", &num_flights);
    printf("There are %d flights", num_flights);
    
    (void)input;
}

#undef MIN_NUM_FLIGHTS
#undef MAX_NUM_FLIGHTS

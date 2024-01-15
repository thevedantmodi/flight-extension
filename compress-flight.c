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
#include <assert.h>
#include "flight-pack.h"

#define MIN_NUM_FLIGHTS 0
#define MAX_NUM_FLIGHTS 255

static Flight_T *Flights_new(unsigned size) {
    Flight_T *words = malloc(size * sizeof(Flight_T));
    assert(words != NULL);
    return words;
}

static void Flights_free(Flight_T **list) {
    assert(*list != NULL);
    free(*list);
}


void compress_flight(FILE *input)
{
    assert(input != NULL);
    unsigned num_flights;
    /* Read in number of flights in file */
    fscanf(input, "%u", &num_flights);
    assert(num_flights >= MIN_NUM_FLIGHTS);
    assert(num_flights <= MAX_NUM_FLIGHTS);

    /* alloc 128 bytes * number of flights */
    Flight_T *words = Flights_new(num_flights);



    putchar(num_flights); /* Output the number of flights */

    /* Free number of flights array */
    Flights_free(&words);

}

void decompress_flight(FILE *input)
{
    char num_flights;
    num_flights = fgetc(input);
    printf("There are %d flights", num_flights);

    Flight_T *words = Flights_new(num_flights);




    Flights_free(&words);

    
    (void)input;
}

#undef MIN_NUM_FLIGHTS
#undef MAX_NUM_FLIGHTS

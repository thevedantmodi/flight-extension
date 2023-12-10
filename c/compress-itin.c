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

#include "compress-itin.h"
#include "flight.h"
#include "flight-parse.h"
#include "flight-word.h"
#include "flight-quantize.h"
#include "flight-pack.h"
#include <assert.h>

#define MIN_NUM_FLIGHTS 0
#define MAX_NUM_FLIGHTS 7

// static void flights_range(unsigned num_flights)
// {
//     if (!(num_flights >= MIN_NUM_FLIGHTS && num_flights <= MAX_NUM_FLIGHTS))
//     {
//         perror("Number of flights is not in range [0,7]");
//         exit(EXIT_FAILURE);
//     }
// }

void compress_itin(FILE *input)
{
    assert(input != NULL);
    unsigned num_flights;
    printf("Number of flights:\n");
    fscanf(input, "%u", &num_flights);
    // flights_range(num_flights); /* Make sure no. flights is in range */
    Flight_Word raw_data = parse_all_flights(input, num_flights);
    
    __uint128_t *packed_words = pack_data(raw_data);

    free(packed_words);
    

    Flight_Word_free(&raw_data);
}

void decompress_itin(FILE *input)
{
    (void)input;
}

#undef MIN_NUM_FLIGHTS
#undef MAX_NUM_FLIGHTS

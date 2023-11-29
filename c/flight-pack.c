/**************************************************************
 *
 *                     flight-pack.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "bitpack.h"
#include "flight-pack.h"
#include "flight-quantize.h"

#define LETTER_W 5
#define FNO_W 14
#define YR_W 7
#define DA_W 5
#define MO_W 4
#define MI_W 6
#define UTC_W 10

#define CAR0_L 123
#define CAR1_L 118

#define FNO_L 104

#define DEPT0_L 99
#define DEPT1_L 94
#define DEPT2_L 89

#define ARR0_L 84
#define ARR1_L 79
#define ARR2_L 74

#define DE_YR_L 67
#define DE_DA_L 62
#define DE_MO_L 58
#define DE_MI_L 52
#define DE_UTC_L 42

#define AR_YR_L 






static __uint128_t quantize_flight(Flight_Data info)
{
    assert(info != NULL);
    __uint128_t flight_packed = 0;
    

    return flight_packed;
}

__uint128_t *pack_data(Flight_Word data)
{
    assert(data != NULL);
    fprintf(stderr, "uint128_t sizeof \t %lu \n", sizeof(__uint128_t));
    unsigned no_flights = data->no_flights;
    __uint128_t *packed_words = malloc(sizeof(__uint128_t) * no_flights);
    assert(packed_words != NULL);
    for (unsigned fl = 0; fl < no_flights; fl++)
    {
        packed_words[fl] = quantize_flight(data->flights[fl]);
    }

    return packed_words;
}

/**************************************************************
 *
 *                     flight-word.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include "flight-word.h"
#include <stdio.h>

static void init_flights(Flight_Word new_word, unsigned no_flights)
{
    assert(new_word != NULL);
    new_word->flights = malloc(sizeof(struct Flight_Data) * no_flights);
    assert(new_word->flights != NULL);

    for (unsigned i = 0; i < no_flights; i++)
    {
        new_word->flights[i] = Flight_Data_new();
    }
}

Flight_Word Flight_Word_new(unsigned no_flights)
{
    Flight_Word new_word = malloc(sizeof(struct Flight_Word)); /* TODO Replace with Hanson NEW */
    assert(new_word != NULL);

    new_word->no_flights = no_flights;

    init_flights(new_word, no_flights);
    assert(new_word->flights != NULL);

    return new_word;
}
void Flight_Word_free(Flight_Word *word)
{
    // for (unsigned i = 0; i < (*word)->no_flights; i++) {
    //     Flight_Data_free(&((*word)->flights[i]));
    // }
    free(*word);
    (void)word;
}

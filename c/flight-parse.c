/**************************************************************
 *
 *                     flight-parse.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include "flight-parse.h"
#define BASE_YEAR 1970

static void parse_flight(FILE *input, Flight_Word data, unsigned idx)
{
    assert(input != NULL);
    assert(data != NULL);
    assert(data->flights != NULL);

    Flight_Data curr_flight = data->flights[idx];

    printf("Carrier of %d-th flight:\n", idx);
    fscanf(input, "\n%c%c", &curr_flight->carrier[0], &curr_flight->carrier[1]);
    /* TODO: Type check and make sure two uppercase chars */

    printf("Flight no. of %d-th flight:\n", idx);
    fscanf(input, "%u", &curr_flight->flight_no);

    printf("Dept of %d-th flight:\n", idx);
    fscanf(input, "\n%c%c%c",
           &curr_flight->dept_code[0],
           &curr_flight->dept_code[1],
           &curr_flight->dept_code[2]);

    printf("Arr of %d-th flight:\n", idx);
    fscanf(input, "\n%c%c%c",
           &curr_flight->arr_code[0],
           &curr_flight->arr_code[1],
           &curr_flight->arr_code[2]);

    printf("ISO datetime of dept of %d-th flight:\n", idx);
    fscanf(input, "\n%u-%u-%uT%u:%u",
           &curr_flight->dept_date->years_past_base,
           &curr_flight->dept_date->month,
           &curr_flight->dept_date->date,
           &curr_flight->dept_date->hour,
           &curr_flight->dept_date->min);

    curr_flight->dept_date->years_past_base -= BASE_YEAR;

    printf("ISO datetime of arr of %d-th flight:\n", idx);
    fscanf(input, "\n%u-%u-%uT%u:%u",
           &curr_flight->arr_date->years_past_base,
           &curr_flight->arr_date->month,
           &curr_flight->arr_date->date,
           &curr_flight->arr_date->hour,
           &curr_flight->arr_date->min);

    curr_flight->arr_date->years_past_base -= BASE_YEAR;

    /*  TODO
        Create a Hanson table mapping IATA_code->IANA_tz
        Create an array mapping IANA_tz->idx in [0, 596]

        Take the IATA of each dest and find IANA_tz, then map to idx and store
     */
}

static void print_all_flights(Flight_Word data)
{
    assert(data != NULL);
    for (unsigned i = 0; i < data->no_flights; i++)
    {
        fprintf(stderr, "%c%c%d\t%c%c%c-%c%c%c\n",
                data->flights[i]->carrier[0],
                data->flights[i]->carrier[1],
                data->flights[i]->flight_no,
                data->flights[i]->dept_code[0],
                data->flights[i]->dept_code[1],
                data->flights[i]->dept_code[2],
                data->flights[i]->arr_code[0],
                data->flights[i]->arr_code[1],
                data->flights[i]->arr_code[2]);
        Datetime_Data_toISODate(data->flights[i]->dept_date);
        Datetime_Data_toISODate(data->flights[i]->arr_date);
        fprintf(stderr, "=====================\n");
    }
}

Flight_Word parse_all_flights(FILE *input, unsigned no_flights)
{
    assert(input != NULL);

    Flight_Word data = Flight_Word_new(no_flights);
    unsigned i;
    for (i = 0; i < no_flights; i++)
    {
        parse_flight(input, data, i);
    }

    print_all_flights(data);

    return data;
}

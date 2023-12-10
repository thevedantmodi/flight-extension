/**************************************************************
 *
 *                     flight.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include "flight.h"
#include <assert.h>
#include <stdlib.h>

#define LEN_IATA_CODE 3

Flight_Data Flight_Data_new(void)
{
    Flight_Data new_data = malloc(sizeof(struct Flight_Data));
    assert(new_data != NULL);

    new_data->flight_no = 0;
    for (int i = 0; i < LEN_IATA_CODE; i++)
    {
        new_data->dept_code[i] = '\0';
        new_data->arr_code[i] = '\0';
    }

    new_data->dept_date = Datetime_Data_new();
    new_data->arr_date = Datetime_Data_new();

    return new_data;
}

void Flight_Data_free(Flight_Data *data_obj)
{
    assert(data_obj != NULL);
    free(*data_obj);
    Datetime_Data_free(&((*data_obj)->dept_date));
    Datetime_Data_free(&((*data_obj)->arr_date));
}

#undef LEN_IATA_CODE

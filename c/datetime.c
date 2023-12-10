/**************************************************************
 *
 *                     datetime.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include "datetime.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define BASE_YEAR 1970

Datetime_Data Datetime_Data_new(void)
{
    Datetime_Data new_date = malloc(sizeof(struct Datetime_Data));
    assert(new_date != NULL);

    new_date->years_past_base = 0;
    new_date->date = 0;
    new_date->month = 0;
    new_date->hour = 0;
    new_date->min = 0;
    new_date->UTC_offset = 0;

    return new_date;
}

void Datetime_Data_free(Datetime_Data *obj)
{
    assert(obj != NULL);
    free(*obj);
}

void Datetime_Data_toISODate(Datetime_Data date)
{
    assert(date != NULL);
    fprintf(stderr, "%u-%u-%uT%u:%u\n",
            BASE_YEAR + date->years_past_base, date->month, date->date, date->hour,
            date->min);
}

#undef BASE_YEAR

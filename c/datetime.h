/**************************************************************
 *
 *                     datetime.h
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#ifndef __DATETIME_H__
#define __DATETIME_H__

#include "datetime.h"

typedef struct Datetime_Data
{
    unsigned years_past_base;
    unsigned date;
    unsigned month;
    unsigned hour;
    unsigned min;
    unsigned UTC_offset;
} *Datetime_Data;

Datetime_Data Datetime_Data_new(void);
void Datetime_Data_free(Datetime_Data *obj);
void Datetime_Data_toISODate(Datetime_Data date);

#endif

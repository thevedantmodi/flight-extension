/**************************************************************
 *
 *                     flight.h
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include "datetime.h"

typedef struct Flight_Data
{
    char carrier[2];
    unsigned flight_no;
    char dept_code[3];
    char arr_code[3];
    Datetime_Data dept_date;
    Datetime_Data arr_date;

} *Flight_Data;

Flight_Data Flight_Data_new(void);
void Flight_Data_free(Flight_Data *data_obj);

#endif

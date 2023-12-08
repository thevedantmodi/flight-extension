##############################################################
#
#                     itinerary.py
#
#
#     Authored by Vedant Modi (vedantmodi.com)
#     07 Dec 2023
#
#
#     TODO Purpose
#
##############################################################

import datetime as dt

class Itinerary:

    carrier = ""
    flight_no = -1
    dept_code = ""
    dept_date = dt.datetime() # UTC time, store offset separately

    arr_code = ""
    arr_date = dt.datetime() # UTC time, store offset separately



    def __init__(self) -> None:
        
        pass
    pass
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

from datetime import datetime
from offsetizer import Offsetizer

class Itinerary:

    CARRIER_LENGTH = 2
    MIN_FLIGHT_NO = 0
    MAX_FLIGHT_NO = 9999
    CODE_LENGTH = 3
    
    MIN_YEAR = 1970
    MAX_YEAR = 2097
    
    MIN_MONTH = 1
    MAX_MONTH = 12
    
    MIN_DAY = 0
    MAX_DAY = 32
    
    MIN_HOUR = 0
    MAX_HOUR = 23
    
    MIN_MINUTES = 0
    MAX_MINUTES = 59

    carrier = ""
    flight_no = -1
    dept_code = ""
    dept_date = datetime(1970, 1, 1) # UTC time, store offset separately

    arr_code = ""
    arr_date = datetime(1970, 1, 1) # UTC time, store offset separately
    
    offset = Offsetizer()

    def __init__(self) -> None:
        # Build flight data
        self.__parse_carrier()
        self.__parse_flight_no()
        self.__parse_dept_code()
        self.__parse_arr_code()
        
        # Build dates in flight data
        self.__parse_dept_date()
        self.__parse_arr_date()
        
        # Localize dates
        self.dept_date = self.offset.offsetize(self.dept_code, self.dept_date)
        self.arr_date = self.offset.offsetize(self.arr_code, self.arr_date)
        
        
    def print_object(self):
        print(self.carrier, self.flight_no)
    
        print("\033[1m Departure:\033[0m",self.dept_code, \
            self.dept_date.isoformat())
        print("\033[1m Arrival:\033[0m",self.arr_code, \
            self.arr_date.isoformat())

    def __parse_carrier(self):
          self.carrier = input("Enter carrier (two chars):\n")
          assert(self.carrier.isupper())
          assert(len(self.carrier) == self.CARRIER_LENGTH)

    def __parse_flight_no(self):
          self.flight_no = int(input("Enter flight number (4 digits):\n"))
          assert(self.flight_no >= self.MIN_FLIGHT_NO)
          assert(self.flight_no <= self.MAX_FLIGHT_NO)
    
    def __parse_dept_code(self):
        self.dept_code = input("Enter departure code (three chars):\n")
        assert(self.dept_code.isupper())
        assert(len(self.dept_code) == self.CODE_LENGTH)
        
    def __parse_arr_code(self):
        self.arr_code = input("Enter arrival code (three chars):\n")
        assert(self.arr_code.isupper())
        assert(len(self.arr_code) == self.CODE_LENGTH)
        
    def __parse_dept_date(self):
        # Build date
        date_str = ""
        date_str += (self.__parse_year()) + " "
        date_str += (self.__parse_month()) + " "
        date_str += (self.__parse_date()) + " "
        date_str += (self.__parse_hour()) + " "
        date_str += (self.__parse_minute()) + " "
        
        self.dept_date = datetime.strptime(date_str, "%Y %m %d %H %M ")
    
    
    def __parse_year(self):
        yr = int(input("Enter year (YYYY):\n"))
        assert(yr >= self.MIN_YEAR)
        assert(yr <= self.MAX_YEAR)
        return str(yr)
    
    def __parse_month(self):
        mn = int(input("Enter month (MM):\n"))
        assert(mn >= self.MIN_MONTH)
        assert(mn <= self.MAX_MONTH)
        return str(mn)
    
    def __parse_date(self):
        da = int(input("Enter day (DD):\n"))
        assert(da >= self.MIN_DAY)
        assert(da <= self.MAX_DAY)
        return str(da)
    
    def __parse_hour(self):
        hr = (int(input("Enter hour (HH):\n")))
        assert(hr >= self.MIN_HOUR)
        assert(hr <= self.MAX_HOUR)
        return str(hr)
    
    def __parse_minute(self):
        mi = int(input("Enter minute (MM):\n"))
        assert(mi >= self.MIN_MINUTES)
        assert(mi <= self.MAX_MINUTES)
        return str(mi)
    
    def __parse_arr_date(self):
        # Build date
        date_str = ""
        date_str += (self.__parse_year()) + " "
        date_str += (self.__parse_month()) + " "
        date_str += (self.__parse_date()) + " "
        date_str += (self.__parse_hour()) + " "
        date_str += (self.__parse_minute()) + " "
        self.arr_date = datetime.strptime(date_str, "%Y %m %d %H %M ")
        pass
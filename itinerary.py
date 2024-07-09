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
import sys

class Itinerary:

    CARRIER_LENGTH = 2
    MIN_FLIGHT_NO = 0
    MAX_FLIGHT_NO = 9999
    FLIGHT_NO_LEN = 4
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
    pretty_flight_no = ""
    dept_code = ""
    dept_date = datetime(1970, 1, 1) # UTC time, store offset separately

    arr_code = ""
    arr_date = datetime(1970, 1, 1) # UTC time, store offset separately
    
    offset = Offsetizer()

    def __init__(self, action, file) -> None:
        if action == 'i': # Inputting flight
            promptMsg = False
            if file == sys.stdin: promptMsg = True
            
            if promptMsg:
                print("Format:")
                print("CA | FLNO | DEP | YYYY | MM | DD | HH | MM \
                    | ARR | YYYY | MM | DD | HH | MM")
            
            # Remove spaces, standardizes if there is space or not
            fl_line = file.readline().rstrip().replace(" ", "")
            
            # Build flight data
            self.__parse_carrier(fl_line[0:2])
            self.__parse_flight_no(fl_line[2:6])
            
            self.__parse_dept_code(fl_line[6:9])
            self.dept_date = self.__parse_full_date(fl_line, 9)
            
            self.__parse_arr_code(fl_line[21:24])
            self.arr_date = self.__parse_full_date(fl_line, 24)
            
            # Localize dates
            self.dept_date = self.offset.offsetize(self.dept_code, self.dept_date)
            self.arr_date = self.offset.offsetize(self.arr_code, self.arr_date)
        else: # Outputting flight
            fl_line = file.readline().rstrip()
            self.__read_flight(fl_line)
            pass
        
        
    def print_object(self):
        self.__clean_flight_no(self.flight_no)
        print(self.carrier, self.pretty_flight_no, \
            self.dept_code, self.dept_date.isoformat(),
            self.arr_code, self.arr_date.isoformat())
        
    def print_object_as_input(self):
        print(self.carrier, 
              str(self.flight_no).zfill(4), 
              self.dept_code,
            str(self.dept_date.year).zfill(4),
            str(self.dept_date.month).zfill(2), 
            str(self.dept_date.day).zfill(2),
            str(self.dept_date.hour).zfill(2),
            str(self.dept_date.minute).zfill(2),
            self.arr_code,
            str(self.arr_date.year).zfill(4),
            str(self.arr_date.month).zfill(2),
            str(self.arr_date.day).zfill(2),
            str(self.arr_date.hour).zfill(2), 
            str(self.arr_date.minute).zfill(2))
    
        # print("\033[1m Departure:\033[0m",self.dept_code, \
        #     self.dept_date.isoformat())
        # print("\033[1m Arrival:\033[0m",self.arr_code, \
        #     self.arr_date.isoformat())

    def __read_flight(self, line):
        count = 0
        for word in line.split():
            match count:
                case 0:
                    #carrier
                    self.__parse_carrier(word)
                    # print(self.carrier)
                    pass
                case 1:
                    # flight number
                    self.__parse_flight_no(word)
                    pass
                case 2:
                    # dept code
                    self.__parse_dept_code(word)
                    pass
                case 3:
                    # dept date
                    self.dept_date = self.__read_date(word)
                    pass
                case 4:
                    # arr code
                    self.__parse_arr_code(word)
                    pass
                case 5:
                    # arr date
                    self.arr_date = self.__read_date(word)
                    pass
            count = count + 1
        pass
    
    
    def __parse_carrier(self, fl_data):

        self.carrier = fl_data
        assert(self.carrier.isupper())
        assert(len(self.carrier) == self.CARRIER_LENGTH)
        
    # propagate 0's if the greater digits are not there
    def __clean_flight_no(self, fl_num):
        self.pretty_flight_no = str(fl_num)
        if len(str(fl_num)) != self.FLIGHT_NO_LEN:
            self.pretty_flight_no = self.pretty_flight_no.zfill(4)

    def __parse_flight_no(self, fl_data):
        self.flight_no = int(fl_data)
        assert(self.flight_no >= self.MIN_FLIGHT_NO)
        assert(self.flight_no <= self.MAX_FLIGHT_NO)
    
    def __parse_dept_code(self, fl_data):
        self.dept_code = fl_data
        
        assert(self.dept_code.isupper())
        assert(len(self.dept_code) == self.CODE_LENGTH)
        
    def __parse_arr_code(self, fl_data):
        self.arr_code = fl_data
        
        assert(self.arr_code.isupper())
        assert(len(self.arr_code) == self.CODE_LENGTH)
        
    def __read_date(self, fl_data):
        return datetime.fromisoformat(fl_data)
        
    def __parse_full_date(self, fl_line, offset):
        # Build date
        date_str = ""
        date_str += (self.__parse_year(fl_line, offset)) + " "
        date_str += (self.__parse_month(fl_line, offset)) + " "
        date_str += (self.__parse_date(fl_line, offset)) + " "
        date_str += (self.__parse_hour(fl_line, offset)) + " "
        date_str += (self.__parse_minute(fl_line, offset)) + " "
        return datetime.strptime(date_str, "%Y %m %d %H %M ")
    
    
    def __parse_year(self, fl_line, offset):
        yr = int(fl_line[offset:offset+4])

        assert(yr >= self.MIN_YEAR)
        assert(yr <= self.MAX_YEAR)
        return str(yr)
    
    def __parse_month(self, fl_line, offset):
        mn = int(fl_line[offset + 4:offset + 6])
        assert(mn >= self.MIN_MONTH)
        assert(mn <= self.MAX_MONTH)
        return str(mn)
    
    def __parse_date(self, fl_line, offset):
        da = int(fl_line[offset + 6:offset + 8])
        assert(da >= self.MIN_DAY)
        assert(da <= self.MAX_DAY)
        return str(da)
    
    def __parse_hour(self, fl_line, offset):
        hr = int(fl_line[offset + 8:offset + 10])
        assert(hr >= self.MIN_HOUR)
        assert(hr <= self.MAX_HOUR)
        return str(hr)
    
    def __parse_minute(self, fl_line, offset):
        mi = int(fl_line[offset + 10:offset + 12])
        assert(mi >= self.MIN_MINUTES)
        assert(mi <= self.MAX_MINUTES)
        return str(mi)
    
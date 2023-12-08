##############################################################
#
#                     flightio.py
#
#
#     Authored by Vedant Modi (vedantmodi.com)
#     07 Dec 2023
#
#
#     TODO Purpose:
#
##############################################################

from itinerary import Itinerary

class FlightIO:
    # Variables
    MAX_NUM_FLIGHTS = 7
    MIN_NUM_FLIGHTS = 0

    num_flights = 0

    flights = list()

    def __init__(self, switch):
        if (switch == True):
            self.inputInfo()
        else:
            self.outputInfo()
        pass



    def inputInfo(self):
        self.__parse_num_flights()
        

        pass

    # After this function, num flights should be initialised 
    def __parse_num_flights(self):
        self.num_flights = int(input("Number of flights:\n"))
        assert(self.num_flights <= self.MAX_NUM_FLIGHTS 
               and self.num_flights >= self.MIN_NUM_FLIGHTS)
        
        
    def outputInfo(self):
        print("Decompressing")
        pass

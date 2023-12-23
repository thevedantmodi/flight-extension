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
import sys

class FlightIO:
    # Variables
    MAX_NUM_FLIGHTS = 7
    MIN_NUM_FLIGHTS = 0
    num_flights = 0

    flights = list()

    def __init__(self, action, file):
        if (action == True):
            self.inputInfo(file)
        else:
            self.outputInfo(file)


    def inputInfo(self, file):
        self.__parse_num_flights(file)
        self.__parse_all_flights(file)
        
        self.__write_compressed()
    
    def __write_compressed(self):
        print(self.num_flights)
        for fl in self.flights:
            fl.print_object()
    
    def __write_decompressed(self):
        print(self.num_flights)
        for fl in self.flights:
            fl.print_object_as_input()
    
    def __parse_num_flights(self, file):
         # Get the first line only to get the number of flights
        if file == sys.stdin: print("Number of flights:") 
        self.num_flights = int(file.readline().rstrip())
    
    def __parse_all_flights(self, file):
        for pos in range(self.num_flights):
            itin = Itinerary('i', file)
            self.flights.append(itin)
    
    def __build_flights(self, file):
        line_count = 0
        while (line_count != self.num_flights):
        # for line in file: # Goes through all flights in file
            itin = Itinerary('o', file)
            self.flights.append(itin)
            line_count = line_count + 1
    
    def outputInfo(self, file):
        self.__parse_num_flights(file)
        self.__build_flights(file)
        self.__write_decompressed()
        pass
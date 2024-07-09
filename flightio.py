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

import sys

from compressor import Compressor
from itinerary import Itinerary


class FlightIO:
    # Variables
    MAX_NUM_FLIGHTS = 255
    MIN_NUM_FLIGHTS = 0
    num_flights = 0

    flights = list()

    # True means compress
    def __init__(self, action, file):
        if action:
            self.inputInfo(file)
        else:
            self.outputInfo(file)

    def inputInfo(self, file):
        self.__parse_num_flights(file)
        self.__parse_all_flights(file)
        self.__write_compressed()

    def __write_compressed(self):
        c = Compressor()
        c.compress(self.flights)
        # print(self.num_flights)
        # for fl in self.flights:
        # fl.print_object()

    def __write_decompressed(self):
        print(self.num_flights)
        for fl in self.flights:
            fl.print_object_as_input()

    def __parse_num_flights(self, file):
        # Get the first line only to get the number of flights
        if file == sys.stdin:
            print("Number of flights:", file=sys.stderr)
        self.num_flights = int(file.readline().rstrip())
        assert self.MIN_NUM_FLIGHTS <= self.num_flights <= self.MAX_NUM_FLIGHTS

    def __parse_all_flights(self, file):
        for _ in range(self.num_flights):
            itin = Itinerary("i", file)
            self.flights.append(itin)

    def __build_flights(self, file):
        line_count = 0
        while line_count != self.num_flights:
            # for line in file: # Goes through all flights in file
            itin = Itinerary("o", file)
            self.flights.append(itin)
            line_count += 1

    def __read_compressed(self, file):
        d = Compressor()
        d.decompress(file)

    def outputInfo(self, file):
        self.__read_compressed(file)
        return
        self.__parse_num_flights(file)
        self.__build_flights(file)
        self.__write_decompressed()

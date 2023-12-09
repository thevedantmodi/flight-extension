##############################################################
#
#                     offsetizer.py
#
#
#     Authored by Vedant Modi (vedantmodi.com)
#     09 Dec 2023
#
#
#     TODO Purpose
#
##############################################################

import airportsdata

from datetime import datetime
from pytz import timezone
import pytz

class Offsetizer:
    airports = airportsdata.load('IATA')
    macs = airportsdata.load_iata_macs()
    
    def __init__(self) -> None:
        pass
    
    def offsetize(self, IATA: str, datetime: datetime):
        # IATA matches invariants
        assert len(IATA) == 3
        assert IATA.isupper()
        
        self.__get_tz(IATA)
        
        self.
        
        pass
    
    # Get tz from database
    def __get_tz(self, IATA: str):
        return self.airports[IATA]["tz"]
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
from zoneinfo import ZoneInfo

class Offsetizer:
    airports = airportsdata.load('IATA')
    macs = airportsdata.load_iata_macs()
    
    def __init__(self) -> None:
        pass
    
    def offsetize(self, IATA: str, datetime: datetime):
        # IATA matches invariants
        assert len(IATA) == 3
        assert IATA.isupper()
        
        return datetime.replace(tzinfo=ZoneInfo(self.__get_tz(IATA)))
    
    # Get tz from database
    def __get_tz(self, IATA: str):
        tz = ""
        try:
            tz = self.airports[IATA]["tz"]
        except KeyError:
            tz = list(self.macs[IATA]['airports'].values())[0]['tz']
            # tz = "America/New_York"
        finally:
            assert(tz != "")
            return tz

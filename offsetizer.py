##############################################################
#
#                     offsetizer.py
#
#
#     Authored by Vedant Modi (vedantmodi.com)
#     09 Dec 2023
#
#
#     Module used to localize a datetime object into a timezone
#     of a location (specified via airport code). Localized time
#     is exported as a Python datetime object, and clients can
#     further serialize the datetime object with the 
#     datetime.isostring() function
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
    
    def offsetize(self, IATA: str, tmstmp: datetime):
        # IATA matches invariants
        assert len(IATA) == 3
        assert IATA.isupper()
        
        # Undefined behavior to localize before Unix Epoch when using datetime
        unix_epoch = datetime(1970, 1, 1)
        assert tmstmp >= unix_epoch
        
        return tmstmp.replace(tzinfo=ZoneInfo(self.__get_tz(IATA)))
    
    # Get tz from database
    def __get_tz(self, IATA: str):
        tz = ""
        try:
            tz = self.airports[IATA]["tz"]
        except KeyError:
            try:
                tz = list(self.macs[IATA]['airports'].values())[0]['tz']
            except KeyError:
                raise KeyError("IATA code", IATA, "not recognized")
        else:
            assert(tz != "")
        finally:
            return tz

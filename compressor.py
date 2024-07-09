##############################################################
#
#                     compressor.py
#
#
#     Authored by Vedant Modi (vedantmodi.com)
#     30 Jun 2024
#
#
#     Compression module for vfl, contains Compressor class to
#     create binary VFL file format. Relies on Bitpack module.
#
##############################################################

import sys

from bitpack import Bitpack


class Compressor:  
    
    letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    # From 'A' to 'Z' in ASCII
    # for l in range(0x41, 0x5A + 0x01):
        
    #     pass
    
    # Returns a binary string that contains the contents of the flights within
    # Itineraries
    def compress(self, flights):
        
        # Should already in [0,255], so can just print a char
        num_flights = len(flights)
        sys.stdout.write(chr(num_flights))
        
        # BEGIN FLIGHTS
        
        word = bytes()
        for f in flights:
            b = Bitpack()
            # Create a 128-bit integer for packing into
            word = 0x_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00
            car1, car2 = self._quantize_carrier(f.carrier)
            
            sys.stdout.write(chr(car1))
            # sys.stdout.write(str(car2.to_bytes()))
            
            word = b.set(word, 5, 123, car1)
            word = b.set(word, 5, 118, car2)
            
            # assert(b.get(word, 5, 123) == car1)
            # # print(b.get(word, 5, 118))
            # assert(b.get(word, 5, 118) == car2)
            # break
            
            # sys.stdout.write(f.carrier)
        sys.stdout.flush()
        pass
    
    # Returns a list of Itineraries that contains the content from the binary
    # string
    def decompress(self, file):
        
        num_flights = ord(file.read(1))
        print(num_flights)
        # print(type(num_flights))
        pass
    
    def _quantize_alpha(self, letter):
        return self.letters.index(letter)
    
    def _quantize_carrier(self, carrier):
        first = carrier[0]
        second = carrier[1]
        
        first_num = self._quantize_alpha(first)
        second_num = self._quantize_alpha(second)
        
        return first_num, second_num
    
    pass

# def main():
#     c = Compressor()
    
#     assert(c._quantize_alpha('A') == 0)
#     assert(c._quantize_alpha('B') == 1)
#     assert(c._quantize_alpha('Z') == 25)
#     assert(c._quantize_alpha('W') != 17)
    
# main()
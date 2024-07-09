##############################################################
#
#                     bitpack.py
#
#
#     Authored by Vedant Modi (vedantmodi.com)
#     03 Jul 2024
#
#
#     Bitpack module
#
##############################################################

class Bitpack:
    
    LENGTH = 128
    
    def _sl(self, word: int, bits: int):
        assert(bits <= self.LENGTH)
        
        if bits == self.LENGTH:
            return 0
        else:
            return word << bits
        
    def _sr(self, word: int, bits: int):
        assert(bits <= self.LENGTH)
        
        if bits == self.LENGTH:
            return 0
        else:
            return word >> bits
    
    def get(self, word: int, size: int, start: int):
        assert(word.bit_length() <= self.LENGTH)
        
        end = start + size
        assert(end <= self.LENGTH)

        high_masked = self._sl(word, self.LENGTH - end)
        low_masked = self._sr(high_masked, self.LENGTH - size)
        
        return low_masked
    
    def fit(self, word: int, width: int):
        return self._sr(word, width) == 0
    
    def set(self, word: int, size: int, start: int, field: int):
        assert(word.bit_length() <= self.LENGTH)
        assert(size <= self.LENGTH)
    
        end = start + size
        assert(end <= self.LENGTH)
        
        if not self.fit(field, size):
            raise OverflowError("field does not fit in word")
        
        return self._sl(self._sr(word, end), end) | \
        self._sr(self._sl(word, self.LENGTH - start), self.LENGTH - start) | \
        field << start
        
# def main():
#     b = Bitpack()
    
#     word = 0
#     my_value = 32
#     new_word = b.set(word, 6, 2, my_value)
#     print(bin(new_word))
    
#     assert(my_value == b.get(new_word, 32,2))
    
# main()
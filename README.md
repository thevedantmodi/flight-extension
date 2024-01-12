# vfl
Vedant's Flight Logger, or Virtual Flight Logger

A file format that can store a flight itinerary.

## Architecture
Uses a Python driver program that will pass/take, respectively, the inputted/
outputted data to the compressor. The compressor, built in C, will output
accept only parsed data from the driver, output a compressed file on acceptable
input, and will fail with an abortion message otherwise.

In graph form, this is the representation

                      User readable input/output                  // Python
            
        Formatted input                           Formatted output // Python

    Quantize output                              Un-quantize input // C

        Output as 128-byte words        Read header and 128-byte words // C

                        Binary compressed file // C


## TODO list
- Change the date time output to just output fields, doesn't need to be ISO fmt date
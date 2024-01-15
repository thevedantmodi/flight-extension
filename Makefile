###############################################################
#
#                     Makefile
#
#     Author: Vedant Modi (vmodi01)
#     Date:     27 Nov 2023
#
#     Summary:
#     Makefile for vfl
#
###############################################################


CC = gcc
IFLAGS = #-I/Users/vedantmodi/Desktop/dev-work/cii/include
CFLAGS = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS) -O2
LDFLAGS = #-L /Users/vedantmodi/Desktop/dev-work/cii/lib
LDLIBS = #-larray
HEADERS = $(shell echo *.h)
DEPENDS = vfl-zip.o compress-flight.o bitpack.o flight-pack.o
EXECS = vfl-zip

all: $(EXECS)

vfl-zip: $(DEPENDS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECS) *.o
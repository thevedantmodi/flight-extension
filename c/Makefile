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
IFLAGS = -I/usr/sup/cii40/include/cii
CFLAGS = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS) -O2
LDFLAGS = -g -lcii40 -L/usr/sup/cii40/lib64
LDLIBS = -lcii40 -lm 
DEPENDS = vfl.o compress-itin.o flight-parse.o flight-word.o datetime.o \
	flight.o flight-quantize.o flight-pack.o bitpack.o
EXECS = vfl

all: $(EXECS)

vfl: $(DEPENDS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECS) *.o
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
# LDFLAGS = -g -lcii40 -L/usr/sup/cii40/lib64
# LDLIBS = -lcii40 -lm 
DEPENDS = vfl-zip.o
EXECS = vfl-zip

all: $(EXECS)

vfl: $(DEPENDS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECS) *.o
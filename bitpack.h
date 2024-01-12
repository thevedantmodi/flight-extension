/**************************************************************
 *
 *                     bitpack.h
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#ifndef __BITPACK__H
#define __BITPACK__H

#include <stdbool.h>
#include <stdint.h>

bool Bitpack_fitss(int64_t n, unsigned width);
bool Bitpack_fitsu(__uint128_t n, unsigned width);

int64_t Bitpack_gets(uint64_t word, unsigned width, unsigned lsb);
__uint128_t Bitpack_getu(__uint128_t word, unsigned width, unsigned lsb);

__uint128_t Bitpack_newu(__uint128_t word, unsigned width, unsigned lsb,
                      __uint128_t value);
uint64_t Bitpack_news(uint64_t word, unsigned width, unsigned lsb,
                      int64_t value);

#endif

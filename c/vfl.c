/**************************************************************
 *
 *                     vfl.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     27 Nov 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "compress-itin.h"

static void (*compress_or_decompress)(FILE *input) = compress_itin;

int main(int argc, char const *argv[])
{
    /* Usage:
        vfl -c [input fname (or stdin)]
        vfl -d [input fname] (send to stdout)
     */

    int i;

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-c") == 0)
        {
            compress_or_decompress = compress_itin; /* We should compress */
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            compress_or_decompress = decompress_itin; /* We should decompress */
        }
        else if (*argv[i] == '-')
        {
            fprintf(stderr, "%s: unknown option '%s'\n",
                    argv[0], argv[i]);
            exit(1);
        }
        else if (argc - i > 2)
        {
            fprintf(stderr, "Usage: %s -d [filename]\n"
                            "       %s -c [filename]\n",
                    argv[0], argv[0]);
            exit(1);
        }
        else
        {
            break;
        }
    }
    assert(argc - i <= 1); /* at most one file on command line */
    if (i < argc)
    {
        FILE *fp = fopen(argv[i], "r");
        assert(fp != NULL);
        compress_or_decompress(fp);
        fclose(fp);
    }
    else
    {
        compress_or_decompress(stdin);
    }

    return EXIT_SUCCESS;
}


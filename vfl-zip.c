/**************************************************************
 *
 *                     vfl-zip.c
 *
 *     Author:  Vedant Modi (vedantmodi.com)
 *     Date:     23 Dec 2023
 *
 *     Summary:
 *     TODO summary
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "compress-flight.h"

static void (*compress_or_decompress)(FILE *input) = compress_flight;

int main(int argc, char const *argv[])
{
    /* Usage:   */
    /* ./vfl-zip -c [input fname (- for stdin)] */
    /* ./vfl-zip -d [input fname] (send to stdout) */
    /* Make sure file is valid, and take in mode */

    /* Thanks to Tufts COMP40 for this parsing code */
    int i;

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-c") == 0)
        {
            compress_or_decompress = compress_flight;
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            compress_or_decompress = decompress_flight;
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


/* For each flight, (URE to pass malformed output to the compressor)*/
/* Read in first two chars as carrier */
/* Get the index of char 1 */
/* Get the index of char 2 */
/* Store in binary in array */
/* Skip character */
/* Read in second 4 chars */
/* Build integer of flight number */
/* Store in binary in array */
/* Store code in string */
/* Pass string into read code (3 chars) */
/* Get the index of char 1 */
/* Get the index of char 2 */
/* Get the index of char 3 */
/* Store date in string */
/* Pass string into read date */
/* Get the year */
/* Get the index of the year (7 bits) */
/* Get the date */
/* Get the index of the date (5 bits) */
/* Get the month */
/* Get the index of the month (4 bits) */
/* Get the minute */
/* Get the index of the minute (6 bits) */
/* Get the UTC offset */
/* Get the index of the UTC offset */
/* Refer to  */


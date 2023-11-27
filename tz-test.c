#if 0
#define _POSIX_C_SOURCE 200112L // for setenv on gcc
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
int main(void)
{
    setenv("TZ", "/usr/share/zoneinfo/America/New_York", 1); // POSIX-specific
 
    time_t time_now = time(NULL);
    struct tm tm = *localtime(&time_now);
    printf("Today is           %s", asctime(&tm));
    printf("(DST is %s)\n", tm.tm_isdst ? "in effect" : "not in effect");
    fprintf(stderr, "tm.tm_gmtoff\t %ld \n", tm.tm_gmtoff);
    tm.tm_mon -= 100;  // tm_mon is now outside its normal range
    mktime(&tm);       // tm_isdst is not set to -1; today's DST status is used


    

    printf("100 months ago was %s", asctime(&tm));
    printf("(DST was %s)\n", tm.tm_isdst ? "in effect" : "not in effect");
}
#endif
#if 0

/* mktime example: weekday calculator */
#include <stdio.h> /* printf, scanf */
#include <time.h>  /* time_t, struct tm, time, mktime */

int main()
{
    time_t rawtime;
    struct tm *timeinfo;
    int year, month, day;
    const char *weekday[] = {"Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};
    char *timezone = "";

    /* prompt user for date */
    printf("Enter year: ");
    fflush(stdout);
    scanf("%d", &year);
    printf("Enter month: ");
    fflush(stdout);
    scanf("%d", &month);
    printf("Enter day: ");
    fflush(stdout);
    scanf("%d", &day);
    printf("Enter timezone: ");
    fflush(stdout);
    scanf("%s", timezone);


    /* get current timeinfo and modify it to the user's choice */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    /* call mktime: timeinfo->tm_wday will be set */
    mktime(timeinfo);

    printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);

    return 0;
}
#endif

#include <stdio.h> /* printf, scanf */
#include <time.h>  /* time_t, struct tm, time, mktime */
#include <stdlib.h>
#include <string.h>

time_t mkTimeForTimezone(struct tm *tm, char *timezone)
{
    char *tz;
    time_t res;

    // tz = getenv("TZ");
    // if (tz != NULL)
    //     tz = strdup(tz);
    setenv("TZ", timezone, 1);
    // tzset();
    res = mktime(tm);
    // if (tz != NULL)
    // {
    //     setenv("TZ", tz, 1);
    //     free(tz);
    // }
    // else
    // {
    //     unsetenv("TZ");
    // }
    // tzset();
    return (res);
}

int main()
{
    char *timezone = "Asia/Singapore";
    struct tm tt;
    time_t t;
    int offset;

    t = time(NULL);
    tt = *gmtime(&t);
    offset = mkTimeForTimezone(&tt, timezone) - t;
    printf("Current offset for %s is %d\n", timezone, offset);
}
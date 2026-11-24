

#include <stdio.h>
#include <string.h>
#include <time.h>

static const char *monthNames[12] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"
};

/* Returns weekday of the 1st of the month: 0 = Sunday ... 6 = Saturday */
int firstWeekday(int month, int year)
{
    struct tm t;
    memset(&t, 0, sizeof(t));
    t.tm_year = year - 1900;   /* years since 1900 */
    t.tm_mon  = month;         /* 0 = January ... 11 = December */
    t.tm_mday = 1;
    t.tm_hour = 12;            /* noon, avoids daylight-saving edge cases */
    mktime(&t);                /* fills in tm_wday */
    return t.tm_wday;
}

/* Returns number of days in the month, using mktime() normalization:
 * day 0 of the next month is the last day of this month. */
int daysInMonth(int month, int year)
{
    struct tm t;
    memset(&t, 0, sizeof(t));
    t.tm_year = year - 1900;
    t.tm_mon  = month + 1;
    t.tm_mday = 0;
    t.tm_hour = 12;
    mktime(&t);
    return t.tm_mday;
}

void printMonth(int month, int year)
{
    char title[40];
    int len, pad, day, wday, days;

    snprintf(title, sizeof(title), "%s %d", monthNames[month], year);
    len = (int)strlen(title);
    pad = (20 - len) / 2;      /* centre the title over the 20-char grid */
    if (pad < 0)
        pad = 0;

    printf("\n%*s%s\n", pad, "", title);
    printf("Su Mo Tu We Th Fr Sa\n");

    wday = firstWeekday(month, year);
    days = daysInMonth(month, year);

    /* Leading blanks before the 1st of the month */
    for (day = 0; day < wday; day++)
        printf("   ");

    for (day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((wday + day) % 7 == 0)   /* after Saturday, start a new line */
            printf("\n");
    }
    if ((wday + days) % 7 != 0)
        printf("\n");
}

int main(void)
{
    int year, month;

    printf("Enter the year (1900 or later): ");
    if (scanf("%d", &year) != 1 || year < 1900) {
        printf("Invalid year.\n");
        return 1;
    }

    printf("\n========== CALENDAR FOR %d ==========\n", year);
    for (month = 0; month < 12; month++)
        printMonth(month, year);

    return 0;
}

/**
 * @file Time.cpp
 * @author Abdul Rafay
 * @brief Contains the implementation of the struct class Time.
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Time.h"

bool IsLeapYear(short year)
{
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return (year % 400) == 0;
}

void convertToUppercase(std::string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

Time::Time()
{
    int t = 0;
    tsecs = (time_t)t;
}

Time::Time(int t)
{
    tsecs = (time_t) t;
}

Time::Time(short year, short month, short day, short hour, short minute, short second)
{
    time_t secs = 0;
    for (short y = 1970; y < year; ++y)
        secs += (IsLeapYear(y) ? 366 : 365) * SECONDS_PER_DAY;
    for (short m = 1; m < month; ++m)
    {
        secs += DaysOfMonth[m - 1] * SECONDS_PER_DAY;
        if (m == 2 && IsLeapYear(year))
            secs += SECONDS_PER_DAY;
    }
    secs += (day - 1) * SECONDS_PER_DAY;
    secs += hour * SECONDS_PER_HOUR;
    secs += minute * SECONDS_PER_MINUTE;
    secs += second;
    tsecs = secs;
}

void Time::printDate()
{
    struct tm gmtm = *localtime(&tsecs);
    cout << Months[gmtm.tm_mon] << " " << gmtm.tm_mday << " " << gmtm.tm_year+1900;
}

void Time::print()
{
    string printtime = ctime(&tsecs);            
    printtime.erase(printtime.length() - 1);
    cout << printtime;
}

bool Time::checkDate(const Time& test)
{
    tm *gmtm = gmtime(&tsecs);
    tm* gmtm2 = gmtime(&test.tsecs);
    if(gmtm->tm_wday == gmtm2->tm_wday && gmtm->tm_mday == gmtm2->tm_mday && gmtm->tm_year == gmtm2->tm_year)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Time Time::getNextWeek()
{
    Time temp = *this;
    temp.tsecs = (time_t) (this->tsecs + SECS_IN_WEEK);
    return temp;
}

int Time::getDaysTill(const Time& t)
{
    int secsdiff = t.tsecs - this->tsecs;
    time_t tmp = (time_t) secsdiff;
    tm *gmt = gmtime(&tmp);
    return gmt->tm_mday;
}

void Time::operator=(const Time& t)
{
    this->tsecs = t.tsecs;
}

bool Time::operator<(const Time& t)
{
    return (this->tsecs < t.tsecs);
}

bool Time::operator>(const Time& t)
{
    return (this->tsecs > t.tsecs);
}

bool Time::operator<=(const Time& t)
{
    return (this->tsecs <= t.tsecs);
}

bool Time::operator>=(const Time& t)
{
    return (this->tsecs >= t.tsecs);
}
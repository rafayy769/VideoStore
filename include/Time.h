/**
 * @file Time.h
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief Header interface for the struct Time
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Utilities.h"

using namespace std;

/**
 * @brief A utility function that returns whether a given year is a leap year or not.
 * 
 * @param year 
 * @return true 
 * @return false 
 */
bool IsLeapYear(short year);

/**
 * @brief A utility function to change a given string such that all its individual letters get uppercased.
 * 
 * @param str 
 */
void convertToUppercase(std::string &str);

/**
 * @struct Time
 * @brief A struct to deal with time.
 * 
 * The struct contains a time_t variable which is the primary member variable. All calculations are performed on it to get the time displayed in standard format. Overloaded operators are defined as well to handle comparisons of times.
 */
struct Time
{
    time_t tsecs; /**< Primary variable for the struct, which stores the time in the form of total number of seconds that have passed since 1970 till the time that is being stored. */

    //Constructors

    /**
     * @brief Construct a new Time object.
     * 
     * Initializes time_t to zero.
     * 
     */
    Time();


    /**
     * @brief Construct a new Time object.
     * 
     * Sets the time object to a specific time.
     * 
     * @param t number of seconds since 1970
     */
    Time(int t);

    /**
     * @brief Construct a new Time object.
     * 
     * Sets the time specified by proper date and time format.
     * 
     * @param year Year
     * @param month Month
     * @param day Day
     * @param hour Hour
     * @param minute Minute
     * @param second Second
     */
    Time(short year, short month, short day, short hour = 0, short minute = 0, short second = 0);

    /**
     * @brief Prints only the date and not the time of the this Time object. Useful later, when only the date is required without the time. See videoStore method videoStore::getRevenueGenerated()
     * 
     */
    void printDate();

    /**
     * @brief Prints the date and time in the standard UTC format. ctime() adds a '\\n' character which is being removed using std::string::erase(), since we don't want an endline, as time needs to be printed inline at certain occasions.
     * 
     */
    void print();

    /**
     * @brief Checks whether the two dates are equal.
     * Compares date of this object with the date of the param "test" and returns a bool accordingly.
     * 
     * @param test Time object Date to test if its equal to the current date.
     * @return bool 
     */
    bool checkDate(const Time& test);

    /**
     * @brief Get the time which is exactly 7 days from this object's time.
     * 
     * @return Time 
     */
    Time getNextWeek();

    /**
     * @brief Get how many days between this object and the passed param "t" time. Useful in calculating how many days overdue is the movie and thus is used to calculate fine.
     * 
     * @param t Time object till which we need to find the total number of days.
     * @return int 
     */
    int getDaysTill(const Time& t);

    //Operator overloads
    /**
     * @brief Assignment operator for Time objects. Copies the total number of seconds from Time object parameter to this object.
     * 
     * @param t 
     */
    void operator=(const Time& t);
    /**
     * @brief Comparison "<" operator for time objects. Useful later in checking whether a given time is ahead of the time being compared or before it.
     * 
     * @param t 
     * @return true 
     * @return false 
     */
    bool operator<(const Time& t);
    /**
     * @brief Comparison ">" operator for time objects. Useful later in checking whether a given time is ahead of the time being compared or before it.
     * 
     * @param t 
     * @return true 
     * @return false 
     */
    bool operator>(const Time& t);
    /**
     * @brief Comparison "<=" operator for time objects. Useful later in checking whether a given time is ahead of the time being compared or before it.
     * 
     * @param t 
     * @return true 
     * @return false 
     */
    bool operator<=(const Time& t);
    /**
     * @brief Comparison ">=" operator for time objects. Useful later in checking whether a given time is ahead of the time being compared or before it.
     * 
     * @param t 
     * @return true 
     * @return false 
     */
    bool operator>=(const Time& t);
};
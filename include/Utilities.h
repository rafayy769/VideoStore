/**
 * @file Utilities.h
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief Contains definitions for some useful functions
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#ifndef _UTILITIES_H1
#define  _UTILITIES_H

#include <string>

#define CLEARCMD "clear"

#ifdef _WIN32
#define CLEARCMD "CLS"
#endif // DEBUG

const int PRICE_PER_MOVIE = 1000;
const int FINE_PER_DAY = 50;
const int SECONDS_PER_MINUTE = 60;
const int SECONDS_PER_HOUR = 3600;
const int SECONDS_PER_DAY = 86400;
const int SECS_IN_WEEK = 60*60*24*7;

const int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};

/**
 * @enum STATUS
 * @brief To be used in CustomerInfo class to represent the account status of the customer.
 * 
 */
enum STATUS{
    CLEAR,          /**< Represents that the account status of user is clear and they have nothing rented or overdue.*/
    RENTED,         /**< Represents that the user have rented something. */
};

#endif // !_UTILITIES_H

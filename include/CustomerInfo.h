/**
 * @file CustomerInfo.h
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief CustomerInfo class is defined here.
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "videoList.h"

/**
 * @class CustomerInfo
 * @brief Represents a customer of the store object. Stores basic information about the customer such as their name. Assigns them a random but unique ID.
 * 
 */
class CustomerInfo
{
    string fName;        /**< Stores the first name of the customer.*/
    string lName;        /**< Stores the last name of the customer.*/      
    int ID;              /**< Stores the unique ID of the customer.*/
    STATUS accStatus;    /**< Stores the account status of the customer.*/
    videoList rented;    /**< List to store all the movies rented by the customer in a single place.*/                
    int numberOfRented;  /**< Number of movies rented by the customer at any given time. */            

public:

    /**
     * @brief Construct a new CustomerInfo object
     * 
     */
    CustomerInfo();
    /**
     * @brief Get the Number Of Rented movies.
     * 
     * @return int 
     */
    int getNumberOfRented();

    /**
     * @brief Set the Number Of Rented movies. Increments or decrements the number of rented movies based on param x. If x==1 increments, else decrements.
     * 
     * @param x 
     */
    void setNumberOfRented(int x);

    /**
     * @brief Returns first name of customer.
     * 
     * @return string 
     */
    string getFName();

    /**
     * @brief Sets first name of the customer.
     * 
     * @param fName 
     */
    void setFName(string fName);

    /**
     * @brief Returns last name of the customer.
     * 
     * @return string 
     */
    string getLName();

    /**
     * @brief Sets last name of the customer.
     * 
     * @param lName 
     */
    void setLName(string lName);

    /**
     * @brief Returns ID Of the customer.
     * 
     * @return int 
     */
    int getID();

    /**
     * @brief Sets ID of the customer.
     * 
     * @param ID 
     */
    void setID(int ID);

    /**
     * @brief Get the Acc Status of customer.
     * 
     * @return STATUS 
     */
    STATUS getAccStatus();

    /**
     * @brief Set the Acc Status of customer.
     * 
     * @param accStatus 
     */
    void setAccStatus(STATUS accStatus);

    /**
     * @brief Get the List of the rented movies.
     * 
     * @return videoList& 
     */
    videoList& getRentedList();

    /**
     * @brief Displays the information of the customer.
     * 
     */
    void displayInfo();
};
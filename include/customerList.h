/**
 * @file customerList.h
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief Implements the class simulating the database for videoStore in the form of a linked list.
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include "CustomerInfo.h"

/**
 * @struct Customer
 * @brief Represents a node in the linked last for customerInfo. Contains the data of the customer and holds the pointer to the next node in the list.
 */
struct Customer
{
    /**
     * @brief Construct a new Customer node.
     * 
     */
    Customer() : next(NULL) {}
    /**
     * @brief parameterized constructor for Customer object.
     * 
     * @param customr 
     */
    Customer(CustomerInfo& customr) : cust(customr), next(NULL) {}
    
    Customer *next;    /**< Points to the next node in the linked list. */
    CustomerInfo cust; /**< Holds the data of the customer.*/
};

/**
 * @class customerList
 * @brief Maintains a linked list for customerInfo objects.Used later in videoStore to store the list of customers of the shop.
 * 
 */
class customerList
{
    Customer *head;   /**< Represents the head of the list, the first element of the list*/
    Customer *tail;   /**< Represents the tail of the list, the last element of the list*/

public:
    /**
     * @brief Construct a new customerList object. Both head and tail initialized to null to represent an empty list.
     * 
     */
    customerList();

    /**
     * @brief Get the Head of the list. Useful for methods outside the customerList class that need to access and traverse the customerList linked list.
     * 
     * @return Customer* 
     */
    Customer* getHead();

    /**
     * @brief Adds a Customer node to the list. That is, a new customer is added to the list via the method.
     * 
     * @param node new Customer node to add to the list.
     */
    void addCustomer(Customer *node);

    /**
     * @brief Searches for a particular customer in the list, and returns the index, at which they are present in the list. Returns -1 otherwise indicating that the customer is not present in the list.
     * 
     * @param ID ID of the customer that we are looking for in the list.
     * @return int 
     */
    int searchCustomer(int ID);

    /**
     * @brief Displays the list of the customers with their info such as name and ID.
     * 
     */
    void displaylist();

    /**
     * @brief Overloads [] operator to access any CustomerInfo object from the list via array indexing notation. Easier to use, and gets usede extensively inside the videoStore methods. Function is guaranteed to return an object always (since it is preceeded by a call to check if the object is in the list), therefore a reference is being used plus I was lazy.
     * 
     * @param ind Index of the Customer object in the list whose CustomerInfo object is required.
     * @return CustomerInfo& 
     */
    CustomerInfo& operator[](int ind);
};
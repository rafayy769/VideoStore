/**
 * @file customerList.cpp
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief Defines and implements the customerList class.
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "customerList.h"

customerList::customerList() : head(NULL), tail(NULL) {}
Customer *customerList::getHead() { return head; }

void customerList::addCustomer(Customer *node)
{
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = tail->next;
    }
}

int customerList::searchCustomer(int ID)
{
    Customer *temp = head;
    int count = 0;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->cust.getID() == ID)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

void customerList::displaylist()
{
    Customer *temp = head;
    while (temp != NULL)
    {
        temp->cust.displayInfo();
        temp = temp->next;
    }
}

CustomerInfo &customerList::operator[](int ind)
{
    Customer *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == ind)
        {
            return temp->cust;
        }
        temp = temp->next;
        i++;
    }
}
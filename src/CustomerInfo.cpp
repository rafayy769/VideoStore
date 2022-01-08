/**
 * @file CustomerInfo.cpp
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief CustomerInfo class is implemented.
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CustomerInfo.h"

CustomerInfo::CustomerInfo() : fName(""), lName(""), ID(0), accStatus(STATUS::CLEAR), numberOfRented(0) {}

int CustomerInfo::getNumberOfRented() { return numberOfRented; }

void CustomerInfo::setNumberOfRented(int x)
{
    numberOfRented = (x == 1 ? numberOfRented + 1 : numberOfRented - 1);
}
string CustomerInfo::getFName()
{
    return this->fName;
}
void CustomerInfo::setFName(string fName)
{
    this->fName = fName;
}
string CustomerInfo::getLName()
{
    return this->lName;
}
void CustomerInfo::setLName(string lName)
{
    this->lName = lName;
}
int CustomerInfo::getID()
{
    return this->ID;
}

void CustomerInfo::setID(int ID)
{
    this->ID = ID;
}
STATUS CustomerInfo::getAccStatus()
{
    return this->accStatus;
}
void CustomerInfo::setAccStatus(STATUS accStatus)
{
    this->accStatus = accStatus;
}

videoList &CustomerInfo::getRentedList() { return rented; }

void CustomerInfo::displayInfo()
{
    cout << "Customer name : " << fName << " " << lName << endl;
    cout << "Customer ID : " << ID << endl;
    cout << "";
}
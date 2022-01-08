/**
 * @file videoStore.cpp
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "videoStore.h"

videoStore::videoStore()
{
    currentTime.tsecs = time(0);
    revHead = NULL;
    revTail = NULL;
}

customerList &videoStore::getCustList() { return customers; }

videoList &videoStore::getVidList() { return moviesList; }

Time videoStore::getCurrentTime() { return currentTime; }

void videoStore::addRevenue(Revenue *node)
{
    if (revHead == NULL)
    {
        revHead = node;
        revTail = node;
    }
    else
    {
        revTail->next = node;
        revTail = revTail->next;
    }
}

void videoStore::updateTime()
{
    int t = currentTime.tsecs;
    t += (10 * 3600);
    currentTime.tsecs = (time_t)t;
}

void videoStore::addMovie()
{
    cin.ignore();
    string input = "";
    cout << "Enter title : ";
    getline(cin, input);
    convertToUppercase(input);
    int ind = moviesList.searchVideo(input);
    if (ind != -1)
    {
        cout << "The movie is already in the list." << endl;
        return;
    }
    else
    {
        string ptname, dirName;
        cout << "Enter Protagonist Name : ";
        getline(cin, ptname);
        convertToUppercase(ptname);
        cout << "Enter Director Name : ";
        getline(cin, dirName);
        convertToUppercase(dirName);
        cout << "Enter total copies : ";
        int copies;
        cin >> copies;
        VideoInfo newmovie(input, ptname, dirName, copies);
        Video *node = new Video(newmovie);
        moviesList.addVideo(node);
        cout << "New movie is created." << endl;
    }
}

void videoStore::addCustomers()
{
    CustomerInfo customer;
    string input;
    cout << "Enter first name : ";
    cin >> input;
    convertToUppercase(input);
    customer.setFName(input);
    cout << "Enter last name : ";
    cin >> input;
    convertToUppercase(input);
    customer.setLName(input);
    srand(time(0));
    int id;
    do
    {
        id = (rand() % 1000) + 2;
    } while (customers.searchCustomer(id) != -1);
    customer.setID(id);
    customer.displayInfo();
    Customer *node = new Customer(customer);
    customers.addCustomer(node);
    cout << "New customer created with ID " << id << endl;
}

void videoStore::showDetails(string title)
{
    int ind = moviesList.searchVideo(title);
    cout << endl;
    if (ind != -1)
    {
        moviesList[ind].displayDetails();
    }
    else
    {
        cout << "Movie not found in the database. Sorry we don't have this movie." << endl;
    }
    cout << endl;
}

bool videoStore::checkAvailability(string inptitle)
{
    int ind = moviesList.searchVideo(inptitle);
    if (ind != -1)
    {
        VideoInfo temp = moviesList[ind];
        if (temp.getAvailableCopies() > 0)
        {
            cout << "Yes, the movie is available for renting out. Total copies : " << temp.getTotalCopies() << ", Available copies : " << temp.getAvailableCopies() << endl;
            return true;
        }
        else
        {
            cout << "Sorry, all rented out. Checked out details are as follows." << endl;
            int totCopies = moviesList[ind].getTotalCopies();
            for (int i = 0; i < totCopies; i++)
            {
                cout << "The movie " << inptitle << " has been issued to the customer ID : " << moviesList[ind].getRentedCopies()[i].customerID << " due date and time to return on : ";
                moviesList[ind].getRentedCopies()[i].dueDate.print();
                cout << endl;
            }

            return false;
        }
    }
    else
    {
        cout << "Sorry, we don't have this movie." << endl;
        return false;
    }
}

void videoStore::rentToCustomer(int id, string title)
{
    int custInd = customers.searchCustomer(id);
    if (custInd == -1)
    {
        cout << "Cannot find the entered customer in the database. Failed to rent the movie." << endl;
        return;
    }
    int vidInd = moviesList.searchVideo(title);
    int avCopies = moviesList[vidInd].getAvailableCopies();
    int totCopies = moviesList[vidInd].getTotalCopies();
    if (avCopies == 0)
    {
        cout << "No available copy of the requested movie to rent :(" << endl;
        return;
    }

    moviesList[vidInd].setAvailableCopies(avCopies - 1);
    moviesList[vidInd].getRentedCopies()[totCopies - avCopies].customerID = id;
    moviesList[vidInd].getRentedCopies()[totCopies - avCopies].rentedON = currentTime;
    moviesList[vidInd].getRentedCopies()[totCopies - avCopies].dueDate = currentTime.getNextWeek();

    Video *node = new Video(moviesList[vidInd]);
    customers[custInd].getRentedList().addVideo(node);
    customers[custInd].setNumberOfRented(1);
    customers[custInd].setAccStatus(STATUS::RENTED);

    Revenue *revRent = new Revenue(currentTime, PRICE_PER_MOVIE);
    addRevenue(revRent);
    cout << "The movie " << title << " has been issued to the customer ID " << id << " on : ";
    currentTime.print();
    cout << " due date and time to return on : ";
    currentTime.getNextWeek().print();
}

void videoStore::returnMovie(int id, string title)
{
    int custInd = customers.searchCustomer(id);
    if (custInd == -1)
    {
        cout << "Cannot find the entered customer in the database." << endl;
        return;
    }

    int vidInd = moviesList.searchVideo(title);
    if (vidInd == -1)
    {
        cout << "The movie is not in the database." << endl;
        return;
    }
    int avCopies = moviesList[vidInd].getAvailableCopies();
    int totCopies = moviesList[vidInd].getTotalCopies();

    for (int i = 0; i < totCopies; i++)
    {
        if (moviesList[vidInd].getRentedCopies()[i].customerID == id)
        {
            Time dueDateTemp = moviesList[vidInd].getRentedCopies()[i].dueDate;
            if (currentTime > dueDateTemp)
            {
                cout << "Due Date and time was : ";
                dueDateTemp.print();
                cout << "\nThe current date and time is : ";
                currentTime.print();
                int overduefine = dueDateTemp.getDaysTill(currentTime) * FINE_PER_DAY;
                cout << "Your calculated fine is : " << overduefine << endl;
                Revenue *revRent = new Revenue;
                revRent->amount = overduefine;
                revRent->date = currentTime;
                revRent->next = NULL;
                addRevenue(revRent);
            }

            moviesList[vidInd].getRentedCopies()[i].customerID = 0;
            moviesList[vidInd].getRentedCopies()[i].dueDate = 0;
            moviesList[vidInd].getRentedCopies()[i].rentedON = 0;
            customers[custInd].getRentedList().removeVideo(title);
            customers[custInd].setNumberOfRented(-1);
            moviesList[vidInd].setAvailableCopies(avCopies + 1);
            if (customers[custInd].getNumberOfRented())
            {
                customers[custInd].setAccStatus(STATUS::CLEAR);
            }

            cout << "Movie returned." << endl;
            return;
        }
    }
    cout << "It seems like the movie " << title << " wasn't issue by customer ID : " << id << endl;
}

int videoStore::getOutStandingAmount()
{
    Video *temp = moviesList.getHead();
    int total = 0;
    while (temp != NULL)
    {
        int totCopies = temp->vid.getTotalCopies();
        for (int i = 0; i < totCopies; i++)
        {
            if (temp->vid.getRentedCopies()[i].customerID)
            {
                Time duedatetemp = temp->vid.getRentedCopies()[i].dueDate;
                if (currentTime > duedatetemp)
                {
                    int fine = duedatetemp.getDaysTill(currentTime) * FINE_PER_DAY;
                    total += fine;
                }
            }
        }
        temp = temp->next;
    }
    return total;
}

void videoStore::getRevenueGenerated()
{
    int mnth, date, year;
    cout << "Enter Starting date." << endl;
    cout << "Enter month number : ";
    cin >> mnth;
    cout << "Enter Date : ";
    cin >> date;
    cout << "Enter year : ";
    cin >> year;
    Time start(year, mnth, date);
    cout << "Enter Ending date." << endl;
    cout << "Enter month number : ";
    cin >> mnth;
    cout << "Enter Date : ";
    cin >> date;
    cout << "Enter year : ";
    cin >> year;
    Time end(year, mnth, date);

    Revenue *revtemp = revHead;
    while (revtemp != NULL)
    {
        if (revtemp->date >= start && revtemp->date <= end)
        {
            cout << "Revenue generated on ";
            revtemp->date.printDate();
            cout << " : " << revtemp->amount << endl;
        }
        revtemp = revtemp->next;
    }
}

void videoStore::deleteCasette(string title)
{
    int vidInd = moviesList.searchVideo(title);
    if (vidInd == -1)
    {
        cout << "Sorry this title doesn't exist." << endl;
    }
    else
    {
        if (moviesList[vidInd].getTotalCopies() > 0 && moviesList[vidInd].getAvailableCopies() > 0)
        {
            int totCopies = moviesList[vidInd].getTotalCopies();
            int avCopies = moviesList[vidInd].getAvailableCopies();
            moviesList[vidInd].setTotalCopies(totCopies - 1);
            moviesList[vidInd].setAvailableCopies(avCopies - 1);
            moviesList[vidInd].getRentedCopies().pop_back();
        }
        else if (moviesList[vidInd].getTotalCopies() == 0)
        {
            moviesList.removeVideo(title);
        }
        cout << "Successfully deleted a casette of " << title << " from the database." << endl;
    }
}
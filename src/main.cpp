/**
 * @file main.cpp
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief The file contains the main function, the starting point of the program. Employs all the classes and structs to simulate a video store with a minimal functionality.
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * @bug No known bugs
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Time.h"
#include "VideoInfo.h"
#include "videoList.h"
#include "CustomerInfo.h"
#include "customerList.h"
#include "videoStore.h"

using namespace std;

int main()
{
    srand(time(0));
    videoStore Store;
    int input;
    while (true)
    {
        system(CLEARCMD);
        cout << "System time : ";
        Store.getCurrentTime().print();
        cout << "\n\t\t _____________________________________________________________________ "
             << "\n\t\t|                                                                     |"
             << "\n\t\t| Select one of the following:                                        |"
             << "\n\t\t|      1.  Add new video ...........................................  |"
             << "\n\t\t|      2.  Add new customer ........................................  |"
             << "\n\t\t|      3.  Show the details of a particular video ..................  |"
             << "\n\t\t|      4.  To check whether the store carries a particular video ...  |"
             << "\n\t\t|      5.  Rent a video ............................................  |"
             << "\n\t\t|      6.  Return a video ..........................................  |"
             << "\n\t\t|      7.  Total videos at store ...................................  |"
             << "\n\t\t|      8.  Total checked out video record ..........................  |"
             << "\n\t\t|      9.  Total checked in video record ...........................  |"
             << "\n\t\t|      10. To search and print the list of movies of a particular ..  |"
             << "\n\t\t|          a. protagonist...........................................  |"
             << "\n\t\t|          b. director..............................................  |"
             << "\n\t\t|      11. Total revenue generated .................................  |"
             << "\n\t\t|      12. Total outstanding amount ................................  |"
             << "\n\t\t|      13. Delete video cassette ...................................  |"
             << "\n\t\t|      14. Print videos rented by a particular customer ............  |"
             << "\n\t\t|      15. Print the list of customers .............................  |"
             << "\n\t\t|      16. To exit .................................................  |"
             << "\n\t\t|_____________________________________________________________________|"
             << endl;
        while (true)
        {
            cout << "\nSelected option : ";
            cin >> input;
            if(!cin.fail())
            {
                break;
            }
            cin.clear();
            cin.ignore();
        }
        if (input == 1)
        {
            Store.addMovie();
        }
        else if (input == 2)
        {
            Store.addCustomers();
        }
        else if(input == 3)
        {
            cout << "Enter the title of the movie : ";
            string inp;
            cin.ignore();
            getline(cin, inp);
            convertToUppercase(inp);
            Store.showDetails(inp);
        }
        else if(input == 4)
        {
            cout << "Enter the title of the movie : ";
            string tempInp;
            cin.ignore();
            getline(cin, tempInp);
            convertToUppercase(tempInp);
            
            bool available = Store.checkAvailability(tempInp);
        }
        else if(input == 5)
        {
            cout << "Enter the title of the movie : ";
            string inp;
            cin.ignore();
            getline(cin, inp);
            convertToUppercase(inp);
            if(Store.checkAvailability(inp))
            {
                cout << "Enter ID of customer to rent it, or enter 1 to go back to main menu to add a new customer." << endl;
                cout << "Customer ID : ";
                int choice;
                cin >> choice;
                if(choice == 1)
                {
                    continue;
                }
                else
                {
                    Store.rentToCustomer(choice, inp);
                }
            }
        }
        else if (input == 6)
        {
            cout << "Enter title of the movie : ";
            string ttl;
            cin.ignore();
            getline(cin, ttl);
            convertToUppercase(ttl);
            cout << "Enter the customer ID : ";
            int x;
            cin >> x;
            Store.returnMovie(x, ttl);
        }
        else if (input == 7)
        {
            cout << "List of movies at store." << endl;
            Store.getVidList().printMovies(true);
        }
        else if (input == 8)
        {
            cout << "List of Movies (check out) : " << endl;
            Store.getVidList().printCheckedOut();

        }
        else if (input == 9)
        {
            cout << "List of Movies (check in) : " << endl;
            Store.getVidList().printCheckedInMovies();
        }
        else if (input == 10)
        {
            cout << "Press P for Protagonist, or D for Director : ";
            char x;
            cin >> x;
            x = toupper(x);
            string tempInput;
            cout << "Enter name : ";
            cin.ignore();
            getline(cin, tempInput);
            convertToUppercase(tempInput);
            Store.getVidList().searchParticular(tempInput, x);
        }
        else if (input == 11)
        {
            Store.getRevenueGenerated();
        }
        else if (input == 12)
        {
            cout << "The total outstanding amount till ";
            Store.getCurrentTime().printDate();
            cout << " is " << Store.getOutStandingAmount() << endl;
        }
        else if (input == 13)
        {
            cout << "Enter the title of the movie to remove : ";
            string temptitle;
            cin.ignore();
            getline(cin, temptitle);
            convertToUppercase(temptitle);
            Store.deleteCasette(temptitle);
        }
        else if (input == 14)
        {
            cout << "Enter customer ID : ";
            int x;
            cin >> x;

            int check = Store.getCustList().searchCustomer(x);
            if (check == -1)
            {
                cout << "Customer doesn't exist in the database." << endl;
            }
            else
            {
                Store.getCustList()[check].getRentedList().printMovies(true);    
            }
        }
        else if (input == 15)
        {
            Store.getCustList().displaylist();
        }
        else if(input == 16)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice :(" << endl;
        }

        Store.updateTime();
        bool tempflag = true;
        do
        {
            cout << "\nPress Y for the main menu, Press N to exit : ";
            char inp;
            cin >> inp;
            if (toupper(inp) == 'N')
            {
                return 0;
            }
            else if (toupper(inp) == 'Y')
            {
                tempflag = true;
            }
            else
            {
                tempflag = false;
            }
        } while (!tempflag);
    }
    return 0;
}
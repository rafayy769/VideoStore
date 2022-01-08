/**
 * @file videoList.cpp
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "videoList.h"

videoList::videoList() : head(NULL) {}
Video *videoList::getHead() { return head; }
void videoList::addVideo(Video *node)
{
    Video *temp = head;
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

int videoList::searchVideo(string title)
{
    Video *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->vid.getVideoTitle() == title)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

void videoList::removeVideo(string videotitle)
{
    Video *temp = head;
    if (head == NULL)
    {
        cout << "There are no movies in the list to remove." << endl;
        return;
    }
    else if (head->vid.getVideoTitle() == videotitle)
    {
        head = temp->next;
        delete temp;
        return;
    }
    else
    {
        Video *prev = NULL;
        while (temp != NULL)
        {
            if (temp->vid.getVideoTitle() == videotitle)
            {
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
}

VideoInfo &videoList::operator[](int ind)
{
    Video *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == ind)
        {
            return temp->vid;
        }
        i++;
        temp = temp->next;
    }
}

void videoList::printMovies(bool titlesOnly)
{
    Video *temp = head;
    while (temp != NULL)
    {
        if (titlesOnly)
        {
            cout << temp->vid.getVideoTitle() << endl;
        }
        else
        {
            temp->vid.displayDetails();
            cout << endl;
        }
        temp = temp->next;
    }
}

void videoList::printCheckedInMovies()
{
    Video *temp = head;
    while (temp != NULL)
    {
        if (temp->vid.getAvailableCopies() > 0)
        {
            cout << temp->vid.getVideoTitle() << endl;
        }
        temp = temp->next;
    }
}

void videoList::printCheckedOut()
{
    if (head == NULL)
    {
        return;
    }
    Video *temp = head;
    while (temp != NULL)
    {
        VideoInfo tempVid = temp->vid;
        vector<Rented> tempList = tempVid.getRentedCopies();
        for (int i = 0; i < tempVid.getTotalCopies(); i++)
        {
            if (tempList[i].customerID)
            {
                cout << "Title : " << tempVid.getVideoTitle() << "   Check out : ";
                tempList[i].rentedON.print();
                cout << ". Check in : ";
                tempList[i].dueDate.print();
                cout << endl;
            }
        }
        temp = temp->next;
    }
}

void videoList::searchParticular(string inpt, char param)
{
    Video *temp = head;
    bool found = false;
    if (param != 'P' && param != 'D')
    {
        cout << "Not a valid function parameter." << endl;
        return;
    }
    while (temp != NULL)
    {
        if (param == 'P')
        {
            if (temp->vid.getProtagonist() == inpt)
            {
                cout << temp->vid.getVideoTitle() << endl;
                found = true;
            }
        }
        else
        {
            if (temp->vid.getMovieDirector() == inpt)
            {
                cout << temp->vid.getVideoTitle() << endl;
                found = true;
            }
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << "Search returned 0 movies. No movie in the database." << endl;
    }
}
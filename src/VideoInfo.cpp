/**
 * @file VideoInfo.cpp
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief Implementation of VideoInfo class
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "VideoInfo.h"

VideoInfo::VideoInfo() : VideoTitle(""), protagonist(""), movieDirector(""), availableCopies(0), totalCopies(0) {}

VideoInfo::VideoInfo(string vt, string pt, string md, int tc) : VideoTitle(vt), protagonist(pt), movieDirector(md), availableCopies(tc), totalCopies(tc)
{
    for (int i = 0; i < tc; i++)
    {
        Rented temp;
        rentedCopies.push_back(temp);
    }
}

vector<Rented> &VideoInfo::getRentedCopies() { return rentedCopies; }

string VideoInfo::getVideoTitle() { return this->VideoTitle; }

void VideoInfo::setVideoTitle(string VideoTitle)
{
    this->VideoTitle = VideoTitle;
}

string VideoInfo::getProtagonist()
{
    return this->protagonist;
}

void VideoInfo::setProtagonist(string protagonist)
{
    this->protagonist = protagonist;
}
string VideoInfo::getMovieDirector()
{
    return this->movieDirector;
}
void VideoInfo::setMovieDirector(string movieDirector)
{
    this->movieDirector = movieDirector;
}
int VideoInfo::getTotalCopies()
{
    return this->totalCopies;
}
void VideoInfo::setTotalCopies(int totalCopies)
{
    this->totalCopies = totalCopies;
}

int VideoInfo::getAvailableCopies()
{
    return this->availableCopies;
}
void VideoInfo::setAvailableCopies(int copies)
{
    this->availableCopies = copies;
}

void VideoInfo::displayDetails()
{
    cout << "Movie title      : " << VideoTitle << endl;
    cout << "Protagonist      : " << protagonist << endl;
    cout << "Movie Director   : " << movieDirector << endl;
    cout << "Available copies : " << availableCopies << endl;
    cout << "Total copies     : " << totalCopies << endl;
}

void VideoInfo::numberOfCopies()
{
    cout << "Available copies : " << availableCopies << endl;
    cout << "Total copies     : " << totalCopies << endl;
}

void VideoInfo::operator=(const VideoInfo &vi)
{
    this->VideoTitle = vi.VideoTitle;
    this->protagonist = vi.protagonist;
    this->availableCopies = vi.availableCopies;
    this->totalCopies = vi.totalCopies;
    this->movieDirector = vi.movieDirector;
}
/**
 * @file VideoInfo.h
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief Contains the definition of the class VideoInfo which is abstraction of a movie.
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "Time.h"
#include <vector>

/**
 * @struct Rented
 * @brief A struct to hold info about when and who rented a particular movie. 
 * An array of Rented is used inside VideoInfo to keep track of which copies of a particular movie have been rented out.
 */
struct Rented
{
    Time rentedON;  /**< The time at which the movie was rented. */
    Time dueDate;   /**< The time at which the movie is due. It is one week away from the time at which it was rented on. */
    int customerID; /**< ID of the customer who rented out the copy. */

    /**
     * @brief Construct a new empty Rented object. A null customerID indicates the copy is not rented since all IDs are greater than 1.
     * 
     */
    Rented() : customerID(0), rentedON(0), dueDate(0) {}
};

/**
 * @class VideoInfo
 * @brief Represents a movie present in the store.
 * 
 * Stores necessary information about the movie itself, such as the title, director name etc. and also stores the information about the total number of copies and available number of copies.
 * 
 */
class VideoInfo
{
    string VideoTitle;            /**< Stores the title of the movie.*/
    string protagonist;           /**< Stores the name of the actor who plays the protagonist.*/
    string movieDirector;         /**< Stores the name of the director of the movie.*/
    int availableCopies;          /**< Stores the total number of copies available of movie.*/
    int totalCopies;              /**< Stores the total number of copies of movie at the store.*/
    vector<Rented> rentedCopies;  /**< Stores info such as who rented a copy and when. The vector is initialized with the total number of copies available and each element is of type Rented and stores the necessary information. */
public:

    /**
     * @brief Construct a new empty VideoInfo object
     * 
     */
    VideoInfo();

    /**
     * @brief Parameterized constructor for VideoInfo object.
     * 
     * @param vt Video title
     * @param pt Protagonist name
     * @param md Movie director name
     * @param tc Total copies of the movie
     */
    VideoInfo(string vt, string pt, string md, int tc);

    /**
     * @brief Get the rentedCopies vector
     * 
     * @return vector<Rented>& 
     */
    vector<Rented>& getRentedCopies();
    
    /**
     * @brief Get the Video Title.
     * 
     * @return string 
     */
    string getVideoTitle();

    /**
     * @brief Set the VideoTitle of the movie.
     * 
     * @param VideoTitle 
     */
    void setVideoTitle(string VideoTitle);

    /**
     * @brief Get the Protagonist actor name of the movie.
     * 
     * @return string 
     */
    string getProtagonist();

    /**
     * @brief Set the Protagonist actor name.
     * 
     * @param protagonist 
     */
    void setProtagonist(string protagonist);

    /**
     * @brief Get the Movie Director name.
     * 
     * @return string 
     */
    string getMovieDirector();

    /**
     * @brief Set the Movie Director name.
     * 
     * @param movieDirector 
     */
    void setMovieDirector(string movieDirector);

    /**
     * @brief Get the Total Copies available of movie.
     * 
     * @return int 
     */
    int getTotalCopies();

    /**
     * @brief Set the Total Copies of the movie.
     * 
     * @param totalCopies 
     */
    void setTotalCopies(int totalCopies);

    /**
     * @brief Get the Available Copies of the movie.
     * 
     * @return int 
     */
    int getAvailableCopies();

    /**
     * @brief Set the Available Copies of the movie.
     * 
     * @param copies 
     */
    void setAvailableCopies(int copies);

    /**
     * @brief Display details of the movie to the console.
     * 
     */
    void displayDetails();

    /**
     * @brief Displays the available and total number of copies of movie to the console.
     * 
     */
    void numberOfCopies();

    /**
     * @brief Assignment operator for VideoInfo object.
     * Copies all the member variables of VideoInfo object vi to this object.
     * 
     * @param vi VideoInfo object to be copied
     */
    void operator=(const VideoInfo &vi);
};
/**
 * @file videoList.h
 * @author Abdul Rafay (24100173@lums.edu.pk)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "VideoInfo.h"

/**
 * @struct Video
 * @brief Represents a node for the linked list that will store VideoInfo objects. Used to construct a linked list of VideoInfo objects.
 * 
 */
struct Video
{
    /**
     * @brief Construct a new Video object.
     * The next pointer is set to NULL since it is not pointing to anything initially.
     * 
     */
    Video()
    {
        next = NULL;
    }
    /**
     * @brief Parameterized constructor for Video object
     * 
     * @param mov 
     */
    Video(VideoInfo& mov) : vid(mov), next(NULL) {}
    VideoInfo vid;        /**< Stores the data of the node.*/
    Video *next;          /**< Points to the next node in the linked list. */
};

/**
 * @class videoList
 * @brief Maintains the linked list where each node is a Video object. 
 * A list to hold all the movies. This is done via linked list data structure of VideoInfo objects. Implements necessary relevant methods as well.
 * 
 */
class videoList
{
    Video *head;     /**< Holds the head, or the first element of the list.*/
public:
    /**
     * @brief Construct a new empty videoList object. The head is set to NULL implying there is no object in the list.
     * 
     */
    videoList();
    
    /**
     * @brief Get the head node of the list. Useful to access the list outside of the videoList class. Access only given to head and the list can be traversed through once head is known.
     * 
     * @return Video* 
     */
    Video* getHead();

    /**
     * @brief Add a movie/Video node to the linked list.
     * 
     * @param node 
     */
    void addVideo(Video *node);

    /**
     * @brief Search for a specific title in the list and return its index.
     * Since there's only one movie stored with a particular title, the index, i.e. at what point in the list is the relevant node stored should be unique and is returned.
     * 
     * @param title Title of the movie that is being searched.
     * @return int Index of the movie in the list.
     */
    int searchVideo(string title);
    
    /**
     * @brief Remove a particular movie from the list using its title. Traverses through the list to find that particular node and removes that.
     * 
     * @param videotitle 
     */
    void removeVideo(string videotitle);

    /**
     * @brief Returns the videoInfo reference from the list. Overloading operator[] to use it just like the arrays, i.e. accessing a particular element from list using its index. Useful later in the videoStore to easily access the list elements instead of traversing through it again and again using while loop syntax. Function is guaranteed to return an object always (since it is preceeded by a call to check if the object is in the list), therefore a reference is being used plus I was lazy. 
     * 
     * @param ind Index of the object required in the list.
     * @return VideoInfo& 
     */
    VideoInfo& operator[](int ind);

    /**
     * @brief Prints all the movies in the list.
     * The param titlesOnly controls whether all the details are displayed or just the titles of the movies.
     * 
     * @param titlesOnly Set to true if only the titles of the movies are required, otherwise false.
     */
    void printMovies(bool titlesOnly);

    /**
     * @brief Prints all the movies that have been checked in, i.e. all the movies in the store whose availableCopies is more than 1. One of the core functionalities of the videoStore.
     * 
     */
    void printCheckedInMovies();

    /**
     * @brief Prints all the movies that have been checked out. That is, all those movies whose availableCopies is less than the total number of copies at the store.
     * 
     */
    void printCheckedOut();

    /**
     * @brief Searches the list for the movies from a particular director or actor. 
     * The parameter param controls whether to look for movies from a particular actor or a particular director.
     * 
     * @param inpt Stores the director or the protagonist name depending upon the param.
     * @param param 'P' for protagonist and 'D' to look for directors.
     */
    void searchParticular(string inpt, char param);
};
/**
 * @file Library.h
 * @author Vance Brenderabrandis + Jacqueline Bybee
 * @date 2022-10-27
 * @brief Header file for the Library class
 * 
 * Header file which holds all the declared methods for the Library class
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Movie.h"
#include <list>


/**
 * Library class that uses an internal linked list to manage Movie Collection
 *
 * @class Library Library.h "Movie-Collection/Library.h"
 * @brief Library class
 *
 */
class Library {
 private:
  std::list<Movie> collection; // Our standard-linked list which we use to actually manage our movie collection
  
 public:

/**
 * Adds a new element to the front of the Collection linked list (not used)
 *
 * @param Movie m Movie "node" to push to the front
 * @return Returns nothing, Only adds a Movie "node" to front of Collection LL
 * @post New Movie node is pushed to front of list
 * 
 */
  void push_front(Movie m);

/**
 * Adds a new node to the end of the Collection LL
 *
 * @param Movie m Movie node to push to the back
 * @return Returns nothing, only adds a Movie node to back of Collection LL
 * @post New Movie Node is pushed to back of List
 * 
 */
  void push_back(Movie m);

/**
 * Inserts a node sorted alphabetically by Title name
 *
 * @param Movie m Movie node to be added
 * @return Returns nothing, only adds a movie node to the list
 * @post New movie node is pushed to the list, sorted alphabetically by Title name
 * 
 */
  void insert_sorted(Movie m);

/**
 * Reads in a user-selected file of Movies into the Library collection LL *sorted by title name*
 *
 * @param std::string fileName Name of the file to be read in
 * @return Returns nothing, only populates Collection list with file-read data
 * @post Collection will be populated with data from user file
 * 
 */
  void readFile(std::string fileName);

/**
 * Program prints data on all movies with the inputted Title
 *
 * @param std::string movieTitle Title of the movie(s) the user wants data on
 * @return Returns nothing, only prints data on desired movie(s)
 * 
 */
  void findMovie(std::string movieTitle);

/**
 * Program prints data on all movies with the inputted Director
 *
 * @param std::string directorName Name of the Director the user wants movie data from
 * @return Returns nothing, only prints data about movies the Director made
 * 
 */
  void directorSearch(std::string directorName);

/**
 * Deletes all movies with the inputted Movie Title
 *
 * @param std::string movieTitle Title of the movie(s) the program will delete from the collection 
 * @return Returns nothing, only deletes movies from Collection
 * @post All movies with the inputted title will be removed from the Collection
 * 
 */
  void deleteMovie(std::string movieTitle);

/**
 * Prints data from all Movies in the Collection
 *
 * @return void Returns nothing, only prints data
 * 
 */
  void printCollection();

/**
 * Outputs the contents of the Collection to a user-designated file
 *
 * @param std::string filename Name the user wants to output the Movie collection to
 * @return Returns nothing, only outputs data to file
 * @post A new file will be created with the data from the Collection LL. Can be read in using readFile()
 * 
 */
  void outputCollection(std::string filename);
};


#endif //LIBRARY_H

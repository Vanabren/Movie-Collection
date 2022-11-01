/**
 * @file Library.h
 * @author Vance Brenderabrandis
 * @date 2022-10-27
 * @brief later
 * 
 * later
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Movie.h"
#include <list>

class Library {
 private:
  std::list<Movie> collection;
  
 public:
  void push_front(Movie m);
  void push_back(Movie m);
  void insert_sorted(Movie m);
  void readFile(std::string fileName);
  void findMovie(std::string movieTitle);
  void directorSearch(std::string directorName);
  void deleteMovie(std::string movieTitle);
  void printCollection();
  void outputCollection(std::string filename);
};


#endif //LIBRARY_H

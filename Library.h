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

#include <list>
#include "Movie.h"

class Library {
 private:
  std::list<Movie> collection;
  
 public:
  Library();
  void push_front(Movie m);
  void push_back(Movie m);
  void insert_sorted(Movie m);
  void readFile(std::string fileName);
  std::string findMovie(std::string movieTitle);
  string directorSearch(std::string directorName);
  void deleteMovie(std::string movieTitle);
};


#endif //LIBRARY_H

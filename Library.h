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
  std::list<movie> collection;
  
 public:
  Library();
  readFile(std::string fileName);
  findMovie(std::string movieTitle);
  directorSearch(std::string directorName);
  deleteMovie(std::string movieTitle);
  

};


#endif //LIBRARY_H

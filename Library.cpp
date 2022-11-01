/**
 * @file Library.cpp
 * @author Vance Brenderabrandis
 * @date 2022-10-27
 * @brief later
 * 
 * later
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Library.h"
#include "Movie.h"

using namespace std;


void Library::push_front(Movie m) {
  collection.push_front(m);
}

void Library::push_back(Movie m) {
  collection.push_back(m);
}

void Library::insert_sorted(Movie m) {
  if(collection.size == 0) {
    collection.push_back(m);
    return;
  }
  
  list<movie>::iterator it;
  for(it = collection.begin(); it != collection.end(); it++) {
    if(m.title < *it.title) {
      collection.insert(it, m);
      return;
    }
  }
}

void Library::readFile(string fileName) {

}

string Library::findMovie(string movieTitle) {

}

string Library::directorSearch(string directorName) {

}

void Library::deleteMovie(string movieTitle) {

}

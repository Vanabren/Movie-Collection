/**
 * @file Library.cpp
 * @author Vance Brenderabrandis + Jacqueline Bybee
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
  ifstream fin;
  fin.open(fileName);

  Movie temp;

  fin >> temp.title; // priming read
  while(fin) {
    fin >> temp.directorName;
    fin >> temp.movieRuntime;
    fin >> temp.price;
    fin >> temp.year;
    
    collection.insert_sorted(temp);

    fin >> temp.title;
  }

  fin.close();
}

string Library::findMovie(string movieTitle) {
  if(collection.size == 0) {
    cout << "No movies in collection!\n";
    return;
  }
  
  list<movie>::iterator it;
  int i = 1; // Starting from 1 for however many movies were found
  int moviesFound = 0; // Needed to check if any movies were even found 
  for(it = collection.begin(); it != collection.end(); it++) {
    if(movieTitle == *it.title) {
      cout << "Movie " << i << ": ";
      cout << " Title: " << movieTitle << "\n"; // Prints title
      cout << " Director: " << *it.directorName << "\n"; // Prints director's name
      cout << " Runtime: " << *it.movieRuntime << "\n"; // Prints movie's runtime
      cout << " Format: " << *it.format << "\n"; // Prints device needed to watch movie
      cout << " Price: " << *it.price << "\n";
      cout << " Year Released: " << *it.year << "\n";
      moviesFound++;
    }
    i++;
  }
  if(moviesFound == 0) {
    cout << "No movies with that title found!\n";
  }
}

string Library::directorSearch(string directorName) {
  if(collection.size == 0) {
    cout << "No movies in collection!\n";
    return;
  }
  
  list<movie>::iterator it;
  int i = 1; // Starting from 1 for however many movies were found
  int moviesFound = 0; // Needed to check if any movies were even found 
  for(it = collection.begin(); it != collection.end(); it++) {
    if(directorName == *it.directorName) {
      cout << "Movie " << i << ": ";
      cout << " Title: " << movieTitle << "\n"; // Title
      cout << " Director: " << *it.directorName << "\n"; // Director Name
      cout << " Runtime: " << *it.movieRuntime << "\n"; // Runtime
      cout << " Format: " << *it.format << "\n"; // Device needed to watch
      cout << " Price: " << *it.price << "\n"; // Price
      cout << " Year Released: " << *it.year << "\n"; // YR released
      moviesFound++;
    }
    i++;
  }
  if(moviesFound == 0) {
    cout << "No movies with that director found!\n";
  }
}

void Library::deleteMovie(string movieTitle) {
  if(collection.size() == 0) {
    cout << "No movies in collection!\n";
    return;
  }

  moviesDeleted = 0;
  for(it = collection.begin(); it != collection.end(); it++) {
    if(movieTitle == *it.title) {
      collection.erase(it); // obliterates the element the iterator is pointing to
      moviesDeleted++;
    }
  }
  if(moviesDeleted == 0) {
    cout << "No movie(s) found with that title!\n";
  }
}

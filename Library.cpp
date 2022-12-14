/**
 * @file Library.cpp
 * @author Vance Brenderabrandis + Jacqueline Bybee
 * @date 2022-10-27
 * @brief Implementation of the Library class' methods
 * 
 * Holds implementation and logic for the Library class' methods in use of the Movie Collection program
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
  if(collection.size() == 0) {
    collection.push_back(m);
    return;
  }
  
  list<Movie>::iterator it;
  for(it = collection.begin(); it != collection.end(); it++) {
    if(m.title < it->title) {
      collection.insert(it, m); // insert inserts new node right before the iterator
      return;
    }
  }
  collection.push_back(m);
}

void Library::readFile(string fileName) {
  ifstream fin;
  fin.open(fileName);

  Movie temp;
  string garbage; // to eat garbage data
  
  getline(fin, garbage, ':'); // eats :
  getline(fin, garbage, ' '); // eats the " " in front of the title
  
  getline(fin, temp.title, ' '); // priming read
  while(fin) {
    getline(fin, garbage, ':');
    getline(fin, garbage, ' ');
    getline(fin, temp.directorName, ' ');
    
    getline(fin, garbage, ':');
    getline(fin, garbage, ' ');
    fin >> temp.movieRuntime;
    
    getline(fin, garbage, ':');
    getline(fin, garbage, ' ');
    fin >> temp.format;
    
    getline(fin, garbage, ':');
    getline(fin, garbage, ' ');
    fin >> temp.price;
    
    getline(fin, garbage, ':');
    getline(fin, garbage, ' ');
    fin >> temp.year;
    
    push_back(temp);
    
    getline(fin, garbage, '\n');
    getline(fin, garbage, ':');
    getline(fin, garbage, ' ');
    getline(fin, temp.title, ' ');
  }

  fin.close();
}

void Library::findMovie(string movieTitle) {
  if(collection.size() == 0) {
    cout << "No movies in collection!\n";
    return;
  }
  
  list<Movie>::iterator it;
  int i = 1; // Starting from 1 for however many movies were found
  int moviesFound = 0; // Needed to check if any movies were even found 
  for(it = collection.begin(); it != collection.end(); it++) {
    if(movieTitle == it->title) {
      cout << "Movie " << i << ":\n";
      cout << " Title: " << movieTitle << "\n"; // Prints title
      cout << " Director: " << it->directorName << "\n"; // Prints director's name
      cout << " Runtime: " << it->movieRuntime << "\n"; // Prints movie's runtime
      cout << " Format: " << it->format << "\n"; // Prints device needed to watch movie
      cout << " Price: " << it->price << "\n";
      cout << " Year Released: " << it->year << "\n";
      moviesFound++;
    }
    i++;
  }
  if(moviesFound == 0) {
    cout << "No movies with that title found!\n";
  }
}

void Library::directorSearch(string directorName) {
  if(collection.size() == 0) {
    cout << "No movies in collection!\n";
    return;
  }
  
  list<Movie>::iterator it;
  int i = 1; // Starting from 1 for however many movies were found
  int moviesFound = 0; // Needed to check if any movies were even found 
  for(it = collection.begin(); it != collection.end(); it++) {
    if(directorName == it->directorName) {
      cout << "Movie " << i << ":\n";
      cout << " Title: " << it->title << "\n"; // Title
      cout << " Director: " << it->directorName << "\n"; // Director Name
      cout << " Runtime: " << it->movieRuntime << "\n"; // Runtime
      cout << " Format: " << it->format << "\n"; // Device needed to watch
      cout << " Price: " << it->price << "\n"; // Price
      cout << " Year Released: " << it->year << "\n"; // YR released
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
    cout << "No movies in collection!\n\n";
    return;
  }

  int moviesDeleted = 0;
  
  list<Movie>::iterator it;
  for(it = collection.begin(); it != collection.end(); it++) {
    if(movieTitle == it->title) {
      it = collection.erase(it); // obliterates the element the iterator is pointing to
      moviesDeleted++;
    }
  }
  if(moviesDeleted == 0) {
    cout << "No movie(s) found with that title!\n\n";
    return;
  }
  cout << "Movies have been deleted\n\n";
}

void Library::printCollection() {
  if(collection.size() == 0) {
    cout << "No movies in collection!\n";
    return;
  }

  list<Movie>::iterator it;
  int numMovies = 1;
  for(it = collection.begin(); it != collection.end(); it++) {
    cout << "Movie " << numMovies << ": \n";
    cout << " Title: " << it->title << "\n";
    cout << " Director: " << it->directorName << "\n"; // Director Name
    cout << " Runtime: " << it->movieRuntime << "\n"; // Runtime
    cout << " Format: " << it->format << "\n"; // Device needed to watch
    cout << " Price: " << setprecision(2) << fixed << it->price << "\n"; // Price
    cout << " Year Released: " << it->year << "\n"; // YR released
    cout << endl;
    numMovies++;
  }
}

void Library::outputCollection(string filename) { // must be same format as read function
  ofstream fout;
  fout.open(filename);

  if(collection.size() == 0) {
    fout.close();
    return;
  }

  list<Movie>::iterator it;
  for(it = collection.begin(); it != collection.end(); it++) {
    fout << "| Title: " << it->title << " | Director: " << it->directorName
         << " | Runtime: " << it->movieRuntime << " | Format: " << it->format
         << " | Price: " << it->price << " | Year Released: " << it->year << " |\n";
  }
  cout << "File successfully outputted!\n";
}

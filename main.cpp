/**
 * @file main.cpp
 * @author Vance Brenderabrandis + Jacqueline Bybee
 * @date 2022-10-27
 * @brief later
 * 
 * later
 */

#include <iostream>
#include <string>
#include "Library.h"
#include "Movie.h"

using namespace std;

void readDatabase(Library& l);
void addMovie(Library& l);
void removeMovie(Library& l);
void searchTitle(Library& l);
void searchDirector(Library& l);
void printCollection(Library& l);
void outputCollection(Library& l);

/**
 * Driver for Movie Collection program
 * 
 */
int main() {
  cout << "Welcome to the Movie Collection Program.\n";

  Library movies;
  
  int choice = 10;
  while(choice != 0) {
    cout << "Please choose one of the options:\n";
    cout << " 1: Add a movie to your collection\n";
    cout << " 2: Remove a movie from your collection\n";
    cout << " 3: Find movies based on their Title\n";
    cout << " 4: Find movies based on their Director\n";
    cout << " 5: Print your collection to the console\n";
    cout << " 6: Read a collection in from a file\n";
    cout << " 7: Output your collection to a file\n";
    cout << " 0 to exit\n";

    cin >> choice;

    if(choice == 1) {
      addMovie(movies);
    }
    else if(choice == 2) {
      removeMovie(movies);
    }
    else if(choice == 3) {
      searchTitle(movies);
    }
    else if(choice == 4) {
      searchDirector(movies);
    }
    else if(choice == 5) {
      printCollection(movies);
    }
    else if(choice == 6) {
      readDatabase(movies);
    }
    else if(choice == 7) {
      outputCollection(movies);
    }
    else if(choice == 0) {
      cout << "Have a nice day.\n";
    }
    else {
      cout << choice << " is not an option. Please try again.\n";
    }
  }
  
  return 0;
}


void readDatabase(Library& l) {
  string filename;
  cout << "What is the name of the file you wish to read in (please add file extension):\n";
  cin >> filename;

  cout << "Reading in " << filename << "\n";
  l.readFile(filename);
}

void addMovie(Library& l) {
  Movie temp;
  cout << "What is the title of the movie: ";
  getline(cin >> ws, temp.title);
  cout << "\nWhat is the name of the director: ";
  getline(cin >> ws, temp.directorName);
  cout << "\nWhat is the runtime of the movie (in minutes): ";
  cin >> temp.movieRuntime;
  cout << "\nWhat format is the movie watched in (Digital, DVD, Blu-ray, or VHS): ";
  cin >> temp.format;
  cout << "\nWhat is the price of the movie (e.g 5.67): ";
  cin >> temp.price;
  cout << "\nWhat year was the movie released: ";
  cin >> temp.year;

  l.insert_sorted(temp);

  cout << "\nNew movie has been added to the collection!\n";
}

void removeMovie(Library& l) {
  string movie;
  
  cout << "What is the name of the movie you wish to remove from your collection: ";
  getline(cin >> ws, movie);
  
  cout << "\nRemoving movie... ";
  
  l.deleteMovie(movie);
  
  cout << "Success!\n";
}

void searchTitle(Library& l) {
  string movie;
  
  cout << "What is the title of the movie(s) you wish to search for: ";
  getline(cin >> ws, movie);

  cout << "\nSearching...\n";
  l.findMovie(movie);
}

void searchDirector(Library& l) {
  string director;

  cout << "What is the name of the director whose movies you wish to search for: ";
  getline(cin >> ws, director);

  cout << "\nSearching...\n";
  l.directorSearch(director);
}

void printCollection(Library& l) {
  cout << "Printing collection:\n";
  l.printCollection();
}

void outputCollection(Library& l) {
  string fileout;
  cout << "What is the name of the file you wish to output your collection to (include file extensions):\n";
  cin >> fileout;

  cout << "Outputting...\n";
  l.outputCollection(fileout);
  cout << "Success!\n";
}

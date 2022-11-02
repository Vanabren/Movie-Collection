/**
 * @file main.cpp
 * @author Vance Brenderabrandis + Jacqueline Bybee
 * @date 2022-10-27
 * @brief Main driver for Movie Collection Program
 * 
 * Main serves to guide the user in full usage of the Movie Collection program and 
 * create their own collection in which to do various commands with.
 */

#include <iostream>
#include <string>
#include "Library.h"
#include "Movie.h"

using namespace std;


/**
 * Reads in a file of the user's choice to read into their collection
 *
 * @param Library& l The main library used throughout the program passed as a reference
 * @return Returns nothing, only reads in data from file (if file exists) into collection in sorted order
 * @post Library will be populated with data
 * 
 */
void readDatabase(Library& l);

/**
 * Allows the user to add a movie of their choice to the collection. Sorts by Title
 *
 * @param Library& l The main library used throughout the program passed as a reference
 * @return void Returns nothing, only adds a Movie to the Library
 * @post A new movie has been sorted into the user's Collection
 * 
 */
void addMovie(Library& l);

/**
 * Allows user to search for a movie(s) by title to remove from Collection
 *
 * @param Library& l The main library used throughout the program passed as a reference
 * @return void Returns nothing, only removes designated Movie (if it exists)
 * @post Movie(s) has been removed from the Library
 * 
 */
void removeMovie(Library& l);

/**
 * Allows the user to search for a Movie's title and print the details of all movies with that title
 *
 * @param Library& l The main library used throughout the program passed as a reference
 * @return void Returns nothing, only prints details of searched-for movie (if it exists)
 * @post Details are printed to screen
 * 
 */
void searchTitle(Library& l);

/**
 * Allows the user to search for a Director and prints the details of all movies by that Director
 *
 * @param Library& l The mian library used throughout the program passed as a reference
 * @return void Returns nothing, only prints data to screen
 * @post Details are printed to screen
 * 
 */
void searchDirector(Library& l);

/**
 * Prints contents of collection to screen in formatted manner
 *
 * @param Library& l Main library used throughout the program passed as a reference
 * @return void Returns nothing, only prints contents of Library's collection to screen
 * @post Details of Library are printed to screen
 * 
 */
void printCollection(Library& l);

/**
 * Allows the user to output contents of collection to a file of their choice
 *
 * @param Library& l The main library used throughout the program passed as reference
 * @return void Returns nothing, only outputs contents of collection to file
 * @post New file is created with contents of Collection. Can be read in as input file.
 * 
 */
void outputCollection(Library& l);

/**
 * Driver for Movie Collection program
 * 
 */
int main() {
  cout << "Welcome to the Movie Collection Program.\n\n";

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
    cout << " 0: Exit Program\n\n";

    cout << "What do you wish to do: ";
    cin >> choice;
    cout << endl;

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
      cout << choice << " is not an option. Please try again.\n\n";
    }
  }
  
  return 0;
}


void readDatabase(Library& l) {
  string filename;
  cout << "What is the name of the file you wish to read in (please add file extension):\n";
  cin >> filename;
  cout << endl;

  cout << "Reading in " << filename << "\n";
  l.readFile(filename);
  cout << "Success!\n\n";
}

void addMovie(Library& l) {
  Movie temp; // Temp Movie struct to pass to method
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

  cout << "\nNew movie has been added to the collection!\n\n";
}

void removeMovie(Library& l) {
  string movie; // Name of movie(s) to search for and delete
  
  cout << "What is the name of the movie you wish to remove from your collection: ";
  getline(cin >> ws, movie);
  
  cout << "\nRemoving movie...\n";
  
  l.deleteMovie(movie);
}

void searchTitle(Library& l) {
  string movie; // Name of movies to search for and print details for
  
  cout << "What is the title of the movie(s) you wish to search for: ";
  getline(cin >> ws, movie);

  cout << "\nSearching...\n";
  l.findMovie(movie);
  cout << endl;
}

void searchDirector(Library& l) {
  string director;

  cout << "What is the name of the director whose movies you wish to search for: ";
  getline(cin >> ws, director);

  cout << "\nSearching...\n";
  l.directorSearch(director);
  cout << endl;
}

void printCollection(Library& l) {
  cout << "Printing collection:\n";
  l.printCollection();
  cout << endl;
}

void outputCollection(Library& l) {
  string fileout; // name of the file to output contents of Library to
  cout << "What is the name of the file you wish to output your collection to (include file extensions):\n";
  cin >> fileout;

  cout << "Outputting...\n";
  l.outputCollection(fileout);
  cout << "Success!\n\n";
}

/**
 * @file main.cpp
 * @author Vance Brenderabrandis
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

void readDatabase();
void addMovie();
void removeMovie();
void searchTitle();
void searchDirector();
void printCollection();
void outputCollection();

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
    cout << " 0 to exit\n"

    if(choice == 1) {
      
    }
    else if(choice == 2) {

    }
    else if(choice == 3) {

    }
    else if(choice == 4) {

    }
    else if(choice == 5) {

    }
    else if(choice == 6) {

    }
    else if(choice == 0) {
      cout << "Have a nice day.\n"
    }
    else {
      cout << choice << " is not an option. Please try again.\n";
    }
  }
  
  return 0;
}


void readDatabase() {

}

void addMovie() {
  Movie add;
  
}

void removeMovie() {

}

void searchTitle() {

}

void searchDirector() {

}

void printCollection() {

}

void outputCollection() {

}

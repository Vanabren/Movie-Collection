/**
 * @file Movie.h
 * @author Vance Brenderabrandis + Jacqueline Bybee
 * @date 2022-10-31
 * @brief Declaration of the Movie struct
 * 
 * Declares the Movie struct which serves as nodes for our Library's collection stl::linked list
 */

#ifndef MOVIE_H
#define MOVIE_H


/**
 * Movie struct which holds all relevant info for movies in our collection
 *
 * @class Movie Movie.h "Movie-Collection/Movie.h"
 * @brief Movie struct with relevant info for movies
 *
 */
struct Movie {
  std::string title;
  std::string directorName;
  int movieRuntime;
  std::string format;
  float price;
  int year;
};

#endif //MOVIE_H

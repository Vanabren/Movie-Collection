# Movie Collection

## Usage:
* The program makes use of a Standard Library Linked List and structs named "Movie" as nodes to simulate a movie collection. Some options include: Adding movies, removing movies, searching based on Movie title or director, outputting the Collection to a file (that can be read back in if the user wants), and more.
* As a side note, collections that are outputted from the program can be read in vice-versa.

## Required Files
* Library.h/.cpp
  - The headerfile and implementation of the Library Class
  
* Movie.h
  - The headerfile / declaration of the Movie struct, which holds all information the movies have such as title, director, price, etc.
  
* main.cpp
  - The driver for the Movie Collection program. Guides users through a series of choices to curate, print contents, and do other various actions with the movie collection.
  
* Makefile
  - Utility used to compile movie collection program from the source code listed above. Creates an executable called *movie*.

## Compilation Instructions
* To compile the code, use the **make** command within the terminal from the working directory where you placed the source files, which will create a useable executable called *movie*.

## Notes
* Limitations:
  - Input file must be formatted properly, or else the read function will fail.
  - When adding a movie into the collection or reading in from a file, spaces for movie titles and director names must be replaced with an underscore '_'. This is because, when reading in files, the read function uses a getline() to get the full name / title and stopping at a '|' (which is how we structured our file). This isn't necessarily a problem for functionality, but when printing the contents of the collection, it can look a little ugly. Of course, the problem doesn't exist for movies with a single word as a title (e.g. Psycho), but that is very rarely the case for most movies. 
  
* Design Choices:
  - We added the push_front() and push_back() methods for our Library class, but neither are used *from main*. When the Library's collection LL has no contents, a push_back() is used to add an initial Movie node, but past that, it isn't used anymore. We leave them as private because, if the user somehow managed to use it, it would mess up the sorted-ness of the Collection and make sorting the Library's collection impossible. That is why the insert_sorted() function is used from main rather than push_front() or push_back()

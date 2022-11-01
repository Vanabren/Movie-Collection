 ##
 # @file Makefile
 # @author Vance Brenderabrandis + Jacqueline
 # @date 2022-11-01
 # @brief Makefile for Movie Collection program
 # 
 # Makefile used to make compilation of Movie Collection program quicker and easier.
 ##

CC = g++ # Compiler is g++
TARGET = movie # Target executable name
CFLAGS = -c -Wall -Wextra # Compile with all warnings and extra warnings

default: all # Typing "make" into console does default action, which is everything / all

all:	$(TARGET)

$(TARGET):	Library.o main.o # Links object files together into executable
	$(CC) -Wall -Wextra -o $(TARGET) Library.o main.o

Library.o: 	Library.cpp Library.h # compiles Library into object code
	$(CC) $(CFLAGS) Library.cpp

main.o:		main.cpp Library.h  # compiles main into object code
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) movie *.o *~ 


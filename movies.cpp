// movies child class

#include <iostream>
#include <cstring>
#include "movies.h"

using namespace std;

movies::movies(char* newtitle, int newyear, char* newdirector, char* newduration, char*newrating):media(newtitle, newyear) {
  // only use methods not already in media parent class
  director = new char[20];
  strcpy(director, newdirector);
  duration = new char[20];
  strcpy(duration, newduration);
  rating = new char[20];
  strcpy(rating, newrating);
}
char* movies::getdirector() {
  return director;
}

char* movies::getduration() {
  return duration;
}

char* movies::getrating() {
  return rating;
}

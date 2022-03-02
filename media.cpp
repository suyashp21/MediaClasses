// media parent class

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media(char* newtitle, int newyear) {
  // includes attributes and methods for all three media types
  year = newyear;
  title = new char[20];
  strcpy(title, newtitle);
}
int media::getyear() {
  return year;
}

char* media::gettitle() {
  return title;
}

void media::settype(char newmediatype) {
  // keep track of what type of media this is
  mediatype = newmediatype;
}

char media::getmediatype() {
  // returns the type of media (music, movie, or video game, denoted by a specific char)
  return mediatype;
}

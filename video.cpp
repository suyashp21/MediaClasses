//video games child class

#include <iostream>
#include <cstring>
#include "video.h"

using namespace std;

video::video(char* newtitle, int newyear, char* newpublisher, char* newrating):media(newtitle, newyear) {
  // only need methods not already in media parent
  publisher = new char[20];
  strcpy(publisher, newpublisher);
  rating = new char[20];
  strcpy(rating, newrating);
}
char* video::getpublisher() {
  return publisher;
}

char* video::getrating() {
  return rating;
}

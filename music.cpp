// music child class

#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

music::music(char* newtitle, int newyear, char* newartist, char* newduration, char* newpublisher):media(newtitle, newyear) {
  // only use methods that media parent does not have
  artist = new char[20];
  strcpy(artist, newartist);
  duration = new char[20];
  strcpy(duration, newduration);
  publisher = new char[20];
  strcpy(publisher, newpublisher);
}
char* music::getartist() {
  return artist;
}

char* music::getduration() {
  return duration;
}

char* music::getpublisher() {
  return publisher;
}

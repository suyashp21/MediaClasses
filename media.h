// media parent class

#include <iostream>
#include <cstring>
#ifndef ADD_H
#define ADD_H //header guard

using namespace std;

class media {
 public:
  media(char* newtitle, int newyear);
  int getyear();
  char* gettitle();
  void settype(char newmediatype);
  char getmediatype(); // returns type of media
 protected:
  int year;
  char* title;
  char mediatype;
};

#endif

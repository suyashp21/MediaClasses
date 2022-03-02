// movies child class

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movies : public media {
 public:
  movies(char* newtitle, int newyear, char* newdirector, char* newduration, char*newrating);
  // only use methods not already in movies parent
  char* getdirector();
  char* getduration();
  char* getrating();
 protected:
  char* director;
  char* duration;
  char* rating;
};

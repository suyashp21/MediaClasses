// video games child class

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class video : public media {
 public:
  // only need methods not already in media parent
  video(char* newtitle, int newyear, char* newpublisher, char* newrating);
  char* getpublisher();
  char* getrating();
 protected:
  char* publisher;
  char* rating;
};

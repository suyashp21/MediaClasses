// music child class

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music : public media {
 public:
  music(char* newtitle, int newyear, char* newartist, char* newduration, char* newpublisher);
  // only use methods not in media class
  char* getartist();
  char* getduration();
  char* getpublisher();
 protected:
  char* artist;
  char* duration;
  char* publisher;
};

/* Author: Suyash Pandit
Date: December 8, 2021
This program simulates a media class, allowing the user
to add music, movies, or videogames, each with different fields.
Unfortunately, one limitation is that each field can only be a single word. */

#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"
#include "movies.h"
#include "video.h"
#include <vector>

using namespace std;

int main() {
  char action[20];
  char type[20];
  char titlesearch[20];
  int yearsearch;
  char searchby[20];
  char confirm = 'n';
  vector <media*> storage;

  cout << "\nWhat would you like to do? (ADD, SEARCH, DELETE, QUIT) ";

  while (true) {
    cin >> action;
    if (strcmp(action, "ADD") == 0) {
      cout << "\nWhat type of media? (MUSIC, MOVIE, or VIDEOGAME) ";
      // ask for type of media and create it
      cin >> type;
      if (strcmp(type, "MUSIC") == 0) {
        char* newtitle = new char[20];
        cout << "Title: ";
        cin >> newtitle;
        
        int newyear;
        cout << "Year: ";
        cin >> newyear;
        
        char* newartist = new char[20];
        cout << "Artist: ";
        cin >> newartist;
  
        char* newduration = new char[20];
        cout << "Duration: ";
        cin >> newduration;
  
        char* newpublisher = new char[20];
        cout << "Publisher: ";
        cin >> newpublisher;
      
        music* m = new music(newtitle, newyear, newartist, newduration, newpublisher);
	m->settype('u');
        storage.push_back(m);
      }
      else if (strcmp(type, "MOVIE") == 0) {
	char* newtitle = new char[20];
	cout << "Title: ";
	cin >> newtitle;

	int newyear;
	cout << "Year: ";
	cin >> newyear;

	char* newdirector = new char[20];
	cout << "Director: ";
	cin >> newdirector;

	char* newduration = new char[20];
	cout << "Duration: ";
	cin >> newduration;

	char* newrating = new char[20];
	cout << "Rating: ";
	cin >> newrating;

	movies* m = new movies(newtitle, newyear, newdirector, newduration, newrating);
	m->settype('o');
	storage.push_back(m);
      }
      else if (strcmp(type, "VIDEOGAME") == 0) {
	char* newtitle = new char[20];
	cout << "Title: ";
	cin >> newtitle;

	int newyear;
	cout << "Year: ";
	cin >> newyear;

	char* newpublisher = new char[20];
	cout << "Publisher: ";
	cin >> newpublisher;

	char* newrating = new char[20];
	cout << "Rating: ";
	cin >> newrating;

	video* m = new video(newtitle, newyear, newpublisher, newrating);
	m->settype('i');
	storage.push_back(m);
      }
      else {
	cout << "Not a valid media type." << endl;
      }
    }
    else if (strcmp(action, "SEARCH") == 0) {
      cout << "Search by TITLE or YEAR? ";
      cin >> searchby;
      if (strcmp(searchby,"TITLE")==0 || strcmp(searchby,"Title")==0 || strcmp(searchby,"title")==0) {
	// search by title
	cout << "Title to search: ";
	cin >> titlesearch;
	bool found = false;
	for (int i=0; i<storage.size(); i++) {
	  if (strcmp(storage[i]->gettitle(),titlesearch)==0) {
	    found = true;
	    if (storage[i]->getmediatype()=='u') {
	      cout << "\nType: Music" << endl;
	      cout << "Title: " << storage[i]->gettitle() << endl;
	      cout << "Year: " << storage[i]->getyear() << endl;
	      cout << "Artist: " << ((music*)storage[i])->getartist() << endl;
	      cout << "Duration: " << ((music*)storage[i])->getduration() << endl;
	      cout << "Publisher: " << ((music*)storage[i])->getpublisher() << endl;
	    }
	    else if (storage[i]->getmediatype()=='o') {
	      cout << "\nType: Movie" << endl;
	      cout << "Title: " << storage[i]->gettitle() << endl;
	      cout << "Year: " << storage[i]->getyear() << endl;
	      cout << "Director: " << ((movies*)storage[i])->getdirector() << endl;
	      cout << "Duration: " << ((movies*)storage[i])->getduration() << endl;
	      cout << "Rating: " << ((movies*)storage[i])->getrating() << endl;
	    }
	    else if (storage[i]->getmediatype()=='i') {
	      cout << "\nType: Video Game" << endl;
	      cout << "Title: " << storage[i]->gettitle() << endl;
	      cout << "Year: " << storage[i]->getyear() << endl;
	      cout << "Publisher: " << ((video*)storage[i])->getpublisher() << endl;
	      cout << "Rating: " << ((video*)storage[i])->getrating() << endl;
	    }
	  }
	}
	if (found == false) {
	  cout << "No item matches that title." << endl;
	}
      }
      else if (strcmp(searchby,"YEAR")==0 || strcmp(searchby,"Year")==0 || strcmp(searchby,"year")==0) {
	// search by year
	cout << "Year to search: ";
	cin >> yearsearch;
	bool found = false;
	for (int i=0; i<storage.size(); i++) {
	  if (storage[i]->getyear()==yearsearch) {
	    found = true;
	    if (storage[i]->getmediatype()=='u') {
	      cout << "\nType: Music" << endl;
	      cout << "Title: " << storage[i]->gettitle() << endl;
	      cout << "Year: " << storage[i]->getyear() << endl;
	      cout << "Artist: " << ((music*)storage[i])->getartist() << endl;
	      cout << "Duration: " << ((music*)storage[i])->getduration() << endl;
	      cout << "Publisher: " << ((music*)storage[i])->getpublisher() << endl;
	    }
	    else if (storage[i]->getmediatype()=='o') {
	      cout << "\nType: Movie" << endl;
	      cout << "Title: " << storage[i]->gettitle() << endl;
	      cout << "Year: " << storage[i]->getyear() << endl;
	      cout << "Director: " << ((movies*)storage[i])->getdirector() << endl;
	      cout << "Duration: " << ((movies*)storage[i])->getduration() << endl;
	      cout << "Rating: " << ((movies*)storage[i])->getrating() << endl;
	    }
	    else if (storage[i]->getmediatype()=='i') {
	      cout << "\nType: Video Game" << endl;
	      cout << "Title: " << storage[i]->gettitle() << endl;
	      cout << "Year: " << storage[i]->getyear() << endl;
	      cout << "Publisher: " << ((video*)storage[i])->getpublisher() << endl;
	      cout << "Rating: " << ((video*)storage[i])->getrating() << endl;
	    }
	  }
	}
	if (found == false) {
	  cout << "No item matches that year." << endl;
	}
	
      }
      else {
	cout << "Command not recognized." << endl;
      }
    }
    else if (strcmp(action, "DELETE") == 0) {
      cout << "Delete by TITLE or YEAR? ";
      cin >> searchby;
      if (strcmp(searchby,"TITLE")==0 || strcmp(searchby,"Title")==0 || strcmp(searchby,"title")==0) {
	// delete by title
	cout << "Title to search: ";
        cin >> titlesearch;
        bool found = false;
        for (int i=0; i<storage.size(); i++) {
          if (strcmp(storage[i]->gettitle(),titlesearch)==0) {
            found = true;
            if (storage[i]->getmediatype()=='u') {
              cout << "\nType: Music" << endl;
              cout << "Title: " << storage[i]->gettitle() << endl;
              cout << "Year: " << storage[i]->getyear() << endl;
              cout << "Artist: " << ((music*)storage[i])->getartist() << endl;
              cout << "Duration: " << ((music*)storage[i])->getduration() << endl;
              cout << "Publisher: " << ((music*)storage[i])->getpublisher() << endl;
            }
            else if (storage[i]->getmediatype()=='o') {
              cout << "\nType: Movie" << endl;
              cout << "Title: " << storage[i]->gettitle() << endl;
              cout << "Year: " << storage[i]->getyear() << endl;
              cout << "Director: " << ((movies*)storage[i])->getdirector() << endl;
              cout << "Duration: " << ((movies*)storage[i])->getduration() << endl;
              cout << "Rating: " << ((movies*)storage[i])->getrating() << endl;
            }
            else if (storage[i]->getmediatype()=='i') {
              cout << "\nType: Video Game" << endl;
              cout << "Title: " << storage[i]->gettitle() << endl;
              cout << "Year: " << storage[i]->getyear() << endl;
              cout << "Publisher: " << ((video*)storage[i])->getpublisher() << endl;
              cout << "Rating: " << ((video*)storage[i])->getrating() << endl;
            }
	    cout << "\nI'm about to delete the above item. Is this what you want to delete? (y/n)" << endl;
	    cin >> confirm;
	    if (confirm == 'y' || confirm == 'Y') {
	      storage.erase(storage.begin()+i);
	      break;
	    }
          }
        }
	if (found == false) {
	  cout << "No item matches that title. Nothing was deleted." << endl;
	}
      }
      else if (strcmp(searchby,"YEAR")==0 || strcmp(searchby,"Year")==0 || strcmp(searchby,"year")==0) {
	// delete by year
        cout << "Year to search: ";
        cin >> yearsearch;
        bool found = false;
        for (int i=0; i<storage.size(); i++) {
          if (storage[i]->getyear()==yearsearch) {
            found = true;
            if (storage[i]->getmediatype()=='u') {
              cout << "\nType: Music" << endl;
              cout << "Title: " << storage[i]->gettitle() << endl;
              cout << "Year: " << storage[i]->getyear() << endl;
              cout << "Artist: " << ((music*)storage[i])->getartist() << endl;
              cout << "Duration: " << ((music*)storage[i])->getduration() << endl;
              cout << "Publisher: " << ((music*)storage[i])->getpublisher() << endl;
            }
            else if (storage[i]->getmediatype()=='o') {
              cout << "\nType: Movie" << endl;
              cout << "Title: " << storage[i]->gettitle() << endl;
              cout << "Year: " << storage[i]->getyear() << endl;
              cout << "Director: " << ((movies*)storage[i])->getdirector() << endl;
              cout << "Duration: " << ((movies*)storage[i])->getduration() << endl;
              cout << "Rating: " << ((movies*)storage[i])->getrating() << endl;
            }
            else if (storage[i]->getmediatype()=='i') {
              cout << "\nType: Video Game" << endl;
              cout << "Title: " << storage[i]->gettitle() << endl;
              cout << "Year: " << storage[i]->getyear() << endl;
              cout << "Publisher: " << ((video*)storage[i])->getpublisher() << endl;
              cout << "Rating: " << ((video*)storage[i])->getrating() << endl;
            }
	    cout << "\nI'm about to delete the above item. Is this what you want to delete? (y/n)" << endl;
	    cin >> confirm;
	    if (confirm == 'y' || confirm == 'Y') {
	      storage.erase(storage.begin()+i);
	    }
          }
        }
	if (found == false) {
	  cout << "No item matches that year. Nothing has been deleted." << endl;
	}
      }

    }
    
    else if (strcmp(action, "QUIT") == 0) {
      // end program
      break;
    }
    else {
      cout << "Invalid command." << endl;
    }
    cout << "\nWhat would you like to do? (ADD, SEARCH, DELETE, or QUIT) "; // ask what the user eants to do next
  }
  return 0;
}

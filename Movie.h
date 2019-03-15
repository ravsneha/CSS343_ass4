/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_MOVIE_H
#define ASS_4_MOVIE_H

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

using namespace std;

class Movie {
public:
    //no arg constructor
    Movie();

    //constructor for comedy and drama
    Movie(int s, int r, string type, string title, string d);

    //constructor for classics
    Movie(int s, int r, string type, string title, string d,
          int m, string ma);

    //destructor
    ~Movie();

    //getters
    int getStock();

    int getRelease();

    string getType();

    string getTitle();

    string getDirector();

    virtual int getReleaseMonth();

    virtual string getMainActor();

    //setters
    void setType(string a);

    void setStock(int a);

    void addStock();

    void reduceStock();

    void setRelease(int a);

    void setTitle(string a);

    void setDirector(string a);

    virtual void setReleaseMonth(int a);

    virtual void setMainActor(string a);

    virtual bool operator<(Movie &a) const;

    virtual bool operator>(Movie &a) const;

    virtual bool operator==(Movie &a) const;

protected:
    string type;
    string director;
    string title;
    string mainActor;
    int stock;
    int release;
    int releaseMonth;
};


#endif //ASS_4_MOVIE_H

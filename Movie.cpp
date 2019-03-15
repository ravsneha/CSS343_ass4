/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#include <stack>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

//////CONSTRUCTORS////////
//no arg constructor
Movie::Movie() {
    this->stock = 0;
    this->release = 0;
    this->type = "NA";
    this->title = title;
    this->director = "NA";
}

//copy constructor
Movie::Movie(Movie &m) {
    if (type != m.type) return; //checks type
    stock = m.stock;
    director = m.director;
    title = m.title;
    release = m.release;
    mainActor = m.mainActor;
    releaseMonth = m.releaseMonth;
}

//arg constructor (comedy and drama)
Movie::Movie(int s, int r, string type, string title, string d) {
    stock = s;
    release = r;
    this->type = type;
    this->title = title;
    director = d;
}

//arg constructor (classics)
Movie::Movie(int s, int r, string type, string title, string d,
             int m, string ma) {
    stock = s;
    release = r;
    this->type = type;
    this->title = title;
    director = d;
    releaseMonth = m;
    mainActor = ma;
}

////////DESTRUCTOR///////
Movie::~Movie() {}

////////GETTERS///////
string Movie::getType() { return type; }

int Movie::getStock() { return stock; }

int Movie::getRelease() { return release; }

string Movie::getTitle() { return title; }

string Movie::getDirector() { return director; }

int Movie::getReleaseMonth() { return releaseMonth; }

string Movie::getMainActor() { return mainActor; }

//////SETTERS////////
void Movie::setType(const string a) { type = a; }

void Movie::setStock(const int a) {
    if (a > -1) stock = a;
}

//increases stock by 1
void Movie::addStock() {
    setStock(getStock() - 1);
}

//decreases stock by 1
void Movie::reduceStock() {
    setStock(getStock() - 1);
}

void Movie::setRelease(const int a) { release = a; }

void Movie::setTitle(const string a) { title = a; }

void Movie::setDirector(const string a) { director = a; }

void Movie::setReleaseMonth(const int a) { releaseMonth = a; }

void Movie::setMainActor(const string a) { mainActor = a; }

//////OPERATORS////////
//all just place holders
//overridden in subclasses
bool Movie::operator<(Movie &a) const { return false; }

bool Movie::operator>(Movie &a) const { return false; }

bool Movie::operator==(Movie &a) const { return false; }
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
#include "Drama.h"

using namespace std;

Drama::Drama() {
    this->stock = 0;
    this->release = 0;
    this->type = "D";
    this->title = title;
    this->director = "NA";
}

Drama::Drama(int s, int r, string type, string title, string d) {
    stock = s;
    release = r;
    this->type = "D";
    this->title = title;
    director = d;
}

Drama::~Drama() {}

bool Drama::operator<(Drama &a) const {
    Drama temp = static_cast<Drama &>(a);
    if (director < temp.director) {
        if (title < temp.title)return true;
        return false;
    }
    return false;
}

bool Drama::operator>(Drama &a) const {
    Drama temp = static_cast<Drama &>(a);
    if (director > temp.director) {
        if (title > temp.title)return true;
        return false;
    }
    return false;
}

bool Drama::operator==(Drama &a) const {
    Drama temp = static_cast<Drama &>(a);
    if (director == temp.director) {
        if (title == temp.title)return true;
        return false;
    }
    return false;
}

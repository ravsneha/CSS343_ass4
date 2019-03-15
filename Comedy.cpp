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
#include "Comedy.h"

using namespace std;

Comedy::Comedy() {
    this->stock = 0;
    this->release = 0;
    this->type = "F";
    this->title = title;
    this->director = "NA";
}

Comedy::Comedy(int s, int r, string type, string title, string d) {
    stock = s;
    release = r;
    this->type = "F";
    this->title = title;
    director = d;
}

Comedy::~Comedy() {}

bool Comedy::operator<(Comedy &a) const {
    Comedy temp = static_cast<Comedy &>(a);
    if (title == temp.title) {
        if (release < temp.release) return true;
        return false;
    } else if (title < temp.title)
        return true;
    return false;
}

bool Comedy::operator>(Comedy &a) const {
    Comedy temp = static_cast<Comedy &>(a);
    if (title == temp.title) {
        if (release > temp.release) return true;
        return false;
    } else if (title > temp.title)
        return true;
    return false;
}

bool Comedy::operator==(Comedy &a) const {
    Comedy temp = static_cast<Comedy &>(a);
    if (title == temp.title) {
        if (release == temp.release)return true;
        return false;
    }
    return false;
}

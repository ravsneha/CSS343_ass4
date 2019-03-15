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
#include "Classic.h"
#include "Movie.h"

using namespace std;

Classic::Classic() {
    this->stock = 0;
    this->release = 0;
    this->type = "C";
    this->title = title;
    this->director = "NA";
    this->releaseMonth = 0;
    this->mainActor = "NA";
}

Classic::Classic(int s, int r, string type, string title, string d,
                 int m, string ma) {
    stock = s;
    release = r;
    this->type = "C";
    this->title = title;
    director = d;
    releaseMonth = m;
    mainActor = ma;
}

Classic::~Classic() {}

bool Classic::operator<(Classic &a) const {
    Classic temp = static_cast<Classic &>(a);
    if ((releaseMonth + release) <
        (temp.releaseMonth + temp.release)) {
        if (mainActor < temp.mainActor) return true;
        return false;
    }
    return false;
}

bool Classic::operator>(Classic &a) const {
    Classic temp = static_cast<Classic &>(a);
    if ((releaseMonth + release) >
        (temp.releaseMonth + temp.release)) {
        if (mainActor > temp.mainActor) return true;
        return false;
    }
    return false;
}

bool Classic::operator==(Classic &a) const {
    Classic temp = static_cast<Classic &>(a);
    if ((releaseMonth + release) ==
        (temp.releaseMonth + temp.release)) {
        if (mainActor == temp.mainActor) return true;
        return false;
    }
    return false;
}
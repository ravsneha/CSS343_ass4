/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_COMEDY_H
#define ASS_4_COMEDY_H

#include <stack>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

class Comedy : public Movie {
public:
    Comedy();

    Comedy(int s, int r, string type, string title, string d);

    ~Comedy();

    bool operator<(Comedy &a) const;

    bool operator>(Comedy &a) const;

    bool operator==(Comedy &a) const;
};


#endif //ASS_4_COMEDY_H

/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_DRAMA_H
#define ASS_4_DRAMA_H

#include <stack>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

class Drama : public Movie {
public:
    Drama();

    Drama(int s, int r, string type, string title, string d);

    ~Drama();

    bool operator<(Drama &a) const;

    bool operator>(Drama &a) const;

    bool operator==(Drama &a) const;
};

#endif

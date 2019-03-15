/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_CLASSIC_H
#define ASS_4_CLASSIC_H

#include <stack>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

class Classic : public Movie {
public:
    Classic();

    Classic(int s, int r, string type, string title, string d,
            int m, string ma);

    ~Classic();

    bool operator<(Classic &a) const;

    bool operator>(Classic &a) const;

    bool operator==(Classic &a) const;


};


#endif //ASS_4_CLASSIC_H

/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"

#ifndef ASS_4_MOVIEFACTORY_H
#define ASS_4_MOVIEFACTORY_H

class MovieFactory {
public:
    //create F and D
    Movie *create(int s, int r, string type, string title, string d);

    //create C
    Movie *create(int s, int r, string type, string title, string d,
                  int m, string ma);
};


#endif //ASS_4_MOVIEFACTORY_H

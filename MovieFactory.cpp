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
#include "MovieFactory.h"

//create FD Movies
Movie *MovieFactory::create(int s, int r, string type, string title, string d) {
    if (type == "F") return new Comedy(s, r, type, title, d);
    else if (type == "D") return new Drama(s, r, type, title, d);
}

//create C Movies
Movie *MovieFactory::create(int s, int r, string type, string title, string d,
                            int m, string ma) {
    return new Classic(s, r, type, title, d, m, ma);
}



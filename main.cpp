#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Store.h"
#include "Customer.h"
#include "Classic.h"
#include "Drama.h"
#include "HashTable.cpp"
#include "Comedy.h"

using namespace std;

int main() {
    Store a;
    a.readMovieFile("test.txt");
    a.readCustomerFile("test.txt");
    a.readCommandsFile("test.txt");
    return 0;
}
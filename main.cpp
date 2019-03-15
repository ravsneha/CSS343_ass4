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
    a.readMovieFile("data4movies.txt");
    a.readCustomerFile("data4customers.txt");
    a.readCommandsFile("data4commands.txt");
    return 0;
}

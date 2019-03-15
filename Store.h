/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_STORE_H
#define ASS_4_STORE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"
#include "Customer.h"
#include "HashTable.cpp"

using namespace std;

class Store {
public:
    //constructor
    Store();

    //destructor
    ~Store();

    bool addCustomer(string f, string l, int i);

    bool removeCustomer(int i);

    void displayCustomers();

    string findCustomer(int i);

    bool borrowMovie(Movie &m);

    bool returnMovie(Movie &m);

    void displayInventory();

    void displayCustomerHistory(int i); //prints customer history
    string movieToString(Movie *a); //turns Movie into string
    void sortF();//sorts comedies
    void sortD(); //sorts dramas
    void sortC();//sorts classics
    void printF();//prints comedies
    void printD(); //prints dramas
    void printC(); //prints classics
    //checks if movie with title exists in vector v
    bool exists(string m, vector<Movie> v);

    //checks if movie with title exists in program
    bool existsInAll(string m);

    //checks if movie with title is in stock (stock!=0)
    bool inStock(string m);

    //gets index of movie with title in vector v
    int getIndex(string m, vector<Movie> v);

    //gets index of classic movie using main actor, release yr and month
    int getIndexForClassics(string ma, int r, int rm);

    //read customer file
    void readCustomerFile(string a);

    //read commands file
    void readCommandsFile(string a);

    //read movie file
    void readMovieFile(string a);


protected:
    HashTable<int, Customer> customers;
    HashTable<int, vector<string>> *history;
    vector<Movie> classic;
    vector<Movie> comedy;
    vector<Movie> drama;
};

#endif

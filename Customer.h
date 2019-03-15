/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_CUSTOMER_H
#define ASS_4_CUSTOMER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Customer.h"

using namespace std;

class Customer {
public:
    Customer();

    Customer(string f, string l, int c);

    ~Customer();

    //getters
    string getFName();

    string getLName();

    int getCID();

    vector<string> getHistory();

    //setters
    void setFName(string);

    void setLName(string);

    void setCID(int);

    void setHistory(vector<string> a);

    void addHistory(string a);


    void displayHistory();

    void readFile(string a);


private:
    string fName;
    string lName;
    int CID;
    vector<string> history;  // stores history of this customer
};

#endif //ASS_4_CUSTOMER_H

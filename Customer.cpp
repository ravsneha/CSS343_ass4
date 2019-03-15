/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

// default constructor
Customer::Customer() {
    fName = "";
    lName = "";
    CID = 0;
}

Customer::Customer(string f, string l, int c) {
    fName = f;
    lName = l;
    CID = c;
}

Customer::~Customer() {}

string Customer::getFName() {
    return fName;
}

string Customer::getLName() {
    return lName;
}

int Customer::getCID() {
    return CID;
}

vector<string> Customer::getHistory() {
    return history;
}

void Customer::setFName(string a) {
    fName = a;
}

void Customer::setLName(string a) {
    lName = a;
}

void Customer::setCID(int a) {
    CID = a;
}

void Customer::setHistory(vector<string> a) {
    history.clear();
    for (int i = 0; (unsigned) i < a.size(); i++) {
        history.push_back(a[i]);
    }
}

void Customer::addHistory(string a) {
    history.push_back(a);
}

void Customer::displayHistory() {
    for (int i = 0; (unsigned) i < history.size(); i++) {
        cout << history[1] << endl;
    }
}
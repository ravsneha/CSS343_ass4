/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Store.h"

using namespace std;

//////CONSTRUCTORS/DESTRUCTORS////////
Store::Store() {}

Store::~Store() {
    customers.clear();
    history->clear();
    classic.clear();
    comedy.clear();
    drama.clear();
    delete &classic;
    delete &comedy;
    delete &drama;
}

//////ADDS CUSTOMERS////////
bool Store::addCustomer(string f, string l, int i) {
    if (customers.contains(i)) return false;
    else {
        Customer newCust = Customer(f, l, i);
        this->customers.add(i, newCust);
        return true;
    }
}

//////REMOVES CUSTOMERS////////
bool Store::removeCustomer(int i) {
    customers.remove(i);
}

//////OUTPUTS CUSTOMERS////////
void Store::displayCustomers() {
    vector<int> keys = customers.getKeys();
    for (int i = 0; i < customers.getNumOfEntries(); i++) {
        cout << "CID: " << keys[i] << " Name: " << findCustomer(keys[i]) << endl;
    }
}

///////FINDS CUSTOMERS AND RETURNS STRING////////
string Store::findCustomer(int i) {
    if (customers.contains(i)) {
        return customers.getVal(i).getFName() + " "
               + customers.getVal(i).getLName();
    }
}

//////BORROWS MOVIE////////
//reduces stock by one, if successful outputs true
bool Store::borrowMovie(Movie &m) {
    if (!existsInAll(m.getTitle())) {
        cout << "That movie is not in our database!" << endl;
        return false;
    } else {
        if (m.getType() == "F") {
            int index;
            if (comedy[index].getStock() >= 1) {
                comedy[index].reduceStock();
                return true;

            } else {
                cout << "Sorry, we are out of stock of this comedy." << endl;
                return false;
            }
        } else if (m.getType() == "D") {
            int index; //= movieIndex(m->getTitle());
            if (drama[index].getStock() >= 1) {
                drama[index].setStock(drama[index].getStock() - 1);
                return true;
            } else {
                cout << "Sorry, we are out of stock of this drama." << endl;
                return false;
            }
        } else if (m.getType() == "C") {
            int index; // = movieIndex(m->getTitle());
            if (classic[index].getStock() >= 1) {
                classic[index].setStock(classic[index].getStock() - 1);
                return true;

            } else {
                cout << "Sorry, we are out of stock of this classic." << endl;
                return false;
            }
        }
    }
}

//////RETURNS MOVIE////////
//increases stock by 1, returns true if successful
bool Store::returnMovie(Movie &m) {
    if (!existsInAll(m.getTitle())) return false;
    else {
        int index = -1;
        if (m.getType() == "F") {
            index = getIndex(m.getTitle(), comedy);
            comedy[index].addStock();
            cout << "Comedy returned" << endl;
            return true;
        } else if (m.getType() == "D") {
            index = getIndex(m.getTitle(), drama);
            drama[index].addStock();
            cout << "Drama returned" << endl;
            return true;
        } else if (m.getType() == "C") {
            index = getIndex(m.getTitle(), classic);
            classic[index].addStock();
            cout << "Classic returned" << endl;
            return true;
        }
    }
}

//////TOSTRING FOR MOVIE////////
//returns string representation of a movie
string Store::movieToString(Movie *a) {
    string retVal = "";
    if (a->getType() == "C") {
        retVal += a->getType() + ", ";
        retVal += a->getStock() + ", ";
        retVal += a->getDirector() + ", ";
        retVal += a->getTitle() + ", ";
        retVal += a->getMainActor() + " ";
        retVal += a->getReleaseMonth() + " " + a->getRelease();
    } else {
        retVal += a->getType() + ", ";
        retVal += a->getStock() + ", ";
        retVal += a->getDirector() + ", ";
        retVal += a->getTitle() + ", ";
        retVal += a->getRelease();
    }
    return retVal;
}

//////DISPLAYS ALL MOVIES IN THE PROGRAM////////
//prints out all string representations of comedy, drama, then classic movies
void Store::displayInventory() {
    //makes sure they're sorted
    sortF();
    sortD();
    sortC();

    printF();
    printD();
    printC();
}

//////DISPLAYS CUSTOMER HISTORY////////
//prints out customer's history
void Store::displayCustomerHistory(int id) {
    vector<string> temp = history->getVal(id);
    for (int i = 0; i < temp.size(); i++) {
        //cout << temp[i] << endl; was not printing correctly
    }
}

//////SORTS ALL COMEDIES IN THE PROGRAM////////
//sorts all comedies in their specified ways
void Store::sortF() {
    for (int i = 0; i < comedy.size(); i++) {
        for (int j = 0; i < comedy.size(); i++) {
            if (comedy[j].getTitle() < comedy[i].getTitle()) {
                Movie temp(comedy[j]);
                comedy[j] = comedy[i];
                comedy[i] = temp;
            } else if (comedy[j].getTitle() == comedy[i].getTitle() &&
                       comedy[j].getRelease() < comedy[i].getRelease()) {
                Movie temp(comedy[j]);
                comedy[j] = comedy[i];
                comedy[i] = temp;
            }
        }
    }
}

//////SORTS ALL DRAMAS IN THE PROGRAM////////
//sorts all dramas in their specified ways
void Store::sortD() {
    for (int i = 0; i < drama.size(); i++) {
        for (int j = 0; i < drama.size(); i++) {
            if (drama[j].getDirector() < drama[i].getDirector()) {
                Movie temp(drama[j]);
                drama[j] = drama[i];
                drama[i] = temp;
            } else if (drama[j].getDirector() == drama[i].getDirector() &&
                       drama[j].getRelease() < drama[i].getRelease()) {
                Movie temp(drama[j]);
                drama[j] = drama[i];
                drama[i] = temp;
            }
        }
    }
}

//////PRINTS ALL COMEDIES IN THE PROGRAM////////
//prints all comedies in their specified ways
void Store::printF() {
    for (int i = 0; i < comedy.size(); i++) {
        cout << movieToString(&comedy[i]) << endl;
    }
}

//////PRINTS ALL DRAMAS IN THE PROGRAM////////
//prints all dramas in their specified ways
void Store::printD() {
    for (int i = 0; i < drama.size(); i++) {
        cout << movieToString(&drama[i]) << endl;
    }
}

//////DISPLAYS ALL CLASSICS IN THE PROGRAM////////
//sorts classics in specific order
void Store::sortC() {
    for (int i = 0; i < classic.size(); i++) {
        for (int j = 0; i < classic.size(); i++) {
            if ((classic[j].getRelease() + classic[j].getReleaseMonth())
                < (classic[i].getRelease() + classic[i].getReleaseMonth())) {
                Movie temp(classic[j]);
                classic[j] = classic[i];
                classic[i] = temp;
            } else if ((classic[j].getRelease() + classic[j].getReleaseMonth())
                       == (classic[i].getRelease() + classic[i].getReleaseMonth()) &&
                       classic[j].getMainActor() < classic[i].getMainActor()) {
                Movie temp(classic[j]);
                classic[j] = classic[i];
                classic[i] = temp;
            }
        }
    }
}

//////PRINTS ALL CLASSICS IN THE PROGRAM////////
//prints all classics in their specified ways
void Store::printC() {
    for (int i = 0; i < classic.size(); i++) {
        cout << movieToString(&classic[i]) << endl;
    }
}

//////CHECKS IF MOVIE EXISTS IN THE VECTOR////////
bool Store::exists(string m, vector<Movie> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getTitle() == m) return true;
    }
    return false;
}

//////CHECKS IF MOVIE EXISTS IN THE PROGRAM////////
bool Store::existsInAll(string m) {
    if (!exists(m, comedy) && !exists(m, classic) && !exists(m, drama)) {
        return false;
    } else return true;
}

//////CHECKS IF MOVIE IS IN STOCK////////
bool Store::inStock(string m) {
    if (!existsInAll(m)) return false;
    else if (exists(m, comedy)) {
        for (int i = 0; i < comedy.size(); i++) {
            if (comedy[i].getTitle() == m &&
                comedy[i].getStock() != 0) {
                return true;
            }
        }
        return false;
    } else if (exists(m, classic)) {
        for (int i = 0; i < classic.size(); i++) {
            if (classic[i].getTitle() == m &&
                classic[i].getStock() != 0) {
                return true;
            }
        }
        return false;
    } else if (exists(m, drama)) {
        for (int i = 0; i < drama.size(); i++) {
            if (drama[i].getTitle() == m &&
                drama[i].getStock() != 0) {
                return true;
            }
        }
        return false;
    }

}

//////GETS MOVIE INDEX IN THE VECTOR////////
int Store::getIndex(string m, vector<Movie> v) {
    if (inStock(m)) {
        if (exists(m, v)) {
            for (int i = 0; i < v.size(); i++) {
                if (v[i].getTitle() == m) return i;
            }
        }
    } else return -1;
}

//////GETS INDEX OF CLASSICS MOVIES////////
//gets index of classic movie using main actor, release yr and month
int Store::getIndexForClassics(string ma, int r, int rm) {
    for (int i = 0; i < classic.size(); i++) {
        if (classic[i].getMainActor() == ma && classic[i].getRelease() == r
            && classic[i].getReleaseMonth() == rm) {
            return i;
        }
    }
    return -1;
}

//////FILE INPUT FOR CUSTOMERS////////
void Store::readCustomerFile(string a) {
    ifstream fileDirectory;
    fileDirectory.open(a);

    if (!fileDirectory.is_open()) {
        cout << "couldn't find file" << endl;
        return;
    }
    ifstream in(a);
    string LinesInput;
    string cid;
    string f;
    string l;
    while (getline(in, LinesInput)) {
        stringstream line(LinesInput);
        getline(line, cid, ' ');
        getline(line, f, ' ');
        getline(line, l);
        customers.add(stoi(cid), Customer(f, l, stoi(cid))); //adds to hash table
        //prints out inputted values
        cout << "CID: " << cid << endl;
        cout << "LName: " << l << endl;
        cout << "FName: " << f << endl;
    }
    fileDirectory.close();
}

//////FILE INPUT FOR MOVIES////////
void Store::readMovieFile(string a) {
    ifstream fileDirectory;
    fileDirectory.open(a);
    if (!fileDirectory.is_open()) {
        cout << "couldn't find file" << endl;
        return;
    }

    ifstream in(a);
    string LinesInput;
    string type;
    string dir;
    string title;
    string ma;
    string ma2;
    string stock;
    string rel;
    string relM;

    while (getline(in, LinesInput)) {
        stringstream line(LinesInput);
        getline(line, type, ',');
        if (type == "C") {
            getline(line, stock, ',');
            getline(line, dir, ',');
            getline(line, title, ',');
            getline(line, ma, ',');
            getline(line, ma2, ',');
            getline(line, relM, ',');
            getline(line, rel);
            cout << "Type: C" + type << endl;
            cout << "Director: " + dir << endl;
            cout << "Title: " + title << endl;
            cout << "Main Actor: " + ma + " " + ma2 << endl;
            cout << "Release Date: " + relM + " " + rel << endl;
            classic.push_back(Movie(stoi(stock), stoi(rel), type, title,
                                    dir, stoi(relM), (ma + " " + ma2)));
        } else {
            getline(line, stock, ',');
            getline(line, dir, ',');
            getline(line, title, ',');
            getline(line, rel);
            cout << "Type: " + type << endl;
            cout << "Director: " + dir << endl;
            cout << "Title: " + title << endl;
            cout << "Release Year: " + rel << endl;
            if (type == "D") {
                drama.push_back(Movie(stoi(stock), stoi(rel), type, title, dir));
            } else if (type == "F") {
                comedy.push_back(Movie(stoi(stock), stoi(rel), type, title, dir));
            } else return; //go into loop
        }

    }
    fileDirectory.close();
}

//////FILE INPUT FOR COMMANDS////////
void Store::readCommandsFile(string a) {
    ifstream fileDirectory;
    fileDirectory.open(a);
    if (!fileDirectory.is_open()) {
        cout << "couldn't find file" << endl;
        return;
    }
    //temp vars (placeholders)
    ifstream in(a);
    string LinesInput;
    string tmpLine;
    string command;
    string cid;
    string mediaT;
    string movieT;

    string dir;
    string title;
    string ma;
    string rel;
    string relM;

    while (getline(in, LinesInput)) {
        stringstream line(LinesInput);
        tmpLine = LinesInput;
        getline(line, command, ' ');
        //CHECKING COMMAND TYPE
        if (command == "B") {
            getline(line, cid, ' ');
            getline(line, mediaT, ' ');
            getline(line, movieT, ' ');
            if (movieT == "F") {
                getline(line, title, ' ');
                getline(line, rel);
                if (exists(title, comedy)) {
                    customers.getVal(stoi(cid)).addHistory(tmpLine);
                    int index = getIndex(title, comedy);
                    borrowMovie(comedy[index]);
                } else cout << "COMEDY MOVIE DNE AND CANNOT BE BORROWED" << endl;
            } else if (movieT == "D") {
                if (exists(title, drama)) {
                    getline(line, dir, ' ');
                    getline(line, title);
                    customers.getVal(stoi(cid)).addHistory(tmpLine);
                    int index = getIndex(title, drama);
                    borrowMovie(drama[index]);
                } else cout << "DRAMA MOVIE DNE AND CANNOT BE BORROWED" << endl;
            } else if (movieT == "C") {
                getline(line, relM, ' ');
                getline(line, rel, ' ');
                getline(line, ma);
                customers.getVal(stoi(cid)).addHistory(tmpLine);
                int index = getIndexForClassics(ma, stoi(rel), stoi(relM));
                if (index != -1)borrowMovie(classic[index]);
                else cout << "CLASSIC MOVIE DNE AND CANNOT BE BORROWED" << endl;
            } else {
                cout << "MOVIE DNE AND CANNOT BE BORROWED" << endl;
            }
        } else if (command == "R") {
            getline(line, cid, ' ');
            getline(line, mediaT, ' ');
            getline(line, movieT, ' ');
            if (movieT == "F") {
                getline(line, title, ' ');
                getline(line, rel);
                if (exists(title, comedy)) {
                    customers.getVal(stoi(cid)).addHistory(tmpLine);
                    int index = getIndex(title, comedy);
                    returnMovie(comedy[index]);
                } else cout << "COMEDY MOVIE DNE AND CANNOT BE RETURNED" << endl;
            } else if (movieT == "D") {
                if (exists(title, drama)) {
                    getline(line, dir, ' ');
                    getline(line, title);
                    customers.getVal(stoi(cid)).addHistory(tmpLine);
                    int index = getIndex(title, drama);
                    returnMovie(drama[index]);
                } else cout << "DRAMA MOVIE DNE AND CANNOT BE RETURNED" << endl;
            } else if (movieT == "C") {
                getline(line, relM, ' ');
                getline(line, rel, ' ');
                getline(line, ma);
                customers.getVal(stoi(cid)).addHistory(tmpLine);
                int index = getIndexForClassics(ma, stoi(rel), stoi(relM));
                if (index != -1)returnMovie(classic[index]);
                else cout << "CLASSIC MOVIE DNE AND CANNOT BE RETURNED" << endl;
            } else {
                cout << "MOVIE DNE AND CANNOT BE RETURNED" << endl;
            }
        } else if (command == "I") {
            return displayInventory();
        } else if (command == "H") {
            return displayCustomerHistory(stoi(cid));
        }

    }
    fileDirectory.close();
}
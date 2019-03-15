/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include"Customer.h"

using namespace std;


template <typename K, typename V>
class HashTable {
public:
    // default constructor
    HashTable() {
        numOfKeys = 0;
    }

    // constructor than takes in arguments for the key and value
    HashTable(const K key, const V value) {
        numOfKeys++;
        keysMap[key] = value;
        keys.push_back(key);
    }

    // returns true if hashtable has no keys, and returns false otherwise.
    bool isEmpty() {
        if (numOfKeys == 0) return true;
        else return false;
    }

    // returns number of keys available.
    int getNumOfEntries() {
        return numOfKeys;
    }

    bool add(K key, V value) {
        if (keysMap.count(key) == 0) {
            numOfKeys++;
            keysMap[key] = value;
            keys.push_back(key);
            return true;
        } else return false;
    }

    bool remove( K key) {
        if (keysMap.count(key) == 1) {
            keysMap.erase(key);
            removeKeyFromVector(key);
            return true;
        } else return false;
    }

    // it sets number of keys in hashtable to zero, it clears the hashtable by
    // looping through all elements and calling delete on every key
    // and its value
    void clear() {
        keysMap.clear();
        keys.clear();
    }

    // it returns value from value dynamic array that corresponds to the input
    // variable as a key.
    V getVal(const K key) {
        return keysMap[key];
    }
    // it sets value from value dynamic array that corresponds to the input
    // variable as a key.
    void setVal(K key, V value) {
        keysMap.erase(key);
        keysMap[key] = value;
    }
    // contain returns true if input is found in the keyType dynamic array,
    // and returns false otherwise.
    bool contains(K key) {
        if (keysMap.count(key) == 1) return true;
        else return false;
    }

    // returns the vector that stores all the keys
    vector<K> getKeys() {
        return keys;
    }

    // returns the vector that stores all the values
    vector<K> getVals() {
        return values;
    }
    // loops through the vector of keys and prints our all the key values
    void printKeys() {
        for (int i = 0; (unsigned)i < keys.size(); i++) cout << keys[i] << endl;
    }
    // removes the key passed in for input from the vector that stores all keys
    void removeKeyFromVector(K input) {
        for (int i = 0; (unsigned)i < keys.size(); i++) {
            if (keys[i] == input) keys.erase(keys.begin() + i);
        }
    }
private:
    // map that stores all the key value pairs
    map<K, V> keysMap;
    vector<K> keys; // stores all the keys
    vector<V> values;
    //int that represents length of Array
    int numOfKeys;
};

#endif // HASHTABLE_H
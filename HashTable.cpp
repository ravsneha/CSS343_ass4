/**
 * Sneha Ravichandran
 * Yusuf Pisan
 * CSS 343
 * Assignment 4
 *
 * March 14 2019
 */

#ifndef ASS_4_HASHTABLE_H
#define ASS_4_HASHTABLE_H

#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<vector>

using namespace std;

template<class Key, class Value>
class HashTable {
public:
    HashTable() {
        numOfKeys = 0;
    }

    HashTable(const Key k, const Value v) {
        numOfKeys++;
        keyMap[k] = v;
        keys.push_back(k);
    }

    int getNumOfEntries() {
        return numOfKeys;
    }

    Value *getVal(const Key &k) {
        return keyMap[k];
    }

    void setVal(const Key &k, const Value &v) {
        keyMap.erase(k), keyMap[k] = v;
    }

    vector<Key> getKeys() {
        return keys;
    }

    bool contains(const Key &k) {
        if (keyMap.count(k) == 1) return true;
        else return false;
    }

    bool isEmpty() {
        if (numOfKeys == 0) return true;
        else return false;
    }

    //remove by reference
    bool remove(const Key &k) {
        if (keyMap.count(k) == 1) {
            keyMap.erase(k);
            removeKey(k);
            return true;
        } else return false;
    }

    //remove by value
    void removeKey(Key k) {
        for (int i = 0; (unsigned) i < keys.size(); i++) {
            if (keys[i] == k) keys.erase(keys.begin() + i);
        }
    }

    void clear() {
        keyMap.clear(), keys.clear();
    }

    bool add(const Key &k, const Value &v) {
        if (keyMap.count(k) == 0) {
            numOfKeys++;
            keyMap[k] = v;
            keys.push_back(k);
            return true;
        } else return false;
    }

    void printKeys() {
        for (int i = 0; (unsigned) i < keys.size(); i++) {
            cout << keys[i] << endl;
        }
    }

private:
    map<Key, Value> keyMap;
    vector<Key> keys;
    int numOfKeys;
};

#endif //ASS_4_HASHTABLE_H

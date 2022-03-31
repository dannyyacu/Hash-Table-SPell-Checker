/*
 * Daniel Yacu:
 * Date Submitted: 3/09
 * Lab Section: 4
 * Assignment Name: Spell Checker using Hash Table
 */

#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

//Stringset class, do not modify definitions for existing members
class Stringset
{
    private:
        vector<list<string>> table;
        int num_elems;
        int size;
    public:
        Stringset();
        vector<list<string>> getTable() const;
        int getNumElems() const;
        int getSize() const;
        void insert(string word);
        bool find(string word) const;
        void remove(string word);
};
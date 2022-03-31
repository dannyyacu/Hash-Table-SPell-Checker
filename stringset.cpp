/*
 * Daniel Yacu:
 * Date Submitted: 3/09
 * Lab Section: 4
 * Assignment Name: Spell Checker using Hash Table
 */
 

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word){
    hash<string> stringHash;
    int bucket = (stringHash(word))%size;
    list<string> Words = table[bucket];

    if(num_elems == table.size()){

        int newSize = size*2;
        vector<list<string>> newTable(newSize);
        for(int col = 0; col < size; col++){
            Words = table[col];
            for (list<string>::iterator it=Words.begin(); it != Words.end(); ++it){
                string temp = *it;
                bucket = (stringHash(temp))%newSize;
                newTable[bucket].push_back(temp);
            }
        }
        size = newSize;
        table = newTable;
    }
    bucket = (stringHash(word))%size;
    Words = table[bucket];

    for (list<string>::iterator it=Words.begin(); it != Words.end(); ++it){
        if(*it == word){
            return;
        }
    }
    table[bucket].push_back(word);
    num_elems++;
}

bool Stringset::find(string word) const
{
    hash<string> stringHash;
    int bucket = (stringHash(word))%size;
    
    list<string> Words = table[bucket];
    for (list<string>::iterator it=Words.begin(); it != Words.end(); ++it){
        if(*it == word){
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    hash<string> stringHash;
    int bucket = (stringHash(word))%size;

    list<string> Words = table[bucket];
    for (list<string>::iterator it=table[bucket].begin(); it != table[bucket].end(); ++it){
        if(*it == word){
            it = table[bucket].erase(it);
            num_elems--;
        }
    }
}
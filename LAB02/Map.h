#ifndef Map_h
#define Map_h
#include <string>
#include <iostream>
using namespace std;

template <typename Domain, typename Range>
class Map{

public:
    Map(int n); // number of entries in the table
    ~Map();
    void add(Domain d, Range r, int i); // add an entry to the table
    bool lookup(Domain d, Range& r);
    Range returnr();
    int getX();

private:
    int numEntries;
    Domain* dArray;
    Range* rArray;
    int x;
};
#include "Map.cpp"
#endif
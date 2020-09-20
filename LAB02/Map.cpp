#include <string>
#include <iostream>
using namespace std;

template <typename Domain, typename Range>
Map<Domain,Range>::Map(int num){
    numEntries = num;
    dArray = new Domain[num];
    rArray = new Range[num];

} // number of entries in the table

template <typename Domain, typename Range>
void Map<Domain,Range>::add(Domain d, Range r, int i){
    dArray[i] = d;
    rArray[i] = r;
} // add an entry to the table

template <typename Domain, typename Range>
bool Map<Domain,Range>::lookup(Domain d, Range& r){
    for(int i = 0 ; i < numEntries; i++){
        if(dArray[i] == d){
            x = i;
            r = rArray[i];
            return true;
        }
    }
    return false;
}

template <typename Domain, typename Range>
Range Map<Domain,Range>::returnr(){
    return rArray[x];
}

template <typename Domain, typename Range>
int Map<Domain,Range>::getX(){
    return(x);
}

template <typename Domain, typename Range>
Map<Domain,Range>::~Map(){
    delete[] dArray;
    delete[] rArray;
}
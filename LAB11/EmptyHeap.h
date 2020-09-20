#ifndef EMPTYHEAP_H
#define EMPTYHEAP_H

#include <stdexcept>
using namespace std;
struct EmptyHeap : std::logic_error {
    using logic_error::logic_error; 
    EmptyHeap() : logic_error("The heap is empty\n") {}
};
#endif
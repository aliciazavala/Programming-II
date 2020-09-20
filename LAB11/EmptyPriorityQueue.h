#ifndef EMPTYPRIORITYQUEUE_H
#define EMPTYPRIORITYQUEUE_H

#include <stdexcept>
using namespace std;
struct EmptyPriorityQueue : std::logic_error {
    using logic_error::logic_error; 
    EmptyPriorityQueue() : logic_error("The priority queue is empty\n") {}
};
#endif
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "PriorityQueue.h"
#include "Heap.h"
#include "Staff.h"

#include <iostream>
#include <string>
 
using namespace std;

class Executive
{
private:


public:
  Executive(string filename);
  ~Executive();
  void showStatus(PriorityQueue<Staff> pq);
  /*
  request: The first and last name of the person submitting the request and the priority that your staff assigned.
  A new instance of an appropriate class for this request is to be created and added to the PriorityQueue.*/
  void request();
  /*fix: The next request is removed from the PriorityQueue, a descriptive statement is written to the console
  stating whose power station has just been fixed.*/
  void fix();
  /*status: Pass your PriorityQueue to the Executive's showStatus method. This method will report the order that
  all current requests will be served, assuming that no new requests arrive. It does this by peeking at and removing
  all requests from the PriorityQueue passed in until the priority queue is empty. Since it was passed by value, this
  will have no effect on the main priority queue being managed. It should produce a report something like: */
  void status();
};

#endif

#include "Executive.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Executive::Executive(string filename)
{
    ifstream inFile;
    inFile.open(filename);
    if(inFile.is_open())
    {
      int size;
      string name; 
      string last;
      int priority;
      string service;
      inFile>>size;
      PriorityQueue<Staff> pq(size);
      while(inFile>>service)
      {
        if(service == "request")
        {
          inFile>>name>>last>>priority;
          Staff x(name,last,priority);
          pq.enqueue(x);
        }
        if(service == "fix")
        {
          try
          {
            cout<<pq.peekFront()<< " has been fixed.\n";
            if(pq.isEmpty() == false)
            {
              pq.dequeue();
            }
          }
          catch(EmptyPriorityQueue& error)
          {
            cout<<error.what();
          }
        }
        if(service == "status")
        {
          showStatus(pq);
        }
      }
    }
    else
    {
      cout<<"Invalid File!!\n";
    }
}

Executive::~Executive()
{

}

void Executive::showStatus(PriorityQueue<Staff> pq)
{
  try
  {
      pq.peekFront();
    cout<<"\n========== Assuming no new requests, the current set of service requests will be processed as follows ===========\n";
    while(pq.isEmpty() != true)
    {
      
        cout<<pq.peekFront()<<'\n';
        pq.dequeue();
      
      
    }
    cout<<"========= End of Status ==============\n";
  }
  catch(EmptyPriorityQueue& error)
  {
    cout<<error.what();
  }
}

#include "Executive.h"

#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
  if(argc < 2)
  {
      cout<<"Incorrect number of parameters!\n";
  }
  else
  {
    Executive exec(argv[1]);
  }
  return(0);
}

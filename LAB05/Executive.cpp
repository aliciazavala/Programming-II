#include "Executive.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;
Executive::Executive(string filename)
{
    inFile.open(filename);
    run();
}
void Executive::run()
{
    Queue<Stack<Function>*> proc;
    Command com;
    string command;
    LinkedList<string> names;
    int i=1;
    while(inFile>>command)
    {
        if(command == "START")
        {
            inFile>>command;
            names.setEntry(i,command);
            com.Start(proc,inFile,command);

        }
        else if(command ==  "CPU")
        {
            com.Cpu(proc,names);
        }
        else if(command == "STATUS")
        {
            com.Status(proc,names);
        }
        else if(command == "THROW")
        {
            com.Throw(proc,names);
        }
        i = i+1;

    }
    names.clear();

}

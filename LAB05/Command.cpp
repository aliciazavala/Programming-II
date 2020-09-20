#include "Command.h"
#include "Function.h"
using namespace std;

void Command::Start(Queue<Stack<Function>*>& proc,ifstream& inFile,string command)
{
    Stack<Function>* func = new Stack<Function>;
    inFile>>command;
    string status;
    while(command != "0")
    {
        inFile>>status;
        Function f(command,status);
        try{
        func->push(f);
        }
        catch(PrecondViolatedExcep& excep)
        {
            cout<<excep.what();
        }
        inFile>>command;
    }
    try{
    proc.enqueue(func);
    }
    catch(PrecondViolatedExcep& excep)
    {
        cout<<excep.what();
    }

}

void Command::Cpu(Queue<Stack<Function>*>& proc,LinkedList<string>& names)
{
    if(proc.peekFront()->isEmpty()==true)
    {
        proc.dequeue();
        cout<<"Process "<<names.getEntry(names.getLength())<<" has ended succesfully.\n";
        names.removeBack();
    }
    else
    {
        proc.peekFront()->pop();
        proc.enqueue(proc.peekFront());
        proc.dequeue();
        names.insert(1,names.getEntry(names.getLength()));
        names.removeBack();
    }
}

void Command::Throw(Queue<Stack<Function>*>& proc,LinkedList<string>& names)
{  
    if(proc.peekFront()->isEmpty()==true )
      {

            proc.dequeue();
            cout<<"Process "<<names.getEntry(names.getLength())<<" has ended due to an unhandled exception.\n";
            names.removeBack();

      }
      else if(proc.peekFront()->peek().Status() == false)
      {
          for(;;)
          {
              proc.peekFront()->pop();
              if(proc.peekFront()->peek().Status() != false)
              {
                break;
                }

          }
      }

}
void Command::Status(Queue<Stack<Function>*>& proc,LinkedList<string>& names)
{
    if(proc.peekFront()->isEmpty()==true)
    {
        cout<<"Process "<<names.getEntry(names.getLength())<<" is running function main \n";
    }
    else
    {
        cout<<"Process "<<names.getEntry(names.getLength())<<" is running the function "<<proc.peekFront()->peek().getName()<<'\n';
    }
}

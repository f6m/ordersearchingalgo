#include "orden_implementation.h"
#include <iostream> // i/o functions
#include <vector>   // vector claass
#include <cstdlib>  // exit function

// We have troubles dividing our initial code: 
//order_implementation.h : Class implementation
//order_interface.cpp : Class interfaz
//main.cpp : Class execution

//Compilation g++ main.cpp -g
//Degugging gdb a.out, for break member fuctions:.....

//Justification:
//Templates need to be instantiated by the compiler before actually compiling them into object code. This instan//tiation can only be achieved if the template arguments are known. Now imagine a scenario where a template func//tion is declared in a.h, defined in a.cpp and used in b.cpp. When a.cpp is compiled, it is not necessarily kno//wn that the upcoming compilation b.cpp will require an instance of the template, let alone which specific inst//ance would that be. For more header and source files, the situation can quickly get more complicated.

//Alternative solution: add order_implementation.cpp

//C++ Templates code should always be put in a header file so the implementation will be visible in every transl//ation unit where you would like to instantiate the template. If you like you can separate the code to *.h and //*.cpp files but you should still #include *.cpp file at the end of *.h file.

//Sort Algorithms to be exemplified:

//+Shell
//+Quicksort
//+Bubble Sort
//+Selection
//+Insertion

//Search Algorithms to be exemplified:

//+Sequential
//+Binary
//+Interpolation

//how to use this in other code?

using namespace::std;

//algord< int > s(10,*argv[1]); //Creamos un objeto, instancia de la clase para ordenar 10 numeros reales y con un orden: o > o <.

// Main program including command line parameters.
int main(int argc,char *argv[])
{
  if (argc != 2) //Se tiene que pasar el orden a utilizar: ./a.out <, ./a.out >
    cout << "Uso: ./a.out </> \n";
  else
    {
  cout << "Sorting Algorithm Examples" <<endl;
  cout << "Vector to order:" <<endl;
  algord<char> s(10,*argv[1]); //An instance (object) of class algord is created, to sort 10 integers with order  > o <.
  cout<<endl;
  cout << "Random entry type:"<< s.ramt(97,122) <<endl; //97 = a, 122 = z
  s.selectsort();
  cout<<"\n";
  cout << "Ordered vector:" <<endl;
  s.ptrvect();
  cout << "Introduce value to search:"<<endl;
  char val;
  cin>>val;
  if(s.binary(val) != -1)
    {
      cout << "Data:"<<val<<endl;
      cout << "founded with binary search at index:"<<s.sequential(val)<<endl;
    }
  else{
    cout << "Data:"<<val<<endl;
    cout << "Not founded"<<endl;
   }

 } //end else
exit(0);
}




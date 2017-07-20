
#ifndef ORDERSEARCH_H
#define ORDERSEARCH_H // To avoid distinct files with this name class 

#include <iostream>
#include <vector>
#include <ctime>    // library to function time
#include <cstdlib>  // library to functions srand/rand
#include <cmath>    // for floor

using namespace std;

// CLASS IMPLEMENTATION/DEFINITION, using Templates 

template<class T> //we only need template for vector V
class algord
{
public: //Class Interface
  algord(int n, char ord);//Constructor
  ~algord();//Destructor
  void bubblesort();  
  void shell();//Function for Shell algorithm
  void quicksort(int izq, int der);//Function for Quicksort algorithm, needs index: left right
  void insertsort(); // Member function for Insertion sort algorithm
  void selectsort(); // Member function for Selection sort algorithm
  void ptrvect(); //Public function to print ordered vector
  T ramt(T low, T up); //Each time this function is called we generate a random T type
  T ramt(int a, int b); //homonimum function
  int sequential(T a); //Function for search a data in V
  int binary(T a); //Function for binary search

protected://Implementacion de la clase
  vector<T> V; // Define a vector with entries of type T
  int N; // Size of vector
  char orden; // Character to indicate desired order: '<' or '>'
  bool order(T a, T b); //This funcion is protected since only is occupied by sorting algorithms
}; //End class definition


// CLASS INTERFACE 

// Class Constructor
template<typename T>
algord<T>::algord(int n, char ord)
{
  //Test to verify size parameter n
  n > 0 ? n : 10; 
   
  //srand(static_cast time(0)));
  //Code block to fill up vector with random entries type T 
  srand(time(NULL)); //Seed for random functions

  for(int i=0; i < n; i++) {
    V.push_back(ramt(97,122)); //Introduce a V un tipo de dato T producido aleatoriamente
    std::cout<< i << "\t" << V[i] << "\n";
    } // Fin For
  N = V.size(); //Fix vector sizer
  orden = ord; //Fix order to use:  > or <
} //End Constructor


// Class Destroyer
template<typename T>
algord<T>::~algord()
{
  //Libera la memoria creada en el constructor
  //V.clear(); //Borra los elementos del vector
}
// Homonimum ramt for interger/char values
template<typename T>
T algord<T>::ramt(int a, int b)
{
  return static_cast <T> (a + rand() % (b - a)); //returns a random integer in [a,b]
}

//Function to randomly generate data tipes T
template<typename T>
T algord<T>::ramt(T low, T up)
{
  // return static_cast <T> (rand()); //rand() generates a pseudo-random number
  // between 0 and RAND_MAX, thus dividing in RAND_MAX creates values in [0,1], modulus
  // operation generates a random number result of dividing by 100 thus between 0 and 99.
  return static_cast <T> (rand()) * (up - low) / RAND_MAX + low;
}


//Funcion to compare according to order given
template<typename T>
bool algord<T>::order(T a,T b)
{
  switch(orden)
    {
    case '<': return (a < b)? true : false; break;
    case '>': return (a > b)? true : false; break;
    }
}

//Blubble sort algorithm
template<typename T>
void algord<T>::bubblesort()
{
  T inter; //intermediate value to save vector entries
  int s=0; //signal variable
  int i=0;
  while(s == 0 && i < N)
    {
      s = 1;
      for(int j=0; j < N; j++)
	   { 
	  if(order(V[j],V[j+1]) && j+1 < N) //Next entry is small avoid comparations out of range
	    {
	      inter = V[j+1]; //Swap V[j]<->V[j+1]
	      V[j+1] = V[j];
	      V[j] = inter;
	      s = 0; 
 	    }
         }// End for
      i++;
     }// End while 
} // End bubblesort

//InsertionSort algorithm
template<typename T>
void algord<T>::insertsort()
{
  T inter; //intermediate value to save vector entries
  int j;
  for(int i = 0; i < N; i++) //index i starts at 0, V[0] is ordered
    {
     j = i;
     while(order(V[j],V[j-1]) && j>0) //Next entry is small avoid comparations out of range
       {
	 inter = V[j-1]; //Swap V[j]<->V[j+1]
	 V[j-1] = V[j];
	 V[j] = inter;
	 j--;
       } //End While
    }// End for
}// End InsertionSort

//InsertionSort algorithm
template<typename T>
void algord<T>::selectsort()
{
  T inter; //intermediate value to save vector entries
  int min; //Assumed Minimum
  int i,j;
  
  for(i = 0; i < N; i++) //index i starts at 0, V[0] is ordered
    {
     min = i;
     for(j=i+1; j <= N;j++)
       {
	 if(order(V[j],V[min])) //Next entry is small avoid comparations out of range
	   {
	     min = j;
	   } //End If
       }// End for
     inter = V[i]; //Swap V[i]<->V[ord]
     V[i] = V[min];
     V[min] = inter;
   }// End for
}// End SelectSort

template<typename T>
void algord<T>::shell()
{
  //Ordena el vector de forma creciente de acuerdo al algoritmo de Shell
  int inter;
  int i;

  for(inter = N / 2;inter > 0; inter /= 2) //Definimos la secuencia a inspeccionar N/2,N/4,N/8,...N/2^k,2,1 (secuencia original de Shell)
    {
      for(i=inter; i < N; i++)
	{
         T tmp = V[i];
	 int j;
	 for(j = i;j >= inter && order(V[j-inter],tmp);j-=inter)
	    V[j]=V[j-inter];
	   
	 V[j] = tmp;
	} //fin for2
    } //fin for1
} //fin shell

template<typename T> //Tipo de dato typename
void algord<T>::quicksort(int izq, int der)
{
     int i = izq, j = der, aux; 
     string p = V[(izq + der) / 2];  // Vector con pivote central 
     string tmp;                         

     while (i <= j)                     
     { 
       while (order(V[i],p)) i++;     // los condicionales empleados dentro de la estructura indican los limites del primer elemto y el ultimo 
       while (order(p,V[j])) j--;     // para poder rolar de un elemnto a otro tenemos nuestra variable tmp, aqui mismo se determinara si el 
          if (i <= j)                  // ordenamiento esta en su principio o en el final de cada una de los subarreglos
           { 
               tmp = V[i]; 
               V[i] = V[j]; 
               V[j] = tmp; 
               i++; j--; 
          } 
     } 

     if (izq < j) 
          quicksort(izq, j);    // dentro de los parametros se estipula que izq debe ser menor que j y nunca podra sobrepasar el lugar del ultimo
     if (i < der)               //  del lado derecho y viceversa.
          quicksort(i, der); 

} //fin quicksort

//Function to print current vector
template<typename T>
void algord<T>::ptrvect()
{
 typename vector<T>::iterator it; //Iterador para desplazarnos en el vector, needs typename before
 for(it=V.begin();it<V.end();it++)
   cout<<(*it)<<endl;
}

//// Search algorithms

//algord class function for sequential search algorithm

template<typename T>
int algord<T>::sequential(T a)
{
  int i=-1;
  while(V[++i] != a && i < N);
  return i;     
} // End Sequential

//algord class function for sequential search algorithm
template<typename T>
int algord<T>::binary(T a)
{
  int m, mid;
  m = floor(N/2);
  mid = 0;
  while(abs(m-mid) > 0 && V[m] != a)
  {
    mid = m;
    if( order(V[m],a) )
       m = floor(m/2);
       else
	 m = floor((N-m)/2);  
  }
 return (V[m]==a)? m: -1;     
} // End Sequential

#endif //ORDERSEARCH_H

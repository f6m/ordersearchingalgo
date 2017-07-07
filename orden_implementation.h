
#ifndef ORDER_H
#define ORDER_H // To avoid distinct files with this name class 

#include <iostream>
#include <vector>
#include <ctime>    // library to function time
#include <cstdlib>  // library to functions srand/rand

using namespace std;

// CLASS IMPLEMENTATION/DEFINITION, using Templates 

template<class T> //we only need template for vector V
class algord
{
public: //Interfaz de la clase
  algord(int n, char ord);//Constructor
  ~algord();//Destructor
  void shell();//Function for Shell algorithm
  void quicksort(int izq, int der);//Function for Quicksort algorithm, needs index: left right
  void ptrvect(); //Public function to print ordered vector
  T ramt(T low, T up); //Each time this function is called we generate a random T type

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
    V.push_back(ramt(1.0,10.0)); //Introduce a V un tipo de dato T producido aleatoriamente
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
         double tmp = V[i];
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

#endif //ORDER_H

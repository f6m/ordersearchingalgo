// Implementacion del algoritmo de ordenacion de Shell
// Algoritmo de Shell presentado en R&K 2da edicion
// Elaborado por f6m

//Compilacion en Ubuntu 14.04
//#g++ shell.cpp -lm -g
//#./a.out '<'
//#./a.out '>'

//Incluir un template que considere el vector con distintos tipos de datos
//Incluir una opcion que permita dos tipos de orden </> en base a los parametros de ejecucion

#include <iostream>
#include <vector>
#include <string>
#include <list> //para las listas
#include <limits> // for numeric_limits
#include <set> //Set class para definir set
#include <utility> // for pair
#include <algorithm> 
#include <iterator> // libreria para el iterador del conjunto
#include <ctime> //libreria para la funcion time
#include <cstdlib> //libreria para las funciones srand/rand   

using namespace std; 
typedef vector<double> Vec; //Definicion de tipo nueva: Vec

//Implementacion de la clase 
//template shell<T>
class shellexam
{
public: //Interfaz de la clase
  shellexam(int n, char ord);//Constructor
  ~shellexam();//Destructor
  void shell();//Funcion con el algoritmo de shell
  void ptrvect();//Funcion para mostrar el vector
  bool order(double a, double b);
protected://Implementacion de la clase
  Vec V;
  int N;
  char orden; 
};

//Interfaz de la clase

//Constructor
shellexam::shellexam(int n, char ord)
{
  //Crea el vector 
  //Llena el vector con numeros aleatorios 
  srand(time(NULL));
  //srand(static_cast time(0)));
  for(int i=0; i < n; i++) {
    V.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX)); //Introduce un numero aleatorio en el intervalo [0,1]
    cout<< i << "\t" << V[i]<< "\t" << V.back() << "\n";
    } // Fin For
  N = V.size(); //Fija el numero de tama~no de elmentos del vector
  orden = ord; //fija el orden a usar > o <
} //fin constructor


//Destructor
shellexam::~shellexam()
{  //Libera la memoria creada en el constructor
  V.clear(); //Borra los elementos del vector
}

//Funcion para ordenarar dos enteros
bool shellexam::order(double a, double b)
{
  switch(orden)
    {
    case '<': return (a < b)? true : false; break;
    case '>': return (a > b)? true : false; break;
    }
}
      
void shellexam::shell()
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

void shellexam::ptrvect()
{
vector<double>::iterator it; //Iterador para desplazarnos en el vector 
 for(it=V.begin();it<V.end();it++)
   cout<<(*it)<<endl;
}

// Programa principal con entradas de parametros.
int main(int argc,char *argv[])
{
  if (argc != 2) //Se tiene que pasar el orden a utilizar: ./a.out <, ./a.out >
    cout << "Uso: ./a.out </> \n";
  else
    {
  cout << " Ejemplo del Algoritmo de Shell" <<endl;
  shellexam s(10,*argv[1]); //Creamos un objeto, instancia de la clase para ordenar 10 numeros reales y con un orden: o > o <.

  s.shell();
  cout<<"\n";
  s.ptrvect();
    }
exit(0);
  
}

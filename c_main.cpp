#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "funciones.h"
#include "vectores.h"

using namespace std;

int main() {
  string doc,cache,cache2;
  ifstream archivo;
  vector<vector<string>> cache_vector;vector<vector<string>>cache_vector2;

  cout<<"---BIENVENIDO AL EDITOR DE TEXTO---"<<endl<<endl;
  do{
  cout<<"Nombre del archivo: ";cin>>doc;cout<<endl;
  archivo.open(doc,ios::in);
  
  }while(archivo.fail());
  cache=leer(doc);
  cache2=cache;
  cache_vector = leer_vector(doc);
  cache_vector2 = cache_vector;
  int anterior=100;
  opciones(doc,cache,cache2,cache_vector,cache_vector2,anterior);}

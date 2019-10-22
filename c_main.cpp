#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "funciones.h"

using namespace std;

int main() {
  string doc,cache,cache2;
  ifstream archivo;

  cout<<"---BIENVENIDO AL EDITOR DE TEXTO---"<<endl<<endl;
  do{
  cout<<"Nombre del archivo: ";cin>>doc;cout<<endl;
  archivo.open(doc,ios::in);
  
  }while(archivo.fail());
  cache=leer(doc);
  cache2=cache;
  opciones(doc,cache,cache2);

}

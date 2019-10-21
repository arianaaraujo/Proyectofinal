//Segunda opción

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

using namespace std;

int main() {
  string doc,texto2;

  cout<<"---BIENVENIDO AL EDITOR DE TEXTO---"<<endl<<endl;
  cout<<"Nombre del archivo: ";cin>>doc;cout<<endl;

  ifstream archivo;
  archivo.open(doc,ios::in);

  if(archivo.fail()){
    cout<<"El archivo no existe."<<endl;
    cout<<"Nombre del archivo: ";cin>>doc;cout<<endl;
  };

  opciones(doc);

}

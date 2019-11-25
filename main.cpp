#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "CArchivo.h"
using namespace std;

int main() {
  string doc;
  ifstream archivo;
  cout<<"---BIENVENIDO AL EDITOR DE TEXTO---"<<endl<<endl;
  do{cout<<"Nombre del archivo: "; cin>>doc; cout<<endl;
  archivo.open(doc,ios::in);} while(archivo.fail());
  int limite=0;
  cout<<"Ingrese el limite: ";
  cin>>limite;
  CArchivo documento(doc, limite);
  }

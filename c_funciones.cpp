#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
using namespace std;

//Opciones:
void text(){
  cout<<"0.  Salir"<<endl<<"1.	Leer archivo"<<endl<<"2.	Guardar archivo"<<endl<<"3.	Justificar"<<endl<<"4.	Alinear a la derecha"<<endl<<"5.	Alinear a la izquierda"<<endl<<"6.	Centrar texto"<<endl<<"7.	Buscar una palabra"<<endl<<"8.	Reemplazar una palabra"<<endl<<"9.	Contar cuántas veces aparece una palabra"<<endl<<"10.	Guardar como PDF"<<endl;    
}

void guardar(string cache, string texto){
  ofstream archivo;
  archivo.open(texto);
  for (int i=0;i<cache.size();i++){
    archivo<<cache[i];
  }
}

string leer(string texto){
  string linea, cache;
  ifstream file(texto.c_str());
	while(getline(file,linea))
		cache+=linea+"\n";
    return cache;
}
//Leer archivo
void mostrar(string texto){
  string texto2;
    ifstream archivo;
    archivo.open(texto,ios::in);
    if(!archivo.fail()){
      while(!archivo.eof()){
       getline(archivo,texto2);
       cout<<texto2<<endl;
     }  archivo.close();}
    cout<<endl;
}

//Centrar texto
void centrar(string & texto){
    string texto2,texto3;
    for(int i=0;i<texto.size();i++){
      texto2+=texto[i];
      if(texto[i]=='\n'){
        int a=texto2.size();
        for(int i=0;i<(40-(a/2));i++){
          texto3+=" ";}texto3+=texto2;
         texto2=" ";
      }}
      texto=texto3;}
      
//Alinear a la derecha
void derecha(string texto){
    string texto2;
    ifstream archivo;
    //ofstream archivo1;
    archivo.open(texto,ios::in);
    //archivo1.open(texto,ios::app);

    if(!archivo.fail()){
      while(!archivo.eof()){
       getline(archivo,texto2);
       int a=texto2.size();
       for(int i=0;i<a;i++){
         cout<<setw(95)<<right;
         //archivo1<<setw(90)<<right;
       }
       cout<<texto2<<endl;
     }  archivo.close();}
    cout<<endl;
}

//Alinear a la izquierda
void izquierda(string texto){
    string texto2;
    ifstream archivo;
    //ofstream archivo;
    archivo.open(texto,ios::in);
    //archivo.open(texto,ios::app);

    if(!archivo.fail()){
      while(!archivo.eof()){
       getline(archivo,texto2);
       int a=texto2.size();
       for(int i=0;i<a;i++){
         cout<<left<<setw(90);}
       cout<<texto2<<endl;
     }  archivo.close();}
    cout<<endl;
}
void print(string cache){
  for (int i=0;i<cache.size();i++){
    cout<<cache[i];
  }
}

void opciones(string texto,string cache){
  int opcion;
  text();
  cout<<endl<<"Ingresar opción: "; cin>>opcion;cout<<endl;

  switch(opcion){
    case 0:
    cout<<"Hasta luego!"<<endl;break;
    case 1:
    mostrar(texto);
    opciones(texto,cache);break;
    case 2:
    guardar(cache,texto); opciones(texto,cache); break;
    //case 3:
    //justificar(cache);opciones(texto);break;
    case 4:
    derecha(texto); opciones(texto,cache); break;
    case 5:
    izquierda(texto); opciones(texto,cache); break;
    case 6:
    centrar(cache); print(cache); opciones(texto,cache);break;  
    }
}
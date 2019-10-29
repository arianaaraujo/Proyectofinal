#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "funciones.h"
#include "vectores.h"
using namespace std;

//Opciones:
void text(){
  cout<<endl<<"0.  Salir"<<endl<<"1.	Leer archivo"<<endl<<"2.	Guardar archivo"<<endl<<"3.	Justificar"<<endl<<"4.	Alinear a la derecha"<<endl<<"5.	Alinear a la izquierda"<<endl<<"6.	Centrar texto"<<endl<<"7.	Buscar una palabra"<<endl<<"8.	Reemplazar una palabra"<<endl<<"9.	Contar cuántas veces aparece una palabra"<<endl<<"10.	Guardar como PDF"<<endl;    
}

void guardar_string(string cache, string texto){
  ofstream archivo;
  archivo.open(texto);
  for (int i=0;i<cache.size();i++){
    archivo<<cache[i];
  }
  cout<<"ARCHIVO GUARDADO CON EXITO :D!"<<endl<<endl;
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
    ;
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
void derecha(string &texto){
    string texto2,texto3;
    for(int i=0;i<texto.size();i++){
      texto2+=texto[i];
      if(texto[i]=='\n'){
        int a=texto2.size();
        for(int i=0;i<(80-a);i++){
          texto3+=" ";}texto3+=texto2;
         texto2=" ";
      }}
      texto=texto3;}


//Alinear a la izquierda
void izquierda(string texto){
    string texto2,texto3;
    for(int i=0;i<texto.size();i++){
      texto2+=texto[i];
      if(texto[i]=='\n'){
        int a=texto2.size();
        for(int i=0;i<(80-a);i++){
          texto2+=" ";}
      }}
      texto2=texto3;}

void print(string cache){
  for (int i=0;i<cache.size();i++){
    cout<<cache[i];
  }
}

void opciones(string texto,string cache,string cache2,vector<vector<string>> cache_vector,vector<vector<string>>cache_vector2, int anterior){
  int opcion;
  text();
  cout<<endl<<"Ingresar opción: "; cin>>opcion;cout<<endl;

  switch(opcion){
    case 0:
    cout<<"Hasta luego!"<<endl;break;
    case 1:
    mostrar(texto);
    opciones(texto,cache,cache2,cache_vector,cache_vector2,1);break;
    case 2:
    if(anterior==3){guardar_vector(cache_vector,texto);}
    else if(anterior==2){cout<<"ACABAS DE GUARDAR EL TEXTO"<<endl; }
    else {guardar_string(cache2,texto);}
    opciones(texto,cache,cache2,cache_vector,cache_vector2,2); break;
    case 3:
    if (cache_vector2!=cache_vector)cache_vector2=cache_vector;
    justificar(cache_vector2); print_v(cache_vector2); opciones(texto,cache,cache2,cache_vector,cache_vector2,3);break;
    case 4:
    if (cache2!=cache)cache2=cache;
    derecha(cache2); print(cache2); opciones(texto,cache,cache2,cache_vector,cache_vector2,4); break;
    case 5:
    if (cache2!=cache)cache2=cache;
    izquierda(cache2); print(cache2); opciones(texto,cache,cache2,cache_vector,cache_vector2,5); break;
    case 6:
    if (cache2!=cache)cache2=cache;
    centrar(cache2); print(cache2); opciones(texto,cache,cache2,cache_vector,cache_vector2,6);break;  
    }
}

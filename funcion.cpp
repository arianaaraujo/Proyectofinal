#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iomanip>

using namespace std;

//Opciones:
void text(){
  cout<<"1.	Leer archivo"<<endl<<"2.	Guardar archivo"<<endl<<"3.	Justificar"<<endl<<"4.	Alinear a la derecha"<<endl<<"5.	Alinear a la izquierda"<<endl<<"6.	Centrar texto"<<endl<<"7.	Buscar una palabra"<<endl<<"8.	Reemplazar una palabra"<<endl<<"9.	Contar cuántas veces aparece una palabra"<<endl<<"10.	Guardar como PDF"<<endl<<"0. Salir."<<endl;    
}

//Leer archivo
void leer(string &texto){
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
void centrar(string &texto){
    string texto2;
    ifstream archivo;
    //ofstream archivo;
    archivo.open(texto,ios::in);
    //archivo.open(texto,ios::app);

    if(!archivo.fail()){
      while(!archivo.eof()){
       getline(archivo,texto2);
       int a=texto2.size();
       for(int i=0;i<(40-(a/2));i++){
         cout<<" ";
         //archivo<<" ";
       }
       cout<<texto2<<endl;
     }  archivo.close();}
    cout<<endl;
}

//Alinear a la derecha
void derecha(string &texto){
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
void izquierda(string &texto){
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
         cout<<left<<setw(90);
         //archivo<<setw(90)<<right;
       }
       cout<<texto2<<endl;
     }  archivo.close();}
    cout<<endl;
}

void opciones(string &texto){
  int opcion;string texto2;

  text();
  cout<<endl<<"Ingresar opción: "; cin>>opcion;cout<<endl;

  switch(opcion){
    case 0:
    cout<<"Hasta luego!"<<endl;break;
    case 1:
    leer(texto);
    opciones(texto);break;
    //case 3:
    //justificar(texto);opciones(texto);break;
    case 4:
    derecha(texto); opciones(texto); break;
    case 5:
    izquierda(texto); opciones(texto); break;
    case 6:
    centrar(texto); opciones(texto);break;  
    }
  }

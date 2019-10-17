#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
using namespace std;
//Opcion 1
void leer(){
  string linea,nombre;
  cout<<endl<<"Ingrese nombre del archivo a abrir: ";
  cin>>nombre;
  //crea un objeto para leer un archivo
  ifstream archivo (nombre);
  //comprueba que el archivo existe
  //si existe lo abre
  if (archivo.is_open())
    //imprime linea por linea
    {while (getline(archivo,linea)){
      cout<<linea<<endl;}
      //cierra el archivo
      archivo.close();
    }
  //si no existe termina el programa
  else{
    cout<<"Archivo no existente"<<endl;
    leer();}
    opciones();
  }

//Opcion 2
void guardar(){
  string nombre;
  int formato;
  cout<<endl<<"Ingrese nombre del archivo a grabar: ";
  cin>>nombre;
  cout<<endl<<"Ingrese opcion para guardar archivo: "<<endl<<"1 (justificar)"<<endl<<"2 (alinear a la izquierda)"<<endl<<"3 (alinear a la derecha)"<<endl<<"4 (centrar)"<<endl;
  cin>>formato;
  //objeto para escribir en un archivo
  ofstream archivo(nombre, ios::app); 
  if (archivo.is_open()){
    //aqui llamara a las sgtes funciones
    switch (formato){
  case 1:
    archivo<<"justificado"<<endl;
    archivo.close();
    break;
  case 2:
    archivo<<"izquierda"<<endl;
    archivo.close();
    break;
  case 3:
    archivo<<"derecha"<<endl;
    archivo.close();
    break;
  case 4:
    archivo<<"centro"<<endl;
    archivo.close();
    break;
  default:
    break;
}}
  //si no existe termina el programa
  else
    cout<<"Archivo no existente"<<endl;
  opciones();
}
void opciones(){
  cout<<endl<<endl<<"1.	Leer archivo"<<endl<<"2.	Guardar archivo"<<endl<<"3.	Justificar"<<endl<<"4.	Alinear a la derecha"<<endl<<"5.	Alinear a la izquierda"<<endl<<"6.	Centrar texto"<<endl<<"7.	Buscar una palabra"<<endl<<"8.	Reemplazar una palabra"<<endl<<"9.	Contar cunatas veces aparece una palabra"<<endl<<"10.	Guardar como PDF";
  int opcion;
  cout<<endl<<endl<<"Ingrese opcion (0 para finalizar programa): "; cin>>opcion;
  switch(opcion){
    case 1:
      leer();
      break;
    case 2:
      guardar();
      break;
    case 0:
      cout<<"GRACIAS!!!"<<endl;
      break;
    default:
      cout<<"Esa no es una opcion valida"<<endl<<"Intentalo de nuevo";
      opciones();
      break;  }}

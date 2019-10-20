#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
using namespace std;
//Opcion 1
vector<string> split(string str, char pattern) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;

    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);
    }

    return resultados;
}
void leer(vector<vector<string>>&texto){
  string linea,nombre;
  cout<<endl<<"Ingrese nombre del archivo a abrir: ";
  cin>>nombre;
  //crea un objeto para leer un archivo
  ifstream archivo (nombre);
  //comprueba que el archivo existe
  //si existe lo abre

  if (archivo.is_open())
    //imprime linea por linea
    {
      while (getline(archivo,linea)){


          //cout<<linea<<endl;

          vector<string> resultados;

          resultados = split(linea, ' ');

          /*for(int i = 0; i < resultados.size(); i++){
              cout << resultados[i] << endl;
          }*/

          texto.push_back(resultados);

      }
      //cierra el archivo
      archivo.close();

    }
  //si no existe termina el programa
  else{
    cout<<"Archivo no existente"<<endl;
    leer(texto);}
    opciones(texto);
  }

//Opcion 2
void derecha(vector<vector<string>>&texto)
{
   int mayor=0;
    for(int i=0; i < texto.size();i++){
        int longitud = 0;
        for(int j =0; j < texto[i].size(); j++){
            longitud = longitud + texto[i][j].size() +1;
        }
        longitud -= 1;
        if(longitud > mayor) mayor = longitud;
    }

    for(int i=0; i < texto.size(); i++){
        int longitud = 0;
        for(int j =0; j < texto[i].size(); j++){
            longitud = longitud + texto[i][j].size() +1;
        }
        longitud -= 1;
        int dif = mayor - longitud;
        for(int j=0; j < dif ; j++) cout << " ";
        for(int j=0; j < texto[i].size(); j++){
            cout << texto[i][j] << " ";
        }
        cout << endl;
    }


}

void guardar(){
  string nombre;
  int formato;
  cout<<endl<<"Ingrese nombre del archivo a grabar: ";
  cin>>nombre;
  /*
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
  */
}
void opciones(vector<vector<string>>&texto){
  cout<<endl<<endl<<"1.	Leer archivo"<<endl<<"2.	Guardar archivo"<<endl<<"3.	Justificar"<<endl<<"4.	Alinear a la derecha"<<endl<<"5.	Alinear a la izquierda"<<endl<<"6.	Centrar texto"<<endl<<"7.	Buscar una palabra"<<endl<<"8.	Reemplazar una palabra"<<endl<<"9.	Contar cunatas veces aparece una palabra"<<endl<<"10.	Guardar como PDF";
  int opcion;
  cout<<endl<<endl<<"Ingrese opcion (0 para finalizar programa): "; cin>>opcion;
  switch(opcion){
    case 1:
      leer(texto);
      break;
    case 2:
      guardar();
      break;
    case 4:
      derecha(texto);
      break;
    case 0:
      cout<<"GRACIAS!!!"<<endl;
      break;
    default:
      cout<<"Esa no es una opcion valida"<<endl<<"Intentalo de nuevo";
      opciones(texto);
      break;  }}

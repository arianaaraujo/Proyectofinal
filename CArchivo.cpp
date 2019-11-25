#include "CArchivo.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
using namespace std;
int limite=0;
void CArchivo::text(){
  cout<<endl<<"0.\tSalir"<<endl<<"1.\tLeer archivo"<<endl<<"2.\tGuardar archivo"<<endl<<"3.\tJustificar"<<endl<<"4.\tAlinear a la derecha"<<endl<<"5.\tAlinear a la izquierda"<<endl<<"6.\tCentrar texto"<<endl<<"7.\tBuscar una palabra"<<endl<<"8.\tReemplazar una palabra"<<endl<<"9.\tContar cuántas veces aparece una palabra"<<endl<<"10.\tGuardar como PDF"<<endl;}

string CArchivo::ltrim(string str){
      string aux;
      string linea;
      for (size_t i=0;i<str.size();i++){
        linea+=str[i];
        if (str[i]=='\n'){
        linea.erase(0,linea.find_first_not_of(" "));
        linea.erase(linea.find_last_not_of(" ") + 1);
        aux+=linea; linea="";}}
      return aux;}
     
void CArchivo::mostrar(){
      string texto2;
      ifstream archivo;
      archivo.open(this->nombre,ios::in);
      if(!archivo.fail()){
        while(!archivo.eof()){
        getline(archivo,texto2);
        cout<<texto2<<endl;
      }  archivo.close();}}

void CArchivo::setCache(string &str){
      string linea;
      ifstream archivo(this->nombre);
      while(getline(archivo,linea))
        str+=linea+"\n";}
        
vector<string> CArchivo::split(string str, char pattern) {
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
  return resultados;}


void CArchivo::setMatriz (vector<vector<string>> &cache_vector){
      string linea;
      ifstream archivo(this->nombre);
      //abre el archivo y llena la matriz linea por linea
      {while (getline(archivo,linea)){
        vector<string> resultados;
        resultados = split(linea,' ');
        cache_vector.push_back(resultados);}
      //cierra el archivo
      archivo.close();}}

void CArchivo::setMatriz2 (vector<vector<string>> &cache_vector,int limite){
      string linea;
      ifstream archivo(this->nombre);
      //abre el archivo y llena la matriz linea por linea
      while (getline(archivo,linea)){
        vector<string> resultados;
        resultados = split(linea,' ');
        vector<string> l = vector<string>();
        int longitudActual = 0;
        for(int i=0; i < resultados.size(); i++){
          int longitudPalabra = resultados[i].size();
          if(longitudActual + longitudPalabra <= limite){
            l.push_back(resultados[i]);
            longitudActual += longitudPalabra +1;
          }else{
            cache_vector.push_back(l);
            l = vector<string>();
            l.push_back(resultados[i]);
            longitudActual = longitudPalabra +1; 
          }}cache_vector.push_back(l);
      }archivo.close();}

void CArchivo::reemplazar(vector<vector<string>> &texto){
  string busq,reem;
  int cont=0;
  cout<<"Ingrese palabra a reemplazar: "; cin>>busq;
  cout<<"Con qué lo vas a reemplazar: "; cin>>reem;
  
  for(int i=0; i < texto.size();i++){
        for(int j =0; j < texto[i].size(); j++){
          if(texto[i][j]==busq){
            texto[i][j]=reem;
            cont++;
          }}}
  if(cont==0) cout<<endl<<"Esa palabra no existe en el texto"<<endl;
  else cout<<endl<<"Se terminó de reemplazar la palabra '"<<busq<<"' por '"<<reem<<"'. "<<endl;}

void CArchivo::contar(vector<vector<string>> texto){
  string busq;
  int cont=0;
  cout<<"Ingrese palabra a buscar: "; cin>>busq;
  for(int i=0; i < texto.size();i++){
        for(int j =0; j < texto[i].size(); j++){
          if(texto[i][j]==busq){cont++;}}}
  cout<<endl<<"Numero de incidencias: "<<cont<<endl;}
void CArchivo::justificar(vector<vector<string>>&texto){
  int mayor=0;
        for(int i=0; i < texto.size();i++){
            int longitud = 0;
            for(int j =0; j < texto[i].size(); j++){
                longitud = longitud + texto[i][j].size() +1;
            }
            longitud -= 1;
            if(longitud > mayor) mayor = longitud;
        }
        //Linea por linea
        for(int i=0; i<texto.size(); i++){
            //Si solo hay una palabra en la linea, imprimirla
            if(texto[i].size() == 1){
                texto[i][0]=texto[i][0];
            }else{
                //Longitud de esta linea
                int longSinEspacios = 0;
                for(int j=0;j<texto[i].size();j++) longSinEspacios += texto[i][j].size();
                int longitud = longSinEspacios + texto[i].size() - 1;
                //Cuantos espacios falta para alcanzar el tamaño de linea mas grande
                int dif = mayor - longSinEspacios;
                //Cuantos caracteres en blanco hay que introducir entre cada palabra
                int n = trunc(float(dif)/(texto[i].size() - 1));
                int nmod = dif % (texto[i].size() - 1);
                //palabra por palabra
                int e = 0;
                for(int j=0; j<texto[i].size(); j++){
                    //imprimimos los espacios entre palabra
                    int extra = e++ < nmod ? 1 : 0;
                    for(int k=0;k<n+extra;k++) texto[i][j]+=" ";
                }}}

}/*return justificado;*/

void CArchivo::centrar(string & texto, int limite){
        string texto2,texto3;
        for(int i=0;i<texto.size();i++){
          texto2+=texto[i];
          if(texto[i]=='\n'){
            int a=texto2.size();
            for(int i=0;i<((limite/2)-(a/2));i++){
              texto3+=" ";}texto3+=texto2;
            texto2=" ";
          }}
          texto=texto3;}

void CArchivo::derecha(string &texto,int limite){
        string texto2,texto3;
        for(int i=0;i<texto.size();i++){
          texto2+=texto[i];
          if(texto[i]=='\n'){
            int a=texto2.size();
            for(int i=0;i<(limite-a);i++){
              texto3+=" ";}texto3+=texto2;
            texto2=" ";
          }}
          texto=texto3;}

void CArchivo::izquierda(string &texto,int limite){
        string texto2;
        for(int i=0;i<texto.size();i++){
          texto2+=texto[i];
          if(texto[i]=='\n'){
            int a=texto2.size();
            for(int i=0;i<(limite-a);i++){
              texto2+=" ";}
          }}}

void CArchivo::print(string cache){
      for (int i=0;i<cache.size();i++){
        cout<<cache[i];}}

void CArchivo::print_v(vector<vector<string>>&texto){   
      for(const auto &linea:texto){
        for(const auto &palabra:linea){
          cout<<palabra;
          }cout<<endl;}}

void CArchivo::guardar_string(string cache){
      ofstream archivo;
      archivo.open(this->nombre);
      for (int i=0;i<cache.size();i++){
        archivo<<cache[i];}}

void CArchivo::guardar4(vector<vector<string>>matriz){
      ofstream archivo;
      archivo.open(this->nombre);
      string cache;
      for(int i=0; i<matriz.size(); i++){
        for(int j=0; j<matriz[i].size(); j++){
          archivo<<matriz[i][j]<<" "; cache=cache+matriz[i][j]+" ";
          }archivo<<endl;cache+="\n";}
      }
void CArchivo::guardar3(vector<vector<string>>matriz){
      ofstream archivo;
      archivo.open(this->nombre);
      string cache;
      for(int i=0; i<matriz.size(); i++){
        for(int j=0; j<matriz[i].size(); j++){
          archivo<<matriz[i][j]<<" "; cache=cache+matriz[i][j]+" ";
          }archivo<<endl;cache+="\n";}
      opciones(nombre,cache,cache,matriz,matriz,8,limite);
      }

void CArchivo::guardar_vector(vector<vector<string>>matriz){
      ofstream archivo;
      archivo.open(this->nombre);
      int mayor=0;
      for(int i=0; i < matriz.size();i++){
          int longitud = 0;
          for(int j =0; j < matriz[i].size(); j++){
              longitud = longitud + matriz[i][j].size() +1;} longitud -= 1;
          if(longitud > mayor) mayor = longitud;}
      //Linea por linea
      for(int i=0; i<matriz.size(); i++){
          //Si solo hay una palabra en la linea, imprimirla
          if(matriz[i].size() == 1){
              archivo<<matriz[i][0];}
              else{//Longitud de esta linea
              int longSinEspacios = 0;
              for(int j=0;j<matriz[i].size();j++) longSinEspacios += matriz[i][j].size();
              int longitud = longSinEspacios + matriz[i].size() - 1;
              //Cuantos espacios falta para alcanzar el tamaño de linea mas grande
              int dif = mayor - longSinEspacios;
              //Cuantos caracteres en blanco hay que introducir entre cada palabra
              int n = trunc(float(dif)/(matriz[i].size() - 1));
              int nmod = dif % (matriz[i].size() - 1);
              //palabra por palabra
              int e = 0;
              for(int j=0; j<matriz[i].size(); j++){
                  //imprimimos los espacios entre palabra
                  int extra = e++ < nmod ? 1 : 0;
                  archivo<<matriz[i][j];
                  for(int k=0;k<n+extra;k++) archivo<<" ";
              }archivo<<endl;}}}

void CArchivo::buscar(vector<vector<string>> texto){
  string busq;
  int cont=0;
  cout<<"Ingrese palabra a buscar: "; cin>>busq;
  for(int i=0; i < texto.size();i++){
        for(int j =0; j < texto[i].size(); j++){
          if(texto[i][j]==busq){
            cout<<endl<<"    Palabra encontrada en la linea "<<i+1<<", "<<j+1<<"° posicion."<<endl;
            cont++;}
          }}
          if(cont==0) cout<<endl<<"   Palabra no encontrada"<<endl;}

void CArchivo::opciones(string nombre, string cache,string cache2,vector<vector<string>> cache_vector,vector<vector<string>> cache_vector2, int anterior,int limite){
      int opcion;
      text();
      cout<<endl<<"Ingresar opción: "; cin>>opcion;cout<<endl;

      switch(opcion){
        case 0:
        cout<<"Hasta luego!"<<endl;break;
        case 1:
        mostrar();
        opciones(nombre,cache,cache2,cache_vector,cache_vector2,1,limite);break;
        case 2:
        if(anterior==3){guardar_vector(cache_vector); cout<<"ARCHIVO GUARDADO CON EXITO :D!"<<endl<<endl;}
        else if(anterior==2){cout<<"ACABAS DE GUARDAR EL TEXTO"<<endl; }
        else {guardar_string(cache2); cout<<"ARCHIVO GUARDADO CON EXITO :D!"<<endl<<endl;}
        opciones(nombre,cache,cache2,cache_vector,cache_vector2,2,limite); 
        break;
        case 3:
        if (cache_vector2!=cache_vector)cache_vector2=cache_vector;
        justificar(cache_vector2); print_v(cache_vector2); opciones(nombre,cache,cache2,cache_vector,cache_vector2,3,limite);break;
        case 4:
        if (cache2!=cache)cache2=cache;
        derecha(cache2,limite); print(cache2); opciones(nombre,cache,cache2,cache_vector,cache_vector2,4,limite); break;
        case 5:
        if (cache2!=cache)cache2=cache;
        izquierda(cache2,limite); print(cache2); opciones(nombre,cache,cache2,cache_vector,cache_vector2,5,limite); break;
        case 6:
        if (cache2!=cache)cache2=cache;
        centrar(cache2,limite); print(cache2); opciones(nombre,cache,cache2,cache_vector,cache_vector2,6,limite);break;
        case 7:
        buscar(cache_vector); opciones(nombre,cache,cache2,cache_vector,cache_vector2,7,limite);break;  
        case 8:
        reemplazar(cache_vector); guardar3(cache_vector);
        break;  
        case 9:
        contar(cache_vector); opciones(nombre,cache,cache2,cache_vector,cache_vector2,9,limite);break;  
        }}

CArchivo::CArchivo(string name, int limite){
  nombre=name;
  setMatriz2(cache_vector,limite);
  cache_vector2=cache_vector;
  setCache(cache);
  guardar4(cache_vector);
  setCache(cache2);
  guardar_string(cache);
  cache=ltrim(cache2);  
  cache2=cache;
  this->limite=limite;
  opciones(nombre,cache,cache2,cache_vector,cache_vector2,100,limite);}

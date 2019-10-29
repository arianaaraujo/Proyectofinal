#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "vectores.h"
using namespace std;

void guardar_vector(vector<vector<string>>&matriz,string texto){
ofstream archivo;
archivo.open(texto);
  int mayor=0;
    for(int i=0; i < matriz.size();i++){
        int longitud = 0;
        for(int j =0; j < matriz[i].size(); j++){
            longitud = longitud + matriz[i][j].size() +1;
        }
        longitud -= 1;
        if(longitud > mayor) mayor = longitud;
    }
    //Linea por linea
    for(int i=0; i<matriz.size(); i++){
        //Si solo hay una palabra en la linea, imprimirla
        if(matriz[i].size() == 1){
            archivo<<matriz[i][0];
        }else{
            //Longitud de esta linea
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

vector<string> split(string str, char pattern) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;

    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);}
    return resultados;}
  
vector<vector<string>> leer_vector(string nombre){
  string linea;
  vector<vector<string>> texto;
  ifstream archivo(nombre);
  //abre el archivo y llena la matriz linea por linea
  {while (getline(archivo,linea)){
    vector<string> resultados;
    resultados = split(linea, ' ');
    texto.push_back(resultados);}
  //cierra el archivo
  archivo.close();}
  return texto;}

void justificar(vector<vector<string>>&texto){
    //se calcula la longitud de la cadena mas grande
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
            }}}}
void print_v(vector<vector<string>>&texto){   
  for(const auto &linea:texto){
    for(const auto &palabra:linea){
      cout<<palabra;
      }cout<<endl;}}

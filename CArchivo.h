#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
using namespace std;

class CArchivo{
  private:
    int limite;
    string nombre;
    string cache;
    string cache2;
    vector<vector<string>> cache_vector;
    vector<vector<string>> cache_vector2;

  public:
  //lista de opciones
  void text();
  //funcion que borra los espacios iniciales
  string ltrim(string str);
  //muestra lo que este en el archivo guardado
  void mostrar();
  //setter para los caches strings
  void setCache(string &str);
  //crea vector por linea de archivo
  vector<string> split(string str, char pattern);
  //setter para los caches vector
  void setMatriz (vector<vector<string>> &cache_vector);
  //funcion justificar
  void justificar(vector<vector<string>>&texto);
  //funcion centrar
  void centrar(string & texto,int limite);
  //funcion derecha
  void derecha(string &texto,int limite);
  //funcion izquierda
  void izquierda(string &texto,int limite);
  //imprime un string
  void print(string cache);
  //imprime una matriz
  void print_v(vector<vector<string>>&texto);
  //guarda el archivo a partir de un string
  void guardar_string(string cache);
  //guarda el archivo a partir de una matriz
  void guardar_vector(vector<vector<string>>matriz);
  //8 guarda el archivo a partir de una matriz
  void guardar3(vector<vector<string>>matriz);
  //8 guarda el archivo a partir de una matriz
  void guardar4(vector<vector<string>>matriz);
  //7 funcion buscar palabra
  void buscar(vector<vector<string>> texto);
  //8 funcion reemplazar una palabra
  void reemplazar(vector<vector<string>> &texto);
  //9 funcion contar repeticiones de una palabra
  void contar(vector<vector<string>> texto);
  //funcion de las opciones
  void opciones(string nombre, string cache,string cache2,vector<vector<string>> cache_vector,vector<vector<string>> cache_vector2, int anterior,int limite);
  //funcion buscar palabra
  void setMatriz2 (vector<vector<string>> &cache_vector,int limite);
  //constructor
  CArchivo(string name, int limite);
};

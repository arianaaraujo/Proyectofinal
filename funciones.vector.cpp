#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "funciones.vector.h"
using namespace std;

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
            cout<<linea<<endl;
            vector<string> resultados;
            resultados = split(linea, ' ');
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
    cout << mayor << endl;

    //Linea por linea
    for(int i=0; i<texto.size(); i++){
        //Si solo hay una palabra en la linea, imprimirla
        if(texto[i].size() == 1){
            cout << texto[i][0] << endl;
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
                cout << texto[i][j];
                //imprimimos los espacios entre palabra
                int extra = e++ < nmod ? 1 : 0;
                for(int k=0;k<n+extra;k++) cout << " ";
            }
            cout << endl;
        }
    }
}

void opciones(vector<vector<string>>&texto){
    cout<<endl<<endl<<"1.	Leer archivo"<<endl<<"2.	Guardar archivo"<<endl<<"3.	Justificar"<<endl<<"4.	Alinear a la derecha"<<endl<<"5.	Alinear a la izquierda"<<endl<<"6.	Centrar texto"<<endl<<"7.	Buscar una palabra"<<endl<<"8.	Reemplazar una palabra"<<endl<<"9.	Contar cunatas veces aparece una palabra"<<endl<<"10.	Guardar como PDF";
    int opcion;
    cout<<endl<<endl<<"Ingrese opcion (0 para finalizar programa): \n"; cin>>opcion;
    switch(opcion){
        case 1:
            leer(texto);
            break;
        case 5:
            justificar(texto);
            break;
        case 0:
            cout<<"GRACIAS!!!"<<endl;
            break;
        default:
            cout<<"Esa no es una opcion valida"<<endl<<"Intentalo de nuevo";
            opciones(texto);
            break;  }}
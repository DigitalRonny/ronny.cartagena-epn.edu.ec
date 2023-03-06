#include<conio.h>
#include"../lib/colores.h"
#include <windows.h> 
#include<iostream>
#include<stdlib.h>
#include <fstream> //manejo archivos
using namespace std;

/*
* @autor    : Ronny Cartagena
* C.I       : 1726340514
* @date     : 06/03/2023
* @details  : Examen Bimestral II
*/

//Constantes
const string RCNOMBRE_COMPLETO = "Ronny Damian Cartagena Toaquiza";
const int RCNUMERO_CEDULA = 1726340514;

struct rcNodo{
    int rcCapacidadBelica;
    char rcGeo[4];
    string rcDetalleArsenal;
    rcNodo *der;
    rcNodo *izq;
};

//Crear nodos, pasar como parametros los datos del nodo
rcNodo *rcCrearNodo(int rcCapacidadBelica, char rcGeo, string rcDetalleArsenal){
    rcNodo *rcNuevo_nodo = new rcNodo();

    rcNuevo_nodo->rcCapacidadBelica = rcCapacidadBelica;
    rcNuevo_nodo->rcGeo[0] = rcGeo;
    rcNuevo_nodo->rcDetalleArsenal = rcDetalleArsenal;
    rcNuevo_nodo->der = NULL;
    rcNuevo_nodo->izq = NULL;

    return rcNuevo_nodo;
}

//insertar nodos
void rcInsertarNodo(rcNodo *&rcArbol, int rcCapacidadBelica, char rcGeo, string rcDetalleArsenal ){
    if (rcArbol == NULL){
        rcNodo *rcNuevo_nodo = rcCrearNodo(rcCapacidadBelica, rcGeo, rcDetalleArsenal);
        rcArbol = rcNuevo_nodo;
    }
    if (rcCapacidadBelica < rcArbol->rcCapacidadBelica){//si el nombre de la ciudad nuevo es menor al de la raiz
        rcInsertarNodo(rcArbol->izq, rcCapacidadBelica,rcGeo,rcDetalleArsenal);
    }
    else if (rcCapacidadBelica > rcArbol->rcCapacidadBelica){
        rcInsertarNodo(rcArbol->der, rcCapacidadBelica,rcGeo,rcDetalleArsenal);
    }
}


//Crear arbol
/* rcNodo *rcRecibirDatos(string rcFilename){
    ifstream rcFile;
    rcFile.open(rcFilename, ios_base::in);
    if ( !rcFile.is_open() ) {
        cout << "Error de abrir el archivo." << endl;
        exit(1);
    }
    int rcNum; //capacidad belica
    char rcLetra; //Geolocalizacion
    string rcCadena; //Detalle arsenal

    while (rcFile >> rcNum >> rcLetra >> rcCadena){
    }

    rcFile.close();
} */


//procedimiento para leer archivo
void rcLeerArchivo(){
    string rcLinea;
    ifstream rcFile;//archivo->rcFile
    string rcFistLine;
    rcFile.open("files\\coordenadas.txt", ios_base::in);
    if (!rcFile.is_open())
    {
        cout<<"Error de abrir el archivo."<< endl;
        exit(1);
    }
    else{
        /* try
        {
            if (rcFistLine){//detectar la primera
                throw ">> Error:";//rcError
                rcFistLine = false;
            }
            else{
                do{
                    getline( rcFile, rcLinea );// va a sacar una linea de f y la va a poner en s para leerla
                    cout << rcLinea << endl;//se imprime la linea que esta en rcLinea

                }while( !rcFile.eof() );//leer hasta end of file
            rcFile.close();
            }
        }
        catch(string rcError){
        cout << "\x1b[31m" << ">> Error en la ope" << "\x1b[0m" << endl;
        } */
            
        while (getline(rcFile, rcLinea)) {
        // Si no se ha almacenado ninguna línea, esta es la primera
            if (rcFistLine == "") {
            rcFistLine = rcLinea;
            // Imprimir la primera línea
            cout <<RED<< ">>Error: " << rcFistLine<< endl;
            }
            else{

                string rcCarga= "\\|/-";
                for (int i = 0; i < 100; i++){
                cout<< GREEN<<rcCarga[i]<<i<<'%'<<"\b\b\b\b";
                Sleep(1);
                }
            cout <<"100%   "<< rcLinea << endl;//se imprime la linea que esta en rcLinea
            }
        }
        rcFile.close();             
    }
}
    

int main(){
    rcNodo *rcArbol=NULL;
    //rcNodo *rcArbol = rcRecibirDatos("coordenadas.txt");

    rcLeerArchivo();
    return 0;
}
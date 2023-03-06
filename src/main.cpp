#include<conio.h>
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

struct rcCoordenada{
    int rcCapacidadBelica;
    char rcGeo[4];
    string rcDetalleArsenal;
};

struct Nodo{
    rcCoordenada coordenada;//almacenar la estructura coordenada en el Nodo
    Nodo *der;
    Nodo *izq;
};


//procedimiento para leer archivo
void rcLeerArchivo(){
    string rcLinea;
    ifstream rcFile;
    bool rcFistLine;
    rcFile.open("files\\coordenadas.txt", ios_base::in);
    if (!rcFile.is_open())
    {
        cout<<"Error de abrir el archivo."<< endl;
        exit(1);
    }
    else{
        try
        {
            if (rcFistLine){
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
    }
    }
    
    

}


int main()
{
    rcLeerArchivo();
    return 0;
}
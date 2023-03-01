#include <iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <ctime>
#include <windows.h>
const char * archivoEmpresa = "archivoEmpresas.dat";
const char * archivoGenero = "archivoGenero.dat";
const char * archivoJuego = "archivoJuego.dat";
const char * archivoFinal = "archivoFinal.dat";

 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
#include "funcionesGlobales.h"
#include "ClassFecha.h"
#include "ClassEmpresa.h"
#include "menuEmpresa.h"
#include "ClassGenero.h"
#include "menuGeneros.h"
#include "classJuego.h"
#include "menuJuego.h"
#include "configuracion.h"
#include "reportes.h"


///puntos a corregir

///falta de ortografia
///clase fecha => vector de int innecesario => ocupa lugar
///si se elimina un objeto no se puede crear otro a partir de este
///aumentar vector de char de descripcion del genero del juego
/// cambiar de int a bool de la propiedad +18
///TODOS LOS SETTERS Y GETTERS
///incluir todos los archivos correctamente
int main(){
 int opc;
    while(true){
        system("cls");
        cout<<"-----------------------"<<endl;
        cout<<"1)MENU EMPRESAS"<<endl;
        cout<<"2)MENU JUEGOS"<<endl;
        cout<<"3)MENU GENEROS"<<endl;
        cout<<"4)CONFIGURACION"<<endl;
        cout<<"5)REPORTES"<<endl;
        cout<<"-----------------------"<<endl;
        SetConsoleTextAttribute(h,4);
        cout<<"0)Salir"<<endl;
        SetConsoleTextAttribute(h,7);
        cout<<"INGRESA OPCION:";cin>>opc;
        system("cls");

        switch(opc){
        case 0:
            return false;
        break;
        case 1:
            menuLogin();
        break;
        case 2:
            menuJuego();
        break;
        case 3:
            menuGeneros();
        break;
        case 4:
        config();
        break;
        case 5:
        reportes();
        break;
        default:
            cout<<"NO EXISTE ESA OPCION"<<endl;
            system("pause");
        }
    }
    return 0;
}



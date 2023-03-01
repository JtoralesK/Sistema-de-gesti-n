#ifndef CONFIGUARION_H_INCLUDED
#define CONFIGUARION_H_INCLUDED
void resetearEmpresa(){
    Empresa obj;
    obj.resetearArchivo();
    cout<<"se reseteo archivo empresa"<<endl;
}
void resetearJuego(){
    Juego obj;
    obj.resetearArchivo();
    cout<<"se reseteo archivo Juego"<<endl;

}
void resetearGenero(){
    Genero obj;
    obj.resetearArchivo();
    cout<<"se reseteo archivo Genero"<<endl;
}
void resetearTodo(){
  Genero obj1;Juego obj2;Empresa obj3;
  obj1.resetearArchivo();
  obj2.resetearArchivo();
  obj3.resetearArchivo();
  cout<<"se resetearon los 3 archivos"<<endl;
}
int config(){

 int opc;
    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    SetConsoleTextAttribute(h,4);
    cout<<"1) RESETEAR ARCHIVO GENEROS"<<endl;
    cout<<"2) RESETEAR ARCHIVO EMPRESAS"<<endl;
    cout<<"3) RESETEAR ARCHIVO JUEGOS"<<endl;
    cout<<"4) RESETEAR TODOS LOS ARCHIVOS"<<endl;
    SetConsoleTextAttribute(h,7);
    cout<<"------------------------"<<endl;
    cout<<"0) VOLVER AL MENU"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    resetearGenero();
    system("pause");
    break;
    case 2:
    resetearEmpresa();
    system("pause");
    break;
    case 3:
    resetearJuego();
    system("pause");
    break;
    case 4:
    resetearTodo();
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}


#endif // CONFIGUARION_H_INCLUDED

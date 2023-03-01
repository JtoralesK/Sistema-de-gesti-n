#ifndef MENUJUEGO_H_INCLUDED
#define MENUJUEGO_H_INCLUDED


bool agregarJuego();
void listarJuegoPorId();
int buscarJuegoPorId(int n);
void listarTodosLosJuegos();
void modificarDescripcionJuego();
void eliminarJuego();


int menuJuego(){

int opc;
    while(true){
        system("cls");
        cout<<"-----------------------"<<endl;
        SetConsoleTextAttribute(h,10);
        cout<<"1)CREAR JUEGO"<<endl;
        SetConsoleTextAttribute(h,7);
        cout<<"2)LISTAR POR ID"<<endl;
        cout<<"3)LISTAR TODOS LOS JUEGOS"<<endl;
        cout<<"4)MODIFICAR DISCRIPCION"<<endl;
        SetConsoleTextAttribute(h,4);
        cout<<"5)ELIMINAR JUEGO"<<endl;
        SetConsoleTextAttribute(h,7);
        cout<<"0)Salir"<<endl;
        cout<<"-----------------------"<<endl;

        cout<<"INGRESA OPCION:";cin>>opc;
        system("cls");

        switch(opc){
        case 0:
            return false;
        break;
        case 1:
              agregarJuego();
              system("pause");
        break;
        case 2:
              listarJuegoPorId();
              system("pause");

        break;
        case 3:
              listarTodosLosJuegos();
              system("pause");
        break;
        case 4:
              modificarDescripcionJuego();
              system("pause");
        break;
         case 5:
              eliminarJuego();
              system("pause");
        break;
        default:return false;
        }
    }
    return 0;


}

bool agregarJuego(){
    Empresa objE;Genero objG;
    Juego obj;
    int idG=1,idE=1;
    int posGe= cuentaCantGeneros();
    int posEm= cuentaCantEmpresas();
    if(posGe<1 || posEm<1){
    if(posGe<1)cout<<"No existe ningun genero para crear un juego"<<endl;
    if(posEm<1){cout<<"No existe ninguna empresa para crear un juego"<<endl;}
    return false;
    }

    cout<<"ingresar id del genero del juego:";cin>>idG;
    if(!(confirmaExisGenero(idG))){
        cout<<"No existe ningun genero con ese id"<<endl;
       return false;
    }
    posGe++;
    cout<<"ingresar id de la empresa que creo el juego:";cin>>idE;
    if(!(confirmaExisEmpresa(idE))){
        cout<<"No existe ninguna empresa con ese id"<<endl;
        return false;
    }
    int id= obj.leerDeDisco(0);
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj.leerDeDisco(pos)){pos++;}
    id=pos+1;
    }
    obj.cargar(id,idE,idG);
    bool escribio = obj.grabarEnDisco();
    return escribio;
}

void listarJuegoPorId(){
    Juego obj;
    int n;
    cout<<"INGRESA ID:";cin>>n;
    if( buscarJuegoPorId(n)<0){
        cout<<"No existe un juego con ese id"<<endl;
    }else{
     int pos=0;
     while((obj.leerDeDisco(pos))==1){
            if(obj.getIdJuego()==n){
                if(obj.getEstado()){
                 obj.mostrar();
                 listarGeneroPorId(obj.getIdGenero(),2);
                 listarEmpresaPorID(obj.getIdEmpresa(),2);
                }else cout<<"este juego ya no exite"<<endl;
            }
         pos++;
      }
    }
}


int buscarJuegoPorId(int id){
    Juego obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getIdJuego()==id){
           return pos;
        }
        pos++;
    }
     return -1;
}

void listarTodosLosJuegos(){
    Juego obj;
    int pos=0,cant=0;
    while((obj.leerDeDisco(pos))==1){
         if(obj.getEstado()){
             obj.mostrar();
              listarGeneroPorId(obj.getIdGenero(),3);
              listarEmpresaPorID(obj.getIdEmpresa(),3);
              cout<<endl;
             cant++;
         }
         pos++;
    }
    if(cant==0){
        cout<<"No existen registros en este archivo"<<endl;
    }
}


void eliminarJuego(){
int id;cout<<"Id del juego a eleminar:";cin>>id;
if(buscarJuegoPorId(id)<0){cout<<"No se encuentra un juego con ese id"<<endl;}
else{
Juego obj;
int pos=0;
while(obj.leerDeDisco(pos)==1){
    if(obj.getIdJuego()==id){
        if(obj.getEstado()){
        obj.setEstado(false);
          if(obj.modificarEndisco(id-1,obj)){
            cout<<"se elimino este juego"<<endl;
          }else{cout<<"no se pudo eliminar este juego"<<endl;}
       }else cout<<"Este juego ya se encuentra eliminado"<<endl;
    }
    pos++;
}
}

}
void modificarDescripcionJuego(){
int id;cout<<"ID del juego a modificar:";cin>>id;
if(buscarJuegoPorId(id)<0){
    cout<<"no se encuentra un juego con ese id"<<endl;
}else{
Juego obj;char des[30];
int pos=0;
while(obj.leerDeDisco(pos)==1){
    if(obj.getIdJuego()==id){
        if(obj.getEstado()){
            cout<<"Ingresa descripcion a modificar:";cargarCadena(des,59);
            obj.setDescripcion(des);
          if(obj.modificarEndisco(id-1,obj)){
            cout<<"se modifico este juego"<<endl;
          }else{cout<<"no se pudo modificar este juego"<<endl;}
       }else cout<<"No se puede modificar un registro eliminado"<<endl;
    }
    pos++;
}
}

}


#endif // MENUJUEGO_H_INCLUDED

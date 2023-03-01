#ifndef MENUGENEROS_H_INCLUDED
#define MENUGENEROS_H_INCLUDED

bool agregarGenero();
void listarGeneroPorId(int id=0,int v=0);
int buscarGeneroPorId(int n);
int cuentaCantGeneros();
void listarTodosLosGeneros();
void modificarNombreGenero();
void eliminarGenero();
bool confirmaExisGenero(int id);

int menuGeneros(){

int opc;
    while(true){
        system("cls");
        cout<<"-----------------------"<<endl;
        SetConsoleTextAttribute(h,10);
        cout<<"1)CREAR GENERO"<<endl;
        SetConsoleTextAttribute(h,7);
        cout<<"2)LISTAR POR ID"<<endl;
        cout<<"3)LISTAR TODOS LOS GENEROS"<<endl;
        cout<<"4)MODIFICAR NOMBRE DEL GENERO"<<endl;
        SetConsoleTextAttribute(h,4);
        cout<<"5)ELIMINAR GENERO"<<endl;
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
              agregarGenero();
              system("pause");
        break;
        case 2:
              listarGeneroPorId();
              system("pause");

        break;
        case 3:
              listarTodosLosGeneros();
              system("pause");
        break;
        case 4:
              modificarNombreGenero();
              system("pause");
        break;
         case 5:
              eliminarGenero();
              system("pause");
        break;
        default:return false;
        }
    }
    return 0;


}

bool agregarGenero(){
    Genero obj;
    int id= obj.leerDeDisco(0);
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj.leerDeDisco(pos)){pos++;}
    id=pos+1;
    }

    obj.cargar(id);
    bool escribio = obj.grabarEnDisco();
    return escribio;
}

void listarGeneroPorId(int id,int v){
    Genero obj;
    if(id==0){cout<<"INGRESA ID:";cin>>id;}
    if(buscarGeneroPorId(id)<0){
        cout<<"no existe ese genero"<<endl;
    }else{
     int pos=0;
     while((obj.leerDeDisco(pos))){
            if(obj.getIdGenero()==id){
                if(obj.getEstado()|| v>0){
                obj.mostrar(v);
                }else cout<<"ese registro se encuentra eliminado"<<endl;
            }
         pos++;
      }
    }
}

int cuentaCantGeneros(){
  Genero obj;int pos=0,cant=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getEstado())cant++;
        pos++;
    }
     return cant;
}
bool confirmaExisGenero(int id){
    Genero obj;
    int pos = buscarGeneroPorId(id);
    if(pos>-1){
        obj.leerDeDisco(pos);
        return obj.getEstado();
    }
    return false;
}
int buscarGeneroPorId(int id){
    Genero obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getIdGenero()==id){
           return pos;
        }
        pos++;
    }
     return -1;
}

void listarTodosLosGeneros(){
    Genero obj;
    int pos=0,cant=0;
    while((obj.leerDeDisco(pos++))==1){
         if(obj.getEstado()){
            obj.mostrar();cout<<endl;
            cant++;
         }
    }
    if(cant==0)cout<<"no existen registros en este archivo"<<endl;

}

void eliminarGenero(){
Genero obj;
int id;cout<<"Id del genero a eliminar:";cin>>id;
if(buscarGeneroPorId(id)<0){
       cout<<"No existe un genero con ese id"<<endl;
}else{
int pos=0;
while(obj.leerDeDisco(pos)==1){
    if(obj.getIdGenero()==id){
        if(obj.getEstado()==true){
        obj.setEstado(false);
          if(obj.modificarEndisco(id-1,obj)){
            cout<<"Este registro ha sido eliminado"<<endl;
          }else cout<<"no se pudo eliminar este registro"<<endl;
       }else cout<<"Ese registro ya se encuentra eliminado"<<endl;
    }
    pos++;
}
}
}
void modificarNombreGenero(){
    int n;
    cout<<"Ingresar id del genero a modificar:";cin>>n;
    int pos= buscarGeneroPorId(n);
    if(pos==-1){cout<<"No existe un registro con ese id"<<endl;}
    else{
    Genero obj;
    char nombre[40];
    obj.leerDeDisco(pos);
    if(obj.getEstado()){
    cout << "Ingrese nombre del genero: "; cargarCadena(nombre, 39);
    obj.setNombre(nombre);
    if( obj.modificarEndisco(pos,obj)){
        cout<<"se ha modificado correctamente"<<endl;
    }else cout<<"hubo un error"<<endl;
    }else cout<<"no se puede modificar un registro eliminado"<<endl;
    }
}



































#endif //MENUGENEROS_H_INCLUDED

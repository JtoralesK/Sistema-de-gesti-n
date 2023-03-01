#ifndef MENULOGIN_H_INCLUDED
#define MENULOGIN_H_INCLUDED
void agregarEmpresa();
void listarEmpresas();
int buscarEmpresaID(int id);
int cuentaCantEmpresas();
void listarEmpresaPorID(int id=0,int v=0);
void modificarNombreEmpresa();
void modificarNombreFundador();
void eleminarRegistro();
bool confirmaExisEmpresa(int id);
int menuLogin(){
int opc;
    while(true){
        system("cls");
        cout<<"-----------------------"<<endl;
        SetConsoleTextAttribute(h,10);
        cout<<"1)CREAR EMPRESA"<<endl;
        SetConsoleTextAttribute(h,7);
        cout<<"2)LISTAR POR ID"<<endl;
        cout<<"3)LISTAR TODOS LAS EMPRESAS"<<endl;
        cout<<"4)MODIFICAR NOMBRE DE LA EMPRESA"<<endl;
        cout<<"5)MODIFICAR FUNDADOR"<<endl;
        SetConsoleTextAttribute(h,4);
        cout<<"6)ELIMINAR EMPRESA"<<endl;
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
              agregarEmpresa();
              system("pause");
        break;
        case 2:
              listarEmpresaPorID();
              system("pause");

        break;
        case 3:
              listarEmpresas();
              system("pause");
        break;
        case 4:
              modificarNombreEmpresa();
              system("pause");
        break;
         case 5:
              modificarNombreFundador();
              system("pause");
        break;
         case 6:
              eleminarRegistro();
              system("pause");
        break;
        default:return false;
        }
    }
    return 0;
}
void agregarEmpresa(){
   Empresa obj;
    int id= obj.leerDeDisco(0);
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj.leerDeDisco(pos)){pos++;}
    id=pos+1;
    }
    obj.cargar(id);
    if(obj.grabarEnDisco()){
    cout<<"Registro grabado con exito"<<endl;
    }else cout<<"Hubo un error"<<endl;
}
void listarEmpresas(){
Empresa obj;
int pos=0,cant=0;
while(obj.leerDeDisco(pos++)==1){
    if(obj.getEstado()==true){
    obj.mostrar();
    cout<<endl;
    cant++;
    }
}
if(cant==0)cout<<"no existen registros en este archivo"<<endl;
}
void listarEmpresaPorID(int id,int v){
Empresa obj;
if(id==0){cout<<"Ingresar id de la empresa:";cin>>id;}
if(buscarEmpresaID(id)<0){
    cout<<"No existe ese registro"<<endl;
}else{
int pos=0;
while(obj.leerDeDisco(pos)==1){
    if(obj.getEmpresaID()==id){
        if(obj.getEstado() || v>0){
           obj.mostrar(v);
        }else cout<<"ese registro se encuentra eliminado"<<endl;
    }

    pos++;
    }
}
}
int buscarEmpresaID(int id){
Empresa obj;
int pos=0;
while(obj.leerDeDisco(pos)==1){
  if(obj.getEmpresaID()==id){
        return pos;
    }
  pos++;
}
return -1;
}

int cuentaCantEmpresas(){
Empresa obj;int pos=0,cant=0;
while(obj.leerDeDisco(pos)){
  if(obj.getEstado())cant++;
  pos++;
}
return cant;
}
bool confirmaExisEmpresa(int id){
    Empresa obj;
    int pos = buscarEmpresaID(id);
    if(pos>-1){
        obj.leerDeDisco(pos);
        return obj.getEstado();
    }
    return false;
}
void modificarNombreEmpresa(){
    int n;
    cout<<"Ingresar id de la empresa a modificar:";cin>>n;
    int pos= buscarEmpresaID(n);
    if(pos==-1){cout<<"No existe un registro con ese id"<<endl;}
    else{
    Empresa obj;
    char nombre[30];
    obj.leerDeDisco(pos);
    if(obj.getEstado()){
    cout << "Ingrese nombre de la empresa: "; cargarCadena(nombre, 29);
    obj.setNombre(nombre);
    if( obj.modificarEndisco(pos,obj)){cout<<"se ha modificado correctamente"<<endl;
    }else cout<<"hubo un error al modificar"<<endl;

    }else{
    cout<<"no se puede modifica un registro eliminado"<<endl;
    }
    }

}
void modificarNombreFundador(){
    int n;
    cout<<"Ingresar id de la empresa a modificar:";cin>>n;
    int pos= buscarEmpresaID(n);
    if(pos==-1){cout<<"No existe un registro con ese id"<<endl;}
    else{
    Empresa obj;
    char nombre[30];
    obj.leerDeDisco(pos);
    if(obj.getEstado()){
         cout << "Ingrese nombre del fundador: "; cargarCadena(nombre, 29);
    obj.setDuenio(nombre);
    if( obj.modificarEndisco(pos,obj)){cout<<"se ha modificado correctamente"<<endl;
    }else cout<<"hubo un error"<<endl;
    }else{cout<<"no se puede modifica un registro eliminado"<<endl;}
    }
}
void eleminarRegistro(){
Empresa obj;
int id;cout<<"Id de la empresa a eliminar:";cin>>id;
if(buscarEmpresaID(id)<0){
    cout<<"No existe una empresa con ese id"<<endl;
}else{
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
    if(obj.getEmpresaID()==id){
        if(obj.getEstado()==true){
          obj.setEstado(false);
          if(obj.modificarEndisco(id-1,obj)){
            cout<<"registro eliminado"<<endl;
          }else cout<<"hubo un error"<<endl;
       }else cout<<"Ese registro ya se encuentra eliminado"<<endl;
    }
    pos++;
}
}
}
#endif // MENULOGIN_H_INCLUDED

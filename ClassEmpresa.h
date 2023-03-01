#ifndef CLASSLOGIN_H_INCLUDED
#define CLASSLOGIN_H_INCLUDED

class Empresa{
private:
   char nombre[30],pais[30],duenio[30];
   int cantEmpleados;
   int tipo;
   bool estado;
   int idEmpresa;
   Fecha inicioDeActividad;
public:
    void cargar(int id);
    void mostrar(int v);
    bool grabarEnDisco();
    bool modificarEndisco(int pos, Empresa obj);
    int leerDeDisco(int p);
    void resetearArchivo();
    ///setters
       bool setCantEmpleados(int e){
            if(e>0){
                cantEmpleados=e;
                return true;
            }else return false;
       }
       void setNombre(const char* n){
              strcpy(nombre,n);
       }
         void setDuenio(const char* d){
              strcpy(duenio,d);
       }
      void setPais(const char* p){
              strcpy(pais,p);
       }
       void setEstado(bool est){
        estado=est;
       }
       void setInicioDeActividad(Fecha f){inicioDeActividad=f;}
       ///getters
    const char * getNombre(){return nombre;}
    const char * getPais(){return pais;}
    bool getEstado(){return estado;}
    int getEmpresaID(){return idEmpresa;}
    Fecha getInicioDeActividad(){return inicioDeActividad;}
    int getAnioInicioDeActividad(){return inicioDeActividad.getAnio();}
    int getMesInicioDeActividad(){return inicioDeActividad.getMes();}
    int getDiaInicioDeActividad(){return inicioDeActividad.getDia();}

};

void Empresa::cargar(int id){
    Fecha f;
    idEmpresa=id;
    estado=true;
    cout<<"INGRESAR NOMBRE:";cargarCadena(nombre,29);
    cout<<"INGRESAR CREADOR DE LA EMPRESA:";cargarCadena(duenio,29);
    cout<<"INGRESAR PAIS:";cargarCadena(pais,29);
    cout<<"INGRESAR CANTIDAD DE EMPLEADOS:";cin>>cantEmpleados;
    while(!(setCantEmpleados(cantEmpleados))){
    cout<<"CANTIDAD DE EMEPLEADOS DEBE SER MAYOR A 0:";
    cout<<"INGRESAR DE VUELTA:";cin>>cantEmpleados;
    }
    cout<<"INGRESAR FECHA DE INICIO DE ACTIVIDAD DE LA EMPRESA:";
    f.CargarFecha();
    setInicioDeActividad(f);
}
void Empresa::mostrar(int v=0){
       /// 0 muestra todo
       /// 2 muestra todo menos id
       /// 3 muestra solo nombre de la empresa
    SetConsoleTextAttribute(h,14);
     if(v>-1){
        cout<<"NOMBRE DE LA EMPRESA:"<<nombre<<endl;
              if(v<=2){
                cout<<"CREADOR DE LA EMPRESA:"<<duenio<<endl;
                cout<<"PAIS:"<<pais<<endl;
                cout<<"CANTIDAD DE EMPLEADOS:"<<cantEmpleados<<endl;
                cout<<"FECHA DE FUNDACION DE LA EMPRESA:";
                inicioDeActividad.MostrarFecha();
              }
      SetConsoleTextAttribute(h,14);
              if(v<=1) cout<<"ID:"<<idEmpresa<<endl;
        }

      SetConsoleTextAttribute(h,7);

}
bool Empresa::grabarEnDisco(){
     FILE *p;
    p=fopen(archivoEmpresa,"ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        return false;
    }
    bool escribio=fwrite(this, sizeof (Empresa), 1,p);
    fclose(p);
    return escribio;
}
 int Empresa::leerDeDisco(int pos){
   FILE *p;
    p=fopen(archivoEmpresa,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (Empresa),0);
    bool leyo=fread(this, sizeof (Empresa), 1,p);
    fclose(p);
    return leyo;
}

void  Empresa::resetearArchivo(){
FILE *p;
    p=fopen(archivoEmpresa,"wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
    }
    fclose(p);
}

bool Empresa::modificarEndisco(int pos, Empresa obj){
    FILE *p;
    p=fopen(archivoEmpresa, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
     }


#endif // CLASSLOGIN_H_INCLUDED

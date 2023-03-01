#ifndef CLASSJUEGO_H_INCLUDED
#define CLASSJUEGO_H_INCLUDED

class Juego {
private:
int idJuego,idGenero,idEmpresa;
char descripcion[60],nombreJuego[30];
int notaDeLaCritica;//1-10
bool mayorDe18;//1 o 0
Fecha fechaDeCreacion;
bool estado;
public:
    void cargar(int id,int idE,int idG);
    void mostrar();
    void resetearArchivo();
    bool grabarEnDisco();
    bool leerDeDisco(int p);
    bool modificarEndisco(int pos, Juego obj);
    ///setters
    bool setIdGenero(int id){
        if(id>0){
            idGenero=id;return true;
        }return false;
    }
     bool setIdEmpresa(int id){
        if(id>0){
            idEmpresa=id;return true;
        }return false;
    }
      void setDescripcion(const char* des){
              strcpy(descripcion,des);
       }
        void setNombreJuego(const char* n){
              strcpy(nombreJuego,n);
       }
        bool setNotaDeLaCritica(int n){
        if(n>0 && n<11){
            notaDeLaCritica=n;return true;
        }return false;
    }
    void setMayorDe18(bool m){
       mayorDe18=m;
    }
    void setEstado(bool a){
        estado=a;
    }
    void setFechaDeCreacion(Fecha f){
        fechaDeCreacion=f;
    }
    ///getter
    bool getEstado(){return estado;}
    int getIdJuego(){return idJuego;}
    int getIdGenero(){return idGenero;}
    int getIdEmpresa(){return idEmpresa;}
    bool getMayorDe18(){return mayorDe18;}
    const char * getDescripcion(){return descripcion;}
    const char * getNombreJuego(){return nombreJuego;}
    Fecha getFechaDeCreacion(){return fechaDeCreacion;}
    int getAnioFechaCreacion(){return fechaDeCreacion.getAnio();}
    int getMesFechaCreacion(){return fechaDeCreacion.getMes();}
    int getDiaFechaCreacion(){return fechaDeCreacion.getDia();}

};

void Juego::cargar(int id, int idE ,int idG){
    estado=true;idJuego=id;idEmpresa=idE;idGenero=idG;
    Fecha f;
    cout<<"INGRESAR NOMBRE DEL JUEGO:";cargarCadena(nombreJuego,29);
    cout<<"INGRESAR DESCRIPCION:";cargarCadena(descripcion,59);
    cout<<"INGRESAR NOTA DE LA CRITICA DEL JUEGO:";cin>>notaDeLaCritica;
    while(!(setNotaDeLaCritica(notaDeLaCritica))){
    cout<<"LA NOTA DEBE SER ENTRE 1 Y 10:";
    cout<<"INGRESAR DE VUELTA:";cin>>notaDeLaCritica;
    }
    cout<<"INGRESA 1 SI ES PARA +18.DE LO CONTRARIO INGRESA 0:";cin>>mayorDe18;
    cout<<"INGRESAR CUANDO SE CREO EL JUEGO"<<endl;
    f.CargarFecha();
    setFechaDeCreacion(f);
}
void Juego::mostrar(){
 cout<<"ID:"<<idJuego<<endl;
 cout<<"NOMBRE DEL JUEGO:"<<nombreJuego<<endl;
 cout<<"DESCRIPCION:"<<descripcion<<endl;
 cout<<"NOTA DE LA CRITICA:"<<notaDeLaCritica<<endl;
 if(mayorDe18){
    cout<<"JUEGO:+18"<<endl;
 }else  cout<<"JUEGO:APTO PARA TODO PUBLICO"<<endl;
  cout<<"FECHA DE CREACION DEL JUEGO:";fechaDeCreacion.MostrarFecha();



}
bool Juego::grabarEnDisco(){
     FILE *p;
    p=fopen(archivoJuego,"ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        return false;
    }
    bool escribio=fwrite(this, sizeof (Juego), 1,p);
    fclose(p);
    return escribio;
}
 bool Juego::leerDeDisco(int pos){
   FILE *p;
    p=fopen(archivoJuego,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (Juego),0);
    bool leyo=fread(this, sizeof (Juego), 1,p);
    fclose(p);
    return leyo;
}

void  Juego::resetearArchivo(){
FILE *p;
    p=fopen(archivoJuego,"wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
    }
    fclose(p);
}

bool Juego::modificarEndisco(int pos, Juego obj){
    FILE *p;
    p=fopen(archivoJuego, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
     }
#endif // CLASSJUEGO_H_INCLUDED

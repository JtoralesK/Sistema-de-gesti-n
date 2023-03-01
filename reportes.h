#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void reporte1(){
Juego obj;int pos=0;
while(obj.leerDeDisco(pos)){
        if(obj.getEstado() && obj.getFechaDeCreacion().getAnio()<2000){
            obj.mostrar();cout<<endl;
        }
    pos++;
}
}
void reporte2(){
Juego obj;int pos=0;
while(obj.leerDeDisco(pos)){
        if(obj.getEstado() && obj.getFechaDeCreacion().getAnio()>2000){
            if(obj.getMayorDe18()>0){
                obj.mostrar();cout<<endl;
            }
        }
    pos++;
}
}

class NewClass{
private:
    char nombreJuego[30],nombreG[40],desG[60];
public:
    void setNombreJuego(const char * n){
      strcpy(nombreJuego, n);
    }
      void setNombreG(const char * nG){
      strcpy(nombreG, nG);
    }
      void setDesG(const char * d){
      strcpy(desG, d);
    }
    void mostrar(){
        cout<<"NOMBRE DEL JUEGO:"<<nombreJuego<<endl;
        cout<<"NOMBRE DEL GENERO:"<<nombreG<<endl;
        cout<<"DESCRIPCION DEL GENERO:"<<desG<<endl;
        cout<<endl;
    }
    bool grabarEnDisco(){
        FILE *f;
        f=fopen(archivoFinal,"ab");
        if(f==NULL)return false;
        bool grabo = fwrite(this,sizeof (NewClass),1,f);
        fclose(f);
        return grabo;
    }
      bool leerDeDisco(int pos){
    FILE *p;
    p=fopen(archivoFinal,"rb");
    if(p==NULL){return false;}
    fseek(p,pos*sizeof (NewClass),0);
    bool leyo=fread(this, sizeof (NewClass), 1,p);
    fclose(p);
    return leyo;
    }
};



void nomYDesGenero( char*n, char *d,int id){
 Genero obj;int pos=0;
    while(obj.leerDeDisco(pos)){
            if(obj.getIdGenero()==id ){
               strcpy(n, obj.getNombre());
               strcpy(d, obj.getDescripcion());
            }
        pos++;
    }
}
bool verificarGenero(int id){
    Genero obj;int pos=0;
    while(obj.leerDeDisco(pos)){
            if(obj.getIdGenero()==id){
                if(obj.getAnioCreacionDelGFecha()>1980){
                    return true;
                }
            }
        pos++;
    }
    return false;
}
void leerRegistros(){
    NewClass obj;int pos =0;
    cout<<"registros grabados"<<endl;
    while(obj.leerDeDisco(pos++))obj.mostrar();
}
void reporte3(){
    Juego obj;int pos=0;
    char n[40];
    char d[60];
    while(obj.leerDeDisco(pos)){
        if(obj.getEstado()){
            ///verificar genero <2000
            if( verificarGenero(obj.getIdGenero())){
                /// buscar nombre del genero y descripcion
                nomYDesGenero(n,d,obj.getIdGenero());
                NewClass aux;
                aux.setNombreJuego(obj.getNombreJuego());
                aux.setDesG(d);
                aux.setNombreG(n);
                if(aux.grabarEnDisco()){
                    cout<<"se grabo un registro"<<endl;
                }else cout<<"algo salio mal"<<endl;
                ///crear archivo

            }
        }
        pos++;
    }
    leerRegistros();
}

void reporte4(){

}

int reportes(){
 int opc;
    while(true){
        system("cls");
        cout<<"-----------------------"<<endl;
        cout<<"1)Los juegos hechos antes de los 2000"<<endl;
        cout<<"2)Los juegos para mayores de 18 creado despues de los 2000"<<endl;
        ///Crear un archivo con los juegos donde su genero se
        ///haya creado despues de los 2000. Las propiedades del archivo son nombre del juego, genero y descripcion del genero.
        cout<<"3) Reporte 3"<<endl;
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
            reporte1();
            system("pause");
        break;
        case 2:
             reporte2();
             system("pause");
        break;
        case 3:
             reporte3();
             system("pause");
        break;
        case 4:
        reporte4();
        system("pause");
        break;
        default:return false;
        }
    }
    return 0;
}

#endif // REPORTES_H_INCLUDED

#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

class Genero{
    private:
    int idGenero;
    char nombre[40];
    char descripcion[60];
    Fecha creacionDelGFecha;
    bool estado;
    public:
    ///setters
    void setCreacionDelGFecha(Fecha f){creacionDelGFecha=f;}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setDescripcion(const char *d){strcpy(descripcion, d);}
    void setEstado(bool e){estado = e;}
    ///getters
    int getIdGenero(){return idGenero;}
    const char* getNombre(){return nombre;}
    const char* getDescripcion(){return descripcion;}
    bool getEstado(){return estado;}
    Fecha getCreacionDelGFecha(){return creacionDelGFecha;}
    int getAnioCreacionDelGFecha(){return creacionDelGFecha.getAnio();}
    int getMesCreacionDelGFecha(){return creacionDelGFecha.getMes();}
    int getDiaCreacionDelGFecha(){return creacionDelGFecha.getDia();}

    bool grabarEnDisco(){
    FILE *p;
    p=fopen(archivoGenero,"ab");
    if(p==NULL){return false;}
    bool escribio=fwrite(this, sizeof (Genero), 1,p);
    fclose(p);
    return escribio;
    }

    bool modificarEndisco(int pos, Genero obj){
    FILE *p;
    p=fopen(archivoGenero, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
     }
    bool leerDeDisco(int pos){
    FILE *p;
    p=fopen(archivoGenero,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p,pos*sizeof (Genero),0);
    bool leyo=fread(this, sizeof (Genero), 1,p);
    fclose(p);
    return leyo;
    }

    void resetearArchivo(){
    FILE *p;
    p=fopen(archivoGenero,"wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
    }
    fclose(p);
    }

    void mostrar(int v=0){
       /// 0 muestra todo
       /// 2 muestra todo menos id
       /// 3 muestra solo nombre del genero
        SetConsoleTextAttribute(h,3);
        if(v>-1){
              cout << "Nombre Del Genero: " << nombre << endl;
              if(v<=2){
                cout << "Descripcion: " << descripcion << endl;
                cout << "FECHA DEL COMIENZO DEL GENERO: "; creacionDelGFecha.MostrarFecha();
              }
              SetConsoleTextAttribute(h,3);

              if(v<=1)cout << "ID: " << idGenero << endl;
        }

        SetConsoleTextAttribute(h,7);

    }

    void cargar(int id){
     idGenero=id;Fecha f;
     cout<<"NOMBRE DEL GENERO:";cargarCadena(nombre,39);
     cout<<"BREVE DESCRIPCION DEL GENERO:";cargarCadena(descripcion,59);
     cout<<"FECHA ESTIMATIVA DE LA CREACION DEL GENERO:";
     f.CargarFecha();
     setCreacionDelGFecha(f);
     estado=true;
    }

};














#endif //CLASEGENERO_H_INCLUDED

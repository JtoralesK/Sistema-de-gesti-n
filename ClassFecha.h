#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED

class Fecha
{
  private:
    int dia;
    int mes;
    int anio;
    bool esbisiesto(int);
  public:
    Fecha(int d=0,int m=0,int a=0){
    if(d!=0){
    dia=d;mes=m;anio=a;
    }else {
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
  }
    }
    ///getters
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;}
    void MostrarFecha();
    void CargarFecha();
};



//Devuelve true si el año recibido es bisiesto.
bool Fecha::esbisiesto(int a)
{
  bool bisiesto=false;
  if(a%4==0)
     bisiesto=true;
  if((a%100==0) && (a%400!=0))
           bisiesto=false;
  return bisiesto;
}

void Fecha::MostrarFecha(){
  SetConsoleTextAttribute(h,11);
  cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
  SetConsoleTextAttribute(h,7);

}
void Fecha::CargarFecha(){
    int a,cM,cD;
    int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    cout<<"Anio:";cin>>a;
    while(a>anio || a<1900){
    cout<<"se pueden ingresar anios desde 1900 hasta "<<anio<<endl;
    cout<<"Anio:";cin>>a;
    }
    if(a==anio){
       cM=mes;cD=dia;
    }else cM=12;
    if(esbisiesto(a)){meses[1]=29;}
    cout<<"Mes:";cin>>mes;
    while(mes>cM || mes<1){
        cout<<"Los meses son de 1-"<<cM<<endl;
        cout<<"Mes:";cin>>mes;
    }
    if(mes==cM && a==anio){
        cD=dia;
    }else cD=meses[mes-1];
    anio=a;
    cout<<"Dia:";cin>>dia;
    while(dia>cD || dia<0){
        cout<<"Los dias son de 1-"<<cD<<endl;
        cout<<"Dia:";cin>>dia;
    }

}



#endif // CLASSFECHA_H_INCLUDED

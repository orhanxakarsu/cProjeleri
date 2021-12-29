#include "iostream"
#include "math.h"
namespace TekNoktaliFonksiyonlar {
    struct girdiler{
        double k;
        int n;
        float m;
        float c;
    };
        float F(float x ,girdiler girdi) { return girdi.k*pow(x,girdi.n)+(girdi.m)*x+(girdi.c); }

        float F1(float x) { return x; }

        float F2(float x,girdiler girdi){return girdi.k*pow(x,girdi.n)+(girdi.m -1)*x+girdi.c;}
        float F2Turev(float x,girdiler girdi){ return (girdi.k*girdi.n)*pow(x,(girdi.n)-1)+((girdi.m) -1);}
    }
    using namespace std;
    using namespace TekNoktaliFonksiyonlar;

struct veriler{
    float sol;
    double sag;
    double kok=sag;
    double hata =5*pow(10,-4);
    int n=0;
};
double bos;
void TekNoktaliArdisikMethod(struct veriler veri,girdiler girdi){
    if(F(veri.sol,girdi)*F(veri.sag,girdi)<0){
        if(F2Turev(veri.sol,girdi)<1 && F2Turev(veri.sag,girdi)<1 ){
            cout <<" ______Tek Noktali Ardisik Method______"<<endl;
            cout <<" ______________________________________"<<endl;
            cout <<"|  Tekrar(#)  |   C(n)    |   HATA(n) |"<<endl;
            cout <<"|_____________|___________|___________|"<<endl;
            do{
                float temp;
                temp = veri.kok;
                bos=veri.kok;
                veri.kok = F2(veri.sag,girdi);
                veri.sag = temp;

                cout<<"|     "<<veri.n<<"            "<<veri.kok<<"       "<<abs(veri.kok-veri.sag)<<"      "<<endl;

                veri.n++;

            }while(abs(veri.kok-bos)>veri.hata);


        } else{
            cout<<endl<<"Bu method uygulanamaz !!!"<<endl;
        }

    }
    else
    {cout<<"a";}

}
int main(){
    struct veriler veri;
    struct girdiler girdi;

    do{
        cout<<"k degerini gir --> ";
        cin>>girdi.k;
        cout<<endl<<"n degerini gir --> ";
        cin>>girdi.n;
        cout<<endl<<"m degerini gir --> ";
        cin>>girdi.m;
        cout<<endl<<"c degerini gir --> ";
        cin>>girdi.c;
        cout<<endl<<"a degerini gir --> ";
        cin>>veri.sol;
        cout<<endl<<"b degerini gir --> ";
        cin>>veri.sag;


    }while((girdi.n!=2||girdi.n!=3) && veri.sol>veri.sag);

    cout<<endl<<"Fonksiyon : "<<girdi.k<<"*x^"<<girdi.n<<"+ "<<girdi.m<<"*x + "<<girdi.c<<endl;
    TekNoktaliArdisikMethod(veri,girdi);
}
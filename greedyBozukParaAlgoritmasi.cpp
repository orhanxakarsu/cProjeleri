#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;
int indis;
void bozukPara(int n,int paralar[])
{
    int miktar = pow(3,n);
    int para = rand()%10;
    int sahte = rand()%100;
    int sahteYeri = rand()%(miktar);
    for (int i=0; i< miktar; i++)
    {
        paralar[i] = para;
    }
    paralar[sahteYeri] = sahte;
}
int agirlikHesapla(int baslangic,int bitis,int dizi[])
{
    int toplam=0;
    for(int i=baslangic; i<bitis; i++)
    {
        toplam +=dizi[i];
    }
    return toplam;
}
void bul(int dizi[],int elemanSayisi,int sol,int sag)
{
    int altDiziElemanSayisi= elemanSayisi/3;

    if(agirlikHesapla(sol,sol + altDiziElemanSayisi,dizi)==agirlikHesapla(sol +altDiziElemanSayisi,sag-altDiziElemanSayisi,dizi))
    {
        if(altDiziElemanSayisi==1){
            indis = sag-1; }
        else{
            bul(dizi,altDiziElemanSayisi,sag -altDiziElemanSayisi,sag);
        }
    }
    else if(agirlikHesapla(sag-2*altDiziElemanSayisi,sag-altDiziElemanSayisi,dizi)==agirlikHesapla(sag-altDiziElemanSayisi,sag,dizi))
    {
        if(altDiziElemanSayisi ==1){
            indis = sag-3;
        }
        else{
            bul(dizi,altDiziElemanSayisi,sol,sol + altDiziElemanSayisi);
        }}
    else if(agirlikHesapla(sol,sag-2*altDiziElemanSayisi,dizi)==agirlikHesapla(sag-altDiziElemanSayisi,sag,dizi)) {
        if(altDiziElemanSayisi ==1){
            indis = sag-2; }
        else{
            bul(dizi,altDiziElemanSayisi,sol +altDiziElemanSayisi,sag -altDiziElemanSayisi);
        }}}
int main(){
    srand(time(0));
    cout<<"Bir karakter gir --> ";
    int diziUstu;
    cin>>diziUstu;
    cout<<endl;
    int diziEleman = pow(3,diziUstu);
    int dizi[diziEleman];
    bozukPara(diziUstu,dizi);
    bul(dizi,diziEleman,0,diziEleman);
    cout<<"Bulunan Eleman : "<<indis<<endl;}

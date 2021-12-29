#include <iostream>
#include "math.h"
#include "stdio.h"
#include "sstream"
using namespace std;



class ikiyeBolme{
    private:
        double  sinirlar[2];
        int iterasyonSayisi;
        double hataSiniri = 1/pow(10,3);
        double sagdan[5];
        double soldan[5];
        double C;
        bool limitAlinabilirlik;
    public:
        double F(double );
        void Method( );
        void LimitKontrol ();
        ikiyeBolme(double ,double) ;
        bool negatiflikKontrol();
        int sayac =0;

};

double ikiyeBolme::F(double sayi) {
    return 2* pow(sayi,3) - 3*pow(sayi,2) - 4*sayi + 5;}



//Burada classımız'ın yapıcı fonksiyonunu çağırıyoruz. Aldığı altsınır ve üstsınır parametrelerini sınırlar dizisine atıyoruz.
ikiyeBolme::ikiyeBolme(double altSinir,double ustSinir ) {
    sinirlar[0]=altSinir;
    sinirlar[1]=ustSinir;
    iterasyonSayisi=0;
    LimitKontrol();}



//Burada Limit Kontrolü yapar. Çünkü İkiye Bölme Methodunda fonksiyonun limitli olması gerekir.
void ikiyeBolme::LimitKontrol() {
    double secilenNokta = (sinirlar[1] + sinirlar[0])/2;
    float artan =0.01;
    float azalan =0.01;

    /*Sagdan ve Soldan 0.01 arttırarak ve azaltarak bi yaklaşım yapmaya çalışır.
     * Burada bakılması gereken noktayı altlimit ve üstlimitin orta noktası yaptım.
     * Daha etkin bi algoritma yapılır mı evet çok daha iyisi olabilir.
     * Fakat denklemi verildiği için fonksiyonun sürekli olmadığı noktanın olmadığını biliyorum. Ona göre bu algoritmayı yazdım.*/

    for(int i =0; i<5; i++){
        sagdan[i] = F(secilenNokta +artan);
        soldan[i] =F(secilenNokta-azalan);
        artan = artan + 0.01;
        azalan = azalan + 0.01; }
    for(int k =0; k < 4; k++){
        if(abs(abs(F(secilenNokta)) - abs(sagdan[k]))<=abs(abs(F(secilenNokta))-abs(sagdan[k+1]))){
            limitAlinabilirlik= true;}
        else{
            limitAlinabilirlik =false;
            cout <<"aBU FONKSIYONUN LIMITI YOK !!! "<<endl;
            break; }}
        if (limitAlinabilirlik==true){
            for(int k =0; k < 4; k++){
                if(abs( abs(F(secilenNokta))-abs(soldan[k]))<= abs(abs(F(secilenNokta))-abs(soldan[k+1]))){
                    limitAlinabilirlik=true; }
                else{
                    limitAlinabilirlik =false;
                    cout <<"bBU FONKSIYONUN LIMITI YOK !!! "<<endl;
                    break; }}}
    if(limitAlinabilirlik==true){
        //Eğer Limiti alınabiliyorsa bizi method'umuzu calıstırdığımız fonksiyona atar.
        Method();
    }}



//Burada İkiye Bölme Methodumuzu Calıstırıyoruz.
void ikiyeBolme::Method() {
    cout <<"_______________________________________________________________"<<endl;
    cout <<"|  Tekrar(#)  |   A(n)   |    B(n)   |    C(n)   |   HATA(n) |"<<endl;
    cout <<"|_____________|__________|___________|___________|___________|"<<endl;
    while((abs((sinirlar[1]-sinirlar[0]))/pow(2,iterasyonSayisi))> hataSiniri || iterasyonSayisi==10){
        C= (sinirlar[0] + sinirlar[1] )/2;
        //Eger algoritmada C degeri kök değerini alırsa fonksiyon sonsuz döngüye giriyordu.
        //Ben de alttaki blokla bunun önüne geçtim. Denemek için : [0.8,1.6] noktası.
        if(F(C)==0){
            cout<<"KOK : "<<C<<endl;
            break;
        }
        else if((F(C)*F(sinirlar[0])) < 0){
            sinirlar[1] = C;
            iterasyonSayisi++;
        }

        else if((F(C)*F(sinirlar[1])) <0){
            sinirlar[0] = C;
            iterasyonSayisi++;
        }
        cout<<"|     "<<iterasyonSayisi<<"      "<<"     "<<sinirlar[0]<<" "<<"       "<<sinirlar[1]<<"      "<<"   "<<C<<"       "<<(sinirlar[1]-sinirlar[0])/pow(2,iterasyonSayisi)<<"      "<<endl;
    }
// Eger kökü bulduysa bu blok calısıp bulunan kokun yerini cubuklarla gösterir.
    if(iterasyonSayisi<10 and F(C) != 0){
        cout<<endl <<"                                                      |"<<endl;
        cout<<"                                                      | "<<endl;
        cout<<"                                                      |"<<endl;
        cout<<"                                                      |"<<endl;
        cout<<"                                                      |"<<endl;
        cout<<"                                                      |"<<endl;
        cout<<"                                          Bu methoda gore bulunan kok  "<<endl;}

    //Eğer Durma koşulunu 10 iterasyonda sağlayamadıysak bu blok çalışır :
    if(iterasyonSayisi>=10){
        cout<<"10 Tekrar Sonunda Istenilen Kok Degerine Ulasilamadi !!! "<<endl; }}


//Class dışı fonksiyon kullanımında tekrara düşmemek için böyle bir fonksiyon yazdım:

double Fonksiyon(double sayi) {
        return 2* pow(sayi,3) - 3*pow(sayi,2) - 4*sayi + 5;
}

//Sınıftan nesne oluşturma işlemi ve method öncesi işlemlerin yapıldığı Fonksiyon :
//Burada stringstream kütüphanesi sayesinde tip dönüşümü yapabildik.
void Basla(string sAltSinir,string sUstSinir){
    float altSinir,ustSinir;
    stringstream sstream1 ;
    stringstream sstream2 ;
    cout<<"Ikiye Bolme Methodunda incelenicek denklem : F(x) = 2x3 -3x2 -4x+5  "<<endl;

    //İçindeki kod parçacığını en az 1 kere kullanmamız gerektiği için do while yapısı kullandım :
    do{
    cout<<endl<<"Algoritmanin Bakacagi araligi gir-> [a,b] !!!    Not -> a: Alt Limit, b: Ust Limit"<<endl<<" [a ->";

    cin>>sAltSinir;
    sstream1<<sAltSinir;
    sstream1>>altSinir;
    cout<<endl<<" ,b] ->";
    cin>>sUstSinir;
    sstream2<<sUstSinir;
    sstream2>>ustSinir;

    cout<<endl<<"["<<altSinir<<","<<ustSinir<<"]"<<endl;
    if((Fonksiyon(altSinir)*Fonksiyon(ustSinir)) > 0){
        cout <<"Verdigin araligin icinde kok yok !!!  Baska bir aralik ver. "<<endl;
    }
    if(altSinir>= ustSinir ){
        cout<<"Alt sinir ust sinirdan buyuk olamaz !!!"<<endl;
    }
    if((ustSinir==false and sUstSinir!="0") or (altSinir==false and sAltSinir !="0")){
        cout<<"Lutfen numerik karakter gir !!!"<<endl;
    }
        sstream1.clear();
        sstream1.str("");
        sstream2.clear();
        sstream2.str("");
    }while(Fonksiyon(altSinir)*Fonksiyon(ustSinir)>0 or altSinir>= ustSinir or (ustSinir==0 and sUstSinir!="0") or (altSinir==0 and sAltSinir !="0"));
    ikiyeBolme Algoritma(altSinir,ustSinir);
}


int main() {
    string altSinir,ustSinir;
    Basla(altSinir,ustSinir);




}

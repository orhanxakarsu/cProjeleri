#include <iostream>
#include <math.h>

using namespace std;

class TurevAlinabilme{
    /* Türev alınabilme şartları:
      *o noktada sürekli olması
      * sagdan türevle soldan türev esit olmalıdır(sivri olmamalıdır)
      * o noktada tanımlı olmalıdır.
     */
    private:
        float turevKatsayilari[3];
        float katsayilar[4];
        float secilenNokta,sagdan[5],soldan[5],sagdanTurev[5],soldanTurev[5];
        bool turevAlinabilirlik;
    public:
        TurevAlinabilme(float,float,float,float);
        void Kontrol(float );
        double Fonksiyon( float);
        void TurevAl();
        double TurevFonksiyon(float);



};
// Methodlarımız :

// Bu Method Katsayılarını belirttiğimiz fonksiyonun türevini alıp başka bir diziye türev katsayılarını atar ->
void TurevAlinabilme::TurevAl() {
    int temp = sizeof(turevKatsayilari) / sizeof(float);
    for (int i =0; i<sizeof(turevKatsayilari)/sizeof(float); i++ ){
        turevKatsayilari[i] =katsayilar[i]*temp;
        temp--;

    }}
//Gelen degerin f(x) değerinini döndürür - >
double TurevAlinabilme::Fonksiyon(float deger ) {
    return katsayilar[0]* pow(deger,3) + katsayilar[1] * pow(deger,2)+ katsayilar[2]*deger + katsayilar[3]; }

//Gelen degerin f'(x) degerini döndürür  ->
double TurevAlinabilme::TurevFonksiyon(float deger) {
    return turevKatsayilari[0] *pow(deger,2) + turevKatsayilari[1]* deger + turevKatsayilari[2];
}

// Yapıcı Fonksiyonumuz  ->
TurevAlinabilme::TurevAlinabilme(float a, float b, float c , float d) {
    katsayilar[0]=a;
    katsayilar[1] = b;
    katsayilar[2] =c;
    katsayilar[3] =d;
    TurevAl();
}


/* Bu methodda amacımız :
 * 1) Fonksiyonun o noktada olup olmadıgını olcmek(Yoksa hata fırlatır)
 * 2) Fonksiyona 5 kere sagdan ve 5 kere soldan yaklasarak sürekliliğini test etmek
 * 3) Fonksiyonun türevinin sagdan ve soldan eşit olduğunu ölçmek  --> */
void TurevAlinabilme::Kontrol(float secilenNokta)  {
    this->secilenNokta=secilenNokta;
    float artan =1;
    float azalan =1;
    for(int i =0; i<5; i++){
        sagdan[i] = Fonksiyon(secilenNokta +artan);
        soldan[i] =Fonksiyon(secilenNokta-azalan);
        sagdanTurev[i] =TurevFonksiyon(secilenNokta + artan);
        soldanTurev[i] = TurevFonksiyon(secilenNokta-azalan);
        artan++;
        azalan++;
    }
    //Şimdi Kontrol Aşaması
    for(int k =0; k < 4; k++){
        if(Fonksiyon(secilenNokta) - abs(sagdan[k])<=Fonksiyon(secilenNokta)-abs(sagdan[k+1])){
            turevAlinabilirlik= true;
        }
        else{
            turevAlinabilirlik =false;
            cout <<"BU FONKSIYONUN TUREVI ALINAMAZa !!! "<<endl;
            break;
        }}
    if (turevAlinabilirlik==true){
        for(int k =0; k < 4; k++){
            if(Fonksiyon((secilenNokta))-abs(soldan[k])<= Fonksiyon(secilenNokta)-abs(soldan[k+1])){
                turevAlinabilirlik=true;
            }
            else{
                turevAlinabilirlik =false;
                cout <<"BU FONKSIYONUN TUREVI ALINAMAZ b!!! "<<endl;
                break;
            }
        }
    if (turevAlinabilirlik==true){
        for(int f=0; f<4; f++){
            if(TurevFonksiyon(secilenNokta)-abs(sagdanTurev[f])<=TurevFonksiyon(secilenNokta)-abs(sagdanTurev[f+1])){
                turevAlinabilirlik = true;
            }
            else{
                turevAlinabilirlik=false;
                cout<<"BU FONKSIYONUN TUREVI ALINAMAZ c!!! "<<endl;
                break;
            }
            if (turevAlinabilirlik==true){
                for(int f=0; f<4; f++){
                    if(TurevFonksiyon(secilenNokta)-abs(soldanTurev[f])<=TurevFonksiyon(secilenNokta)-abs(soldanTurev[f+1])){
                        turevAlinabilirlik = true;
                    }
                    else{
                        turevAlinabilirlik=false;
                        cout<<"BU FONKSIYONUN TUREVI ALINAMAZd !!! "<<endl;
                        break;
                    }


        }}}}}
if(turevAlinabilirlik==true){
cout << "BU FONKSIYONUN BURADA TUREVI ALINABILIR !!! "<<endl;
}}

void Basla(float a, float b,float c, float d){
    float kontrolNoktasi;
    cout << "            Turev Alinabilirlik Programi "<<endl <<endl;
    cout <<"Fonksiyon ax^3 + bx^2 + cx + d seklinde olacaktir. "<<endl<<endl;
    cout <<"a katsayisi -> ";
    cin>>a;
    cout <<endl<<"b katsayisi -> ";
    cin >>b;
    cout <<endl<<"c katsayisi -> ";
    cin >>c;
    cout <<endl<<"d katsayisi -> ";
    cin >>d;
    cout << "Fonksiyonunuz : "<< a<<"x^3 + "<<b<<"x^2 + "<<c<<"x + "<<d<<endl;
    TurevAlinabilme KontrolEt(a,b,c,d);
    cout << "Kontrol etmek istediginiz nokta : ";
    cin>>kontrolNoktasi;
    cout<<endl;
    KontrolEt.Kontrol(kontrolNoktasi);

}
int main() {
    float a,b,c,d;
    Basla(a,b,c,d);

}

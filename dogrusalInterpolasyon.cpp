#include <iostream>
using namespace std;
struct veriler{
    float nokta1[2];
    float nokta2[2];
    float bilinmeyen[2];
};

float DogrusalInterpolasyonFonksiyon(struct veriler veri)
{
    return ((veri.nokta2[1]-veri.nokta1[1])/(veri.nokta2[0]-veri.nokta1[0]))*(veri.bilinmeyen[0]-veri.nokta1[0]) +veri.nokta1[1];
}

int main() {
    struct veriler veri;
    {
        veri.nokta1[0]=1;
        veri.nokta1[1]=10;
        veri.nokta2[0]=6;
        veri.nokta2[1]=5;


    }
    cout<<"Bilinmeyen sayiyi gir --> ";
    cin>>veri.bilinmeyen[0];
    cout<<endl<<"Bilinmeyen y :  "<<DogrusalInterpolasyonFonksiyon(veri);
}

#include <iostream>
using namespace std;



namespace Lagrance{
    void F(int,float[][2],float[2]);

}
void Lagrance::F(int n,float dizi[][2],float bilinmeyen[2]) {
    float temp;
    for(int i=0; i<=n; i++)
    {
        temp=1;
        for(int j=0; j<=n; j++)
        {
            if(i != j){
                temp =temp*(bilinmeyen[0]-dizi[j][0])/(dizi[i][0]-dizi[j][0]);
                      }}
        temp*=dizi[i][1];

        bilinmeyen[1]+=temp;
    }}


int main()
{
    cout <<"***Noktalar***"<<endl;

    float dizi[5][2] ={{-1,-3},{0,-1},{1,4},{2,7},{3,0}};
    int n;
    for(int i =0; i<5; i++)
    {
       for(int j=0; j<2; j++)
       {
           cout<<dizi[i][j]<<"      ";
       }
       cout<<endl;
    }
    float bilinmeyen[2];
    do{
    cout<<"N degerini giriniz (nokta sayisi -1): ";
    cin>>n;
    if(n>4)
    {
    cout<<"Lutfen bir daha giriniz !!! (Aralik disi deger girilemez !!! )"<<endl;
    }
    }while(n>4 || n<0);
    cout<<endl<<"y degerini hesaplamak icin x degerini giriniz > ";
    cin>>bilinmeyen[0];
    if(n ==1)
    {
        float dizii[2][2]={{-1,-3},{3,0}};
        Lagrance::F(n,dizii,bilinmeyen);
    }
    if(n != 1)
    {
        Lagrance::F(n,dizi,bilinmeyen);
    }
    cout<<endl<<"x:"<<n<<"====> "<<bilinmeyen[1];
}

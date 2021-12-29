#include <iostream>
struct veriler{
    float nokta1[2];
    float nokta2[2];
    float nokta3[2];
    float bilinmeyen[2];
    float b0();
    float b1();
    float b2();
    float F();
};
float veriler::b0() {return nokta1[1];}
float veriler::b1() {return (nokta2[1]-nokta1[1])/(nokta2[0]-nokta1[0]);}
float veriler::b2() {return ((nokta3[1]-nokta2[1])/(nokta3[0]-nokta2[0])-b1())/(nokta3[0]-nokta1[0]); }
float veriler::F() {return b0() +b1()*(bilinmeyen[0]-nokta1[0])+ b2()*(bilinmeyen[0]-nokta1[0])*(bilinmeyen[0]-nokta2[0]); }

int main() {
    struct veriler veri;

    {
        veri.nokta1[0] = 0;
        veri.nokta1[1] = -8;
        veri.nokta2[0] = 2.928;
        veri.nokta2[1] = 0;
        veri.nokta3[0] = 3.5;
        veri.nokta3[1] = 2.063;
        veri.bilinmeyen[0]=3;
    }
    std::cout<<veri.F();
}

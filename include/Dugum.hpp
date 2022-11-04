#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;//Burada programımdaki bazı kodların çalışabilmesi için bazı kütühaneleri programıma dahil ediyorum.

class Dugum//Dugum adında bir class oluşturup içerisine gerekli değişken ve fonksiyonları tanımladım.
{
public:
    Dugum(string veri);
    string veri;
    Dugum* sonraki;
    Dugum* onceki;
};



#endif
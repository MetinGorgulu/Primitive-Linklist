#ifndef Liste_hpp
#define Liste_hpp
#include <exception>
#include "Dugum.hpp"
#include <iostream>//Burada programımdaki bazı kodların çalışabilmesi için bazı kütühaneleri programıma dahil ediyorum.

//Liste adında bir class oluşturup içerisine gerekli değişken ve fonksiyonları tanımladım.
class Liste
{
public:
    Liste();
    
    void E(int x,string veri );
    void C(int x);
    friend ostream& operator<<(ostream& os,Liste& liste);
    ~Liste();

private: 
    Dugum* ilk;
    int dugumsayisi;

};


#endif
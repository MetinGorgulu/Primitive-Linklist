/**
* @file        Dugum.cpp
* @description Programım Ekle Ve Çıkar olmak üzere iki fonksiyondan oluşuyor. Ekle fonksiyonuyla Girilen her veri yi bir düğüme
               dönüştürüyor ve girilen her sıraya göre bir liste oluşturuluyor.Çıkarma fonksiyonuyla verilen sıradaki düğümü listeden
               çıkarıp o düğümü yok ediyor.
* @course      1.Ogretim B grubu
* @assignment  1.Odev
* @date        14.11.2021
* @author      Metin Görgülü G201210374 metin.gorgulu@ogr.sakarya.edu.tr

*/
#include"Dugum.hpp"//Burada programımdaki bazı kodların çalışabilmesi için bazı kütühaneleri programıma dahil ediyorum.

Dugum::Dugum(string veri)
{
    this->veri = veri;
    onceki = sonraki = 0;
    
}
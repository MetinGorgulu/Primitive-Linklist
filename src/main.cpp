/**
* @file        main.cpp
* @description Programım Ekle Ve Çıkar olmak üzere iki fonksiyondan oluşuyor. Ekle fonksiyonuyla Girilen her veri yi bir düğüme
               dönüştürüyor ve girilen her sıraya göre bir liste oluşturuluyor.Çıkarma fonksiyonuyla verilen sıradaki düğümü listeden
               çıkarıp o düğümü yok ediyor.
* @course      1.Ogretim B grubu
* @assignment  1.Odev
* @date        14.11.2021
* @author      Metin Görgülü G201210374 metin.gorgulu@ogr.sakarya.edu.tr

*/

#include<iostream>
#include<iomanip>
#include"Liste.hpp"
#include<string>
#include<fstream>
#include<algorithm>
using namespace std; //Burada programımdaki bazı kodların çalışabilmesi için bazı kütühaneleri programıma dahil ediyorum.





int main()//main içerisinde bazı değişkenleri tanımladım ve dışarıdan .txt formatlı dosyanın alınıp içerisine ödevde belirtildiği
//formatta yazılan metni programıma uygun bir şekilde dönüştürmesi için ayarladım.
{
 
    ifstream file("./doc/Veri.txt");
    string satir;
    char islem;
    int x;
    string veri;
    Liste liste;
    while(getline(file, satir))
    {
        satir.erase(remove(satir.begin(), satir.end(),'(') ,satir.end());
        satir.erase(remove(satir.begin(), satir.end(),')') ,satir.end());
        size_t KareYer = satir.find("#");
        islem = satir[0];
        if (islem=='E')
        {
            x = stoi(satir.substr(1,KareYer-1));
            veri = satir.substr(KareYer+1);
            liste.E(x,veri);
        }
        else
        {
            x = stoi(satir.substr(1));
            liste.C(x);
        }
    }
    cout<<liste;
    file.close();
    return 0;
}

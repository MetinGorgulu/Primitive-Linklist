/**
* @file        Liste.cpp
* @description Programım Ekle Ve Çıkar olmak üzere iki fonksiyondan oluşuyor. Ekle fonksiyonuyla Girilen her veri yi bir düğüme
               dönüştürüyor ve girilen her sıraya göre bir liste oluşturuluyor.Çıkarma fonksiyonuyla verilen sıradaki düğümü listeden
               çıkarıp o düğümü yok ediyor.
* @course      1.Ogretim B grubu
* @assignment  1.Odev
* @date        14.11.2021
* @author      Metin Görgülü G201210374 metin.gorgulu@ogr.sakarya.edu.tr

*/
#include "Liste.hpp"
#include <iomanip>//Burada programımdaki bazı kodların çalışabilmesi için bazı kütühaneleri programıma dahil ediyorum.


Liste::Liste()
{
    ilk=0;
    dugumsayisi=-1;
}
Liste::~Liste()//Listenin içerisinden bir düğüm çıkarıldığında onu işaret eden pointer ın gösterdiği değerin silinmesi için yazdım.
{
    Dugum* gecicisil = ilk;
    while(gecicisil!=0)
    {
        Dugum *silinecek =gecicisil;
        gecicisil=gecicisil->sonraki;
        delete silinecek;

    }
}
void Liste::E(int x, string veri)//Liste classının içine koyduğum E fonksiyonunu verileri kaydırarak verilen metni listeye yazdırdım.
{
    dugumsayisi = dugumsayisi + 1;
    Dugum* yeniDugum = new Dugum(veri);
    string sakalama=veri;
    if(x<0)
    {
        cout<<"Lutfen Gecerli Bir Indiks Giriniz.";
    }
    if(ilk==0)
    {
        ilk = yeniDugum;
        
    }
    else
    {
        Dugum* gec = ilk;
        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }
        if(x>=dugumsayisi)
        {
            yeniDugum->onceki= gec;
            gec->sonraki = yeniDugum;
            
        }
        
        else
        {
            yeniDugum->onceki= gec;
            gec->sonraki = yeniDugum;
            if(x>0)
            {
                for(int i=dugumsayisi ;i>x;i--)
                { 
                gec->sonraki->veri=gec->veri;
                gec=gec->onceki;

                }
                gec->sonraki->veri=veri;
            }
            else
            {
                for(int i=dugumsayisi ;i>1;i--)
                { 
                gec->sonraki->veri=gec->veri;
                gec=gec->onceki;
                }
                gec->sonraki->veri=gec->veri;
                gec->veri=veri;
            }
        }

        
    }
    
}
void Liste::C(int x)//Liste classının içine koyduğum C fonksiyonunu verileri kaydırarak listenen seçilen indisli veriyi çıkarttırdım.
{
    if(ilk==0)
    {
        cout<<"Silinecek Herhangi Bir Veri Bulunamadi.";
    }
    else if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0; 
        cout<<"Butun Veriler Silindi.";
    }
    else if(x>dugumsayisi)
    {
        Dugum *gec = ilk; 
        while(gec->sonraki->sonraki !=0) 
        {
            gec = gec->sonraki;

        }
        delete gec->sonraki;
        gec->sonraki =0;
    }
    else
    {
        Dugum* gecsil= ilk;
        Dugum* gecsilsakla= ilk;
        for(int i=0;i<x+1;i++){
            gecsil=gecsil->sonraki;
        }
        for(int i=x;i<dugumsayisi;i++){
            gecsil->onceki->veri=gecsil->veri;
            gecsil=gecsil->sonraki;
        }
        for(int i = 0  ;i < dugumsayisi ; i++)
        {
            gecsilsakla=gecsilsakla->sonraki;
        }
        gecsilsakla->onceki->sonraki = 0;
        delete gecsilsakla;
    }
    dugumsayisi-=1;    
}
ostream& operator<<(ostream& os,Liste& liste)//Burada ödevde istenilen formatta çıktıyı yazdırmak için kodları yazdım.
//Okuyacak olan öğretmene kolaylık olması için altına da her bir düğümün adresini verisini onceki ve sonraki değerlerini yazdırdım.
{
    using namespace std;
    Dugum* gec = liste.ilk;
    os<<endl<<"        ";
    while(gec->sonraki!=0)
    {
        os<<setw(0)<<gec->veri<<"<-->";
        gec=gec->sonraki;
    }
    os<<setw(0)<<gec->veri<<endl;;
    Dugum* geci= liste.ilk;
    os<<endl;
    os<<"------------------------------------------------------------------------------------"<<endl;
    os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    while(geci!=0)
    {
        os<<setw(15)<<geci<<setw(15)<<geci->veri<<setw(15)<<geci->onceki<<setw(15)<<geci->sonraki<<endl;
        geci=geci->sonraki;
    }
    os<<"------------------------------------------------------------------------------------"<<endl;
    return os;
}
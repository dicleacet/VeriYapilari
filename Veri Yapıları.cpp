#include <iostream>

using namespace std;

struct Ogrenci
{
string isim,harfnotu;
int ogrencino,*testnotlari;
double ortalama;
};
Ogrenci *Ogrenciler; 

double notHesapla(int *notlar, int Drs)
{
    int toplam = 0;
    for(int i=0;i<Drs;i++)
    {
        toplam += notlar[i];
    }
    return toplam/Drs;
}

void Verial(int ogr,int Drs)
{
    Ogrenciler = new Ogrenci[ogr];
    for(int i=0;i<ogr;i++)
    {
        cout << i+1 << ". Ogrenci adi: ";
        cin >> Ogrenciler[i].isim;
        cout << i+1 << ". Ogrenci No: ";
        cin >> Ogrenciler[i].ogrencino;
        Ogrenciler[i].testnotlari= new int[Drs];
        for(int j=0;j<Drs;j++)
        {
            cout << i+1 << ". Ogrencinin " << j+1 << ". test sonucunu giriniz: ";
            cin >> Ogrenciler[i].testnotlari[j];
        }
        double note = notHesapla(Ogrenciler[i].testnotlari,Drs);
        Ogrenciler[i].ortalama = note;
        if (note>85)
            Ogrenciler[i].harfnotu = "A";
        else if (note>=75 && note<85)
            Ogrenciler[i].harfnotu = "B";
        else if (note>=65 && note<75)
            Ogrenciler[i].harfnotu = "C";
        else if (note>=50 && note<65)
            Ogrenciler[i].harfnotu = "D";
        else if (note>0 && note<50)
            Ogrenciler[i].harfnotu = "F";
        cout << endl << "--------------------------------" << endl; 
    }       
}

void goster(int ogr,int Drs)
{
    for(int i=0;i<ogr;i++)
    {
        cout << i+1 << ". ogrenci adi: " << Ogrenciler[i].isim << endl;
        cout << i+1 << ". ogrenci no: " << Ogrenciler[i].ogrencino << endl;
        for(int j=0;j<Drs;j++)
        {
            cout << i+1 << ". ogrencinin " << j+1 << ". Ders puani: " << Ogrenciler[i].testnotlari[j] << endl;
        }
        cout << i+1 << ". ogrenci ortalamasi: "<< Ogrenciler[i].ortalama << " - Harf notu: " << Ogrenciler[i].harfnotu << endl;
        cout << endl << "--------------------------------" << endl; 
    }
    system("PAUSE");
}

void sil(int ogr,int Drs)
{
    for(int i=0;i<ogr;i++)
    {
       delete [] Ogrenciler[i].testnotlari;
    }
    delete [] Ogrenciler;
    cout << "Bellek Bosaltildi !!!" << endl;
    system("PAUSE");
}


int main()
{
    int ogr,Drs;
    cout << "Ogrenci Sayisini Giriniz: ";
    cin >> ogr;
    cout << "Ders Sayisini Giriniz: ";
    cin >> Drs;
    Verial(ogr,Drs);
    goster(ogr,Drs);
    sil(ogr,Drs);
}
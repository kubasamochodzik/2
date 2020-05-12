#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct uczeniowie
{
        string imie, nazwisko,pesel,adres;
        int numerek;
};
class klasa
{
vector <struct uczeniowie> spis;
public:
void wczytajZPliku(const char *);  
void wypisz();
void zapiszDoPliku(const char *);
                              
};

void klasa::wczytajZPliku(const char *nazwa)
{
        struct uczeniowie dane;
ifstream plik1;
plik1.open(nazwa);  
   if(plik1.good())  
    while(!plik1.eof())  
    {
    plik1  >> dane.numerek;
    plik1  >> dane.imie;
    plik1  >> dane.nazwisko;
	plik1  >> dane.pesel;
    plik1  >> dane.adres;  
    spis.push_back(dane); 
    }
    plik1.close();  

}
void klasa::wypisz()
{
		string napis;
		ifstream plik;
		    plik.open("1.txt");
		    if(plik.good())
		     while(!plik.eof())
		    {
	plik>>napis;
	cout<<napis;
	cout<<endl; 
		    }
		    plik.close();
}
void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczeniowie>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
        plik <<"["<<"{"<<it->numerek<<":"<<it->imie<<":"<<it->nazwisko<<":"<<it->pesel<<":"<<it->adres<<"}"<<"]"<< "\n";
        cout <<"["<<"{"<<it->numerek<<":"<<it->imie<<":"<<it->nazwisko<<":"<<it->pesel<<":"<<it->adres<<"}"<<"]"<< "\n";
        }
        plik.close();  
}
int main(int argc, char** argv) {
    klasa TI;
    TI.wczytajZPliku("2.txt");
    TI.wypisz();
    TI.zapiszDoPliku("1.txt");
    return 0;
}

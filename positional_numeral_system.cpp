#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string dziesietny_na_sys2(int liczba, int sys2)
{
    string wynik = "";
    int modulo;
    if(liczba != -1)
    {
        do
        {
            modulo = liczba%sys2;
            if(modulo >= 0 && modulo <= 9) wynik = char((48+modulo)) + wynik;
            else wynik = char((55+modulo)) + wynik;
            liczba = (liczba - modulo)/sys2;
        }
        while(liczba != 0);
        return wynik;
    }
    else return "Error";
}

unsigned int sys1_na_dziesietny(int sys1, string liczba)
{
    bool czy_duza = 0;
    bool czy_mala = 0;
    unsigned int wynik = 0;
    for(int i = 0; i < liczba.length(); i++)
    {
        if(liczba[i] >= 48 && liczba[i] <= 57) wynik = wynik + (liczba[i] - 48) * pow(float(sys1), liczba.length() - 1 - i);
        else
        {
            if(liczba[i] >= 65 && liczba[i] < 55 + sys1)
            {
                if(czy_mala) return -1;
                else
                {
                    czy_duza = 1; wynik = wynik + (liczba[i] - 55) * pow(float(sys1), liczba.length() - 1 - i);
                }
            }
            else
            {
                if(liczba[i] >= 97 && liczba[i] < 87 + sys1)
                {
                    if(czy_duza) return -1;
                    else
                    {
                        czy_mala = 1;
                        wynik = wynik + (liczba[i] - 87) * pow(float(sys1), liczba.length() - 1 - i);
                    }
                }
                else return -1;
            }
        }
    }
    return wynik;
}

int main()
{
    cout<<"Tutaj mozesz zamieniac liczby pomiedzy dowolnymi systemami liczbowymi."<<endl<<"Podstawy z zakresu (1; 36)."<<endl<<"Kolejnosc: system1, liczba, system2"<<endl;
    int n = 1;
    int m = 36;
    int sys1, sys2;
    string liczba;
    cin>>sys1>>liczba>>sys2;
    if(sys1 > n && sys1 < m && sys2 > n && sys2 < m) cout<<endl<<"Liczba po zamianie: "<<dziesietny_na_sys2(sys1_na_dziesietny(sys1, liczba), sys2)<<endl;
    else cout<<endl<<"Error"<<endl;
    return 0;
}

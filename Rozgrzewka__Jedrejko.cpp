#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Student {
int id;
string imie;
string nazwisko;
string plec;
string pesel;
};

struct Bazastudentow{
Student tablica[100];
int ile_studentow;
};
void Wczytaj (Student &x)
{
cout<<"id: ";
cin>>x.id;
cout<<"imie: ";
cin>>x.imie;
cout<<"nazwisko: ";
cin>>x.nazwisko;
cout<<"plec: ";
cin>>x.plec;
cout<<"pesel: ";
cin>>x.pesel;
}

string display_student (Student &x)
{
    return to_string(x.id) +", "+ string(x.imie) +", "+string(x.nazwisko) +", "+string(x.plec) +", "+string(x.pesel);
}

void display_all_students (Bazastudentow &xx, int &n)
{
for (int i=0; i<n; i++)
{
cout<<display_student(xx.tablica[i]);
cout<<endl;
}
}

int find_students (Bazastudentow &xx, int ind)
{
    int polozenie;
    for (int i=0; i<100; i++)
    {
        if(ind==xx.tablica[i].id)
        {
            cout<<"Znaleziono studenta o indeksie ["<<ind<<"]"<<endl;
            polozenie = i;
            cout<<"Polozenie: ";
            return polozenie;
            cout<<endl;
        }

    }
    cout<<"Brak studenta w bazie danych"<<endl;
    return -1;


}
void wyzeruj (Bazastudentow &xx)
{
    for (int i=0; i<100; i++)
    {
        xx.tablica[i].id=0;
        xx.tablica[i].imie="0";
        xx.tablica[i].nazwisko="0";
        xx.tablica[i].plec="0";
        xx.tablica[i].pesel="0";

    }
}

int indeks (Bazastudentow &xx)
{
int PierwszeZero;
for (int i=0; i<100; i++)
{
    if (xx.tablica[i].id==0)
        {PierwszeZero=i;
        break;
        }
}
return PierwszeZero;
}

void save(Bazastudentow &xx)
{
     fstream plik;
            plik.open("baza_danych.txt", ios::out | ios::app);

            for(int i=0; i<xx.ile_studentow; i++)
            {
                plik<<xx.tablica[i].id<<endl;
                plik<<xx.tablica[i].imie<<endl;
                plik<<xx.tablica[i].nazwisko<<endl;
                plik<<xx.tablica[i].plec<<endl;
                plik<<xx.tablica[i].pesel<<endl;
            }
            plik.close();
}
void load (Bazastudentow &xx)
{
    fstream plik;
            plik.open("baza_danych.txt", ios::in);
            if( plik.good() == true )
            {
                cout << "Wczytano produkty z bazy danych!" << std::endl;

                int liczba_lin=0;
                string linia;
                while(!plik.eof())
                {
                    getline(plik, linia);
                    liczba_lin++;
                }
                int liczba_st=(liczba_lin-1)/5;
                plik.close();


                fstream plik;
                plik.open("baza_danych.txt", ios::in);
                for(int i =0; i<liczba_st; i++)
                {
                    plik>>xx.tablica[i].id;
                    plik>>xx.tablica[i].imie;
                    plik>>xx.tablica[i].nazwisko;
                    plik>>xx.tablica[i].plec;
                    plik>>xx.tablica[i].pesel;
                }
                xx.ile_studentow=liczba_st;
            }
            else
                cout << "Dostep do pliku zostal zabroniony!" <<endl;

            plik.close();
}
void add_student (Bazastudentow &xx)
{
    int PierwszeZero = indeks(xx);
    cout<<endl;
    cout<<"id: ";
    cin>>xx.tablica[PierwszeZero].id;
    cout<<"imie: ";
    cin>>xx.tablica[PierwszeZero].imie;
    cout<<"nazwisko: ";
    cin>>xx.tablica[PierwszeZero].nazwisko;
    cout<<"plec: ";
    cin>>xx.tablica[PierwszeZero].plec;
    cout<<"pesel: ";
    cin>>xx.tablica[PierwszeZero].pesel;
    xx.ile_studentow++;
}

void remove_student (Bazastudentow &xx)
{
    int ind2;
    cout<<"Usun studenta o id: "<<endl;
    cin>>ind2;
    for (int i=ind2; i<xx.ile_studentow; i++)
    {
        xx.tablica[i]=xx.tablica[i+1];
    }
    xx.ile_studentow--;
}

int main()
{
cout<<"Podaj dane studenta"<<endl;
Student x;
Wczytaj(x);
cout<<endl;
cout<<endl;
int n;
n=3;
Student studenci[n];
studenci[0].id=1;
studenci[0].imie="Jan";
studenci[0].nazwisko="Kowalski";
studenci[0].plec="mezczyzna";
studenci[0].pesel="97092289554";

studenci[1].id=2;
studenci[1].imie="Marta";
studenci[1].nazwisko="Kowalska";
studenci[1].plec="kobieta";
studenci[1].pesel="94121969867";


Bazastudentow xx;
wyzeruj(xx);

xx.tablica[0]=x;
xx.tablica[1]=studenci[0];
xx.tablica[2]=studenci[1];
xx.ile_studentow=n;
display_all_students(xx, xx.ile_studentow); //display przed dodaniem


cout<<"Wyszukaj indeks: "; //szukanie studenta
int ind, ind2;
cin>>ind;
cout<<find_students (xx, ind);

add_student(xx); //dodanie studenta
add_student(xx); //dodanie studenta
display_all_students(xx, xx.ile_studentow); //display po dodaniu
cout<<endl;
cout<<"liczba studentow: "<<xx.ile_studentow<<endl;

remove_student(xx); //usuniecie studenta
display_all_students(xx, xx.ile_studentow); //display po usunieciu

save(xx); //zapisanie

    return 0;


}

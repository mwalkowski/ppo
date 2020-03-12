#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct Studenci
{
    string imie;
    string nazwisko;
    string plec;
    string pesel;
    string indeks;
};

struct BazaStudentow
{
    Studenci li[100];
    int liczba=0;

};

void display_student(Studenci &a)
{
    cout<<a.imie<<endl;
    cout<<a.nazwisko<<endl;
    cout<<a.plec<<endl;
    cout<<a.pesel<<endl;
    cout<<a.indeks<<endl<<endl;

}



void display_all_students(Studenci ty[],int n)
{
    for(int i=0; i<n; i++)
        display_student(ty[i]);

}

int find_student(BazaStudentow ty, string n)
{
    for(int i=0; i<ty.liczba; i++)
    {


        if(ty.li[i].indeks==n)
        {
            return i;
        }
    }
    return -1;
}

void add_student(BazaStudentow &ty)
{
    //przykladowe

    ty.li[ty.liczba].imie="Dodan";
    ty.li[ty.liczba].nazwisko="Dodany";
    ty.li[ty.liczba].plec="M";
    ty.li[ty.liczba].pesel="69092517177";
    ty.li[ty.liczba].indeks="464225";

    //z klawiatury
    /*
    cout<<"podaj imie: "<<endl;
    cin>>ty.li[ty.liczba].imie;
    cout<<"podaj nazwisko: "<<endl;
    cin>>ty.li[ty.liczba].nazwisko;
    cout<<"podaj plec: "<<endl;
    cin>>ty.li[ty.liczba].plec;
    cout<<"podaj pesel: "<<endl;
    cin>>ty.li[ty.liczba].pesel;
    cout<<"podaj indeks: "<<endl;
    cin>>ty.li[ty.liczba].indeks;
    */

    ty.liczba++;
}

void remove_student(BazaStudentow &ty, string n)
{
    int r=find_student(ty, n);
    ty.li[r]=ty.li[ty.liczba-1];



    ty.li[ty.liczba-1].imie="";
    ty.li[ty.liczba-1].nazwisko="";
    ty.li[ty.liczba-1].plec="";
    ty.li[ty.liczba-1].pesel="";
    ty.li[ty.liczba-1].indeks="";
    ty.liczba--;
}

void load_students(BazaStudentow &ty)
{
    fstream plik;
    plik.open("stud.txt", ios::in);
    int i=0;
    while(!plik.eof())
    {


        plik>>ty.li[i].imie;
        plik>>ty.li[i].nazwisko;
        plik>>ty.li[i].plec;
        plik>>ty.li[i].pesel;
        plik>>ty.li[i].indeks;
        i++;
        ty.liczba++;
    }
    plik.close();

}


void save_students(BazaStudentow &ty)
{
    fstream plik;
    plik.open("stud.txt", ios::out);
    for(int i=0; i<ty.liczba; i++)
    {


        plik<<ty.li[i].imie<<endl;
        plik<<ty.li[i].nazwisko<<endl;
        plik<<ty.li[i].plec<<endl;
        plik<<ty.li[i].pesel<<endl;
        plik <<ty.li[i].indeks<<endl;
    }
    plik.close();

}


int main()
{
    Studenci pierwszy= {"Andrzej","Testowy","M","02252712489","621335"};

    Studenci tab[3]= {{"Marek","Poczatek","M","81110144648","169923"},{"Aneta","Srodek","K","77032591273","197726"},{"Karol","Koniec","M","91071789372","175443"}};

    display_all_students(tab,3);


    BazaStudentow baz;

    baz.li[0]= {"Marek","Poczatek","M","81110144648","169923"};
    baz.li[1]= {"Aneta","Srodek","K","77032591273","197726"};
    baz.li[2]= {"Karol","Koniec","M","91071789372","175443"};
    baz.liczba=3;

    cout<<find_student(baz,"197726");


    display_all_students(baz.li,baz.liczba);

/*
    add_student(baz);

    display_all_students(baz.li, baz.liczba);
*/

/*
    remove_student(baz,"197726" );
    display_all_students(baz.li,baz.liczba);
*/

/*
    save_students(baz);
*/

/*
    load_students(baz);
    display_all_students(baz.li,baz.liczba);
*/

    return 0;
}

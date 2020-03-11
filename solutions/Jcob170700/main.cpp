#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct Student
{
    int nr;
    string imie, nazwisko, pesel, indeks, plec;

};

struct Baza
{
    Student baza[100];
    int ilosc;
};

int find_student (Baza &baza, string indeks)
{
    int miejsce;
    for (int i=0;baza.ilosc;i++)
    {
        if (baza.baza[i].indeks==indeks)
        {
            miejsce=i;
            return miejsce+1;
        }
        return miejsce=-1;
    }
}


void add_student (Baza &baza)
{
    if (baza.ilosc>100)
        cout << "Baza studentow pelna!";
    else
    {
        baza.baza[baza.ilosc].nr=baza.ilosc+1;
        cout << "Podaj imie: " << endl;
        cin>>baza.baza[baza.ilosc].imie;
        cout << "Podaj nazwisko: " << endl;
        cin>>baza.baza[baza.ilosc].nazwisko;
        cout << "Podaj plec (mezczyzna/kobieta): " << endl;
        cin>>baza.baza[baza.ilosc].plec;
        cout << "Podaj pesel: " << endl;
        cin>>baza.baza[baza.ilosc].pesel;
        cout << "Podaj indeks: " << endl;
        cin >> baza.baza[baza.ilosc].indeks;
        baza.ilosc++;
    }


}

void load_students (Baza &baza)
{
    fstream plik;
    bool plik_domyslny;
    string linia, sciezka;
    int i=0;
    int nr=1;
    cout << "Wczytac domyslny plik?(0-nie/1-tak): " << endl;
    cin >> plik_domyslny;
    if(plik_domyslny==1) {
        plik.open("C:\\Users\\Kuba\\CLionProjects\\ppo\\solutions\\Jcob170700\\baza.txt", ios::in);
    } else{
        cout << "Podaj sciezke do pliku z ktorego chcesz wczytac dane: " << endl;
        cin >> sciezka;
        plik.open(sciezka, ios::in);
    }
    if(!plik.good())
    {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }
    while(getline(plik,linia))
    {
        baza.baza[i].imie=linia;
        getline(plik,linia);
        baza.baza[i].nazwisko=linia;
        getline(plik,linia);
        baza.baza[i].plec=linia;
        getline(plik,linia);
        baza.baza[i].pesel=linia;
        getline(plik,linia);
        baza.baza[i].indeks=linia;
        baza.baza[i].nr=nr;
        i++;
        nr++;
    }
    baza.ilosc=i;
    plik.close();
    cout << "Baza zostala pomyslnie wczytana" << endl;
}


void display_student (Baza &baza, int miejsce)
{
    cout << baza.baza[miejsce-1].nr << "." << endl;
    cout << "Imie studenta: "<< baza.baza[miejsce-1].imie << endl;
    cout << "Nazwisko studenta: " << baza.baza[miejsce-1].nazwisko << endl;
    cout << "Plec: " << baza.baza[miejsce-1].plec << endl;
    cout << "Nr pesel: " << baza.baza[miejsce-1].pesel << endl;
    cout << "Nr indeksu: " << baza.baza[miejsce-1].indeks << endl;
}

void display_all_students (Baza &baza)
{
    for (int i=0;i<baza.ilosc;i++)
    {
        cout << baza.baza[i].nr<<"."<<endl;
        cout << "Imie studenta: "<< baza.baza[i].imie << endl;
        cout << "Nazwisko studenta: " << baza.baza[i].nazwisko << endl;
        cout << "Plec: " << baza.baza[i].plec << endl;
        cout << "Nr pesel: " << baza.baza[i].pesel << endl;
        cout << "Nr indeksu: " << baza.baza[i].indeks << endl;
    }
}

void save_students(Baza baza) {
    fstream plik;
    bool plik_domyslny;
    string sciezka;
    cout << "Zapsiac baze w domyslnym pliku?(0-nie/1-tak)" << endl;
    cin >> plik_domyslny;
    if (plik_domyslny==1)
    {
        plik.open("C:\\Users\\Kuba\\CLionProjects\\ppo\\solutions\\Jcob170700\\baza.txt", ios::out);
    }
    else
    {
        cout << "Podaj sciezke do pliku w ktorym chcesz zapisac baze studemtow: " << endl;
        cin >> sciezka;
        plik.open(sciezka, ios::out);
    }
    for(int i=0; i<baza.ilosc; i++)
    {
        plik << baza.baza[i].imie << endl;
        plik << baza.baza[i].nazwisko << endl;
        plik << baza.baza[i].plec << endl;
        plik << baza.baza[i].pesel << endl;
        plik << baza.baza[i].indeks << endl;
    }
    plik.close();

}

void remove_student (Baza &baza)
{
    int nr;
    cout << "Podaj numer studenta, ktorego chcesz usunac z bazy" << endl;
    cin >> nr;
    if (nr>baza.ilosc)
    {
        cout << "Nie ma takiego numeru na liscie!" << endl;
    }
    else
    {
        for (int i=nr-1;i<baza.ilosc-1;i++)
        {
            baza.baza[i].nr=i+1;
            baza.baza[i].imie=baza.baza[i+1].imie;
            baza.baza[i].nazwisko=baza.baza[i+1].nazwisko;
            baza.baza[i].plec=baza.baza[i+1].plec;
            baza.baza[i].pesel=baza.baza[i+1].pesel;
            baza.baza[i].indeks=baza.baza[i+1].indeks;
        }
        baza.ilosc--;
    }
}

void menu (Baza &baza)
{
    int nr=0;
    int opcja = 1;
    string nr_indeksu;
    do
    {
        cout << "Wybierz co zrobic" << endl;
        cout << "1 - Wczytaj liste studnentow" << endl;
        cout << "2 - Wyswietl wszystkich studemtow na liscie" << endl;
        cout << "3 - Dodaj studenta do listy" << endl;
        cout << "4 - Usun studenta z listy" << endl;
        cout << "5 - Znajdz studenta z listy" << endl;
        cout << "6 - Wyswietl studenta z listy" << endl;
        cout << "7 - Zapisz liste studentow" << endl;
        cout << "8 - Wyjscie z programu" << endl;
        cin >> opcja;
        switch (opcja)
        {
            case 1:
            {
                load_students(baza);
                break;
            }
            case 2:
            {
                display_all_students(baza);
                break;
            }
            case 3:
            {
                add_student(baza);
                break;
            }
            case 4:
            {
                remove_student(baza);
                break;
            }
            case 5:
            {
                cout << "Podaj indeks szukanego studenta" << endl;
                cin >> nr_indeksu;
                cout << "Student ma nr: " << find_student(baza,nr_indeksu) << endl;
                break;
            }
            case 6:
            {
                cout << "Podaj nr studenta ktorego chcesz wyswietlic";
                cin >> nr;
                cout << "" << endl;
                display_student(baza,nr);
                break;
            }
            case 7:
            {
                save_students(baza);
                break;
            }
            default:
            {
                opcja=7;
                break;
            }
        }
    }
    while (opcja!=7);
}

int main()
{
    Baza baza{{},0};
    menu(baza);
    return 0;
}

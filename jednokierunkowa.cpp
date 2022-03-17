#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

struct osoba {
    string imie;
    string nazwisko;
    int wiek;
    osoba *nastepna; // wskaźnik na następny element
    osoba(); // konstruktor
};

osoba::osoba() {
    nastepna = 0; // konstruktor
}

struct lista {
    osoba *pierwsza; // wskaźnik na początek listy
    void dodaj_osobe (string imie, string nazwisko, int wiek);
    void usun_osobe (int nr);
    void wyswietl_liste ();
    lista();
};


lista::lista() {
    pierwsza = 0; // konstruktor
}

void lista::wyswietl_liste()
{
    // wskaznik na pierszy element listy
    osoba *temp = pierwsza;

    // przewijamy wskazniki na nastepne elementy
    while (temp)
    {
        cout << "imie: " << temp->imie << " nazwisko: " << temp->nazwisko << endl;
        temp=temp->nastepna;
    }
}

void lista::usun_osobe (int nr)
{
    // jezeli to pierwszy element listy
    if (nr==1)
    {
        osoba *temp = pierwsza;
        pierwsza = temp->nastepna; //ustawiamy poczatek na drugi element
        delete temp; // usuwamy stary pierwszy element z pamieci
    }

        // jeżeli nie jest to pierwszy element
    else if (nr>=2)
    {
        int j = 1;

        // do usuniecia srodkowego elemetnu potrzebujemy wskaznika na osobe n-1
        // wskaznik *temp bedzie wskaznikiem na osobe poprzedzajaca osobe usuwana
        osoba *temp = pierwsza;

        while (temp)
        {
            // sprawdzamy czy wskaznik jest na osobie n-1 niz usuwana
            if ((j+1)==nr) break;

            // jezeli nie to przewijamy petle do przodu
            temp = temp->nastepna;
            j++;
        }

        // wskaznik *temp wskazuje teraz na osobe n-1
        // nadpisujemy wkaznik n-1 z osoby n na osobe n+1
        // bezpowrotnie tracimy osobe n-ta

        // jezeli usuwamy ostatni element listy
        if (temp->nastepna->nastepna==0) {
            delete temp->nastepna;
            temp->nastepna = 0;
        }
            // jezeli usuwamy srodkowy element
        else {
            osoba *usuwana = temp->nastepna;
            temp->nastepna = temp->nastepna->nastepna;
            delete usuwana;
        }
    }
}

void lista::dodaj_osobe(string imie, string nazwisko, int wiek)
{
    osoba *nowa = new osoba; // tworzy nowy element listy

    // wypełniamy naszymi danymi
    nowa->imie = imie;
    nowa->nazwisko = nazwisko;
    nowa->wiek = wiek;

    if (pierwsza==0) // sprawdzamy czy to pierwszy element listy
    {
        // jeżeli tak to nowy element jest teraz początkiem listy
        pierwsza = nowa;
    }
    else
    {
        // w przeciwnym wypadku wędrujemy na koniec listy
        osoba *temp = pierwsza;

        while (temp->nastepna)
        {
            // znajdujemy wskaźnik na ostatni element
            temp = temp->nastepna;
        }

        temp->nastepna = nowa; // ostatni element wskazuje na nasz nowy
    }
}

int random(int min, int max) {//range : [min, max]
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

osoba *search(lista *baza, int index){

    osoba *el = baza->pierwsza;
    for(int i = 0; i < index; i ++) {
        el = el->nastepna;
    }

    return el;
}

lista merge(lista a, lista b){
    lista merged;

    osoba *temp = a.pierwsza;

    while(temp != NULL){
        merged.dodaj_osobe(temp->imie, temp->nazwisko, temp->wiek);
        temp = temp->nastepna;
    }

    temp = b.pierwsza;

    while(temp != NULL){
        merged.dodaj_osobe(temp->imie, temp->nazwisko, temp->wiek);
        temp = temp->nastepna;
    }

    return merged;

}


int main() {
    lista *baza = new lista; // tworzymy liste

    string arr_imiona[] = {"Maciej", "Oleksandr", "Denis", "Dariusz", "Andrej", "Jozek", "Zbigniew"};
    string arr_nazwiska[] = {"Nowak", "Kowalski", "Wiśniewski", "Wójcik", "Kowalczyk", "Kamiński", "Lewandowski"};

    for (int i = 0; i < 1000; i++) {
        baza->dodaj_osobe(arr_imiona[random(0, arr_imiona->length())], arr_nazwiska[random(0, arr_nazwiska->length())],
                          i);
    }

    unsigned int start_time =  clock();

    osoba *osoba;
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);
    osoba = search(baza, 500);

    unsigned int end_time =  clock();

    cout<<"-----------------------------------------------"<<endl;

    cout<<"Wiek szukanej osoby: "<<osoba->wiek<<endl;


    cout<<"The above code block was executed in " << (end_time - start_time) / 1000.0 << " s\n"<<endl;
    /*U mnie ten szas wynośi 0 s*/


    unsigned int start_time2 = clock();
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);
    osoba = search(baza, 999);

    cout<<"-----------------------------------------------"<<endl;

    cout<<"Wiek szukanej osoby: "<<osoba->wiek<<endl;

    unsigned int end_time2 = clock();

    cout<<"The above code block was executed in " << (end_time2 - start_time2) / 1000.0  << " s\n"<<endl;

    /* U mnie ten szas wynośi 0.001 sek, czyli średni: 0.0001 sek */

    unsigned int start_time3 = clock();

    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;
    osoba = search(baza, random(1, 999));
    cout<<osoba->wiek<<endl;

    unsigned int end_time3 = clock();

    cout<<"The above code block was executed in " << (end_time3 - start_time3) / 1000.0  << " s\n"<<endl;

    /* U mnie ten szas bez cout'ow wynośi 0 sek, z cout'ami - 0,049 czyli średni: 0.00326 sek */

    delete baza;

    return 0;
}
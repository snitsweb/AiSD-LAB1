#include<iostream>

using namespace std;

class kolejka {
public:
    kolejka() {
        poczatek = koniec = 0;
        f = 1;
    }

    ~kolejka() //zwolnienie pamięci dla elementów kolejki
    {
        while (koniec - poczatek > 0) {
            el = p;
            p = p->nastepny;
            delete el;
            ++poczatek;
        }
        if (!f)
            delete p;
    }

    unsigned int size() { return koniec - poczatek; }//liczba elementów w kolejce
    void push_back(int x)//dodanie elementu na koniec kolejki
    {
        if (f)//jesli pierwszy element wrzucamy do kolejki
        {
            k = new wezel;    //utworzenie elementu ostatniego
            k->element = x; //przypisanie do niego wartosci
            p = new wezel;        //utworzenei elemntu pierwszego
            p->nastepny = k;  //element pierwszy wskazuje na ostatni
            f = 0;
        } else {
            el = new wezel;    //utworzenie nowego elementu kolejki
            el->element = x;    //przypisanie do niego wartosci
            k->nastepny = el;    //ostatni dotychczas element wskazuje na utworzony
            k = el;                //element utworzony staje się ostatnim
        }
        ++koniec;
    }

    int pop_back()// usunięcie pierwszego elementu z kolejki i zwrócenie 1 gdy ok, 0 - gdy nie ma nic do usunięcia
    {
        if (koniec - poczatek == 0)return 0; //gdy nie ma nic w kolejce zwracamy 0
        el = p;
        p = p->nastepny; //przejscie na następny element kolejki
        delete el;        //usunięcie pierwszego elementu w kolejce
        ++poczatek;
        return 1;
    }

    int first() //zwrócenie pierwszego elementu w kolejce
    {
        return p->nastepny->element;
    }

    int last() //wyznaczenie ostatniego elementu w kolejce
    {
        return k->element;
    }

private:
    bool f; //flaga okreslająca, czy w kolejce cos już się pojawiło
    struct wezel {
        int element;
        wezel *nastepny;
    };
    unsigned int poczatek, koniec; //początek i koniec kolejki - index
    wezel *p, *k, *el; //poczatek, koniec,
};

int main() {
    kolejka queue;

    for (int i = 0; i < 100; i++) {
        queue.push_back(i);
        cout << "Dodano do listy: " << i << endl;
    }

    while (queue.pop_back()) {
        cout << "Usunięto z listy: " << queue.first() << endl;
    }

    return 0;
}
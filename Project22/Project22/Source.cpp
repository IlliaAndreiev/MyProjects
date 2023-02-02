#include <iostream>
#include <cassert>
using namespace std;

/** struktura pre uzol jednosmerneho zoznamu */
struct node {
    int data;    // data v uzle
    node* next;  // dalsi uzol v zozname
};

/** struktura pre jednosmerny kruhovy spajany zoznam */
struct linkedList {
    node* last;  // smernik na posledny uzol, alebo NULL
};

/* inicializacia prazdneho zoznamu */
void init(linkedList& z) {
    z.last = NULL;
}

/* nacitanie cisel a ich pridanie na koniec zoznamu */
void read(linkedList& z) {
    int x;
    cin >> x;
    while (x != -1) {       // kym uzivatel nezada -1
        node* temp = new node;
        temp->data = x;
        // zvlast riesime pridanie prveho prvku
        if (z.last == NULL) {
            z.last = temp;
            temp->next = temp;
        }
        else {
            // pridanie prvku do neprazdneho zoznamu
            temp->next = z.last->next;
            z.last->next = temp;
            z.last = temp;
        }
        cin >> x;
    }
}

/* uvolnenie pamate pre zoznam */
void destroy(linkedList& z) {
    // prazdny zoznam netreba uvolnovat
    if (z.last == NULL) return;

    // do p si ulozime smernik na prvy uzol zoznamu
    node* p = z.last->next;
    // rozpojime kruh
    z.last->next = NULL;

    // teraz uz pracujeme ako v beznom spajanom zozname
    while (p != NULL) {
        node* p2 = p->next;
        delete p;
        p = p2;
    }
}

/* vypis zoznamu */
void print(const linkedList& z) {
    // TODO: VAS KOD TU
    node* p = z.last;
    if (p != NULL) p = p->next;
    while (p != z.last) {
        cout << p->data << " ";
        p = p->next;
    }
    if (z.last != NULL) cout << z.last->data;
    cout << endl;
    /*node* p = new node;
    p->data = NULL;
    p->next = NULL;
    p = NULL;
    int N = 0;
    while (p != z.last) {
        N++;
            p = p->next;
    }
    int *arr = new int[N];
    p = z.last;
    for (int i = N; i > 0; i--) {
        arr[i] = p->data;
        p = p->next;
    }
    for (int i = 0; i < N; i++) cout << arr[i];*/
    /* node* p = p->data;
     p = p->next;
     while (p != NULL) {
         cout << p->data << " ";
         p = p->next;
     }
     cout << endl;*/
}

int main(void) {
    // vytvorenie prazdeho zoznamu
    linkedList z1;
    init(z1);

    // nacitanie a vyspis prvej casti zoznamu
    read(z1);
    print(z1);
    // nacitanie a vypis druhej casti zoznamu
    read(z1);
    print(z1);

    // uvolnenie pamate
    destroy(z1);
}
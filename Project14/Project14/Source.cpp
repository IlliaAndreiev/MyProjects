#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 3000;

struct cislo {
    unsigned long long  pocet_cifier;
    unsigned long long cifry[MAXN];
};

/** Funkcia do premennej a vytvori reprezentaciu
 * kladneho celeho cisla z premennej x */
void vytvorCislo(cislo& a, unsigned long long x) {
    assert(x > 0);
    a.pocet_cifier = 0;
    while (x > 0) {
        a.cifry[a.pocet_cifier] = x % 10;
        x = x / 10;
        a.pocet_cifier++;
    }
}

/* Tato funkcia nacita cislo a ulozi ho do structu cislo.
 * Vyuziva typ char, ktory sme este nebrali, ale nemusite jej rozumiet. */
void nacitaj_cislo(cislo& a) {
    a.pocet_cifier = 0;
    char c;
    cin >> noskipws >> c;
    while (c >= '0' && c <= '9') {
        a.cifry[a.pocet_cifier] = c - '0';
        a.pocet_cifier++;
        assert(a.pocet_cifier <= MAXN);
        cin >> noskipws >> c;
    }
    assert(c == '\n');
    for (int i = 0; i < a.pocet_cifier - i - 1; i++) {
        swap(a.cifry[i], a.cifry[a.pocet_cifier - i - 1]);
    }
    cin >> skipws;
}




void vypis(cislo& a) {
    for (int i = a.pocet_cifier - 1; i >= 0; i--) {
        cout << a.cifry[i];
    }
    cout << endl;
}



void nasob(cislo& a, unsigned long long x) {
    
    unsigned long long num = 0;
    for (int i = a.pocet_cifier - 1; i >= 0; i--) {
        num += a.cifry[i] * pow(10, i);
    }

    string num1 = to_string(num);
    string tempnum1 = num1;
    string num2 = to_string(x);
    string tempnum2 = num2;
    // Check condition if one string is negative
    if (num1[0] == '-' && num2[0] != '-') {
        num1 = num1.substr(1);
    }
    else if (num1[0] != '-' && num2[0] == '-') {
        num2 = num2.substr(1);
    }
    else if (num1[0] == '-' && num2[0] == '-') {
        num1 = num1.substr(1);
        num2 = num2.substr(1);
    }
    string s1 = num1;
    string s2 = num2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    vector<int> m(s1.length() + s2.length());
    // Go from right to left in num1
    for (int i = 0; i < s1.length(); i++) {
        // Go from right to left in num2
        for (int j = 0; j < s2.length(); j++) {
            m[i + j]
                = m[i + j] + (s1[i] - '0') * (s2[j] - '0');
        }
    }
    string product = "";
    // Multiply with current digit of first number
    // and add result to previously stored product
    // at current position.
    for (int i = 0; i < m.size(); i++) {
        int digit = m[i] % 10;
        int carry = m[i] / 10;
        if (i + 1 < m.size()) {
            m[i + 1] = m[i + 1] + carry;
        }
        product = to_string(digit) + product;
    }
    // ignore '0's from the right
    while (product.length() > 1 && product[0] == '0') {
        product = product.substr(1);
    }
    // Check condition if one string is negative
    if (tempnum1[0] == '-' && tempnum2[0] != '-') {
        product = "-" + product;
    }
    else if (tempnum1[0] != '-' && tempnum2[0] == '-') {
        product = "-" + product;
    }

    cout << product << endl;

    int digetsCount = product.length();

    a.pocet_cifier = digetsCount;

    /*string num = "";
    unsigned long long num2 = 0;
    for (int i = a.pocet_cifier - 1; i >= 0; i--) {
        int b = a.cifry[i] * x * pow(10, i);
        num += to_string(b);
        int digits = 0;
    }
    cout << num << endl;*/
    
    /*int digetsCount = 0;
    unsigned long long n = num;
    while (n != 0) {
        //if (digetsCount >= 54) break;
        n = n / 10;
        digetsCount++;
    }

    a.pocet_cifier = digetsCount;
    for (int i = 0; i < a.pocet_cifier; i++) {
        if(num!= 0){
        a.cifry[i] = num % 10;
        num /= 10;
        }
        else if(num2 != 0 && num == 0) {
            a.cifry[i] = num2 % 10;
            num2 /= 10;
        }
    }*/
}



void faktorial(cislo& a, int n) {
    /* TODO: Naprogramujte tuto funkciu.
       Odporucame pouzit funkcie vytvorCislo a nasob. */

    a.pocet_cifier = 1; // zmazte alebo zmente podla potreby
    a.cifry[0] = n;

    /*int num = 0;
    for (int i = a.pocet_cifier - 1; i >= 0; i--) {
        num += a.cifry[i] * pow(10, i);
    }
    num = a.cifry[0];*/

    for (int i = n-1; i >= 1; i--) n *= i;
    
    
    int digetsCount = 0;
    int num = n;
    while (num != 0) {
        num = num / 10;
        digetsCount++;
    }

    a.pocet_cifier = digetsCount;

    for (int i = 0; i < a.pocet_cifier; i++) {
        a.cifry[i] = n % 10;
        n /= 10;
    }

    
}



int main() {
    cislo a;
    nacitaj_cislo(a);
    unsigned long long  b;
    cin >> b;
    unsigned long long  n;
    cin >> n;

    cout << "a: ";
    vypis(a);
    cout << "  pocet cifier: " << a.pocet_cifier << endl;

    cout << "a*" << b << ": ";
    nasob(a, b);
    cout << "  pocet cifier: " << a.pocet_cifier << endl;


    cislo f;
    cout << n << "!: ";
    faktorial(f, n);
    vypis(f);
    cout << "  pocet cifier: " << f.pocet_cifier << endl;
}
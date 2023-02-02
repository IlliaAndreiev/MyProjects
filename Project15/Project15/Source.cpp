#include <iostream>
#include <cstring>
using namespace std;

void get(char t[]) {
    for (int i = 0; i < 100; i++) {
        cin >> noskipws >> t[i];
        if (t[i] == '\n') {
            t[i] = 0;
            break;
        }

    }
}

void check(char t[], string& t2) {
    for (int n = 0; n < 1000; n++)
        for (int i = 0; i < strlen(t); i++)
            if (int(t[i]) == n)
                t2 += t[i];
    cout << t2 << endl;
}

int main() {
    char a[100];
    char b[100];
    while(true){
    get(a);
    get(b);
    if (strlen(a) == 0 || strlen(b) == 0) break;

    string a2;
    string b2;

    check(a, a2);
    check(b, b2);

    if (a2 == b2) cout << "YES" << endl;
    else cout << "NO" << endl;
    }
}
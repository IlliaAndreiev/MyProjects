/*#include <iostream>
using namespace std;

int main() {
	const int N = 100;
	int m = 0, n = 0;
	while (m < 1 && n < 1) {
		cin >> m >> n;
	}
	bool arr[N][N];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '1') arr[i][j] = c;
            else arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && arr[i + 1][j] == 0) cout << "0";
			else if (arr[i][j] == 0 && arr[i + 1][j] == 1) cout << "1";
			else if (arr[i][j] == 1 && arr[i + 1][j] == 0) cout << "0";
			else if (arr[i][j] == 1 && arr[i + 1][j] == 1) cout << "1";
		}
    cout << endl;
}*/

#include <iostream>
#include <cassert>
using namespace std;

bool** create(int m, int n) {
    bool** arr;
    arr = new bool* [m];
    for (int i = 0; i < m; i++)
        arr[i] = new bool[n];
    return arr;
}

void check(bool** arr, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            arr[i][j] = (c == '1');
        }
}
void write(bool** arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j];
        cout << endl;
    }
}
int main(void) {
    int m, n;
    cin >> m >> n;
    bool** arr1 = create(m, n);
    check(arr1, m, n);
    bool** arr2 = create(m, n);
    check(arr2, m, n);
    bool** arr3 = create(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if ((arr1[i][j]) && (arr2[i][j])) arr3[i][j] = true;
            else if ((arr1[i][j] == 0) || (arr2[i][j] == 0)) arr3[i][j] = false;
        }
    write(arr3, m, n);
}
/*void deleting(bool** a, int m) {
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}*/
//deleting(arr, m);
    //deleting(arr2, m);
    //deleting(arr3, m);
/*#include <iostream>
#include <cassert>
using namespace std;

bool** vytvorMaticu(int m, int n) {
    bool** a;
    a = new bool* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new bool[n];
    }
    return a;
}
void zmazMaticu(bool** a, int m) {
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}
void nacitajMaticu(bool** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '1');
        }
    }
}
void vypisMaticu(bool** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
int main(void) {
    int m, n;
    cin >> m >> n;
    bool** a = vytvorMaticu(m, n);
    nacitajMaticu(a, m, n);
    bool** b = vytvorMaticu(m, n);
    nacitajMaticu(b, m, n);
    bool** c = vytvorMaticu(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((a[i][j]) && (b[i][j])) { c[i][j] = true; }
            else if ((a[i][j] == 0) || (b[i][j] == 0)) { c[i][j] = false; }
        }
    }
    vypisMaticu(c, m, n);
    zmazMaticu(a, m);
    zmazMaticu(b, m);
    zmazMaticu(c, m);
}
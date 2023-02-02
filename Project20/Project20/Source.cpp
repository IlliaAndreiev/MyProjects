#include <iostream>
using namespace std;

const int MAX = 100;
int N, M;
int num_min = MAX * 20;
int c_min[MAX]{};
bool isfound = false;

void weight(int* a, int* b, int* c, int num, int m, int n) {
	if (n == N) {
		if (m < M) {
			//cout << "Not found" << endl;
		}
		else {
			isfound = true;
			if (num < num_min) {
				num_min = num;
				for (int i = 0; i < N; i++)
					c_min[i] = c[i];
			}
			//cout << "Number of ties used: " << num << endl;
			//for (int i = 0; i < N; i++) cout << a[i] << ": " << c[i] << endl;
		}
		return;
	};
	weight(a, b, c, num, m, n + 1);//without n-th weight
	for (int k = 1; k <= 20; k++) {
		if ((m + a[n]) <= M && k <= b[n]) {
			m += a[n];
			num++;
			c[n]++;
			weight(a, b, c, num, m, n + 1);
		}
	}
	c[n] = 0;


}

int main() {
	cin >> N >> M;
	int a[MAX], b[MAX];
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
	}

	int m = 0, num = 0;
	int c[MAX]{};

	weight(a, b, c, num, m, 0);
	if (isfound)
	{
		cout << "Pocet pouzitych zavazi: " << num_min << endl;
		for (int i = 0; i < N; i++) cout << "Zavazie " << a[i] << ": " << c_min[i] << endl;
	}
	else
	{
		cout << "Hmotnost sa neda vytvorit" << endl;
	}

}
/*#include <iostream>
using namespace std;

const int MAX = 100;
int N, M;

int weight(int* a, int* b, int* c, int num, int n) {
	if (n == 0) return 0;
	int num1 = 0;
	int c1[MAX];
	int h = weight(a, b, c1, num1, n-1);
	int m = 0;
	for (int i = 0; i < MAX; i++) c[i] = 0;
	for (int k = 1; k <= 20; k++) {
		for (int i = 0; i < n; i++) {
			if ((m + a[i]) <= M && k <= b[i]) {
				m += a[i];
				num++;
				c[i]++;
			}
		}
	}
	if (num < num1 && m == M && h == M) return m;
	else if (m == M && h == M) {
		for (int i = 0; i < MAX; i++) c[i] = c1[i];
		num = num1;
		return h;
	}
}

int main() {	
	cin >> N >> M;
	int a[MAX], b[MAX];
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
	}

	int m = 0, num = 0;
	int c[MAX] = {0};

	m = weight(a, b, c, num, N);

	/*for (int k = 1; k <= 20; k++) {
		for (int i = 0; i < N; i++) {
			if ((m + a[i]) <= M && k <= b[i]) {
				m += a[i];
				num++;
				c[i]++;
			}
		}
	}

	if (m != M) {
		m = 0;
		num = 0;
		for (int i = 0; i < MAX; i++) c[i] = 0;
		for (int k = 1; k <= 20; k++) {
			for (int i = N-1; i >= 0; i--) {
				if ((m + a[i]) <= M && k <= b[i]) {
					m += a[i];
					num++;
					c[i]++;
				}
			}
		}
	}*/

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < b[i]; j++) { 
			if ((m + a[i]) <= M) {
				m += a[i];
				num++;
				c[i]++;
			}
		}
	}
	if (m != M){
		m = 0;
		num = 0;
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < b[i]; j++) {
			if ((m + a[i]) <= M) {
				m += a[i];
				num++;
				c[i][1]++;
			}
		}
	}
}
	//if(m != M) cout << "Hmotnost sa neda vytvorit" << endl;
	//else {
		cout << "Number of ties used: " << num << endl;
		for (int i = 0; i < N; i++) cout << a[i] << ": " << c[i] << endl;
	//}
}*/
#include <iostream>
using namespace std;

class AGr {
private:
	int n;
	int m;
public:

	AGr(int n, int m) {
		this->n = n;
		this->m = m;
	}
	void addM() {
		this->m = m + 1;
	}

	void mergeGrafs(AGr first, AGr second) {
		int* g = new int[first.m + second.m];
		for (int i = 0; i < first.m + second.m; i++) {
			**g[i] = new int[first.m + second.m];
		}
	}

	friend int processGraf(AGr a, int m);
};

class MGr {
private:
	AGr* p;
public:
	MGr(AGr* a) {
		this->p = a;
	}
};

int processGraf(AGr a, int m) {
	int* g = new int [m];
	for (int i = 0; i < m; i++) {
		**g[i] = new int[m];
	}
	MGr p(&a);
	return g[0];
}

int main() {
	int n = 0;
	int m = 0;
	AGr a(n, m);
	return 0;
}
#include <iostream>
#include "Functions.h"
#include "Matrix.h"
using namespace std;

void funct121(Matrix& a) {
	Matrix t(a.getColumns(), a.getRows());
	for (int k = 0; k < a.getRows(); k++) {
		for (int m = 0; m < a.getColumns(); m++) {
			t(m, (a.getRows() - k - 1)) = a(k, m);
		}
	}
	a.setRows(t.getRows());
	a.setColumns(t.getColumns());
	for (int k = 0; k < a.getRows(); k++) {
		for (int m = 0; m < a.getColumns(); m++) {
			a(k, m) = t(k, m);
		}
	}
}

int columnDistants(Matrix& a, int j, int k) {
	int i = 0;
	int s = 0;
	for (i; i < a.getRows(); i++) {
		s += (a(i, k) - a(i, j))* (a(i, k) - a(i, j));
	}
	return s;
}

void funct84(Matrix& a) {
	int distants;
		for (int j = 0; j < a.getColumns(); j++) {
			for (int k = j+1; k < a.getColumns(); k++) {
				distants = columnDistants(a, j, k);
				if (distants == 0) cout<<j+1<<" "<<k+1<< endl;
			}
		}
}
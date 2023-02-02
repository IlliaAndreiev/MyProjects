#include <iostream>
using namespace std;

void expand(int* arr, int lim, int x) {
	int* new_arr = new int[lim * 2];
	for (int i = 0; i < lim - 1; i++) {
		new_arr[i] = arr[i];
		cout << new_arr[i] << endl;
	}

	for (int i = lim - 1; i < lim * 2; i++) {
		new_arr[i] = x;
		x++;
		cout << new_arr[i] << endl;
	}
}

void add(int* arr, int lim) {
	int x = 1;
	for (int size = 0; size < lim; size++) {
		if (size + 1 == lim) {
			expand(arr, lim, x);
		}
		arr[size] = x;
		x++;
	}
}
int main() {
	const int lim = 1000;
	int arr[lim];
	add(arr, lim);
	return 0;
}
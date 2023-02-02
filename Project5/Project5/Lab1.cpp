#include <iostream>
#include <algorithm>

using namespace std;

void main() {

	int n;
	double m;
	int i;
	int j;


	cout << "Enter N and M: " << endl;
	cin >> n;
	cin >> m;

	if (0 <= n && n <= 1000 && -10e9 <= m && m <= 10e9) {
		cout << "N and M: " << n << " " << m << endl;
	}
	else {
		cout << "ERROR: INVALID NUMBER" << endl;
		return;
	}

	double* a = new double[n];

	cout << "Enter numbers:" << endl;

	for (i = 0; i < n; i++) {
		cin >> a[i];



		if (-10e9 <= a[i] <= 10e9) {

			cout << a[i] << " ";

		}
	}
	cout << endl;

	int temp;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			//cout << a[i] << " ";
		
		}
       // cout << endl;
		

		int lo = 0;
		int hi = n - 1;
		int med;
		bool is_found = false;
		while (lo <= hi) {
			med = lo + (hi - lo) / 2;
			if (a[med] == m) {
				is_found = true;
				break;
			}

			if (a[med] < m)
				lo = med + 1;
			else
				hi = med - 1;
		}
		if (is_found)
			cout << a[med] << endl;
		else {
			cout << "inf";
		}
		return;

	}

}
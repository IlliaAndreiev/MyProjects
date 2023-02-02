#include <iostream>
using namespace std;

bool is_cross(double a, double b, double c) {
	if (a == 0 || b == 0 || c == 0) {
		return false;
	}
	if (!((-b > 0 && a > 0) || (b > 0 && -a > 0))) {
		return false;
	}

	if (-c / b > 0) {
		return true;
	}
	return false;
}
void main() {
	cout << boolalpha;
	cout << "f(1, -1, 1) = " << is_cross(1, -1, 1) << endl;
	cout << "f(1, -1, -1) = " << is_cross(1, -1, -1) << endl;
	cout << "f(1, 1, -1) = " << is_cross(1, 1, -1) << endl;
	cout << "f(1, 1, 1) = " << is_cross(-1, -1, -1) << endl;

	char c = '0' + 33 % 17 * 16 + (1 / 2 == 3 / 4);
	cout << "c = '" << c << "'" << endl;
}
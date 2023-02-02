#include <iostream>
using namespace std;
class rational {
public:
	int numirator;
	int denomirator;
	rational();
	rational(int num, int denom);
	friend istream& operator >> (istream& i, rational& r);
	friend ostream& operator << (ostream& o, const rational& r);
	rational& operator = (const rational& r);
	friend rational operator + (rational& r1, rational& r2);
	friend rational operator - (rational& r1, rational& r2);
	friend rational operator * (rational& r1, rational& r2);
	friend rational operator / (rational& r1, rational& r2);
	friend int euclid(int x, int y);
	void reduce();
};

rational::rational() {
	this -> numirator = 0;
	this -> denomirator = 1;
};
rational::rational(int num, int denom) {
	this -> numirator = num;
	this -> denomirator = denom;
};
rational& rational::operator=(const rational& r) {
	this->numirator = r.numirator;
	this->denomirator = r.denomirator;
	return *this;
};
istream& operator >> (istream& i, rational& r) {
	i >> r.numirator;
	i >> r.denomirator;
	return i;
};
ostream& operator << (ostream& o, const rational& r) {
	o << r.numirator;
	o << '/';
	o << r.denomirator;
	return o;
};
rational operator + (rational& r1, rational& r2) {
	rational r;
	r.numirator = r1.numirator * r2.denomirator + r2.numirator * r1.denomirator;
	r.denomirator = r1.denomirator * r2.denomirator;

	return r;
};
rational operator - (rational& r1, rational& r2) {
	rational r;
	r.numirator = r1.numirator * r2.denomirator - r2.numirator * r1.denomirator;
	r.denomirator = r1.denomirator * r2.denomirator;

	return r;
};
rational operator * (rational& r1, rational& r2) {
	rational r;
	r.numirator = r1.numirator * r2.numirator;
	r.denomirator = r1.denomirator * r2.denomirator;

	return r;
};
rational operator / (rational& r1, rational& r2) {
	rational r;
	r.numirator = r1.numirator * r2.denomirator;
	r.denomirator = r1.denomirator * r2.numirator;

	return r;
};
int euclid(int x, int y) {
	if (x == 0) {
		return y;
	}
	else if (y == 0) {
		return x;
	} else if (x < y) {
		return euclid(x, y%x);
	} else if (y < x) {
		return euclid(x%y, y);
	}
}
void rational::reduce() {
	int n = euclid(this -> numirator, this -> denomirator);
	this -> numirator /= n;
	this -> denomirator /= n;
};
int main() {
	rational r1;
	rational r2;
	cin >> r1 >> r2;
	rational r = r1 + r2;
	cout << r << endl;
}
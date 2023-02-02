#include <iostream>
#include "Matrix.h"
#include "Functions.h"
#include <fstream>
using namespace std;

void info() {
	cout << "K-16 Андрєв Ілля Варіант Тип1: 84, Тип2: 121" << endl;
	cout << "Розв’язати задачу за допомогою класу для обробки матриць цілих. Матриця зображується динамічною структурою даних із вказівниками." << endl;
	cout << "84. Визначити всі пари номерів стовпчиків, відстань між якими дорівнює 0." << endl;
	cout << "121. Повернути матрицю на 90 градусів за годинниковою стрілкою." << endl;

}
int main() {
	info();
	string path;
	cout << "Enter full path to file:" << endl;
	cin >> path;
	if (path == "") path = "in.txt";
	ifstream f(path.c_str());
	if (path == "in.txt") path = "out.txt";
	ofstream f(path.c_str());
	Matrix m;
	f >> m;
	cout << m << endl;
	cout << endl;
	funct84(m);
	cout << endl;
	funct121(m);
	cout << m << endl;
	
	return 0;
}
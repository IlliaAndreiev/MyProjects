#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix() {
	m = new int* [300];
	for (int i = 0; i < 300; i++) {
		m[i] = new int[300];
	}
	this->rows = 0;
	this->columns = 0;
}

/*Matrix::Matrix(const Matrix& source)
    : Matrix{ **source.m }
{

    // Copying the data by making
    // deep copy
    cout << "Copy Constructor is called -"
        << "Deep copy for "
        << **source.m
        << endl;
}*/

// Move Constructor
Matrix::Matrix(Matrix&& source) {
    cout << "Move Constructor for "
        << *source.m << endl;
	this->m = source.m;
	this->rows = source.rows;
	this->columns = source.columns;
    source.m = nullptr;
}

Matrix::Matrix(int rows, int columns) {
	m = new int*[300];
	for (int i = 0; i < 300; i++) {
		m[i] = new int[300];
	}
	this->rows = rows;
	this->columns = columns;
}
Matrix::~Matrix() {
		if (m != nullptr) { 
			for (int i = 0; i < columns; i++) {
				delete[] m[i];
			}
			 delete[] m;
		}
}

Matrix& Matrix::operator=(Matrix&& other){
	if (this != &other){
		for (int i = 0; i < columns; i++) {
			delete[] m[i];
		}
		delete[] m;

		m = other.m;
		columns = other.columns;
		rows = other.rows;

		other.m = nullptr;
		other.columns = 0;
		other.rows = 0;
	}
	return *this;
}

int& Matrix::operator()(unsigned int i, unsigned int j)
{
	return m[i][j];
}

const int& Matrix::operator()(unsigned int i, unsigned int j)const
{
	return m[i][j];
}

ifstream& operator>>(ifstream& i, Matrix& a) {
	int t;
	i >> t;
	a.setRows(t);
	i >> t;
	a.setColumns(t);
	for (int k = 0; k < a.getRows(); k++) {
		for (int m = 0; m < a.getColumns(); m++) {
			i >> t;
			a(k,m) = t;
		}
	}
	return i;
}

ofstream& operator<<(ofstream& i, const Matrix& a) {
	i << a.getRows() << " " << a.getColumns() << endl;
	for (int k = 0; k < a.getRows(); k++) {
		for (int m = 0; m < a.getColumns(); m++) {
			i << a(k, m) << " ";
		}
		i << endl;
	}
	return i;
}

ostream& operator<<(ostream & i, const Matrix & a) {
	i << a.getRows() << " " << a.getColumns() << endl;
	for (int k = 0; k < a.getRows(); k++) {
		for (int m = 0; m < a.getColumns(); m++) {
			i << a(k, m) << " ";
		}
		i << endl;
		}
	return i;
}
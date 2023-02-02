#pragma once
#include<iostream>
#include <fstream>
using namespace std;
class Matrix {
private:
	int rows, columns;
	int** m;
public:
	Matrix();
	Matrix(int rows, int columns);
	//Matrix(const Matrix& source);
	Matrix(Matrix&& source);
	~Matrix();
	Matrix& operator=(Matrix&& other);
	int& operator()(unsigned int i, unsigned int j);
	const int& operator()(unsigned int i, unsigned int j)const;
	friend ifstream& operator>>(ifstream& i, Matrix& a);

	friend ofstream& operator<<(ofstream& i, const Matrix& a);

	friend ostream& operator<<(ostream& i, const Matrix& a);

	void setRows(int rows) {
		this->rows = rows;
	}
	void setColumns(int columns) {
		this->columns = columns;
	}
	int getRows()const {
		return rows;
	}
	int getColumns()const {
		return columns;
	}
};
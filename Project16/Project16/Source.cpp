#include <iostream>
#include <cmath>
#include "SVGdraw.h"
using namespace std;

int main() {
	
	int d = 0, p = 0;
	while(d < 1 || d > 100 || p < 1 || p > 10)cin >> d >> p;

	double xd[100];
	double yd[100];
	for (int i = 0; i < d; i++) cin >> xd[i] >> yd[i];

	double xp[10];
	double yp[10];
	for (int i = 0; i < p; i++) cin >> xp[i] >> yp[i];

	int drawingX, drawingY, R;
	cin >> drawingX >> drawingY >> R;

	double distance[10][100];
	for (int i = 0; i < p; i++) for (int n = 0; n < d; n++) {
		distance[i][n] = sqrt(pow(xp[i] - xd[n], 2) + pow(yp[i] - yd[n], 2));
	}

	double shortest[100];
	for (int i = 0; i < d; i++) shortest[i] = 999999;

	int indexes[100];
	
	for (int i = 0; i < d; i++) for (int n = 0; n < p; n++) {
		if (shortest[i] > distance[n][i]) {
			shortest[i] = distance[n][i];
			indexes[i] = n;
		}
	}

	int bnp[10] = {};
	for (int n = 0; n < p; n++) for (int i = 0; i < d; i++) {
		if(indexes[i] == n) bnp[n]++;
	}

	for (int i = 0; i < d; i++) cout << "dom " << i << " posta " << indexes[i] << endl;
	for (int i = 0; i < p; i++) cout << "posta " << i << " pocet domov " << bnp[i] << endl;


	
	SVGdraw drawing(drawingX, drawingY, "posty.svg");

	const int MAXP = 10;
	const char* colors[MAXP] = { "red", "green", "blue", "white", "black", "gray", "yellow", "brown", "orange", "purple" };

	for (int i = 0; i < d; i++) { 
		drawing.setFillColor(colors[indexes[i]]);
		drawing.drawLine(xd[i], yd[i], xp[indexes[i]], yp[indexes[i]]); 
	}

	for (int i = 0; i < d; i++) { 
		drawing.setFillColor(colors[indexes[i]]);
		drawing.drawEllipse(xd[i], yd[i], R / 2, R / 2);
	}

	for (int i = 0; i < p; i++) { 
		drawing.setFillColor(colors[i]);
			drawing.drawRectangle(xp[i] - R / 2, yp[i] - R / 2, R, R); 
	}

	


	drawing.finish();
}
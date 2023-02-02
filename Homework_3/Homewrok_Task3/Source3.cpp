#include <stdio.h>

void vynasob(int& a, int& b, int& s) {

	printf("Zadaj 2. cislo: \n");

	scanf_s("%d", &b);
	s = a * b;
}

void result(int& s) {
 printf("Vysledok je: %d\n", s);
}

int main() {
	int a, b;

	printf("Zadaj 1. cislo: \n");

	scanf_s("%d", &a);

	int s;

	vynasob(a, b, s);
	
	result(s);
	
}
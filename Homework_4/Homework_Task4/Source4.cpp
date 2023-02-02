#include <stdio.h>

void transition(int& a, int& b, int& temp){
  temp = a;
  a = b;
  b = temp;
}

int main() {
	int a, b;
    int temp;
	printf("Zadaj hodnotu premennej a: \n");

	scanf_s("%d", &a);

	printf("Zadaj hodnotu premennej b: \n");

	scanf_s("%d", &b);

	transition(a, b, temp);

	printf("Hodnota a: %d ", a);
	printf("b: %d\n", b); 
}
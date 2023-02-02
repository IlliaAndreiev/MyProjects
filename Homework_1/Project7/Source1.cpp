#include <stdio.h>
#include<iostream>
void sucet(int*  num9999999, int& petryaaaa, int& september) {
	september = *num9999999 * *(num9999999+1);
}

int main() {
	int* pointer;
	int num1 = 7, num2;
	int *object = (int*)malloc(sizeof(int)*5);
	*(object) = 19;
	object[1] = 99;
	printf("Zadaj dve cisla oddelene medzerou: \n");
	 
	//scanf_s("%d", &num1);
	//scanf_s("%d", &num2);
	pointer = &num1;
	int s;
	//std::cout<<object[3];
	sucet(object, num2, s);

	printf("Sucet cisel je: %d\n", s);
}

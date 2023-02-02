#include <stdio.h>

void create_array(int &num, int* Num) {
	if (num % 2 == 0){
		for (int i = 0; i < 5; ++i) {
			*(Num + i) = i + 32;
		};
	}
	else
		for (int i = 0; i < 5; ++i) {
			*(Num + i) = i + 73;
		};
}
int main() {
	int num;

	printf("Zadaj cislo: ");

	scanf_s("%d", &num);

	int Num [5];
	create_array(num, Num);
	for(int j = 0; j < 5; ++j){
	printf("Array: %d\n", *(Num+j));
	}
}
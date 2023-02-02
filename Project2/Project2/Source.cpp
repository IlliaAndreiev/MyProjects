#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	/*int width = 15, height = 25;
	int rows, column;
	for (rows = 0; rows < height; ++rows) {
		for (column = 0; column < width; ++column) {
			if ( column <= width/2 + rows && column >= width / 2 - rows) {
				if (rows == 9) {
					printf("0");
				}
				else if (rows > 9){
					printf("%c", 'A' + rows - 10);
				}
				else{
				printf("%d",rows+1);
				}
			}
			else {
				printf("*");
			}

		}
		printf( "\n");

	}*/
	/*bool switcher = false;
	char buff;
	FILE* file;
	int num1, num2;
	file = fopen("C:\\Users\\iandr\\source\\repos\\Project2\\Project2\\input.txt","r");
	while (( fscanf(file, "%d %d", &num1, &num2)) != EOF)
	{
	
		
		printf("%d %d\n", num1, num2);
		

	}*/
	
	int num = 5;
	int i;
	int num2 = 1;
	for (i = num; i> 0; i--) {
		num2 = num2 * i;
	}
	printf("%d", num2);
}
#include <iostream>
using namespace std;

int main() {
	int rawNum;
	cin >> rawNum;
	int baseNum = rawNum / 10;
	int powNum = rawNum % 10;
	int resultNum = baseNum;
	int firstNum = baseNum;
	for (int i = 1; i < powNum; i++) {
		resultNum = firstNum * resultNum;
	}
	cout << resultNum;
	return 0;
}
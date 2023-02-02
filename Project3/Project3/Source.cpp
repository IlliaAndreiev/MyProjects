#include <iostream>
using namespace std;

int a = 1;
int f(int x)
{
	return x;
}

namespace A
{
	int a = 10;

	int f(int x)
	{
		return x * x;
	}
}

namespace B
{
	int a = 20;
	int f(int x)
	{
		return x * x * x;
	}

	namespace C
	{
		int a = 30;
		int f(int x)
		{
			return x * x * x * x;
		}
	}
}

/*namespace B::C
{
	int b = a + 50;
}

int* create_array(int arr[], int* ptr_arr)
{
	int local_arr = { 1, 2, 3 };

	arr = local_arr;
	ptr 
}
	*/
	int main()
	{
		cout << "global a = " << a << endl;
		cout << "global A::a = " << A::a << endl;
		cout << "global B::a  = " << B::a << endl;
		cout << "global B::C::a = " << B::C::a << endl << endl;

		cout << "func f(2) = " << f(2) << endl;
		cout << "func A::f(2) = " << A::f(2) << endl;
		cout << "func B::f(2)  = " << B::f(2) << endl;
		cout << "func B::C::f(2) = " << B::C::f(2) << endl << endl;

		int a = 3;
		cout << "local a = " << a << endl;
		cout << "global A::a = " << A::a << endl;
		cout << "global B::a = " << B::a << endl;
		cout << "global B::C::a = " << B::C::a << endl << endl;
		{
			int a = 5;
			cout << "local block a = " << a << endl;
			cout << "global ::a = " << ::a << endl;
			cout << "global A::a = " << A::a << endl;
			cout << "global B::a = " << B::a << endl;
			cout << "global B::C::a = " << B::C::a << endl << endl;
		}

		int value = 77;
		cout << "value = " << value << endl;
		cout << "&value (memory adress) = " << &value << endl;
		int &new_value = value;
		cout << "new_value = " << new_value << endl;
		cout << "&new_value (memory adress) = " << &new_value << endl;
		new_value = 66;
		cout << "value = " << value << endl;
		cout << "new_value = " << new_value << endl;

		int* ptr = &value;
		cout << "pointer ptr = &value = " << ptr << endl;
		cout << "*ptr = value = " << *ptr << endl;

		/*char* str = "Hello char pointer!";
		cout << "char* = " << str << endl;
		char buff[] = "Hello char[]!";
		cout << "char[] = " << buff << endl;
		char *str2 = buff;
		cout << "char* = " << str2 << endl;

		int arr[] = { 1, 2, 3 };
		int arr_ptr = new int[3] {1, 2, 3};*/

		return 0;
	}
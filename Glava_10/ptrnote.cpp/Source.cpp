#include <iostream>
using namespace std;

int main()

{
	int intarray[5] = { 31, 54, 77, 52, 93 };  //объ€вление массива

	for (int j = 0; j < 5; j++)			//вывод значени€ элементов массива
		cout << *(intarray + j) << endl;		//с помощью указател€ *

	return 0;
}
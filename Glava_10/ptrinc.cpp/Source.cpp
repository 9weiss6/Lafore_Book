#include <iostream>
using namespace std;

int main()
{
	int intarray[5] = { 31, 41, 51, 61, 71 };

	int* ptrint;		//указатель на int
	ptrint = intarray;		//указывает на наш массив
	
	for (int j = 0; j < 5; j++)
		cout << *(ptrint++) << endl;		//только там можно использовать инкремент, 
											//т.к. переменная ptrint не является константой 
		return 0;
}
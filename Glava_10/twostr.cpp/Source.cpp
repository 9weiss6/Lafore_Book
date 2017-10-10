//описание строк через массивы и через указатели
#include <iostream>
using namespace std;

int main()
{
	char str1[] = "This is string massive";
	char* str2 = "This is string pointer";

	cout << str1 << endl;
	cout << str2 << endl;

	//str1++		- так делать нельзя

	for (int j = 0; j < 5; j++)
	{
	str2++;
	cout << str2 << endl;
	}

	return 0;

}
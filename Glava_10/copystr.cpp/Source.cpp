//функция копирующая одну строку в другую с использованием указателей 

#include <iostream>
using namespace std;

int main()

{
	void copystr(char*, const char* ); //прототип функции 
	char* str1 = "Don't panic, be happy!";
	char str2[80];

	copystr(str1, str2);
	cout << str2 << endl;

	return 0;
}

void copystr(char* dest, const char*  src )
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}
//Показ строки определённой через указатель

#include <iostream>
using namespace std;

int main()
{
	void dispstr(char*);			//адрес массива использован как аргумент функции
	char str[] = "It is arguments function";

	dispstr(str);

	return 0;
}

/////////////////////////////////////////////

void dispstr(char* ps)
{
	while (*ps)			//Означает while (*ps = true) конец строки интерпритируется как false = '\0'
		cout << *ps++;
	cout << endl;
}
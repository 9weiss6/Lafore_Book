//Знакомство с новыми операторами new и delete

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	char* str = "A bad head does not give rest to the feet.";
	int len = strlen(str);		//вычисляет длину строки str

	char* ptr;					//определяет строковую переменную
	ptr = new char[len + 1];	//выделяет память для строковой перемееной 

	strcpy(ptr, str);			//копирует строку str в ptr

	cout << "ptr = " << ptr << endl;		//выводит строку 

	delete[] ptr;				//освобождает выделенную память 

	return 0;
}
//Использование оператора new для выделения памяти под строку 

#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	char* str;
public:
	String(char* s)		//Создаём конструктор с 1 параметром с указателем на строковую переменную
	{
		int leigth = strlen(s);			//Определяем переменную и присваиваем ей значение "длину строки"
		str = new char[leigth + 1];		//Выделяем необходимую память размером с длину строки s  + завершающий символ '/0'(конец строки)
		strcpy(str, s);					//Копируем строку из s в str
	}
	~String()							//Деструктор
	{
		cout << "Delete this string.";
		delete[] str;					//Освобождает память от str
	}

	void display()
	{
		cout << str << endl;
	}

};

int main()
{
	String s1 = "The quieter you go, the further you'll get.";
	cout << "s1 = ";
	s1.display();

	return 0;
}
//сортировка объектов через массив указателей на них

#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
	string name;
public:
	void setName()
	{
		cout << "Enter name: "; cin >> name;
	}
	void printName()
	{
		cout << endl << name;
	}
	string getName()
	{
		return name;
	}
};

int main()
{
	void bsort(person**, int);		//прототип функции 
	person* persPtr[100];			//массив указателей на person
	int n = 0;						//количество элементов в массиве
	char choise;					//переменная для ввода символа
	do
	{
		persPtr[n] = new person;	//создает новый объект
		persPtr[n]->setName();		//вводим имя
		n++;
		cout << "Continue? (y/n) ";	//запрос продолжать или нет
		cin >> choise;
	} while (choise == 'y');

	cout << "\nNo sort list: ";		//показывает неотсортированный список 
	for (int j = 0; j < n; j++)
		persPtr[j]->printName();

	bsort(persPtr, n);		//сортирует указатели

	cout << "\nSort list: ";		//показывает отсортированный список
	for (int j = 0; j < n; j++)
		persPtr[j]->printName();
	cout << endl;

	return 0;
}

void bsort(person** pp, int n)
{
	void order(person**, person**);		//прототип функции
	int j, k;

	for (j = 0; j < n - 1; j++)			//внешний цикл
		for (k = j + 1; k < n; k++)		//внутренний цикл
			order(pp + j, pp + k);		//сортирует два элемента
}

void order(person** pp1, person** pp2)
{
	if ((*pp1)->getName() > (*pp2)->getName())		//если первая строка больше второй 
	{
		person* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
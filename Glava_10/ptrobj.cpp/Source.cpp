//Массив указателей на объекты

#include <iostream>
using namespace std;

class person
{
private:
	char name[40];
public:
	void setName()
	{
		cout << "Enter name: ";
		cin >> name;
	}
	void printName()
	{
		cout << "\nName: " << name;
	}
};

int main()
{
	person* persPtr[100];			//массив указателей 
	int n = 0;						//количество элементов в массиве
	char choise;

	do {
		persPtr[n] = new person;	//создаем новый объект 
		persPtr[n]->setName();		//вводим имя
		n++;
		cout << "Continue? (y/n): ";	//запрос на продолжение
		cin >> choise;
	} while (choise == 'y');

		for (int j = 0; j < n; j++)
		{
			cout << "\nInformation for number " << j + 1;
			persPtr[j]->printName();		//вывод информации
		}
		cout << endl;

		return 0;
}
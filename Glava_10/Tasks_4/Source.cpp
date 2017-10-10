//работа со списками 

#include <iostream>
using namespace std;

struct link		//один элемент связного списка 
{
	int data;
	link* next;		//указатель на следующую структуру
};

class linklist
{
private:
	link* first;		//указатель на первую структуру 
public:
	linklist()			//конструктор без агрументов
	{
		first = NULL;
	}

	//---Прототипы---//
	~linklist();
	void additem(int d); //добавление переменной в структуру 
	void display();
		
};

void linklist::additem(int d) //добавление переменной в одну структуру
{
	link* newlink = new link;	//выделяет память под новую структуру 
	newlink->data = d;			//определяет значение переменной (посредством доступа к элементу структуры)
	newlink->next = first;		//значение указателя заменяется значением first (посредством доступа к элементу структуры)
	first = newlink;			//first теперь указывает на новый элемент
}

void linklist::display()
{
	link* current = first;		//начинаем с первого элемента списка
	while (current != NULL)		//пока current != NULL (пока есть данные)
	{
		cout << current->data << endl; //выводим данные
		current = current->next;	//сдвигаем указатель на следующий элемент
	}
}

linklist::~linklist()			//деструктор
{
	cout << "\nDeleted! ";		//выводит на экран данные переменной
	link* current = first;		//установить указатель на первый элемент
	
	while (current != NULL)		//пока current != NULL (пока есть данные)
	{
		link* t = current;				//сохраняет указатель на данный элемент
		
		current = current->next;		//получает ссылку на следующую ссылку
		delete t;						//удаляет эту ссылку
		
	}
	
}

int main()
{
	linklist list;  //создаём переменную-список 

	list.additem(25);		//задаём значение списку 
	list.additem(36);
	list.additem(49);
	list.additem(64);

	list.display();		//показываем список

	
	
	return 0;
}

/*
---
Недостаток списков заключается в том, что для поиска определенного элемента
необходимо пройти сквозь весь список, т.к. в том же массива достаточно знать индекс массива
и получить мгновенный доступ.
Но в отличии от массивов, в списках устранена возможная потеря данных
---
*/
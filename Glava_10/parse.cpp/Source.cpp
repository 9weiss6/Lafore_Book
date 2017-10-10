//Программа для разбора ввода арифметических выражений

#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 80;		//максимальная длина выражения
const int MAX = 40;		//длина массива данных

///////////////////////////////////////////////////////////////////////////////////

class Stack
{
private:
	char st[MAX];		//массив данных
	int top;			//количество сохранённых данных
public:
	Stack()				//конструктор 
	{
		top = 0;
	}

	void push(char var) //поместить в стек 
	{
		st[++top] = var;
	}
	char pop()			//взять из стека
	{	
		return st[top--];
	}

	int gettop()		//узнать количество элементов
	{
		return top;
	}
};

///////////////////////////////////////////////////////////////////////////////////

class express
{
private:
	Stack s;
	char* pStr;
	int len;
public:
	express(char* ptr)		//конструктор
	{
		pStr = ptr;			//запоминаем указатель на длину
		len = strlen(pStr);	//устанавлваем длину
	}
	void parse();		//прототип функции разбора выражения
	int solve();			//прототип функции получения результата
};

void express::parse()
{
	char ch;			//символ из строки
	char lastval;		//последнее значение
	char lasttop;		//последний оператор

	for (int j = 0; j < len; j++)	//для всех символов в строке
	{
		ch = pStr[j];				//получаем символ

		if (ch >= '0' && ch <= '9')		//если это цифра
			s.push(ch - '0');			//то сохраняем её значение
		else
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if (s.gettop() == 1)
					s.push(ch);
				else
				{
					lastval = s.pop();			//получаем предыдущее число 
					lasttop = s.pop();			//получаем предыдущий оператор
					//если это * или /, а предыдущий был + или -, то
					if ((ch == '*' || ch == '/') && (lasttop == '+' || lasttop == '-'))
					{
						s.push(lasttop);		//отменяем последние два взятия из стека
						s.push(lastval);
					}
					else
					{
						//помещаем в стек результат операции
						switch (lasttop)
						{
						case '+': s.push(s.pop() + lastval); break;
						case '-': s.push(s.pop() - lastval); break;
						case '*': s.push(s.pop() * lastval); break;
						case '/': s.push(s.pop() / lastval); break;
						default: cout << "\nUnknown Operator"; exit(1);
						}
					}
					s.push(ch);					//помещаем в стек текущий оператор
				}
			}
			else
			{
				cout << "\nUnknown Symbol"; exit(1);
			}
	}
}

///////////////////////////////////////////////////////////////////////////////////

int express::solve()
{
	char lastval;			//предыдущее значение

	while (s.gettop() > 1)
	{
		lastval = s.pop();		//получаем предыдущее значение 
		switch (s.pop())		//получаем предыдущий оператор
		{
		case '+': s.push(s.pop() + lastval); break;
		case '-': s.push(s.pop() - lastval); break;
		case '*': s.push(s.pop() * lastval); break;
		case '/': s.push(s.pop() / lastval); break;
		default: cout << "\nUnknown Operator"; exit(1);
		}
	}
	return int(s.pop());			//последний оператор в стеке, это результат
}

///////////////////////////////////////////////////////////////////////////////////

int main()
{
	char answer;					//'д' или 'н'
	char string[LEN];				//строка для разбора 

	cout << "\nEnter arifmetic string: (view - 2+3*4/3-2): ";

	do
	{
		cout << "\n->";
		cin >> string;								//вводим строку
		express* eptr = new express(string);		//создаем объект для разбора
		eptr->parse();								//разбираем
		cout << "\nResult: " << eptr->solve();		//решаем
		delete eptr;								//освобождаем память удаляя объект
		cout << "\nContinue? (y/n): "; cin >> answer;
	} while (answer == 'y');

	return 0;
}

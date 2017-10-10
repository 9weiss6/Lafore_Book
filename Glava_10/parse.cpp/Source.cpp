//��������� ��� ������� ����� �������������� ���������

#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 80;		//������������ ����� ���������
const int MAX = 40;		//����� ������� ������

///////////////////////////////////////////////////////////////////////////////////

class Stack
{
private:
	char st[MAX];		//������ ������
	int top;			//���������� ���������� ������
public:
	Stack()				//����������� 
	{
		top = 0;
	}

	void push(char var) //��������� � ���� 
	{
		st[++top] = var;
	}
	char pop()			//����� �� �����
	{	
		return st[top--];
	}

	int gettop()		//������ ���������� ���������
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
	express(char* ptr)		//�����������
	{
		pStr = ptr;			//���������� ��������� �� �����
		len = strlen(pStr);	//������������ �����
	}
	void parse();		//�������� ������� ������� ���������
	int solve();			//�������� ������� ��������� ����������
};

void express::parse()
{
	char ch;			//������ �� ������
	char lastval;		//��������� ��������
	char lasttop;		//��������� ��������

	for (int j = 0; j < len; j++)	//��� ���� �������� � ������
	{
		ch = pStr[j];				//�������� ������

		if (ch >= '0' && ch <= '9')		//���� ��� �����
			s.push(ch - '0');			//�� ��������� � ��������
		else
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if (s.gettop() == 1)
					s.push(ch);
				else
				{
					lastval = s.pop();			//�������� ���������� ����� 
					lasttop = s.pop();			//�������� ���������� ��������
					//���� ��� * ��� /, � ���������� ��� + ��� -, ��
					if ((ch == '*' || ch == '/') && (lasttop == '+' || lasttop == '-'))
					{
						s.push(lasttop);		//�������� ��������� ��� ������ �� �����
						s.push(lastval);
					}
					else
					{
						//�������� � ���� ��������� ��������
						switch (lasttop)
						{
						case '+': s.push(s.pop() + lastval); break;
						case '-': s.push(s.pop() - lastval); break;
						case '*': s.push(s.pop() * lastval); break;
						case '/': s.push(s.pop() / lastval); break;
						default: cout << "\nUnknown Operator"; exit(1);
						}
					}
					s.push(ch);					//�������� � ���� ������� ��������
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
	char lastval;			//���������� ��������

	while (s.gettop() > 1)
	{
		lastval = s.pop();		//�������� ���������� �������� 
		switch (s.pop())		//�������� ���������� ��������
		{
		case '+': s.push(s.pop() + lastval); break;
		case '-': s.push(s.pop() - lastval); break;
		case '*': s.push(s.pop() * lastval); break;
		case '/': s.push(s.pop() / lastval); break;
		default: cout << "\nUnknown Operator"; exit(1);
		}
	}
	return int(s.pop());			//��������� �������� � �����, ��� ���������
}

///////////////////////////////////////////////////////////////////////////////////

int main()
{
	char answer;					//'�' ��� '�'
	char string[LEN];				//������ ��� ������� 

	cout << "\nEnter arifmetic string: (view - 2+3*4/3-2): ";

	do
	{
		cout << "\n->";
		cin >> string;								//������ ������
		express* eptr = new express(string);		//������� ������ ��� �������
		eptr->parse();								//���������
		cout << "\nResult: " << eptr->solve();		//������
		delete eptr;								//����������� ������ ������ ������
		cout << "\nContinue? (y/n): "; cin >> answer;
	} while (answer == 'y');

	return 0;
}

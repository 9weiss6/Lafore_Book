//������ �� �������� 

#include <iostream>
using namespace std;

struct link		//���� ������� �������� ������ 
{
	int data;
	link* next;		//��������� �� ��������� ���������
};

class linklist
{
private:
	link* first;		//��������� �� ������ ��������� 
public:
	linklist()			//����������� ��� ����������
	{
		first = NULL;
	}

	//---���������---//
	~linklist();
	void additem(int d); //���������� ���������� � ��������� 
	void display();
		
};

void linklist::additem(int d) //���������� ���������� � ���� ���������
{
	link* newlink = new link;	//�������� ������ ��� ����� ��������� 
	newlink->data = d;			//���������� �������� ���������� (����������� ������� � �������� ���������)
	newlink->next = first;		//�������� ��������� ���������� ��������� first (����������� ������� � �������� ���������)
	first = newlink;			//first ������ ��������� �� ����� �������
}

void linklist::display()
{
	link* current = first;		//�������� � ������� �������� ������
	while (current != NULL)		//���� current != NULL (���� ���� ������)
	{
		cout << current->data << endl; //������� ������
		current = current->next;	//�������� ��������� �� ��������� �������
	}
}

linklist::~linklist()			//����������
{
	cout << "\nDeleted! ";		//������� �� ����� ������ ����������
	link* current = first;		//���������� ��������� �� ������ �������
	
	while (current != NULL)		//���� current != NULL (���� ���� ������)
	{
		link* t = current;				//��������� ��������� �� ������ �������
		
		current = current->next;		//�������� ������ �� ��������� ������
		delete t;						//������� ��� ������
		
	}
	
}

int main()
{
	linklist list;  //������ ����������-������ 

	list.additem(25);		//����� �������� ������ 
	list.additem(36);
	list.additem(49);
	list.additem(64);

	list.display();		//���������� ������

	
	
	return 0;
}

/*
---
���������� ������� ����������� � ���, ��� ��� ������ ������������� ��������
���������� ������ ������ ���� ������, �.�. � ��� �� ������� ���������� ����� ������ �������
� �������� ���������� ������.
�� � ������� �� ��������, � ������� ��������� ��������� ������ ������
---
*/
//������ ���������� �� �������

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
	person* persPtr[100];			//������ ���������� 
	int n = 0;						//���������� ��������� � �������
	char choise;

	do {
		persPtr[n] = new person;	//������� ����� ������ 
		persPtr[n]->setName();		//������ ���
		n++;
		cout << "Continue? (y/n): ";	//������ �� �����������
		cin >> choise;
	} while (choise == 'y');

		for (int j = 0; j < n; j++)
		{
			cout << "\nInformation for number " << j + 1;
			persPtr[j]->printName();		//����� ����������
		}
		cout << endl;

		return 0;
}
//������������� ��������� new ��� ��������� ������ ��� ������ 

#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	char* str;
public:
	String(char* s)		//������ ����������� � 1 ���������� � ���������� �� ��������� ����������
	{
		int leigth = strlen(s);			//���������� ���������� � ����������� �� �������� "����� ������"
		str = new char[leigth + 1];		//�������� ����������� ������ �������� � ����� ������ s  + ����������� ������ '/0'(����� ������)
		strcpy(str, s);					//�������� ������ �� s � str
	}
	~String()							//����������
	{
		cout << "Delete this string.";
		delete[] str;					//����������� ������ �� str
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
//����� ������ ����������� ����� ���������

#include <iostream>
using namespace std;

int main()
{
	void dispstr(char*);			//����� ������� ����������� ��� �������� �������
	char str[] = "It is arguments function";

	dispstr(str);

	return 0;
}

/////////////////////////////////////////////

void dispstr(char* ps)
{
	while (*ps)			//�������� while (*ps = true) ����� ������ ���������������� ��� false = '\0'
		cout << *ps++;
	cout << endl;
}
#include <iostream>
using namespace std;

int main()
{
	int intarray[5] = { 31, 41, 51, 61, 71 };

	int* ptrint;		//��������� �� int
	ptrint = intarray;		//��������� �� ��� ������
	
	for (int j = 0; j < 5; j++)
		cout << *(ptrint++) << endl;		//������ ��� ����� ������������ ���������, 
											//�.�. ���������� ptrint �� �������� ���������� 
		return 0;
}
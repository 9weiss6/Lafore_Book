//���������� � ������ ����������� new � delete

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	char* str = "A bad head does not give rest to the feet.";
	int len = strlen(str);		//��������� ����� ������ str

	char* ptr;					//���������� ��������� ����������
	ptr = new char[len + 1];	//�������� ������ ��� ��������� ���������� 

	strcpy(ptr, str);			//�������� ������ str � ptr

	cout << "ptr = " << ptr << endl;		//������� ������ 

	delete[] ptr;				//����������� ���������� ������ 

	return 0;
}
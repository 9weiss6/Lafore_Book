#include <iostream>
using namespace std;

class Base
{
public:
	virtual void show()
	{
		cout << "base\n";
	}

	/*
	virtual void show() = 0;
	*/
};

class Dev1 : public Base
{
public:
	void show()
	{
		cout << "dev1\n";
	}
};

class Dev2 : public Base
{
public:
	void show()
	{
		cout << "dev2\n";
	}
};

int main()
{
	Dev1 dv1;
	Dev2 dv2;
	Base* ptr;

	ptr = &dv1;
	ptr->show();
	ptr = &dv2;
	ptr->show();

	system("pause");
	return 0;
}

//передача агрумента функции по ссылке
#include <iostream>
using namespace std;

int main()

{
	void centimize(double&);	//прототип функции
	
	double var = 10.0;		//вещественный тип данных
	cout << "var = " << var << " inch" << endl;

	centimize(var);		//использование функции по переводу в сантиметры 
	cout << "var = " << var << " centimeters" << endl;

	return 0;
}

void centimize(double& v)
{
	v *= 2.54;
}
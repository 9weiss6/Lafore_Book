//передача агрумента функции по указателю
#include <iostream>
using namespace std;

int main()

{
	void centimize(double*);	//прототип функции

	double var = 10.0;		//вещественный тип данных
	cout << "var = " << var << " inch" << endl;

	centimize(&var);		//использование функции по переводу в сантиметры 
	cout << "var = " << var << " centimeters" << endl;

	return 0;
}

void centimize(double* ptrd)
{
	*ptrd *= 2.54;		//*ptrd - это то же самое что и var
}
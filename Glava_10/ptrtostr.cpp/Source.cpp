//Массив указателей на строки

#include <iostream>
using namespace std;
const int days = 7;

int main()
{
	char* arrptrs[days] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	for (int j = 0; j < days; j++)
		cout << arrptrs[j] << endl;

	return 0;
}
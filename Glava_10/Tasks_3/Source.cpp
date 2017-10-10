#include <iostream>
#include <cstring>

using namespace std;
const int days = 7;


int main()
{
	int n = 0;
	void bsort(char**, int);
	char* arrptrs[days] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	
	cout << "\nNot sort ";
	for (int j = 0; j < days; j++)
		cout << *(arrptrs + j) << endl;

	bsort(arrptrs, days);

	cout << "\nSort ";
	for (int j = 0; j < days; j++)
		cout << *(arrptrs + j) << endl;

	system("PAUSE");
	return 0;
}

void bsost(char** ar, int n)
{
	void order(char**, char**);
	int k, j;

	for (j = 0; j < n - 1; j++)
		for (k = j + 1; k < n; k++)
			order(ar + j, ar + k);
}

void order(char** ar1, char** ar2)
{
	if (strcmp(*ar1, *ar2) > 0)	//сортирует два указателя, если в первом строка больше, чем во втором
	{
		char* tempptr = *ar1;
		*ar1 = *ar2;
		*ar2 = tempptr;
	}
}


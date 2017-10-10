#include <iostream>
using namespace std;

int main()
{
	float num_arr[100];
	char answer;
	int num = 0;

	do {
		cout << "\nEnter number: ";
		cin >> *(num_arr + num++);
		cout << "\nContinue? (y/n): ";
		cin >> answer;
	} while (answer != 'n');

	float total = 0.0;

	for (int i = 0; i < num; i++)
	{
		total += *(num_arr + i);
	}

	float total_mean = total / num;

	cout << "\nMean number: " << total_mean;

	cout << endl << endl;

	system("PAUSE");

	return 0;
}
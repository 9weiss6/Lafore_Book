//������ � ������ ������ ����� ���������

#include <iostream>
using namespace std;

class Meters
{
private:
	int metr;
	int centemetr;
	int millimetr;
public:
	void getmet()
	{
		cout << "Meters = "; cin >> metr;
		cout << "Centemeters = "; cin >> centemetr;
		cout << "Millimeters = "; cin >> millimetr;
	}

	void showmet()
	{
		cout << "\nMeters = " << metr << " m";
		cout << "\nCentemeters = " << centemetr << " cm";
		cout << "\nMillimeters = " << millimetr << " mm";
	}
};

int main()
{
	Meters& met = *(new Meters);	//������ ����� ��������� ������������ ������ � ������ ������ ����� �������� '.'
	met.getmet();
	met.showmet();
	cout << endl;

	return 0;

}
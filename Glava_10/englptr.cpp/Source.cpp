//Доступ к членам класса через указатели

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
	

	Meters met_;		//Объявление объекта класса
	met_.getmet();
	met_.showmet();
	cout << endl << "\nCreate object class - met_1\n" << endl;
	Meters* met_1;
	met_1 = new Meters;
	met_1->getmet();
	met_1->showmet();
	cout << endl;

	return 0;

}
//модель лошадиных скачек

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "msoftcon.h"

//для очистки окна перед выводом скачек

#include <stdlib.h>		//для работы system ("cls"); - нельзя использовать в связке с system("pause");
//#include <conio.h>   для работы функции clrscr();  - not work


using namespace std;

const int CPF = 5;
const int maxHorses = 7;

class track;
////////////////////////////////////////////////////////
class horse
{
private:
	const track* ptrTrack;
	const int horse_number;
	float finish_time;
	float distance_run;
public:
	horse(const int n, const track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0)
	{

	}
	~horse()
	{

	}
	void display_horse(const float elapsed_time);
};
/////////////////////////////////////////////////////////
class track
{
private:
	horse* hArray[maxHorses];
	int total_horses;
	int horse_count; 
	const float track_length;
	float elapsed_time;
public:
	    track(float lenT, int nH);
		~track();
		void display_track();
		void run();
		float get_track_len() const;
};
//////////////////////////////////////////////////
void horse::display_horse(float elapsed_time)
{
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
	set_color(static_cast<color>(cBLUE + horse_number));
	char horse_char = '1' + static_cast<char>(horse_number);
	_putch(' '); _putch('\xDB'); _putch(horse_char); _putch('\xDB');
	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)
	{
		if (rand() % 3)
			distance_run += 0.2F;
		finish_time = elapsed_time;
	}
	else
	{
		int mins = int(finish_time) / 60;
		int  secs = int(finish_time) - mins * 60;
		cout << " Time = " << mins << ":" << secs;
	}
}

////////////////////////////////////////////////////////////////////

track::track(float lenT, int nH) : track_length(lenT), total_horses(nH), horse_count(0), elapsed_time(0.0)
{
	init_graphics();
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
	for (int j = 0; j < total_horses; j++)
		hArray[j] = new horse(horse_count++, this);

	time_t aTime;
	srand(static_cast<unsigned>(time(&aTime)));
	display_track();
}

////////////////////////////////////////////////////////////////////

track::~track()
{
	for (int j = 0; j < total_horses; j++)
		delete hArray[j];
}

////////////////////////////////////////////////////////////////////

void track::display_track()
{
	clear_screen();
	system("cls");
	for (int f = 0; f <= track_length; f++)
		for (int r = 1; r <= total_horses * 2 + 1; r++)
		{
			set_cursor_pos(f * CPF + 5, r);
			if (f == 0 || f == track_length)
				cout << '\xDE';
			else
				cout << '\xB3';
		}
}

////////////////////////////////////////////////////////////////////

void track::run()
{
	while ( !_kbhit() )
	{
		elapsed_time += 1.75;

		for (int j = 0; j < total_horses; j++)
			hArray[j]->display_horse(elapsed_time);
		wait(500);
	}
	_getch();
	cout << endl;
}

////////////////////////////////////////////////////////////////////

float track::get_track_len() const
{
	return track_length;
}

////////////////////////////////////////////////////////////////////

int main()
{
	float length;
	int total;

	cout << "\nEnter length distance (1...12): "; 
	cin >> length;
	system("cls");
	cout << "\nEnter cout horses (1...7): ";
	cin >> total;
	system("cls");
	
	track theTrack(length, total);
	theTrack.run();

	system("PAUSE");
	return 0;
}



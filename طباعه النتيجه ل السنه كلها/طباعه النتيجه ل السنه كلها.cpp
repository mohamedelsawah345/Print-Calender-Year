
// طباعه النتيجه ل السنه كلها.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
string arrMonthName[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
int NumberOfDyesInMonthesLeap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int NumberOfDyesInMonthesNotLeap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
short ReturnorderOfDayInWeek(short day, short year, short Month)
{
	string ArrOfWeek[7] = { "Sun","Mon","Tues","Wed","Thurs","Frid","Sat" };
	short a, y, m, D;


	a = (14 - Month) / 12;
	y = year - a;
	m = Month + 12 * a - 2;

	return  ((day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12))) % 7;




}
bool CheckLeapOrNot(int Year)
{
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
		return true;
	else
		return false;
}
short ReadYear()
{
	short Number;
	cout << "please enter your year \n";
	cin >> Number;

	return Number;

}
short ReadMounth()
{
	short Number;
	cout << "please enter your mounth \n";
	cin >> Number;

	return Number;

}
int NumberOfDaysIbMounth(int Mounth, int Year)
{
	if (CheckLeapOrNot(Year))
	{
		return NumberOfDyesInMonthesLeap[Mounth - 1];
	}
	else
		return NumberOfDyesInMonthesNotLeap[Mounth - 1];
}
void PrintCalenderMonth(short year, short month)
{

	short M = ReturnorderOfDayInWeek(1, year, month);
	cout << "_____________" << arrMonthName[month - 1] << "_______________\n\n";

	cout << setw(5) << "Sun" << setw(5) << "Mon" << setw(5) << "Tue" << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat\n";


	for (int K = 0; K < M; K++)
	{
		cout << setw(5) << "";
	}

	for (int i = 1; i <= NumberOfDaysIbMounth(month, year); i++)
	{
		cout << setw(5) << i;
		if (++M == 7)
		{
			M = 0;
			cout << endl;
		}
	}



}
void PrintCalenderinYear(short year)
{
	for (int i = 1; i <= 12; i++)
	{
		PrintCalenderMonth(year, i);
			cout << endl;
	}


}

int main()
{
	short year = ReadYear();
	cout << "Calender fo :" << year << endl;
	PrintCalenderinYear(year);
}






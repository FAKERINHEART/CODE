#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num;
	cin >> num;
	cout << num << endl;
	string str;
	for(int i = 1; i <= num; i++)
	{
		int day, month, year;
		string string_month, temp;
		cin >> day >> temp >> string_month >> year;
		if(string_month == "pop") month = 0;
		else if(string_month == "no") month = 1;
		else if(string_month == "zip") month = 2;
		else if(string_month == "zotz") month = 3; 
		else if(string_month == "tzec") month = 4;
		else if(string_month == "xul") month = 5;
		else if(string_month == "yoxkin") month = 6;
		else if(string_month == "mol") month = 7;
		else if(string_month == "chen") month = 8;
		else if(string_month == "yax") month = 9;
		else if(string_month == "zac") month = 10;
		else if(string_month == "ceh") month = 11; 
		else if(string_month == "mac") month = 12;
		else if(string_month == "kankin") month = 13;
		else if(string_month == "muan") month = 14;
		else if(string_month == "pax") month = 15;
		else if(string_month == "koyab") month =16;
		else if(string_month == "cumhu") month = 17; 
		else if(string_month == "uayet") month = 18;
		 
		 int days = (day + 1) + month * 20 + year * 365;
		 
		 int Tzolkin_day, Tzolkin_month, Tzolkin_year;
		 
		 string str_Tzolkin_month[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
		 
		 Tzolkin_year = days / 260;
		 if(days % 260 == 0) Tzolkin_year--;	 
		 
		 Tzolkin_day = days % 260 % 13;
		 if(!Tzolkin_day) Tzolkin_day = 13; 
		 
		 Tzolkin_month = days % 260 % 20;
		 if(!Tzolkin_month) Tzolkin_month = 20; 
		 
		 cout << Tzolkin_day << " " << str_Tzolkin_month[Tzolkin_month - 1] << " " << Tzolkin_year << endl;
	}
	return 0;
}

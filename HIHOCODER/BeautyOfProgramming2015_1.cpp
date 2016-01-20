#include <iostream>
#include <string>

using namespace std;

bool test_LeapYear(int year)
{
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;
	else return false;	
} 

int main()
{
	int num;
	char temp;
	int day_first, year_first, day_second, year_second, month_first, month_second;
	string str_month_first, str_month_second;
	string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	int count;
	cin >> num;
	for(int i = 1; i <= num; i++)
	{
		count = 0;
		cin >> str_month_first >> day_first >> temp >> year_first;
		cin.clear();
		cin.sync();
		cin >> str_month_second >> day_second >> temp >> year_second;
		cin.clear();
		cin.sync();
		for(int j = year_first + 1; j < year_second; j++) if(test_LeapYear(j)) count++;
		int k = 0;
		while(str_month_first != Months[k++]);
		month_first = k;
		k = 0;
		while(str_month_second != Months[k++]);
		month_second = k;
		//cout << month_first << month_second << endl;
		if((year_second > year_first || year_second == year_first && (month_second >= 3 || month_second == 2 && day_second == 29))&& (month_first < 2 || month_first == 2 && day_first <= 29)) if(test_LeapYear(year_first)) count++;
		if(year_second > year_first && (month_second >= 3 || month_second == 2 && day_second == 29)) if(test_LeapYear(year_second)) count++;
		cout << "Case #" << i << ": " << count << endl;
	}
	return 0;
}

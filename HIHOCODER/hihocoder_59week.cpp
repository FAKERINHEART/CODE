#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <cstdlib>

using namespace std;

class Order
{
	public:
		string Name_Function;
		int Seconds_Last;
};

class Record
{
	public:
		string Name_Function;
		int Seconds_Start;
		string Command;
		int sub;
		Record(string one, int two, string three, int four)
		{
			Name_Function = one;
			Seconds_Start = two;
			Command = three;
			sub = four;
		}
};

string SecondsToTime(int Seconds)
{
	stringstream ss;
	string str_h, str_m, str_s;
	int h, m, s;
	h = Seconds / 3600;
	ss << h;
	ss >> str_h;
	ss.clear();
	m = (Seconds % 3600) / 60;
	ss << m;
	ss >> str_m;
	ss.clear();
	s = (Seconds % 3600) % 60;
	ss << s;
	ss >> str_s;
	ss.clear();
	if(h < 10) str_h = "0" + str_h;
	if(m < 10) str_m = "0" + str_m;
	if(s < 10) str_s = "0" + str_s;
	return str_h + ":" + str_m + ":" + str_s;
}

int TimeToSeconds(string Time)
{
	int time = 0;
	stringstream ss;
	ss << Time;
	getline(ss, Time, ':');
	time += atoi(Time.c_str()) * 3600;
	getline(ss, Time, ':');
	time += atoi(Time.c_str()) * 60;
	getline(ss, Time);
	time += atoi(Time.c_str());
	ss.clear();
	return time;
}

int main()
{
	int n;
	string Name, Time, Command;
	int Seconds_Now, Seconds_Previous = -1;
	deque<Record> _Record;
	
	cin >> n;	
	Order _Order[n];
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> Name >> Time >> Command;
		Seconds_Now = TimeToSeconds(Time);
		if(Seconds_Now < Seconds_Previous)
		{
			cout << "Incorrect performance log" << endl;
			return 0;
		}
		else
		{
			Seconds_Previous = Seconds_Now;
			if(Command == "START")
			{
				_Order[count].Name_Function = Name;
				_Order[count].Seconds_Last = 0;
				_Record.push_back(Record(Name, Seconds_Now, Command, count));
				count++;
			}
			else if(Command == "END")
			{
				if(_Record.empty() || Name != _Record.back().Name_Function)
				{
					cout << "Incorrect performance log" << endl;
					return 0;
				}
				else
				{
					_Order[_Record.back().sub].Seconds_Last = Seconds_Now - _Record.back().Seconds_Start;
					_Record.pop_back(); 
				}
			}
		}
	}
	if(!_Record.empty())
	{
		cout << "Incorrect performance log" << endl;
		return 0;
	}
	else for(int i = 0; i < count; i++) cout << _Order[i].Name_Function << " " << SecondsToTime(_Order[i].Seconds_Last) << endl;
	
	return 0;
}

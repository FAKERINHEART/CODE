#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class eq
{
public:
	double down;
	bool down_equal;
	double up;
	bool up_equal;
	int num;
	eq(double _down, bool _down_equal, double _up, bool _up_equal): up(_up), down_equal(_down_equal), down(_down), up_equal(_up_equal), num(1){}
};

int main()
{
	int n;
	cin >> n;
	vector<eq> _v;
	string str;
	double symbol, num;
	bool symbol_equal, num_equal;
	
	bool flag;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		cin >> str;
		cin >> num;
	 	//cout << str << num << endl;
		if(str == "<") 
		{
			symbol = -1;
			symbol_equal = true;
			num_equal = false;
		}
		else if(str == "<=") 
		{
			symbol = -1;
			symbol_equal = true;
			num_equal = true;
		}
		else if(str == "=") 
		{
			symbol = num;
			symbol_equal = true;
			num_equal = true;
		}
		else if(str == ">=") 
		{
			symbol = 1001;
			swap(symbol, num);
			symbol_equal = true;
			num_equal = true;
		}	
		else if(str == ">")	
		{
			symbol = 1001;
			swap(symbol, num);
			symbol_equal = false;
			num_equal = true;
		}
		
		flag = false;
		double MIN, MAX;
		bool MIN_EQUAL, MAX_EQUAL;
		for(int j = 0; j < _v.size(); j++)
		{
			if(num < _v[j].up)
			{
				MIN = num;
				MIN_EQUAL = num_equal;
			}
			else if(num == _v[j].up)
			{
				MIN = num;
				MIN_EQUAL = num_equal & _v[j].up_equal;
			}
			else if(num > _v[j].up)
			{
				MIN = _v[j].up;
				MIN_EQUAL = _v[j].up_equal;
			}
			
			if(symbol < _v[j].down)
			{
				MAX = _v[j].down;
				MAX_EQUAL = _v[j].down_equal;
			}
			else if(symbol == _v[j].down)
			{
				MAX = _v[j].down;
				MAX_EQUAL = _v[j].down_equal & symbol_equal;
			}
			else if(symbol > _v[j].down)
			{
				MAX = symbol;
				MAX_EQUAL = symbol_equal;
			}
			
			if(MAX == MIN && MAX_EQUAL && MIN_EQUAL || MAX < MIN)
			{
				_v[j].down = MAX;
				_v[j].down_equal = MAX_EQUAL;
				_v[j].up = MIN;
				_v[j].up_equal = MIN_EQUAL;
				_v[j].num++;
				flag = true;
			}
		}
		if(!flag) _v.push_back(eq(symbol, symbol_equal, num, num_equal));
		//cout << _v.size() << endl;
	} 
	
	int M = 0;
	for(int i = 0; i < _v.size(); i++) M = max(_v[i].num, M);
	cout << M << endl;
	_v.clear();
	return 0;
} 

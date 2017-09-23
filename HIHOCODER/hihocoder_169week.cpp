#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <deque>

using namespace std;

char operOr[7] = {'+', '-', '*', '/', '(', ')', '#'};
map<char, int> operOrId{{'+', -1}, {'-', -2}, {'*', -3}, {'/', -4}, {'(', -5}, {')', -6}, {'#', -7}};
map<char, int> operOrPrior{{'+', 3}, {'-', 3}, {'*', 4}, {'/', 4}, {'(', 2}, {')', 2}, {'#', 1}};

int calculate(int first, int second, char third)
{
	switch(third)
	{
	case '+': return first + second;
	case '-': return first - second;
	case '*': return first * second;
	case '/': return first / second;
	}
	
	return -1;
}

int main()
{
	string str;
	cin >> str;
	str += '#';
	
	vector<int> v_str;
	v_str.reserve(101);
	
	for(int i = 0; i < str.length();)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			long long sum = 0;
			while(str[i] >= '0' && str[i] <= '9')
			{
				sum = sum * 10 + (str[i] - '0');
				++i;
			}
			
			v_str.push_back(sum);
		}
		else
		{
			v_str.push_back(operOrId[str[i]]);
			++i;
		}
	}
	
	//for(int i = 0; i < v_str.size(); ++i) cout << v_str[i] << endl;
	
	deque<char> dq_operOr;
	deque<int>	dq_operAnd;
	
	for(int i = 0; i < v_str.size(); ++i)
	{
		if(v_str[i] >= 0)
		{
			//cout << "aaa_1: " << v_str[i] << endl;
			dq_operAnd.push_back(v_str[i]);
			//cout << "aaa_2: " << v_str[i] << endl;
		}
		else
		{
			char temp_operOr = operOr[-v_str[i] - 1];
			
			if(temp_operOr == '(')
			{
				//cout << "bbb_1: " << temp_operOr << endl;
				
				dq_operOr.push_back(temp_operOr);
				
				//cout << "bbb_2: " << temp_operOr << endl;
			}
			else if(temp_operOr == ')')
			{
				//cout << "ddd_1: " << ")" << endl;
				while(dq_operOr.back() != '(')
				{
					int second = dq_operAnd.back();
					dq_operAnd.pop_back();
					int first = dq_operAnd.back();
					dq_operAnd.pop_back();
					char third = dq_operOr.back();
					dq_operOr.pop_back();
					
					dq_operAnd.push_back(calculate(first, second, third));
					//cout << "ccc: " << first << " " << second << " " << third << endl;
				}
				
				dq_operOr.pop_back();
				//cout << "ddd_2: " << ")" << endl;
			}
			else
			{
				//cout << "fff_1: " << temp_operOr << endl;
				
				while(dq_operOr.size() > 0 && operOrPrior[temp_operOr] <= operOrPrior[dq_operOr.back()])
				{
					int second = dq_operAnd.back();
					dq_operAnd.pop_back();
					int first = dq_operAnd.back();
					dq_operAnd.pop_back();
					char third = dq_operOr.back();
					dq_operOr.pop_back();
					
					dq_operAnd.push_back(calculate(first, second, third));
					//cout << "eee: " << first  << " " << second << " " << third << endl;
				}
				
				
				dq_operOr.push_back(temp_operOr);
				
				//cout << "fff_2: " << temp_operOr << endl;
			}
		}
	}
	
	cout << dq_operAnd.back() << endl;
	
	
	
	return 0;
}

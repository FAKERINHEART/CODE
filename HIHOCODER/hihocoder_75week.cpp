#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	
	vector<char> v;
	int r = 0, y = 0, b = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '<')
		{
			if(str[i + 1] == 'r')
			{
				v.push_back('r');
				i += 4;
				continue;
			}
			else if(str[i + 1] == 'y')
			{
				v.push_back('y');
				i += 7;
				continue;
			}
			else if(str[i + 1] == 'b')
			{
				v.push_back('b');
				i += 5;
				continue;	
			} 
			else if(str[i + 1] == '/')
			{
				v.pop_back();
				if(str[i + 2] == 'r')
				{
					i += 5;
					continue;
				}
				else if(str[i + 2] == 'y')
				{
					i += 8;
					continue;
				}
				else if(str[i + 2] == 'b')
				{
					i += 6;
					continue;	
				} 
			}
		}
		else
		{
			if(v.empty()) continue;
			else if(v.back() == 'r' && str[i] <= 'z' && str[i] >= 'a') r++;
			else if(v.back() == 'y' && str[i] <= 'z' && str[i] >= 'a') y++;
			else if(v.back() == 'b' && str[i] <= 'z' && str[i] >= 'a') b++; 
		}
	}
	cout << r << " " << y << " " << b << endl;
	
	return 0;
}

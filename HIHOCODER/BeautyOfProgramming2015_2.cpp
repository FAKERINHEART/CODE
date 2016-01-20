#include <iostream>
#include <string>

using namespace std;

string sub_str()

int main()
{
	int num;
	cin >> num;
	string str;
	int count;
	for(int i = 1; i <= num; i++)
	{
		cin >> str;
		count = 0;
		for(int j = 0; j < str.length(); j++)
		{
			int k = str.length() - 1;
			int l = j;
			while(k >= l)
			{
				if(str[l] == str[k])
				{
					cout++;
					l++;
					k--;	
				} 
				else
				{
					k--;
				}
			}
		}
	}
	return 0;
}

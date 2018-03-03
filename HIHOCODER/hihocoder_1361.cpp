#include <iostream>
#include <memory.h>
#include <string> 

using namespace std;

int main()
{
	bool used[26];
	memset(used, false, sizeof(used));
	used['J' - 'A'] = true;
	
	string str;
	cin >> str;
	
	size_t len = str.length();
	 
	for (size_t i = 0; i < len; ++i)
	{
		if (str[i] == 'J')
		{
			str[i] = 'I';
		}
	}
	
	int k = 0, l = 0;
		
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{	
			while (true)
			{
				if (k >= len)
				{
					if (used[l] == true)
					{
						++l;
					}
					else
					{
						cout << char('A' + l);
						used[l] = true;
						++l;
						break; 
					}
				}
				else 
				{
					if (used[str[k] - 'A'] == true)
					{
						++k;
					}
					else
					{
						cout << str[k];
						used[str[k] - 'A'] = true;
						++k;
						break;
					}
				}
			}
		}
		
		cout << endl;
	}
	
	return 0;
}

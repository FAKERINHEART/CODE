#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
string temp;

int remove()
{
	int count = 0;
	for(int i = 0, j; str.length() && i < str.length() - 1;)
	{
		j = i + 1;
		while(j < str.length() && str[j] == str[i]) j++;
		if(j - i > 1) 
		{
			str.erase(i, j - i);
			count += (j - i);	
		}
		else i++;
	}
	return count;
}

int main()
{
	
	int T, count, ret;
	int MAX;
	cin >> T;
	while(T--)
	{
		cin >> temp;
		MAX = 0;
		for(int k = 0; k < temp.length(); k++)
		{
			for(int l = 0; l < 3; l++) 
			{
				count = 0;
				
				str = temp;
				str.insert(k, 1, 'A' + l);
				while(ret = remove()) count += ret;
				
				MAX = max(MAX, count);
			}	
		}
		cout << MAX << endl;
	}
	return 0;
} 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool KMP(string object, string pattern)
{
	int length_object = object.length(), length_pattern = pattern.length();
	if(!length_object) return false;
	if(!length_pattern) return true;
	int next[length_pattern + 1];
	
	int i = 0, j = -1;
	next[0] = -1;
	while(i < length_pattern)
	{
		if(j == -1 || pattern[j] == pattern[i])
		{
			j++;
			i++;
			next[i] = j;
		}
		else j = next[j];
	}
	
	i = 0, j = 0;
	while(i < length_object)
	{
		if(j == -1 || pattern[j] == object[i])
		{
			j++;
			i++;
		}
		else j = next[j];
		if(j == length_pattern) return true; 
	}
	return false;
}

int main()
{
	int num_case, num_string;
	string str[100];
	int sub_min_string, min_length;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		cin >> num_string;
		min_length = -1;
		for(int j = 0; j < num_string; j++)
		{
			cin >> str[j];
			if(str[j].length() < min_length)
			{
				min_length = str[j].length();
				sub_min_string = j;
			}
		} 
		bool key;
		for(int k = min_length; k >= 0; k--)
		{
			for(int l = 0; l <= min_length - k; l++)
			{
				string temp1 = str[sub_min_string].substr(l, k);
				string temp2 = temp1;
				reverse(temp2.begin(), temp2.end());
				key = true;
				for(int m = 0; m < num_string; m++)
				{
					if(!KMP(str[m], temp1) && !KMP(str[m], temp2))
					{
						key = false;
						break;
					}
				}
				if(key) break;
			}
			if(key)
			{
				cout << k << endl;
				break;
			}
		}
	}
	return 0;
} 

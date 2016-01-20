#include <iostream>
#include <cstring>
#include <string>
#include <set>

using namespace std;

int diff(string str)
{
	int al[26];
	int count = 0, length = str.length();
	memset(al, 0, sizeof(al));
	for(int i = 0; i < length; i++)
	{
		if(!al[str[i] - 'a']) count++;
		al[str[i] - 'a']++;
	}
	return count;
}

int main()
{
	int arr[101];
	memset(arr, 0, sizeof(arr));
	int pre_pre = 0, pre = 1, now = pre_pre + pre;
	while(now <= 101)
	{
		arr[now] = 1;
		pre_pre = pre;
		pre = now;
		now = pre_pre + pre;
	}
	
	set<string> _s;
	string str, sub_str;
	cin >> str;
	int length = str.length();
	for(int i = 0; i < length; i++)
	{
		for(int j = i; j < length; j++)
		{
			sub_str = str.substr(i, j - i + 1);
			if(arr[diff(sub_str)]) _s.insert(sub_str);
		}
	}
	set<string>::iterator iter = _s.begin();
	while(iter != _s.end())
	{
		cout << *iter << endl;
		iter++;
	}
	
	return 0;	
} 

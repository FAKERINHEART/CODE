#include<iostream>
#include<string>
#include<cstring>
#include<algorithm> 

using namespace std;

int radius[2000000];
int max_length;
string temp, str;

void findLongestPalindrome()
{
	memset(radius, 0, sizeof(radius));
	max_length = -1;
	for(int i = 1, j = 0, k; i < str.length(); i += k)
	{
		while(i - j >= 0 && i + j < str.length() && str[i - j] == str[i + j]) j++;
		radius[i] = j - 1;
		max_length = max(max_length, radius[i]);
		for(k = 1; k <= radius[i] && radius[i - k] != radius[i] - k; k++) 
		{
			radius[i + k] = min(radius[i - k], radius[i] - k);
			max_length = max(max_length, radius[i + k]);
		}
		j = max(j - k, 0);
	}
	return;
}

int main()
{
	int num;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		str.clear();
		cin >> temp;
		
		str += '#';
		for(int j = 0; j < temp.length(); j++)
		{
			str += temp[j];
			str += '#';
		}	
		
		findLongestPalindrome();
		cout << max_length << endl;
	} 
	return 0;
}

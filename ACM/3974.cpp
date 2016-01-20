#include<iostream>
#include<string>
#include<cstring>
#include<algorithm> 

using namespace std;
int radius[2000000];
int max_length;
string temp, str;

void test_length(int x)
{
	if(str[x] == '#') max_length = max(max_length, (radius[x] - radius[x] / 2) * 2);
	else
	{
		if(radius[x] % 2) max_length = max(max_length, (radius[x] - (radius[x] / 2 + 1)) * 2 + 1);
		else max_length = max(max_length, (radius[x] - radius[x] / 2) * 2 + 1);
	}
	return;
}

void findLongestPalindrome()
{
	memset(radius, 0, sizeof(radius));
	max_length = -1;
	for(int i = 1, j = 0, k; i < str.length(); i += k)
	{
		while(i - j >= 0 && i + j < str.length() && str[i - j] == str[i + j]) j++;
		radius[i] = j - 1;
		test_length(i);
		for(k = 1; k <= radius[i] && radius[i - k] != radius[i] - k; k++) 
		{
			radius[i + k] = min(radius[i - k], radius[i] - k);
			test_length(i + k);
		}
		j = max(j - k, 0);
	}
	return;
}

int main()
{
	int count = 0;
	while(cin >> temp)
	{
		str.clear();
		if(temp == "END") break;
		count++;
		int j;
		for(j = 0; j < temp.length() - 1; j++)
		{
			str += temp[j];
			str += '#';
		}	
		str += temp[j];
		
		findLongestPalindrome();
		cout << "Case " << count << ": " << max_length << endl;
	} 
	return 0;
} 

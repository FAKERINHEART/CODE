#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if(!str1.length() || !str2.length())
	{
		cout << 0 << endl;
		cout << endl;
		return 0;
	}
	
	int arr[str1.length()][str2.length()];
	int sub[str1.length()][str2.length()];
	memset(arr, 0, sizeof(arr));
	memset(sub, 0, sizeof(sub));
	for(int i = 0; i < str2.length(); i++)
	{
		if(str1[0] == str2[i])
		{
			arr[0][i] = 1;
			sub[0][i] = 0;
		}
	}
	for(int i = 0; i < str1.length(); i++)
	{
		if(str1[i] == str2[0])
		{
			arr[i][0] = 1;
			sub[i][0] = i;
		}
	}
	
	for(int i = 1; i < str1.length(); i++)
	{
		for(int j = 1; j < str2.length(); j++)
		{
			if(str1[i] == str2[j])
			{
				if(str1[i - 1] == str2[j - 1])
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
					sub[i][j] = i;
				}
				else
				{
					arr[i][j] = 1;
					sub[i][j] = i - 1;
				}
			}
			else
			{
				if(arr[i - 1][j - 1] > arr[i - 1][j] && arr[i - 1][j - 1] > arr[i][j - 1])
				{
					arr[i][j] = arr[i - 1][j - 1];
					sub[i][j] = i - 1;
				}
				else if(arr[i - 1][j] > arr[i - 1][j - 1] && arr[i - 1][j] > arr[i][j - 1])
				{
					arr[i][j] = arr[i - 1][j];
					sub[i][j] = i - 1;
				}
				else if(arr[i][j - 1] > arr[i - 1][j - 1] && arr[i - 1][j - 1] > arr[i - 1][j])
				{
					arr[i][j] = arr[i][j];
					sub[i][j] = i;
				}
			}
		}
	}
	
	cout << arr[str1.length() - 1][str2.length() - 1] << endl;
	cout << str1.substr(sub[str1.length() - 1][str2.length() - 1] - arr[str1.length() - 1][str2.length() - 1] + 1, arr[str1.length() - 1][str2.length() - 1]) << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str[n];
	double num[n];
	for(int i = 0; i < n; i++) cin >> str[i] >> str[i] >> num[i];
	int MAX = 0, count;
	for(double i = -1; i <= 1001; i += 0.5)
	{
		count = 0;
		for(int j = 0; j < n; j++)
		{
			if(str[j] == "<" && i < num[j]) count++;
			else if(str[j] == "<=" && i <= num[j]) count++;
			else if(str[j] == "=" && i == num[j]) count++;
			else if(str[j] == ">=" && i >= num[j]) count++;
			else if(str[j] == ">" && i > num[j]) count++;
		}
		MAX = max(MAX, count);
	}
	cout << MAX << endl;
}

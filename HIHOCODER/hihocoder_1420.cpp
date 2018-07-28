#include<iostream>

using namespace std;

int product[210];
int num1[101], num2[101];
string s1, s2;

int main()
{ 
	cin >> s1 >> s2;

	for (int i = 0; i < s1.length(); ++i)
	{
		num1[i] = s1[i] - '0';
	}

	for (int i = 0; i < s2.length(); ++i)
	{
		num2[i] = s2[i] - '0';
	}

	int current_base = 0;

	for (int i = s2.length() - 1; i >= 0; --i, ++current_base)
	{
		int current = current_base;

		for (int j = s1.length() - 1; j >= 0; --j, ++current)
		{
			int p = num2[i] * num1[j];
			product[current] += p % 10;
			product[current + 1] += p / 10;
			product[current + 1] += product[current] / 10;
			product[current] %= 10;
		}
	}

	int highDigit = 209;
	
	while (highDigit > 0 && product[highDigit] == 0)
	{
		--highDigit;
	}

	while(highDigit >= 0)
	{
		cout << product[highDigit--];
	}

	cout << endl;

	return 0;  
} 

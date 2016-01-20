#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num_case, k;
	string str;
	int result[64];
	long long N;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		cin >> k >> str >> N;
		for(int j = k - 1; j >= 0; j--)
		{
			if(N % 2)
			{
				result[j] = 1;
				if(str[j] == 'p') N = (N - 1) / 2;
				else N = (N + 1) / 2; 
			}
			else
			{
				result[j] = 0;
				N /= 2;
			}
		}
		if(N) cout << "Impossible";
		else for(int j = 0; j < k; j++) cout << result[j];
		cout << endl; 
	}
	return 0;
} 

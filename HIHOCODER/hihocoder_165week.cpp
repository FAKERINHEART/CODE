#include <iostream>
#include <string>

using namespace std;

int cnt[26] = {0};

bool isValid(int n)
{
	for(int i = 0; i < 26; ++i)
	{
		if(cnt[i] > (n - 1) / 2 + 1)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	string s;
	cin >> s;
	
	int N = s.length();
	
	for(int i = 0; i < N; ++i)
	{
		++cnt[s[i] - 'a'];
	}
	
	if(isValid(N) == false)
	{
		cout << "INVALID" << endl;
	}
	else
	{
		int pre = -1;
		
		for(int i = 0; i < s.length(); ++i)
		{
			for(int j = 0; j < 26; ++j)
			{
				if(cnt[j] > 0 && j != pre)
				{
					--cnt[j];
					
					if(isValid(N - 1) == true)
					{
						cout << (char)('a' + j);
						pre = j;
						--N;
						break;
					}
					else
					{
						++cnt[j];
					}
				}
			}
		}
		
		cout << endl;
	}
	
	return 0;
} 

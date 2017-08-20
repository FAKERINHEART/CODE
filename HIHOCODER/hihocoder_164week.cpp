#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	string S;
	
	cin >> T;
	
	while(T--)
	{
		cin >> S;
		
		int MIN = S.length();
		
		for(int i = 0; i <= S.length(); ++i)
		{
			int temp = 0;
			
			for(int j = 0; j < i; ++j)
			{
				if(S[j] == '1')
				{
					++temp;
				}
			}

			for(int j = i; j < S.length(); ++j)
			{
				if(S[j] == '0')
				{
					++temp;
				}
			}
			
			MIN = min(MIN, temp);
		}
		
		cout << MIN << endl;
	}
	
	return 0;
} 

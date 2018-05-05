#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int dp[26];
bool adjacent[26][26];

int main()
{
    int N, M;
    string str;
    
    cin >> N;
	cin >> str;
	cin >> M;
	
    for (int i = 0; i < M; ++i)
    {
        char ch1, ch2;
        
		cin >> ch1 >> ch2;
        
        adjacent[ch1 - 'a'][ch2 - 'a'] = true;
        adjacent[ch2 - 'a'][ch1 - 'a'] = true;
    }

    for (int i = 0; i < str.length(); ++i)
    {
        char ch = str[i];
        int MAX = 1;
        
        for (int j = 0; j < 26; ++j)
        {
            if (adjacent[ch - 'a'][j] == false)
            {
                MAX = max(MAX, dp[j] + 1);
            }
        }
        
        dp[ch - 'a'] = MAX;
    }

    std::cout << N - *max_element(dp, dp + 26) << std::endl;
    
    return 0;
}

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.size(), m = str2.size();
	int dp0[n + 1][m + 1], dp1[n + 1][m + 1], f[n + 1][m + 1];
	
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(str1[i - 1] == str2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = 0;
		}
	}
	
    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= m; j++)
    	{
    		dp1[i][j] = 0;
    		if(f[i][j] >= 3)
    		{
    			dp1[i][j] = max(dp1[i][j], dp0[i - 3][j - 3] + 3);
    			if(f[i][j] > 3) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - 1] + 1);
			}
			dp0[i][j] = max(dp0[i - 1][j], dp0[i][j - 1]);
			dp0[i][j] = max(dp0[i][j], dp1[i][j]);
		}
	}
    cout << dp0[n][m] << endl;
    
	return 0;
} 

#include <iostream>

using namespace std;

int dfs(long long n)
{
    if (n == 0)
	{
		return 0;
	}
	
    long long ans = 1;
    
	while((ans << 1) <= n)
	{
		ans <<= 1;
	}
	
    ans = min(n - ans, 2 * ans - n);
    
	return 1 + dfs(ans);
}

int main()
{
    long long n;
    
	cin >> n;
    
    cout << dfs(n) << endl;
    
	return 0;
}

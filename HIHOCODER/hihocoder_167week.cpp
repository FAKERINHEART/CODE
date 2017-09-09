#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	int n;
	cin >> n;
	
	int array[n];
	
	for(int i = 1; i <= n; ++i) cin >> array[i];
	
	long long ans = 1;
	
	for(int i = 1; i <= n; ++i)
	{
		int cnt = 1;
		int p = array[i];
		
		while(p != i)
		{
			p = array[p];
			++cnt;
		}
		
		ans = ans * cnt / gcd(ans, cnt);
	}
	
	cout << ans << endl;
	
	return 0;
}

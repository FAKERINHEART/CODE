#include <iostream>

using namespace std;

long long Josephus(int n, int k)
{
	if(n == 1) return 0;
	if(n < k)
	{
		long long res = 0;
		for(int i = 2; i <= n; ++i) res = (res + k) % i;
		return res;
	}
	long long res = Josephus(n - n / k, k);
	if(res < n % k) res = res - n % k + n;
	else res = res - n % k + (res - n % k) / (k - 1);
	return res;
}

int main()
{
	int t;
	cin >> t;
	int n, k;
	long long res;
	while(t--)
	{
		cin >> n >> k;
		res = Josephus(n, k);	
		cout << res << endl;
	}
	return 0;
}

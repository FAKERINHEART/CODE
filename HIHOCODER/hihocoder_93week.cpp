#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	bool isPrime[n + 1];
	memset(isPrime, true, sizeof(isPrime));
	int primeCount = 0;
	int primeList[n + 1];
	
	for(int i = 2; i <= n; ++i)
	{
		if(isPrime[i]) primeList[++primeCount] = i;
		
		for(int j = 1; j <= primeCount; ++j)
		{
			if(i * primeList[j] > n) break;
			isPrime[i * primeList[j]] = false;
			if(i % primeList[j] == 0) break;
		}
	}
	
	cout << primeCount << endl;
	return 0;
}

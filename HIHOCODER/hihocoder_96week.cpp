#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int L, R;
	cin >> L >> R;
	
	bool isPrime[R + 1];
	memset(isPrime, true, sizeof(isPrime));
	int primeCount = 0;
	int primeList[R + 1];
	int phi[R + 1];
	
	for(int i = 2; i <= R; i++)
	{
		if(isPrime[i]) 
		{
			primeList[++primeCount] = i;
			phi[i] = i - 1;
		}
		
		for(int j = 1; j <= primeCount; ++j)
		{
			if(i * primeList[j] > R) break;
			isPrime[i * primeList[j]] = false;
			
			if(i % primeList[j] == 0) 
			{
				phi[i * primeList[j]] = phi[i] * primeList[j];
				break;
			}
			else
			{
				phi[ i * primeList[j] ] = phi[i] * (primeList[j] - 1);
			}
		}
	}
	
	int MIN = R + 1, SUB_MIN = R + 1;
	for(int i = L; i <= R; i++)
	{
		if(MIN > phi[i] || (MIN == phi[i] && SUB_MIN > i))
		{
			MIN = phi[i];
			SUB_MIN = i;
		}
	}
	cout << SUB_MIN << endl;
	return 0;
}

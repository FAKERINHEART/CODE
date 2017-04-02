#include <iostream>
#include <set>
#include <cmath>

using namespace std;

long long gcd(long long m, long long n)
{
	long long t;
	while(m % n)
	{
		t = m % n;
		m = n;
		n = t;
	}
	return n;
}

int main()
{
	long long N, M;
	cin >> N >> M;
	
	long long numN = 0, numM = 0, num = 0; 
	long long j;
	set<long long> s;
	
	j = sqrt(N);
	for(long long i = 1; i <= j; i++) 
	{
		if(i < j && N % i == 0) 
		{
			numN += 2;
			s.insert(i);
			s.insert(N / i);
		}
		else if(i == j && N % i == 0)
		{
			if(i == sqrt(N))
			{
				++numN;
				s.insert(i);
			}
			else
			{
				numN += 2;
				s.insert(i);
				s.insert(N / i);
			}
			
		}
	}
	
	j = sqrt(M);
	for(long long i = 1; i <= j; i++)
	{
		if(i < j && M % i == 0)
		{
			numM += 2;
			if(!s.insert(i).second) ++num;
			if(!s.insert(M / i).second) ++num;
		} 
		else if(i == j && M % i == 0)
		{
			if(i == sqrt(M))
			{
				++numM;
				if(!s.insert(i).second) ++num;
			}
			else
			{
				numM += 2;
				if(!s.insert(i).second) ++num;
				if(!s.insert(M / i).second) ++num;
			}
			
		}
	}
	
	long long g = gcd(numN * numM, num);
	cout << numN * numM / g << " " << num / g << endl;
	return 0;
}

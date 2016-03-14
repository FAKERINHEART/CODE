#include <iostream>

using namespace std;

long long n, primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

long long value;
long long max_num;

void dfs(int primes_now_index, int primes_now_max_num, long long value_now, long long max_num_now)
{

	if(max_num_now > max_num || max_num_now == max_num && value_now < value)
	{
		max_num = max_num_now;
		value = value_now;
	}
	
	for(int i = 1; i <= primes_now_max_num; i++)
	{
		value_now *= primes[primes_now_index];
		if(value_now > n) break;
		else dfs(primes_now_index + 1, i, value_now, max_num_now * (i + 1));
	}
	return;
} 

int main()
{
	while(cin >> n)
	{
		value = 1;
		max_num = 1;
		dfs(0, 55, 1, 1);
		cout << value << endl;
	}
	return 0;
}

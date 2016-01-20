#include <iostream>

using namespace std;

int num_find = 9;

int main()
{
	long long n, count, right, now, sub_now;
	while(cin >> n)
	{
		if(n == -1) break;
		count = 0;
		now = n;
		right = 0;
		sub_now = 1;
		while(now)
		{
			if(now % 10 < num_find)	count  += (now / 10) * sub_now;
			else if(now % 10 == num_find) count += ((now / 10) * sub_now + right + 1);
			else count += (now / 10 + 1) * sub_now;
			right += (now % 10) * sub_now; 
			now /= 10; 
			sub_now *= 10;
		}
		cout << count << endl;
	}
	return 0;
}

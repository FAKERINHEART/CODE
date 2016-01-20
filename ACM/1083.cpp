#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, times[401], a, b, Max;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		memset(times, 0, sizeof(times));
		cin >> N;
		for(int j = 0; j < N; j++)
		{
			cin >> a >> b;
			if(a > b) swap(a, b);
			if(!a % 2) a -= 1;
			if(b % 2) b += 1;
			for(int k = a; k <= b; k++) times[k]++;
		}
		Max = -1;
		for(int j = 1; j <= 400; j++) Max = max(Max, times[j]);
		cout << Max * 10 << endl;
	}
	return 0;
}

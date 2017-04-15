#include <iostream>
#include <cstring>

using namespace std;

int n, m, K;
int need[2000000];
int ansX, ansY;

void update(int x, int y) 
{
	if (ansX == -1) 
	{
		ansX = x;
		ansY = y;
	} 
	else if (ansX + ansY > x + y) 
	{
		ansX = x;
		ansY = y;
	} 
	else if (ansX + ansY == x + y && x < ansX) 
	{
		ansX = x;
		ansY = y;
	}
	
	return;
}

long long getsum(int col, int len) 
{
	if (len <= col) 
	{
		return (1ll + len) * len / 2;
	}
	return (1ll + col) * col / 2 + 1ll * (len - col) * col;
}

void work(int n, int m, bool change) 
{
	long long sum = 0;
	for (int i = 1; i <= m; i++) sum = (sum + getsum(i, n)) % K;
	for (int start = 1; start <= n; start++) 
	{
		int r = (K - sum) % K;
		if (need[r] != -1) 
		{
			int x = 1 + need[r];
			int y = start + need[r];
			if (change) swap(x, y);
			update(x, y);
		}
		sum = (sum - getsum(start, n) % K + K + getsum(start + m, n) % K) % K;
	}
	
	return;
}

int main() 
{
	int Q; 
	cin >> Q;
	while (Q--) 
	{
		cin >> n >> m >> K;
		memset(need, -1, sizeof(need));
		
		int u = 0;
		need[u] = 0;
		while (true) 
		{
			int nu = (1ll * n * m + u) % K;
			if (need[nu] != -1) break;
			need[nu] = need[u] + 1;
			u = nu;
		}

		ansX = ansY = -1;

		work(n, m, false);
		work(m, n, true);

		if (ansX == -1) cout << "-1" << endl;
		else cout << ansX << " " << ansY << endl;
	}
	return 0;
}


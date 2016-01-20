#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, M, MAX;
	int V[103];
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		for(int i = 1; i <= N; i++) cin >> V[i];
		if(M >= N)
		{
			cout << 100 << endl;
			continue;
		}
		
		V[0] = 1;
		V[N + 1] = 100;
		MAX = V[M + 1] - V[0];
		for(int i = M + 2; i <= N; i++)	MAX = max(MAX, V[i] - V[i - M - 1] - 1);
		MAX = max(MAX, V[N + 1] - V[N - M]);
		cout << MAX << endl;
	}
	return 0;
}

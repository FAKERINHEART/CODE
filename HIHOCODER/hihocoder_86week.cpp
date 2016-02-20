#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int rank[N][K + 1], temp;
	for(int i = 0; i < N; i++)
	{
		for(int j = K; j >= 0; j--)
		{
			cin >> temp;
			rank[i][temp] = j;
		}
	}
	
	int result = 0, sum;
	for(int i = K; i >= 1; i--)
	{
		sum = 0;
		for(int j = 0; j < N; j++) if(rank[j][i] > rank[j][result]) ++sum;
		if(sum > N / 2) result = i;
	}
	if(!result) cout << "otaku" << endl;
	else cout << result << endl;
	return 0;
}

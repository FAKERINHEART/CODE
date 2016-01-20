#include <iostream>
#include <algorithm>

using namespace std;

int dp_min[50][50], dp_max[50][50];
int symbol[50], results[50];

int main()
{
	int N;
	char temp;
	while(cin >> N)
	{
		for(int i = 0; i < N; i++)
		{
			cin >> temp >> dp_max[i][i];
			if(temp == 't') symbol[i] = 1;
			else symbol[i] = 0;
			dp_min[i][i] = dp_max[i][i];
		}
		
		int MAX, MIN, MAX_MAX = -(1 << 30), count = 0;
		for(int start = 0; start < N; start++)
		{
			for(int len = 1; len < N; len++)
			{
				for(int j = start; j < start + N - len; j++)
				{
					MAX = -(1 << 30);
					MIN = 1 << 30;
					for(int k = j; k < j + len; k++)
					{
						if(symbol[(k + 1) % N])
						{
							MAX = max(MAX, dp_max[j % N][k % N] + dp_max[(k + 1) % N][(j + len) % N]);
							MIN = min(MIN, dp_min[j % N][k % N] + dp_min[(k + 1) % N][(j + len) % N]);
						}
						else
						{
							MAX = max(MAX, dp_max[j % N][k % N] * dp_max[(k + 1) % N][(j + len) % N]);
							MAX = max(MAX, dp_min[j % N][k % N] * dp_min[(k + 1) % N][(j + len) % N]);
							MIN = min(MIN, dp_min[j % N][k % N] * dp_min[(k + 1) % N][(j + len) % N]);
							MIN = min(MIN, dp_max[j % N][k % N] * dp_min[(k + 1) % N][(j + len) % N]);
							MIN = min(MIN, dp_min[j % N][k % N] * dp_max[(k + 1) % N][(j + len) % N]);	
						}
					}
					dp_max[j % N][(j + len) % N] = MAX;
					dp_min[j % N][(j + len) % N] = MIN;
				}
			}
			if(MAX >= MAX_MAX)
			{
				if(MAX > MAX_MAX)
				{
					MAX_MAX = MAX;
					count = 0;
				}
				results[count++] = start + 1;
			}			
		} 
		cout << MAX_MAX << endl;
		for(int i = 0; i < count; i++) cout << results[i] << " ";
		cout << endl;
	}
	return 0;
}

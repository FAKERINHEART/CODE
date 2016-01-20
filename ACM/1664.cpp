#include <iostream>

using namespace std;

int main()
{
	int num, M, N;
	int array[11][11];
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		cin >> M >> N;
		for(int j = 0; j <= M; j++)	
		{
			for(int k = 0; k <= N; k++) 
			{
				if(!j && k || k == 1) array[j][k] = 1;
				else if(!k) array[j][k] = 0;
				else array[j][k] = array[j][k - 1] + ((j >= k)? array[j - k][k]: 0);
			}
		}
		cout << array[M][N] << endl;
	}
	return 0;
} 

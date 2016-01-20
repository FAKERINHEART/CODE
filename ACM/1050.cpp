#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int Array[N][N];
	int Sum[N][N];
	int Max = -1, sum;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> Array[i][j];
			if(!i) Sum[i][j] = Array[i][j];
			else Sum[i][j] = Sum[i - 1][j] + Array[i][j];
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = i; j < N; j++)
		{
			sum = 0;
			for(int k = 0; k < N; k++)
			{
				sum += (Sum[j][k] - Sum[i][k] + Array[i][k]);
				if(sum < 0) sum = 0;
				else if(sum > Max) Max = sum;
			}
		}
	}
	cout << Max << endl; 
	return 0;
} 

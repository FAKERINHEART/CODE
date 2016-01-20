#include <iostream>

using namespace std;

void DFS(int** edge, int now, int N)
{
	for(int i = 0; i < N; i++)
	{
		if(edge[now][i] > 0)
		{
			edge[now][i]--;
			edge[i][now]--;
			DFS(edge, i, N);
		}
	}
	cout << now + 1 << " ";
	return;
}

int main()
{
	int N, M, v1, v2;
	cin >> N >> M;
	int** edge = new int*[N];
	for(int i = 0; i < N; i++)
	{
		edge[i] = new int[N];
		for(int j = 0; j < N; j++) edge[i][j] = 0;
	} 
	for(int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		edge[v1 - 1][v2 - 1]++;
		edge[v2 - 1][v1 - 1]++;
	}
	
	/*
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++) cout << edge[i][j] << " ";
		cout << endl;
	} 
	*/

	DFS(edge, 0, N);
	cout << endl;
	for(int i = 0; i < N; i++) delete[] edge[i];
	delete[] edge;
	return 0;
} 

#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 20000;

int main()
{
	int N, M;
	int rowH, columnH;
	cin >> N >> M;
	char arr[N][M];
	int dis[N][M];
	bool visited[N][M];
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 'H')
			{
				rowH = i;
				columnH = j;
			}
			dis[i][j] = 20000;
		}
	
	memset(visited, false, sizeof(visited)); 
	deque<pair<int, int> > _deq;
	_deq.push_back(make_pair(rowH, columnH));
	dis[rowH][columnH] = 0;
	visited[rowH][columnH] = true;
	
	int rowTemp, columnTemp;
	while(!_deq.empty())
	{
		rowTemp = _deq.front().first;
		columnTemp = _deq.front().second;
		
		if(rowTemp > 0 && !visited[rowTemp - 1][columnTemp])
		{
			if(arr[rowTemp - 1][columnTemp] == '.' || arr[rowTemp - 1][columnTemp] == 'S') dis[rowTemp - 1][columnTemp] = min(dis[rowTemp - 1][columnTemp], dis[rowTemp][columnTemp] + 1);
			if(arr[rowTemp - 1][columnTemp] == '.') _deq.push_back(make_pair(rowTemp - 1, columnTemp));
			visited[rowTemp - 1][columnTemp] = true;
		}
		if(rowTemp < N && !visited[rowTemp + 1][columnTemp])
		{
			if(arr[rowTemp + 1][columnTemp] == '.' || arr[rowTemp + 1][columnTemp] == 'S') dis[rowTemp + 1][columnTemp] = min(dis[rowTemp + 1][columnTemp], dis[rowTemp][columnTemp] + 1);
			if(arr[rowTemp + 1][columnTemp] == '.') _deq.push_back(make_pair(rowTemp + 1, columnTemp));
			visited[rowTemp + 1][columnTemp] = true;
		}
		if(columnTemp > 0 && !visited[rowTemp][columnTemp - 1])
		{
			if(arr[rowTemp][columnTemp - 1] == '.' || arr[rowTemp][columnTemp - 1] == 'S') dis[rowTemp][columnTemp - 1] = min(dis[rowTemp][columnTemp - 1], dis[rowTemp][columnTemp] + 1);
			if(arr[rowTemp][columnTemp - 1] == '.') _deq.push_back(make_pair(rowTemp, columnTemp - 1));
			visited[rowTemp][columnTemp - 1] = true;
		}
		if(columnTemp < M && !visited[rowTemp][columnTemp + 1])
		{
			if(arr[rowTemp][columnTemp + 1] == '.' || arr[rowTemp][columnTemp + 1] == 'S') dis[rowTemp][columnTemp + 1] = min(dis[rowTemp][columnTemp + 1], dis[rowTemp][columnTemp] + 1);
			if(arr[rowTemp][columnTemp + 1] == '.') _deq.push_back(make_pair(rowTemp, columnTemp + 1));
			visited[rowTemp][columnTemp + 1] = true;
		}
		_deq.pop_front();
	}
	/*
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++) cout << dis[i][j] << " ";
		cout << endl;
	}
	*/
	int flag = false;
	int MIN = 20000;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(arr[i][j] == 'S' && dis[i][j] < MAX)
			{
				if(i > 0 && arr[i - 1][j] == 'S' && dis[i - 1][j] < MAX)
				{
					MIN = min(MIN, dis[i][j] + dis[i - 1][j]);
					flag = true;
				}
				if(i < N && arr[i + 1][j] == 'S' && dis[i + 1][j] < MAX)
				{
					MIN = min(MIN, dis[i][j] + dis[i + 1][j]);
					flag = true;
				}
				if(j > 0 && arr[i][j - 1] == 'S' && dis[i][j - 1] < MAX)
				{
					MIN = min(MIN, dis[i][j] + dis[i][j - 1]);
					flag = true;
				}
				if(j < M && arr[i][j + 1] == 'S' && dis[i][j + 1] < MAX)
				{
					MIN = min(MIN, dis[i][j] + dis[i][j + 1]);
					flag = true;
				}
			}
		}
	}	
	
	if(flag) cout << MIN << endl;
	else cout << "Hi and Ho will not have lunch." << endl;	
	
	return 0;
}

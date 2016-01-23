#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

int N;
int temp[100001][2];
vector<int> MAP[100001];
long long dist[100001];
bool visited[100001];

struct node
{
	int sub;
	int cord;	
};

bool compare(const node& a, const node& b)
{
    return a.cord < b.cord;
}

long long bfs()
{
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= N; i++) dist[i] = 1 << 30;
	deque<int> deq;
	dist[1] = 0;
	visited[1] = true;
	deq.push_back(1);
	
	while(!deq.empty())
	{
		int front = deq.front();
		for(int i = 0; i < MAP[front].size(); i++)
		{
			int value = min(abs(temp[front][0] - temp[MAP[front][i]][0]), abs(temp[front][1] - temp[MAP[front][i]][1]));
			if(dist[MAP[front][i]] > dist[front] + value)
			{
				dist[MAP[front][i]] = dist[front] + value;
				if(!visited[MAP[front][i]])
				{
					visited[MAP[front][i]] = true;
					deq.push_back(MAP[front][i]);	
				}
			}
		}
		
		deq.pop_front();
		visited[front] = false;
	}
	
	return dist[N];
}

int main()
{
	cin >> N;
	node x[N + 1], y[N + 1];
	for(int i = 1; i <= N; i++)
	{
		cin >> temp[i][0] >> temp[i][1];
		x[i].sub = i;
		x[i].cord = temp[i][0];
		y[i].sub = i;
		y[i].cord = temp[i][1]; 
	}
	sort(x + 1, x + N + 1, compare);
	sort(y + 1, y + N + 1, compare);
	for(int i = 1; i < N; i++)
	{
		MAP[x[i].sub].push_back(x[i + 1].sub);
		MAP[x[i + 1].sub].push_back(x[i].sub);
		MAP[y[i].sub].push_back(y[i + 1].sub);
		MAP[y[i + 1].sub].push_back(y[i].sub);
	}
	cout << bfs() << endl;
	return 0;
}

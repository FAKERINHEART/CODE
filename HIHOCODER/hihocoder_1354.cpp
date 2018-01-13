#include <iostream>
#include <utility>
#include <cstring>
#include <deque>

using namespace std;

int A[501], B[501], dist[501][501];
pair<int, int> node[501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int calc_dist(int x, int y, int k)
{
    if (k == 0) return B[y];
    
    if (k == 1) return B[y - 1];
    
	if (k == 2) return A[x - 1];
	
	return A[x];
}

int main()
{
    int N, M, K, Q, x1, y1, x2, y2;
    cin >> N >> M;
    
    for (int i = 1; i < N; ++i) 
	{
        cin >> A[i];
    }
    
	for (int i = 1; i < M; ++i)
	{
		cin >> B[i];
    }
    
    cin >> K;
    
    for (int i = 1; i <= K; ++i)
	{
		cin >> node[i].first >> node[i].second;
    }
    
    cin >> Q;
    
    for (int i = 0; i < Q; ++i) 
	{
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int i = 1; i <= N; ++i)
        {
        	for (int j = 1; j <= M; ++j)
        	{
        		dist[i][j] = (1 << 20);
			}
		}
        
        for (int i = 1; i <= K; ++i) 
		{
            dist[node[i].first][node[i].second] = -1;
        }
        
        deque<pair<int, int> > q;
        dist[x1][y1] = 0;
		q.push_back(pair<int, int>(x1, y1));
		
        while(!q.empty())
		{
            pair<int, int> temp = q.front(); 
			q.pop_front();
            for (int i = 0; i < 4; ++i)
			{
                int nx = temp.first + dx[i];
                int ny = temp.second + dy[i];
                
                if (nx <= N && nx > 0 && ny <= M && ny > 0)
				{
					int temp_dist = calc_dist(temp.first, temp.second, i);
					
					if (dist[nx][ny] > dist[temp.first][temp.second] + temp_dist)
					{
						dist[nx][ny] = dist[temp.first][temp.second] + temp_dist;
						q.push_back(pair<int, int>(nx, ny));
					}
                }
            }
        }
        
        if (dist[x2][y2] == -1 || dist[x2][y2] == (1 << 20))
		{
			cout << -1 << endl;
        }
        else
        {
        	cout << dist[x2][y2] << endl;
		}
    }
    
    return 0;
}


#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N, M, x, y, ans = 2;
vector<vector<int> > map;
vector<vector<set<int> > > neigh;

void DFS(int x, int y,int preX, int preY, int val)
{
    if(x < 0 || x >= N || y < 0 || y >= M || map[x][y] != val|| neigh[x][y].count(preX * M + preY)) return;
    
    if(neigh[x][y].size() == 0) 
	{
		ans += 2;
	}
    else
	{
		ans -= 2;
	}
	
    neigh[preX][preY].insert(x * M + y);
    neigh[x][y].insert(preX * M + preY);
    
    DFS(x+1, y, x, y, val);
    DFS(x-1, y, x, y, val);
    DFS(x, y+1, x, y, val);
    DFS(x, y-1, x, y, val);
    
    return;
}

int main()
{
    cin >> N >> M >> x >> y;
    
    map.resize(N, vector<int>(M));
    neigh.resize(N, vector<set<int> >(M));
    
    for(int i = 0; i < N; ++i)
    {
    	for(int j =0; j < M; ++j)
        {
            cin >> map[i][j];
        }	
	}
        
    DFS(x, y, x, y, map[x][y]);
    
	cout << ans << endl;
    
	return 0;
} 

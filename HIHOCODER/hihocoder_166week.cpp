#include <iostream>
#include <deque>
#include <string>

using namespace std;

struct node
{
	node(int _x, int _y, int _status): x(_x), y(_y), status(_status){}
	int x;
	int y;
	int status;
};

int visited[100][100][64];
string str[100];
int direction[4][2]={-1,0,0,-1,1,0,0,1};
int N, M, K, sx, sy, ex, ey;

int bfs(int x, int y)
{
    visited[x][y][0] = 1;
    deque<node> dq;
    dq.push_back(node{x, y, 0});
    
    while(!dq.empty())
    {
        node now = dq.front();
		dq.pop_front();
		
        if(now.x == ex && now.y == ey)
		{
			return visited[now.x][now.y][now.status] - 1;
		}
        
		for(int i = 0; i < 4; ++i)
        {
        	int tempx = now.x + direction[i][0];
            int tempy = now.y + direction[i][1];
            
            if(tempx >= 0 && tempx < N && tempy >= 0 && tempy < M && str[tempx][tempy] != '#')
            {
                if(str[tempx][tempy] == '.' && visited[tempx][tempy][now.status] == 0)
                {
                    visited[tempx][tempy][now.status] = visited[now.x][now.y][now.status] + 1;
                    dq.push_back(node{tempx, tempy, now.status});
                }
                else if(str[tempx][tempy] >= '0' && str[tempx][tempy] <= '5')
                {
                    int tempstatus = now.status | (1 << (str[tempx][tempy] - '0'));
                    
                    if(visited[tempx][tempy][tempstatus] != 0)
					{
						continue;
					}
                    visited[tempx][tempy][tempstatus] = visited[now.x][now.y][now.status] + 1;
                    dq.push_back(node{tempx, tempy, tempstatus});
                }
                else if(str[tempx][tempy] >= 'A' && str[tempx][tempy] <= 'Z')
                {
                    if((now.status & (1 << (str[tempx][tempy]-'A'))) && visited[tempx][tempy][now.status] == 0)
                    {
                        visited[tempx][tempy][now.status] = visited[now.x][now.y][now.status] + 1;
                        dq.push_back(node{tempx, tempy, now.status});
                    }
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    cin >> N >> M >> K >> sx >> sy >> ex >> ey;
	 
    for(int i = 0; i < N; ++i) cin >> str[i];
    
	for(int i = 0; i < K; ++i)
    {
    	int tempx, tempy;
        
		cin >> tempx >> tempy;
        str[tempx][tempy] = (char)(i + '0');
    }
    
	cout << bfs(sx, sy) << endl;
	
    return 0;
}  

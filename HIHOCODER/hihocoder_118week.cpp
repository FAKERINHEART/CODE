#include <iostream>
#include <cstring>
#include <deque>
#include <set>

using namespace std;

int N, M;
int capacity[1200][1200];
int chart[501][501];
int source, terminal;

void EdmondsKarp()
{   
    deque<int> q;
    int flow[terminal + 1], pre[terminal + 1], MaxFlow = 0;
    while(1)
    {
        q.clear();
        for(int i = 0; i <= terminal; i++) pre[i] = -1;
        memset(flow, 0, sizeof(flow));

        pre[0] = 0;
        flow[0] = 1 << 30;

        int temp;
        q.push_back(0);
        while(!q.empty())
        {
            temp = q.front();

            if(temp == terminal) break;
            else
            {
                for(int i = 0; i <= terminal; i++)
                {
                    if(pre[i] == -1 && capacity[temp][i])
                    {
                        pre[i] = temp;
                        flow[i] = min(flow[temp], capacity[temp][i]);
                        q.push_back(i);
                    }
                }
            }
            q.pop_front();
        }

        if(pre[terminal] == -1) break;
        else
        {
            MaxFlow += flow[terminal];
            for(int i = terminal; i != source; i = pre[i])
            {
                capacity[pre[i]][i] -= flow[terminal];
                capacity[i][pre[i]] += flow[terminal];
            }
        }
    }
    int cnt = 0;
	for(int j = M + 1; j <= 2 * M; j++)
	{
		int flag = false;
		for(int i = 1; i <= M; i++)
		{
			chart[i][j - M] -= capacity[i][j];
			if(chart[i][j - M])
			{
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	cout << cnt << endl;
    return;
}

int main()
{
    while(cin >> M >> N)
    {
        memset(capacity, 0, sizeof(capacity));
		memset(chart, 0, sizeof(chart));
		
        int first, second;
        while(N--)
        {
            cin >> first >> second;
            capacity[first][second + M] = 1;
            chart[first][second] = 1;
        }
        for(int i = 1; i <= M; i++)	
		{
			capacity[0][i] = 1;
			capacity[M + i][2 * M + 1] = 1;
		}
        source = 0;
        terminal = 2 * M + 1;
        
        EdmondsKarp();
    }

    return 0;
}

#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int N, M;
int capacity[500][500];
int source, terminal;

void EdmondsKarp()
{   
    deque<int> q;
    int flow[M], pre[M], MaxFlow = 0;
    while(1)
    {
        q.clear();
        for(int i = 0; i < M; i++) pre[i] = -1;
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
                for(int i = 0; i < M; i++)
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
    cout << MaxFlow << endl;
    return;
}

int main()
{

    while(cin >> M >> N)
    {
        memset(capacity, 0, sizeof(capacity));

        int first, second, weight;
        while(N--)
        {
            cin >> first >> second >> weight;
            capacity[first - 1][second - 1] += weight;
        }
        source = 0;
        terminal = M - 1;

        EdmondsKarp();
    }

    return 0;
}


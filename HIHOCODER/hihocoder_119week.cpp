#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int P, Q;
int N, M;
int capacity[500][500];
int value[500];
int source, terminal;
int sum = 0;

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

    cout << sum - MaxFlow << endl;
    return;
}

int main()
{
	int temp, temp2;
	
	memset(capacity, 0, sizeof(capacity));
	memset(value, 0, sizeof(value));
	cin >> P >> Q;
	for(int i = 1; i <= Q; ++i) 
	{
		cin >> temp;
		capacity[P + i][P + Q + 1] = temp;
	}
	for(int i = 1; i <= P; ++i)
	{
		cin >> temp;
		capacity[0][i] = temp;
		sum += temp;
		cin >> temp;
		for(int j = 1; j <= temp; j++)
		{
			cin >> temp2;
			capacity[i][P + temp2] = 1 << 30;
		}
	}
	M = P + Q + 2;
	source = 0;
	terminal = M - 1;
	EdmondsKarp();
	
    return 0;
}


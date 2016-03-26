#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct event
{
	int t;
	int n;
	int x;
};

bool compare(const event& a, const event& b)
{
	if(a.t != b.t)
	{
		return (a.t < b.t);
	}
	else
	{
		return (a.x < b.x);
	}
}

int main()
{
	int CASE;
	cin >> CASE;
	while(CASE--)
	{
		int T, L, R, N, Q;
		cin >> T >> L >> R >> N >> Q;
		
		event e[2][2 * Q];
		int t, l, n, d;
		for(int i = 0; i < Q; i++)
		{
			cin >> t >> l >> n >> d;
			
			if(l < L)
			{
				e[d][i].t = t + l - L;
				e[d][i].n = n;
				e[d][i].x = 1;
				e[d][i + Q].t = t;
				e[d][i + Q].n = n;
				e[d][i + Q].x = -1;
			}
			else if(l == L)
			{
				e[d][i].t = t -1;
				e[d][i].n = n;
				e[d][i].x = 1;
				e[d][i + Q].t = t + 1;
				e[d][i + Q].n = n;
				e[d][i + Q].x = -1;
			}
			else if(l > L)
			{
				e[d][i].t = t;
				e[d][i].n = n;
				e[d][i].x = 1;
				e[d][i + Q].t = t + l - L;
				e[d][i + Q].n = n;
				e[d][i + Q].x = -1;
			}
			
			e[1 - d][i].t = t - L;
			e[1 - d][i].n = n;
			e[1 - d][i].x = 1;
			e[1 - d][i + Q].t = t + l;
			e[1 - d][i + Q].n = n;
			e[1 - d][i + Q].x = -1;
		}
		
		sort(e[0], e[0] + 2 * Q, compare);
		sort(e[1], e[1] + 2 * Q, compare);
		
		int time = T, direction = 0, sub[2] = {0};
		int lane[2][N];
		memset(lane, 0, sizeof(lane));
	
		bool found;
		while(R--)
		{
			found = false;
			while(sub[direction] < 2 * Q)
			{
				event& temp_e = e[direction][sub[direction]];
				if(temp_e.t < time)	lane[direction][temp_e.n] += temp_e.x;
				else
				{
					for(int j = 0; j < N; j++)
					{
						if(lane[direction][j] == 0) 
						{
							found = true;
							time = time + L;
							break;
						}
					}
					if(found) break;
					time = temp_e.t;
					lane[direction][temp_e.n] += temp_e.x;
				}
				sub[direction]++;
			}
			if (!found)	time += L;
			direction = 1 - direction;
		}
		cout << time << endl; 
	}
	return 0;
}

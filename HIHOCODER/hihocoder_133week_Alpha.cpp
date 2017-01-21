#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <deque>

using namespace std;

bool node[200][200];
bool reachable[200][200];

int main()
{
	int K;
	cin >> K;
	for(int l = 0; l < K; l++)
	{
		int N, M;
		cin >> N >> M;
		
		memset(node, false, sizeof(node));
		
		string s1, s2;
		int one[2], two[2];
		
		for(int i = 0; i < M; i++)
		{
			cin >> s1 >> s2;
			one[0] = 0;
			for(int j = 1; j < s1.length(); j++)
			{
				one[0] = one[0] * 10 + (s1[j] - '0');
			}
			one[0] -= 1;
			one[1] = one[0] + N;
			
			two[0] = 0;
			for(int j = 1; j < s2.length(); j++)
			{
				two[0] = two[0] * 10 + (s2[j] - '0');
			}
			two[0] -= 1;
			two[1] = two[0] + N;
			
			if(s1[0] == 'm' && s2[0] == 'm')//one0, two0
			{
				node[one[1]][two[0]] = true;
				node[two[1]][one[0]] = true;
			}
			else if(s1[0] == 'm' && s2[0] == 'h')//one0, two1
			{
				node[one[1]][two[1]] = true;
				node[two[0]][one[0]] = true;	
			} 
			else if(s1[0] == 'h' && s2[0] == 'm')//one1, two0
			{
				node[one[0]][two[0]] = true;
				node[two[1]][one[1]] = true;
			} 
			else if(s1[0] == 'h' && s2[0] == 'h')//one1, two1
			{
				node[one[0]][two[1]] = true;
				node[two[0]][one[1]] = true;
			} 
		}
		
		memset(reachable, false, sizeof(reachable));
		
		for(int i = 0; i < 2 * N; i++)
		{
			bool visited[200];
			memset(visited, 0, sizeof(visited));
			
			deque<int> q;
			q.push_back(i);
			visited[i] = true;
			while(!q.empty())
			{
				int x = q.front();
				for(int j = 0; j < 2 * N; ++j)
				{
					if(node[x][j] && !visited[j])
					{
						q.push_back(j);
						visited[j] = true;
					}
				}
				reachable[i][x] = true;
				q.pop_front();
			}
		}
		
		bool flag = true;
		for(int i = 0; i < N; i++)
		{
			if(reachable[i][i + N] && reachable[i + N][i])
			{
				flag = false;
				break;
			}
			if(!flag)
			{
				break;
			}
		}
		
		if(flag == true)
		{
			cout << "GOOD" << endl;
		}
		else
		{
			cout << "BAD" << endl;
		} 
	}
	
	return 0;
}

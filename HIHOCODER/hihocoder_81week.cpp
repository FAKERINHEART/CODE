#include <stdio.h> 
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

int N, M;
int nStart[100001];
vector<int> signalReceive[100001];
vector<int> signalSend[100001];
vector<int> Map[100001];
deque<int> deq;

int main()
{
	int nCase, signalTemp;
	scanf("%d", &nCase);
	while(nCase--)
	{	
		memset(nStart, 0, sizeof(nStart));
		for(int i = 0; i <= 100000; i++)	
		{
			signalReceive[i].clear();
			signalSend[i].clear();
			Map[i].clear();
		}
		deq.clear();

		scanf("%d%d", &N, &M);		
		for(int i = 0; i < M; i++) 
		{
			scanf("%d", &signalTemp);
			signalSend[0].push_back(signalTemp);
		}
		int n;
		for(int i = 1; i <= N; i++)
		{
			scanf("%d", &signalTemp);
			signalReceive[signalTemp].push_back(i);
			
			scanf("%d", &n);
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &signalTemp);
				signalSend[i].push_back(signalTemp);
			}
		}
		
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j < signalSend[i].size(); j++)
			{
				for(int k = 0; k < signalReceive[signalSend[i][j]].size(); k++)
				{
					Map[i].push_back(signalReceive[signalSend[i][j]][k]);
				}
			}
		}
		
		deq.push_back(0);
		while(!deq.empty())
		{
			for(int i = 0; i < Map[deq.front()].size(); i++)
			{
				nStart[Map[deq.front()][i]]++;
				deq.push_back(Map[deq.front()][i]);
			}
			deq.pop_front();
		}
		for(int i = 1; i <= N; i++) printf("%d ", nStart[i]);
		printf("\n");
	}
	return 0;
}

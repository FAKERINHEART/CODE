#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long A[100000], P[100000], S[100000];

struct Node
{
	int num;
	long long value;
	
	bool operator<(const Node &one)
	{
		return value > one.value;
	}
};

Node nodes[200000];

using namespace std;

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < M; ++i)
	{
		cin >> A[i];
	}
	
	for (int i = 0; i < M; ++i)
	{
		cin >> P[i];
	}
	
	for (int i = 0; i < M; ++i)
	{
		cin >> S[i];
	}
	
	int slot_num = 0;
	
	for (int i = 0; i < M; ++i)
	{
		if (A[i] / S[i] != 0)
		{
			nodes[slot_num].num = A[i] / S[i];
			nodes[slot_num].value = P[i] * S[i];
			++slot_num;
		}
		
		if (A[i] % S[i] != 0)
		{
			nodes[slot_num].num = 1;
			nodes[slot_num].value =  P[i] * (A[i] % S[i]);
			++slot_num;
		}
	}
	
	long long ret = 0;
	
	sort(nodes, nodes + slot_num);
	
	for (int i = 0; i < slot_num; ++i)
	{
		if (N == 0)
		{
			break;
		}
		else if (N > nodes[i].num)
		{
			ret += nodes[i].value * nodes[i].num;
			N -= nodes[i].num;
		}
		else
		{
			ret += nodes[i].value * N;
			N = 0;
		}
	}
	
	cout << ret << endl;
	
	return 0;
}

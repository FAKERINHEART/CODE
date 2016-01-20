#include <iostream>
#include <cstdio> 
#include <cmath> 
#include <deque>

using namespace std;

int data[1000000];

class Segment_Tree
{
public:
	int l;
	int r;
	int value_min;
	Segment_Tree* LSON;
	Segment_Tree* RSON;
	Segment_Tree(int left, int right):l(left), r(right), LSON(NULL), RSON(NULL){}	
};

void Build(int l, int r, Segment_Tree* &ST)
{
	ST = new Segment_Tree(l, r);
	if(l == r)
	{
		ST->value_min = data[l];
		return;
	}
	else
	{
		Segment_Tree* LST;
		Segment_Tree* RST;
		Build(l, (l + r) / 2, LST);
		Build((l + r) / 2 + 1, r, RST);
		ST->LSON = LST;
		ST->RSON = RST;
		ST->value_min = min(LST->value_min, RST->value_min);
		return;
	}
}

void PUT(Segment_Tree* ST)
{
	deque<Segment_Tree*> dq;
	dq.push_back(ST);
	while(!dq.empty())
	{
		cout << (dq.front())->l << " " << (dq.front())->r << " " << (dq.front())->value_min << endl;
		if((dq.front())->LSON) dq.push_back((dq.front())->LSON);
		if((dq.front())->RSON) dq.push_back((dq.front())->RSON);
		dq.pop_front();
	}
}



int QUERY(int l, int r, Segment_Tree* ST)
{
	if(ST->l == l && ST->r == r) return ST->value_min;
	else
	{
		int mid = (ST->l + ST->r) / 2;
		if(r <= mid) return QUERY(l, r, ST->LSON);
		else if(l > mid) return QUERY(l, r, ST->RSON);
		else return min(QUERY(l, mid, ST->LSON), QUERY(mid + 1, r, ST->RSON));
	}
}

void UPDATE(int sub, int value, Segment_Tree* ST)
{
	if(ST->l == sub && ST->r == sub)
	{
		ST->value_min = value;
		return;
	}
	else
	{
		int mid = (ST->l + ST->r) / 2;
		if(sub <= mid) UPDATE(sub, value, ST->LSON);
		else UPDATE(sub, value, ST->RSON);
		ST->value_min = min(ST->LSON->value_min, ST->RSON->value_min);
		return;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &data[i]);
	Segment_Tree* ROOT;
	Build(0, N - 1, ROOT);
	//PUT(ROOT);
	int NUM, one, two, three;
	scanf("%d", &NUM);
	for(int i = 0; i < NUM; i++)
	{
		scanf("%d%d%d", &one, &two, &three);
		if(!one) printf("%d\n", QUERY(two - 1, three - 1, ROOT));
		else UPDATE(two - 1, three, ROOT);
	}
	return 0;
}

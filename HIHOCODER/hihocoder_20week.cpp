#include <iostream>
#include <cstdio> 
#include <cmath> 
#include <deque>

using namespace std;

int data[100000];

class Segment_Tree
{
public:
	int l;
	int r;
	int length;
	long long value_sum;
	int lazy_tag; 
	Segment_Tree* LSON;
	Segment_Tree* RSON;
	Segment_Tree(int left, int right):l(left), r(right), LSON(NULL), RSON(NULL), lazy_tag(-1), length(right - left + 1){}	
};

void Build(int l, int r, Segment_Tree* &ST)
{
	ST = new Segment_Tree(l, r);
	if(l == r)
	{
		ST->value_sum = data[l];
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
		ST->value_sum = LST->value_sum + RST->value_sum;
		return;
	}
}

void PUT(Segment_Tree* ST)
{
	deque<Segment_Tree*> dq;
	dq.push_back(ST);
	while(!dq.empty())
	{
		cout << (dq.front())->l << " " << (dq.front())->r << " " << (dq.front())->value_sum << " " << (dq.front())->lazy_tag << endl;
		if((dq.front())->LSON) dq.push_back((dq.front())->LSON);
		if((dq.front())->RSON) dq.push_back((dq.front())->RSON);
		dq.pop_front();
	}
}

long long QUERY(int l, int r, Segment_Tree* ST)
{
	if(ST->l == l && ST->r == r) return ST->value_sum;
	else
	{
		if(ST->lazy_tag != -1)
		{
			ST->LSON->lazy_tag = ST->lazy_tag;
			ST->LSON->value_sum = ST->lazy_tag * ST->LSON->length;
			ST->RSON->lazy_tag = ST->lazy_tag;
			ST->RSON->value_sum = ST->lazy_tag * ST->RSON->length;
			ST->lazy_tag = -1;
		}
		
		int mid = (ST->l + ST->r) / 2;
		if(r <= mid) return QUERY(l, r, ST->LSON);
		else if(l > mid) return QUERY(l, r, ST->RSON);
		else return (QUERY(l, mid, ST->LSON) + QUERY(mid + 1, r, ST->RSON));
	}
}

void UPDATE(int l, int r, int value, Segment_Tree* ST)
{
	if(ST->l == l && ST->r == r)
	{
		ST->value_sum = ST->length * value;
		ST->lazy_tag = value;
		return;
	}
	else
	{
		if(ST->lazy_tag != -1)
		{
			ST->LSON->lazy_tag = ST->lazy_tag;
			ST->LSON->value_sum = ST->LSON->length * ST->lazy_tag;
			ST->RSON->lazy_tag = ST->lazy_tag;
			ST->RSON->value_sum = ST->RSON->length * ST->lazy_tag;
			ST->lazy_tag = -1;
		}
		int mid = (ST->l + ST->r) / 2;
		if(r <= mid) UPDATE(l, r, value, ST->LSON);
		else if(l > mid) UPDATE(l, r, value, ST->RSON);
		else 
		{
			UPDATE(l, mid, value, ST->LSON);
			UPDATE(mid + 1, r, value, ST->RSON);
		}
		ST->value_sum = ST->LSON->value_sum + ST->RSON->value_sum;
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
	int NUM, one, two, three, four;
	scanf("%d", &NUM);
	for(int i = 0; i < NUM; i++)
	{
		scanf("%d", &one);
		if(!one)
		{
			scanf("%d%d", &two, &three);
			printf("%lld\n", QUERY(two - 1, three - 1, ROOT));
		} 
		else 
		{
			scanf("%d%d%d", &two, &three, &four);
			UPDATE(two - 1, three - 1, four, ROOT);
		}
	}
	return 0;
}

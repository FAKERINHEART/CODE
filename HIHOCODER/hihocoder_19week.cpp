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
};

Segment_Tree ST[4000000];
 
void Build(int l, int r, int now)
{
	ST[now].l = l;
	ST[now].r = r;
	if(l == r)
	{
		ST[now].value_min = data[l];
		return;
	}
	else
	{
		Build(l, (l + r) / 2, 2 * now + 1);
		Build((l + r) / 2 + 1, r, 2 * now + 2);
		ST[now].value_min = min(ST[2 * now + 1].value_min, ST[2 * now + 2].value_min);
		return;
	}
}

void PUT(int N)
{
	for(int i = 0; i < 4 * N; i++ ) cout << i << ": " << ST[i].l << " " << ST[i].r << " " << ST[i].value_min << endl;
}

int QUERY(int l, int r, int now)
{
	if(ST[now].l == l && ST[now].r == r) return ST[now].value_min;
	else
	{
		int mid = (ST[now].l + ST[now].r) / 2;
		if(r <= mid) return QUERY(l, r, 2 * now + 1);
		else if(l > mid) return QUERY(l, r, 2 * now + 2);
		else return min(QUERY(l, mid, 2 * now + 1), QUERY(mid + 1, r, 2 * now + 2));
	}
}

void UPDATE(int sub, int value, int now)
{
	if(ST[now].l == sub && ST[now].r == sub)
	{
		ST[now].value_min = value;
		return;
	}
	else
	{
		int mid = (ST[now].l + ST[now].r) / 2;
		if(sub <= mid) UPDATE(sub, value, 2 * now + 1);
		else UPDATE(sub, value, 2 * now + 2);
		
		ST[now].value_min = min(ST[2 * now + 1].value_min, ST[2 * now + 2].value_min);
		return;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &data[i]);
	Build(0, N - 1, 0);
	//PUT(N);
	int NUM, one, two, three;
	scanf("%d", &NUM);
	for(int i = 0; i < NUM; i++)
	{
		scanf("%d%d%d", &one, &two, &three);
		if(!one) printf("%d\n", QUERY(two - 1, three - 1, 0));
		else UPDATE(two - 1, three, 0);
	}
	return 0;
}

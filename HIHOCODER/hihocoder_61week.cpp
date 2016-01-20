#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
char data[50001];
int p = 0;

class Segment_Tree
{
public:
	int l;
	int r;
	int same;
	int add;
	int inc;
};

Segment_Tree ST[50000 >> 2];

void Build(int l, int r, int now)
{
	ST[now].l = l;
	ST[now].r = r;
	ST[now].add = 0;
	ST[now].inc = 0;
	
	if(l == r)
	{
		ST[now].same = data[l] - 'A';
		return;
	}
	else
	{
		Build(l, (l + r) / 2, 2 * now + 1);
		Build((l + r) / 2 + 1, r, 2 * now + 2);
		ST[now].same = -1;
		return;
	}
}

void PUT(int N)
{
	for(int i = 0; i < 4 * N; i++ ) 
		cout << i << ": " << ST[i].l << " " << ST[i].r << " " << ST[i].add << " " << ST[i].inc << " " << ST[i].same << endl;
}


void QUERY(int now)
{
	if(ST[now].l == ST[now].r)
	{
		if(ST[now].same != -1) data[ST[now].l] = ST[now].same + 'A';
		data[ST[now].l] = (data[ST[now].l] + ST[now].add - 'A') % 26 + 'A';
		return;
	}
	if(ST[now].same != -1)
	{
		ST[2 * now + 1].same = ST[now].same;
		ST[2 * now + 2].same = ST[now].same;
	}
	int mid = (ST[now].l + ST[now].r) / 2;
	ST[2 * now + 1].add += ST[now].add;
	ST[2 * now + 1].inc += ST[now].inc;
	ST[2 * now + 2].add += (ST[now].add + (mid + 1 - ST[now].l) * ST[now].inc);
	ST[2 * now + 2].inc += ST[now].inc;
	QUERY(2 * now + 1);
	QUERY(2 * now + 2);
}

void UPDATE(int l, int r, int type, int add, int inc, int now)
{
	if(l <= r)
	{
		if(ST[now].l == l && ST[now].r == r)
		{
			if(type == 1)
			{
				ST[now].same = add;
				ST[now].add = 0;
				ST[now].inc = 0;
			}
			else if(type == 2 || type == 4)
			{
				ST[now].add += add;
				ST[now].inc += inc; 
			}
		}
		else
		{
			int mid = (ST[now].l + ST[now].r) / 2;
			if(ST[now].same != -1)
			{
				ST[2 * now + 1].same = ST[now].same;
				ST[2 * now + 2].same = ST[now].same;
			} 
			ST[2 * now + 1].add += ST[now].add;
			ST[2 * now + 1].inc += ST[now].inc;
			ST[2 * now + 2].add += (ST[now].add + (mid + 1 - ST[now].l) * ST[now].inc);
			ST[2 * now + 2].inc += ST[now].inc;
			ST[now].same = -1;
			ST[now].add = 0;
			ST[now].inc = 0;
			
			if(r <= mid) UPDATE(l, r, type, add, inc, 2 * now + 1);
			else if(l > mid) UPDATE(l, r, type, add, inc, 2 * now + 2);
			else
			{
				if(type == 1)
				{
					UPDATE(l, mid, type, add, inc, 2 * now + 1);
					UPDATE(mid + 1, r, type, add, inc, 2 * now + 2);
				}
				else if(type == 2 || type == 4)
				{
					UPDATE(l, mid, type, add, inc, 2 * now + 1);
					UPDATE(mid + 1, r, type, add + (mid + 1 - l) * inc, inc, 2 * now + 2);
				}
			}
		}
	}
	else
	{
		UPDATE(l, N - 1, type, add, inc, now);
		if(type == 1) UPDATE(0, r, type, add, inc, now);
		else if(type == 2 || type == 4) UPDATE(0, r, type, add + (N - l) * inc, inc, now);
	}
}


int main()
{
	scanf("%d%d", &N, &M);
	scanf("%s", data);
	Build(0, N - 1, 0);
	//PUT(N);
	
	int one, two, three, four;
	char a;
	char temp[4];
	for(int i = 0; i < M; i++)
	{
		scanf("%s", temp);
		scanf("%d", &one);
		if(one == 1)
		{
			scanf("%d %d %c", &two, &three, &a);
			UPDATE((two - 1 + p) % N, (three - 1 + p) % N, 1, a - 'A', 0, 0);	
		 }
		else if(one == 2)
		{
			scanf("%d %d %d", &two, &three, &four);
			UPDATE((two - 1 + p) % N, (three - 1 + p) % N, 2, four, 0, 0);
		}
		else if(one == 3)
		{
			scanf("%d", &two);
			p = (p + two) % N;
		}
		else if(one == 4)
		{
			scanf("%d %d", &two, &three);
			UPDATE((two - 1 + p) % N, (three - 1 + p) % N, 4, 1, 1, 0);
		}
	}
	QUERY(0);
	for(int i = 0; i < N; i++) cout << data[(i + p) % N];
	cout << endl;
	return 0;
}

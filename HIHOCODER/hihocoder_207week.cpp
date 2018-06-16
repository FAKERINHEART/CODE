#include <iostream>
#include <algorithm>

struct node
{
	int a;
	int b;
	
	bool operator<(const node two)
	{
		if (a < two.a)
		{
			return true;
		}
		else if (a == two.a && b < two.b)
		{
			return true;
		}
		
		return false;
	}
};

int N = 0;
node nodes[24];

void init(int a, int b, int c, int d)
{
	if (a * 10 + b <= 23 && c * 10 + d <= 59 || a * 10 + b == 24 && c * 10 + d == 0)
	{
		nodes[N].a = a * 10 + b;
		nodes[N].b = c * 10 + d;
		++N;
	}
	
	return;
}

int main()
{
	int A, B, C, D;
	
	std::cin >> A >> B >> C >> D;
	
	init(A, B, C, D);
	init(A, B, D, C);
	init(A, C, B, D);
	init(A, C, D, B);
	init(A, D, B, C);
	init(A, D, C, B);
	
	init(B, A, C, D);
	init(B, A, D, C);
	init(B, C, A, D);
	init(B, C, D, A);
	init(B, D, A, C);
	init(B, D, C, A);
	
	init(C, B, A, D);
	init(C, B, D, A);
	init(C, A, B, D);
	init(C, A, D, B);
	init(C, D, B, A);
	init(C, D, A, B);
	
	init(D, B, C, A);
	init(D, B, A, C);
	init(D, C, B, A);
	init(D, C, A, B);
	init(D, A, B, C);
	init(D, A, C, B);
	
	if (N == 0)
	{
		printf("NOT POSSIBLE\n");
	}
	else
	{
		std::sort(nodes, nodes + N);
	
		printf("%02d:%02d\n", nodes[N - 1].a, nodes[N - 1].b);
	}
	
	//for 
	
	return 0;
}

#include <iostream>

using namespace std;

long long numCatalan[22];//卡特兰数 

void visit(int nNode, long long n)
{
	if(nNode == 1) cout << "X";
	else if(n <= numCatalan[nNode - 1])
	{
		cout << "X";
		
		cout << "(";
		visit(nNode - 1, n);
		cout << ")";
	}
	else if(n > numCatalan[nNode] - numCatalan[nNode - 1])
	{
		cout << "(";
		visit(nNode - 1, n - (numCatalan[nNode] - numCatalan[nNode - 1]));
		cout << ")";
		
		cout << "X";
	}
	else
	{
		int nNodeSub;
		for(int i = nNode - 1; i >= 0; i--)
		{
			if(n > numCatalan[i] * numCatalan[nNode - 1 - i]) n -= numCatalan[i] * numCatalan[nNode - 1 - i];
			else
			{
				nNodeSub = i;
				break;
			}
		}
		
		cout << "(";
		visit(nNode - 1 - nNodeSub, n / numCatalan[nNodeSub] + (n % numCatalan[nNodeSub] != 0));
		cout << ")";
		
		cout << "X";
		
		cout << "(";
		visit(nNodeSub, (n - 1) % numCatalan[nNodeSub] + 1);
		cout << ")";
	}
	
	return;
}

int main()
{
	//初始化卡特兰数	
	numCatalan[0] = 1;
	for(int i = 1; i <= 21; i++) numCatalan[i] = numCatalan[i - 1] * (4 * i - 2) / (i + 1);
	
	long long n;
	int nNode;
	while(cin >> n)
	{
		if(!n) break;
		for(int i = 1; i <= 21; i++)
		{
			if(n > numCatalan[i]) n -= numCatalan[i];
			else
			{
				nNode = i;
				break;
			}
		}
		visit(nNode, n);
		cout << endl;
	}
	return 0;
} 

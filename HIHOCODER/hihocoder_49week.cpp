#include <iostream>

using namespace std;

class node
{
	public:
		node()
		{
			degree = 0;
		}
		int degree;
};


int main()
{
	int N, M, u, v;
	cin >> N >> M;
	node* _node = new node[N];
	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		_node[u - 1].degree++;
		_node[v - 1].degree++;
	}
	int num = 0;
	for(int i = 0; i < N; i++) if(_node[i - 1].degree % 2) num++;
	if(num == 0 || num == 2) cout << "Full" << endl;
	else cout << "Part" << endl;
	
	delete[] _node;
	return 0;	
} 

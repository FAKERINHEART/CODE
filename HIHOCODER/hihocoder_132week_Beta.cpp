#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <deque>

using namespace std;


class edge;

class node
{
public:
	int dfs_low;
	int dfs_level;
	bool in_stack;
	edge* first;
	node()
	{
		dfs_level = 0;
		in_stack = false;
		first = NULL;
	}
};

class edge
{
public:
	int sub;
	edge* next;
	edge(int s)
	{
		sub = s;
		next = NULL;
	}
};

node* _node;
int order_level = 0;
vector<int> stack_group;
int group[20000];
int key;

void dfs(int sub)
{
	order_level++;
	_node[sub].dfs_level = _node[sub].dfs_low = order_level;
	stack_group.push_back(sub);
	_node[sub].in_stack = true;
	edge* p = _node[sub].first;
	while(p)
	{
		if(!_node[p->sub].dfs_level)
		{
			dfs(p->sub);
			_node[sub].dfs_low = min(_node[p->sub].dfs_low, _node[sub].dfs_low);
		}
		else if(_node[p->sub].in_stack) _node[sub].dfs_low = min(_node[p->sub].dfs_level, _node[sub].dfs_low);
		p = p->next;
	}
	
	if(_node[sub].dfs_level == _node[sub].dfs_low)
	{
		++key;
		vector<int>::reverse_iterator riter = stack_group.rbegin();
		while(*riter != sub)
		{
			_node[*riter].in_stack = false;
			group[*riter] = key; 
			stack_group.pop_back();			
			riter++;
		}
		_node[*riter].in_stack = false;
		group[*riter] = key;
		stack_group.pop_back();
	}
	return;
}


int main()
{
	int K;
	cin >> K;
	while(K--)
	{
		int N, M;
		cin >> N >> M;
		
		_node = new node[2 * N];
		
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
			
			//cout << one[0] << " " << one[1] << endl;
			//cout << two[0] << " " << two[1] << endl;
			
			if(s1[0] == 'm' && s2[0] == 'm')//one0, two0
			{
				edge* temp = new edge(two[0]);
				temp->next = _node[one[1]].first;
				_node[one[1]].first = temp;
				
				temp = new edge(one[0]);
				temp->next = _node[two[1]].first;
				_node[two[1]].first = temp;
			}
			else if(s1[0] == 'm' && s2[0] == 'h')//one0, two1
			{
				edge* temp = new edge(two[1]);
				temp->next = _node[one[1]].first;
				_node[one[1]].first = temp;
				
				temp = new edge(one[0]);
				temp->next = _node[two[0]].first;
				_node[two[0]].first = temp;
			} 
			else if(s1[0] == 'h' && s2[0] == 'm')//one1, two0
			{
				edge* temp = new edge(two[0]);
				temp->next = _node[one[0]].first;
				_node[one[0]].first = temp;
				
				temp = new edge(one[1]);
				temp->next = _node[two[1]].first;
				_node[two[1]].first = temp;
			} 
			else if(s1[0] == 'h' && s2[0] == 'h')//one1, two1
			{
				edge* temp = new edge(two[1]);
				temp->next = _node[one[0]].first;
				_node[one[0]].first = temp;
				
				temp = new edge(one[1]);
				temp->next = _node[two[0]].first;
				_node[two[0]].first = temp;
			} 
		}
		
		for(int i = 0; i < 2 * N; i++)
		{
			if(!_node[i].dfs_level)
			{
				dfs(i);
			}
		}
		
		bool group_more_than_one = true;
		
		for(int i = 0; i < N; i++)
		{
			if(group[i] == group[i + N])
			{
				group_more_than_one = false;
				break;	
			}
			//cout << i << ": " << group[i] << endl;
		}
		
		if(group_more_than_one == true)
		{
			cout << "GOOD" << endl;
		}
		else
		{
			cout << "BAD" << endl;
		} 
		
		order_level = 0;
		stack_group.clear();
		delete [] _node;
	}


	return 0;
}

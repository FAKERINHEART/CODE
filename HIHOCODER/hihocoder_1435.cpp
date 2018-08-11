#include <iostream>
#include <vector>

enum VISIT_STATUS
{
	E_UNVISITED = 0,
	E_VISITING = 1,
	E_VISITED = 2,
};

struct Node
{
	VISIT_STATUS visit_status;
	std::vector<int> next_nodes;

	Node()
	{
		visit_status = E_UNVISITED;
		next_nodes.clear();
	}
};

std::vector<Node> v_node;

bool dfs(int now_node)
{
	if (v_node[now_node].visit_status == E_VISITING)
	{
		return true;
	}
	
	v_node[now_node].visit_status = E_VISITING;
	
	for (int i = 0; i < v_node[now_node].next_nodes.size(); ++i)
	{
		int next_node = v_node[now_node].next_nodes[i];
		
		if (v_node[next_node].visit_status == E_UNVISITED)
		{
			if (dfs(next_node) == true)
			{
				return true;
			}
		}
		else if (v_node[next_node].visit_status == E_VISITING)
		{
			return true;
		}
	}
	
	v_node[now_node].visit_status = E_VISITED;
	
	return false;
}

int main()
{
	int T;
	
	std::cin >> T;
	
	while(T--)
	{
		int N, M;
	
		std::cin >> N >> M;
		
		v_node.clear();
		
		for (int i = 0; i < N; ++i)
		{
			v_node.push_back(Node());
		}
		
		for (int i = 0; i < M; ++i)
		{
			int from_node, to_node;
			
			std::cin >> from_node >> to_node;
			v_node[from_node - 1].next_nodes.push_back(to_node - 1);
		}
		
		bool ret = false;
		
		for (int i = 0; i < N; ++i)
		{
			if (v_node[i].visit_status == E_UNVISITED)
			{
				ret = dfs(i);
	
				if (ret == true)
				{
					break;
				}
			}
		}
		
		if (ret == true)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0;
}

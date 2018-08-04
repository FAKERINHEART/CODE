#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

struct Node
{
	std::string str;
	int num;
	
	bool operator<(const Node &one)
	{
		if (str < one.str)
		{
			return true;
		}
		else if (str == one.str)
		{
			if (num < one.num)
			{
				return true;
			}
		}
		
		return false;
	}
};

Node nodes[100];

int main()
{
	int N;
	
	std::cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		std::string temp;
		
		std::cin >> temp;
		
		for (int j = 0; j < temp.length(); ++j)
		{
			if (temp[j] >= '0' && temp[j] <= '9')
			{
				nodes[i].str = temp.substr(0, j);
				nodes[i].num = atoi(temp.substr(j).c_str());
				
				break;
			}
		}
	}
	
	std::sort(nodes, nodes + N);
	
	for (int i = 0; i < N; ++i)
	{
		std::cout << nodes[i].str << nodes[i].num << std::endl;
	}

	return 0;
}

#include <iostream>
#include <string>
#include <map>

struct NODE
{
	int in_count;
	int out_count;
	NODE()
	{
		in_count = 0;
		out_count = 0;	
	}	
};

int main()
{
	int N;
	
	std::cin >> N;
	
	std::map<std::string, NODE> m;
	
	for (int i = 0; i < N; ++i)
	{
		std::string one, two;
		
		std::cin >> one >> two;
		
		++m[one].out_count;
		++m[two].in_count;
	}
	
	std::string begin, end;
	
	for (std::map<std::string, NODE>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		if (iter->second.in_count - iter->second.out_count == 1)
		{
			end = iter->first;
		}
		else if (iter->second.out_count - iter->second.in_count == 1)
		{
			begin = iter->first;
		}
	}
	
	std::cout << begin << " " << end << std::endl;
	
	return 0;
}

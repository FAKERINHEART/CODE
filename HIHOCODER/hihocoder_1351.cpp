#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<std::string, std::int32_t> m;
	std::int32_t N, M;
	
	std::cin >> N;
	
	for (std::int32_t i = 0; i < N; ++i)
	{
		std::cin >> M;
		std::map<std::string, bool> temp;
		
		for (std::int32_t j = 0; j < M; ++j)
		{
			std::string id, date, price;
			std::cin >> id >> date >> price;
			if (temp.find(id + price) == temp.end())
			{
				temp[id + price] = true;
			}
		}
		
		for (std::map<std::string, bool>::iterator iter = temp.begin(); iter != temp.end(); ++iter)
		{
			++m[iter->first];
		}
	}
	
	for (std::map<std::string, std::int32_t>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		if (iter->second == N)
		{
			std::cout << iter->first.substr(0, 9) << std::endl;
		} 
	}
	
	return 0;
} 

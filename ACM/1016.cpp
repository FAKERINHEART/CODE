#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	string str[16];
	map<char, int> m;
	stringstream ss;
	
	while(cin >> str[0])
	{
		if(str[0] == "-1") break;
		bool test = false;
		for(int i = 1; i <= 15; i++)
		{
			for(int j = 0; j < str[i - 1].length(); j++) ++m[str[i - 1][j]];
			map<char, int>::const_iterator iter = m.begin();
			while(iter != m.end())
			{
				ss << iter->second;
				str[i].append(ss.str());
				ss.str("");
				str[i].append(1, iter->first);
				++iter;
			}
			m.clear();
			
			if(str[i] == str[i - 1])
			{
				if(i - 1 == 0) cout << str[0] << " is self-inventorying" << endl;
				else cout << str[0] <<" is self-inventorying after " << i - 1 << " steps" << endl;
				test = true;
				break;
			}
			else if(i >= 2)
			{
				int j;
				for(j = i - 2; j >= 0; j--) if(str[i] == str[j]) break;
				if(j >= 0)
				{
					cout << str[0] << " enters an inventory loop of length " << i - j << endl;
					test = true;
					break;
				} 
			}
		}
		if(!test) cout << str[0] << " can not be classified after 15 iterations" << endl;
		
		for(int i = 1; i <= 15; i++) str[i].clear();
	}
	return 0;
}

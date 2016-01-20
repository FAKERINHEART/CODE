#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int N, M;
	int s = 0;
	map<string, int> m;
	cin >> N >> M;	
	string str[N];
	for(int i = 0; i < N; i++)
	{
		cin >> str[i];
		if(m.find(str[i]) == m.end())
		{
			cout << "Internet" << endl;
			if(m.size() == M) 
			{
				m.erase(m.find(str[s]));
				s++;
			}
		}
		else cout << "Cache" << endl;
		
		m[str[i]] = i;
		while(m.find(str[s])->second != s) s++;	
	}
	
	return 0;	
} 

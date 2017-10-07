#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using namespace std;

unordered_map<int, int> mother;
map<int, vector<int> > sons;
string names[10000];
int n;

int findMother(int one)
{
	if(mother[one] == one)
	{
		return one;
	}
	else
	{
		mother[one] = findMother(mother[one]);
		
		return mother[one];
	}
}

void Union(int first, int second)
{
	int m_first = findMother(first);
	int m_second = findMother(second);
	
	if(m_first > m_second)
	{
		mother[m_first] = m_second;
	}
	else if(m_first < m_second)
	{
		mother[m_second] = m_first;
	}
	
	return;
}

int main()
{
	cin >> n;
	
	unordered_map<string, vector<int> > email2nameindex;
	
	for(int i = 0; i < n; ++i)
	{
		cin >> names[i];
		mother[i] = i;
		
		int temp;
		cin >> temp;
		
		for(int j = 0; j < temp; ++j)
		{
			string email;
			cin >> email;
			
			int len = email2nameindex[email].size();
			
			for(int k = 0; k < len; ++k)
			{
				Union(email2nameindex[email][k], i);
			}
			email2nameindex[email].push_back(i);
		}
	}
	
	for(int i = 0; i < n ; ++i)
	{
		int m = findMother(i);
		sons[m].push_back(i); 
	}
	
	for(map<int, vector<int> >::iterator iter = sons.begin(); iter != sons.end(); ++iter)
	{
		cout << names[(iter->second)[0]];
		
		for(int i = 1; i < (iter->second).size(); ++i)
		{
			cout << " " << names[(iter->second)[i]];
		}
		cout << endl;
	}
	
	return 0;
}

#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

set<int> FIND(string& origin, string& sub)
{
	int start = 0;
	start = origin.find(sub, start);
	int len = sub.length();
	
	set<int> s;
	while(start != string::npos)
	{
		s.insert(start + len - 1);
		start = origin.find(sub, start + 1);
	}
	return s;
}

bool EQUAL(set<int>& one, set<int>& two)
{
	if(one.size() != two.size())
	{
		return false;
	}
	for(set<int>::iterator it1 = one.begin(), it2 = two.begin(); it1 != one.end() && it2 != two.end(); ++it1, ++it2)
	{
		if(*it1 != *it2)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	map<string, set<int> > m;
	
	string S;
	char tempS[100]; 
	int N;
	
	cin >> S;
	int len = S.length();	
	
	for(int i = 0; i < len; ++i)
	{
		for(int j = i; j < len; ++j)
		{
			string temp = S.substr(i, j - i + 1);
			map<string, set<int> >::iterator it = m.find(temp);
			if(it == m.end())
			{
				m[temp] = FIND(S, temp);
			}
		}
	}
	
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> S;
		set<string> sStr;
		
		for(map<string, set<int> >::iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			if(EQUAL(iter->second, m[S]) == true)
			{
				sStr.insert(iter->first);
			}
		}
		string shortStr = *sStr.begin(), longStr = *sStr.begin();
		for(set<string>::iterator iter = sStr.begin(); iter != sStr.end(); ++iter)
		{
			if(iter->length() < shortStr.length())
			{
				shortStr = *iter;
			}
			
			if(iter->length() > longStr.length())
			{
				longStr = *iter;
			}
		}
		cout << shortStr << " " << longStr << " ";
		
		for(set<int>::iterator iter = m[S].begin(); iter != m[S].end(); ++iter)
		{
			cout << *iter + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
} 

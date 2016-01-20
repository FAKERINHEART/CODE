#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class trie
{
public:
	trie():count(0){memset(next, 0, sizeof(next)); }
	int count;
	trie* next[26];
};

int main()
{
	int n, m;
	cin >> n;
	string str;
	trie* root = new trie(), * p;
	while(n--)
	{
		p = root;
		cin >> str;
		for(int i = 0; i < str.length(); i++)
		{
			if(p->next[str[i] - 'a']) p->next[str[i] - 'a']->count++;
			else
			{
				p->next[str[i] - 'a'] = new trie();
				p->next[str[i] - 'a']->count = 1;
			}
			p = p->next[str[i] - 'a'];
		}
	}
	
	cin >> m;
	while(m--)
	{
		p = root;
		cin >> str;
		int i;
		for(i = 0; i < str.length(); i++)
		{
			if(!p->next[str[i] - 'a']) break;
			else p = p->next[str[i] - 'a'];
		}
		if(i == str.length()) cout << p->count << endl;
		else cout << 0 << endl;
	}
	
	return 0;
}

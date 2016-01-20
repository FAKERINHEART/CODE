#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class TrieNode
{
public:
	TrieNode(): count(0){memset(next, 0, sizeof(next));}
	int count;
	TrieNode* next[26];	
};

int dfs(TrieNode *p)
{
	if(p->count > 0 && p->count <= 5) return 1;
	else
	{
		int sum = 0;
		for(int i = 0; i < 26; i++)	if(p->next[i]) sum += dfs(p->next[i]);
		return sum;
	}
}

int main()
{
	int N;
	cin >> N;
	TrieNode *root = new TrieNode(), *p;
	string str;
	while(N--)
	{
		p = root;
		cin >> str;
		for(int i = 0; i < str.length(); i++)
		{
			if(!p->next[str[i] - 'a']) p->next[str[i] - 'a'] = new TrieNode();
			p->next[str[i] - 'a']->count++;
			p = p->next[str[i] - 'a'];
		}
	}
	cout << dfs(root) << endl;
	return 0;
} 

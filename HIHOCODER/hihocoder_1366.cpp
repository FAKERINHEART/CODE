#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct TrieNode
{
	bool is_end;
	TrieNode *next[26];
	
	TrieNode()
	{
		is_end = false;
		memset(next, 0, sizeof(next));
	}
	~TrieNode()
	{
		for (int i = 0; i < 26; ++i)
		{
			if (next[i] != NULL)
			{
				delete next[i];
			}
		}
	}
};

void build(TrieNode *root, const string &str)
{
	TrieNode *p = root;
	
	for (int i = 0; i < str.length(); ++i)
	{
		if (p->next[str[i] - 'a'] == NULL)
		{
			p->next[str[i] - 'a'] = new TrieNode();
		}
		
		p = p->next[str[i] - 'a'];
	}
	
	p->is_end = true;
	
	return;
}

bool check(TrieNode *root, const string &str)
{
	TrieNode *p = root;
	
	for (int i = 0; i < str.length(); ++i)
	{
		if (p->next[str[i] - 'a'] == NULL)
		{
			return false;
		}
		
		p = p->next[str[i] - 'a'];
	}
	
	return p->is_end;
}

int main()
{
	int N;
	cin >> N;
	
	TrieNode *root = new TrieNode();
	
	string str;
	
	int count = 0;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		
		build(root, str);
		
		reverse(str.begin(), str.end());
		count += check(root, str);
	}
	
	cout << count << endl; 
	
	delete root;
	
	return 0;
}

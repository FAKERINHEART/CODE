#include <iostream>
#include <cstring>

using namespace std;

struct trie
{
	int index;
	int next[2];
	int flag;
	trie()
	{
		index = -1;
		next[0] = -1;
		next[1] = -1;
		flag = -1;
	}
};

trie t[3200010];
int count, N, M;

void add(long long ip, int mask, int flag, int index)
{
	int now = 1;
	
	for(int i = 31; i >= 32 - mask; --i)
	{
		int k = ((ip & (1 << i)) >> i);
		
		if(t[now].next[k] == -1)
		{
			++count;
			t[now].next[k] = count;
		}
		
		now = t[now].next[k];
	}
	
	if(t[now].index == -1)
	{
		t[now].index = index;
		t[now].flag = flag;
	}
	//cout << flag << endl;
	//cout << now << ": " << t[now].index << "|" << t[now].flag << endl;
	
	return;
}

bool query(long long ip)
{
	int now = 1, index = -1, flag;
	
	for(int i = 31; i >= 0; --i)
	{
		if(t[now].index != -1)
		{
			if(index == -1 || index > t[now].index)
			{
				index = t[now].index;
				flag = t[now].flag;
			}
		}
		
		int k = ((ip & (1 << i)) >> i);
		
		if(t[now].next[k] == -1)
		{
			break;
		}
		
		now = t[now].next[k];
	}
	
	if(index == -1)
	{
		return true;
	}
	else
	{
		return flag;
	}
}

int main()
{
	cin >> N >> M;
	count = 1;
	
	int mask;
	char operation;
	string x;
	long long ip1, ip2, ip3, ip4;
	
	for(int i = 1; i <= N; ++i)
	{
		cin >> x;
		scanf("%lld.%lld.%lld.%lld%c", &ip1, &ip2, &ip3, &ip4, &operation);
		if(operation == '/')
		{
			cin >> mask;
		}
		else
		{
			mask = 32;
		}
		
		long long res = (ip1 << 24) + (ip2 << 16) + (ip3 << 8) + ip4;
		
		if(x == "allow")
		{
			add(res, mask, 1, i);
		}
		else
		{
			add(res, mask, 0, i);
		}
	}
	
	for(int i = 1; i <= M; ++i)
	{
		scanf("%lld.%lld.%lld.%lld", &ip1, &ip2, &ip3, &ip4);
		
		long long res = (ip1 << 24) + (ip2 << 16) + (ip3 << 8) + ip4;
		
		if(query(res))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}

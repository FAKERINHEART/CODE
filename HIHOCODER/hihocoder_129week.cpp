#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXL = 1000000;
string S;//字符串S 
int n;//当前的状态序号
int maxlen[2 * MAXL + 10];//每个状态中字符串的最大长度 
int minlen[2 * MAXL + 10];//每个状态中字符串的最小长度 
bool numEndPosAddOne[2 * MAXL + 10];//endposition的个数是不是它们子节点之和加1 
int numEndPos[2 * MAXL + 10];//endposition的个数 
int transition[2 * MAXL + 10][26];//状态转换表
int suffixlink[2 * MAXL + 10];//向前的状态连接
int inDegree[2 * MAXL + 10];//每个状态suffixlink的入度 

int new_status(int _maxlen, int _minlen, int* _trans, int _slink, bool addOne)
{
	maxlen[n] = _maxlen;
	minlen[n] = _minlen;
	numEndPosAddOne[n] = addOne;
	if(addOne == true)
	{
		numEndPos[n] = 1;
	}
	else
	{
		numEndPos[n] = 0;
	}
	for(int i = 0; i < 26; ++i)
	{
		if(_trans == NULL)
		{
			transition[n][i] = -1;
		}
		else
		{
			transition[n][i] = _trans[i];
		}
	}
	suffixlink[n] = _slink;
	
	return n++;
}

int add_char(char ch, int st) //ch: 要加入的新字符, st: 上一个字符的状态序号 
{
	int c = ch - 'a';
	int z = new_status(maxlen[st] + 1, -1, NULL, -1, true);
	int v = st;
	while(v != -1 && transition[v][c] == -1)
	{
		transition[v][c] = z;
		v = suffixlink[v];
	}
	
	if(v == -1)//当所有向前的状态连接在之前都没有向c状态转移时 
	{
		minlen[z] = 1;
		suffixlink[z] = 0;
		return z;
	}
	
	int x = transition[v][c];
	if(maxlen[v] + 1 == maxlen[x])//当第一个向前的状态连接在之前有向c状态转移时, 但是其最长字符串长度加1等于状态转移以后的最长字符串长度 
	{
		minlen[z] = maxlen[x] + 1;
		suffixlink[z] = x;
		return z;
	}
	//当第一个向前的状态连接在之前有向c状态转移时, 但是其最长字符串长度加1不等于状态转移以后的最长字符串长度 
	int y = new_status(maxlen[v] + 1, -1, transition[x], suffixlink[x], false);
	suffixlink[y] = suffixlink[x];
	
	minlen[x] = maxlen[y] + 1; 
	suffixlink[x] = y;
	minlen[z] = maxlen[y] + 1;
	suffixlink[z] = y;
	
	int w = v;
	while(w != -1 && transition[w][c] == x)
	{
		transition[w][c] = y;
		w = suffixlink[w];
	}
	
	minlen[y] = maxlen[suffixlink[y]] + 1;
	
	return z; 
}

int main()
{ 
	cin >> S;
	
	//初始化空字符串 
	maxlen[0] = 0;
	minlen[0] = 0;
	numEndPosAddOne[0] = false;
	numEndPos[0] = 0;
	for(int i = 0; i < 26; ++i)
	{
		transition[0][i] = -1;
	}
	suffixlink[0] = -1;
	n = 1;
	
	int st = n - 1;
	for(int i = 0; i < S.length(); ++i)
	{
		st = add_char(S[i], st);
	}

	//拓扑排序计算每个状态的endPos的个数
	for(int i = n - 1; i >= 0; --i)
	{
		if(suffixlink[i] != -1)
		{
			++inDegree[suffixlink[i]];
		}
	}
	
	deque<int> dq;
	for(int i = n - 1; i >= 0; --i)
	{
		if(inDegree[i] == 0)
		{
			dq.push_back(i);
		}
	}
	while(!dq.empty())
	{
		int i = dq.front();
		if(suffixlink[i] != -1)
		{
			numEndPos[suffixlink[i]] += numEndPos[i];
			--inDegree[suffixlink[i]];
			if(inDegree[suffixlink[i]] == 0)
			{
				dq.push_back(suffixlink[i]);
			}
		}
		dq.pop_front();
	}
	/* 
	for(int i = n - 1; i >= 0; --i)
	{
		cout << i << " " << numEndPos[i] << endl;
	}
	*/ 
	long long ans[S.length() + 1];
	memset(ans, 0, sizeof(ans));
	for(int i = n - 1; i >= 0; --i)
	{
		ans[maxlen[i]] = max(ans[maxlen[i]], (long long)numEndPos[i]);
	}
	
	for(int i = S.length() - 1; i >= 1; --i)
	{
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for(int i = 1; i <= S.length(); ++i)
	{
		cout << ans[i] << endl;
	}
	/*
	long long num = 0;
	for(int i = 1; i < n; ++i)
	{
		num = num + maxlen[i] - minlen[i] + 1;
		//cout << maxlen[i] << " " << minlen[i] << endl;
	}
	cout << num << endl;
	*/
	return 0;	
} 

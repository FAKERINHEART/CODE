#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

const int MAXL = 1000000;
string S;//字符串S 
int n;//当前的状态序号
int maxlen[2 * MAXL + 10];//每个状态中字符串的最大长度 
int minlen[2 * MAXL + 10];//每个状态中字符串的最小长度 
bool numEndPosAddOne[2 * MAXL + 10];//endposition的个数是不是它们子节点之和加1 
int numEndPos[2 * MAXL + 10];//endposition的个数 
int transition[2 * MAXL + 10][11];//状态转换表
int suffixlink[2 * MAXL + 10];//向前的状态连接 
long long SUM[2 * MAXL + 10];//各个状态不同旋律的和
int indegreeTransition[2 * MAXL + 10];//每个状态经由transition的入度
int numdir[2 * MAXL + 10];

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
	for(int i = 0; i < 11; ++i)
	{
		if(_trans == NULL)
		{
			transition[n][i] = -1;
		}
		else
		{
			if(transition[n][i] && transition[n][i] != -1)
			{
				--indegreeTransition[transition[n][i]];
			}
			transition[n][i] = _trans[i];
			if(transition[n][i] && transition[n][i] != -1)
			{
				++indegreeTransition[transition[n][i]];
			}
		}
	}
	suffixlink[n] = _slink;
	
	return n++;
}

int add_char(char ch, int st) //ch: 要加入的新字符, st: 上一个字符的状态序号 
{
	int c = ch - '0';
	int z = new_status(maxlen[st] + 1, -1, NULL, -1, true);
	int v = st;
	while(v != -1 && transition[v][c] == -1)
	{
		if(transition[v][c] && transition[v][c] != -1)
		{
			--indegreeTransition[transition[v][c]];
		}
		transition[v][c] = z;
		if(transition[v][c] && transition[v][c] != -1)
		{
			++indegreeTransition[transition[v][c]];
		}
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
		if(transition[w][c] && transition[w][c] != -1)
		{
			--indegreeTransition[transition[w][c]];
		}
		transition[w][c] = y;
		if(transition[w][c] && transition[w][c] != -1)
		{
			++indegreeTransition[transition[w][c]];
		}
		w = suffixlink[w];
	}
	
	minlen[y] = maxlen[suffixlink[y]] + 1;
	
	return z; 
}


int main()
{
	int N;
	cin >> N;
	string temp;
	S = "";
	for(int i = 0; i < N; ++i)
	{
		cin >> temp;
		S += temp;
		S += ":";
	}
	S = S.substr(0, S.length() - 1);
	//cout << S << endl;
	
	//初始化空字符串 
	maxlen[0] = 0;
	minlen[0] = 0;
	numEndPosAddOne[0] = false;
	numEndPos[0] = 0;
	for(int i = 0; i < 11; ++i)
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
	/*
	for(int i = 0; i < n; ++i)
	{
		cout << i << ": " << indegreeTransition[i] << endl;
	}
	*/
	/*
	for(int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		for(int j = 0; j < 11; ++j)
		{
			cout << transition[i][j] << " ";
		}
		cout << endl;
	}
	*/
		
	memset(SUM, 0, sizeof(SUM));
	numdir[0] = 1;
	deque<int> dq;
	dq.push_back(0);

	while(!dq.empty())
	{
		int sub = dq.front();
		for(int i = 0; i < 11; ++i)
		{
			if(transition[sub][i] != -1)
			{
				if(i != 10)
				{
					SUM[transition[sub][i]] = (SUM[transition[sub][i]] + SUM[sub] * 10 + i * numdir[sub]) % (1000000007L);
					numdir[transition[sub][i]] += numdir[sub];
				}
				--indegreeTransition[transition[sub][i]];
				if(indegreeTransition[transition[sub][i]] == 0)
				{
					dq.push_back(transition[sub][i]);
				}
			}
		}
		dq.pop_front();
		//cout << sub << "sss" << endl;
	}
	/*
	for(int i = 0; i < n; ++i)
	{
		cout << i << ": " << SUM[i] << " " << numdir[i] << endl;
	}
	*/
	long long SSS = 0;
	for(int i = 0; i < n; ++i)
	{
		SSS = (SSS + SUM[i]) % (1000000007L);
	}
	cout << SSS << endl;
	
	return 0;	
} 

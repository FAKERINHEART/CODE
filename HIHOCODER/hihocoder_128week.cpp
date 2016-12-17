#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXL = 1000000;
string S;//�ַ���S 
int n;//��ǰ��״̬���
int maxlen[2 * MAXL + 10];//ÿ��״̬���ַ�������󳤶� 
int minlen[2 * MAXL + 10];//ÿ��״̬���ַ�������С���� 
bool numEndPosAddOne[2 * MAXL + 10];//endposition�ĸ����ǲ��������ӽڵ�֮�ͼ�1 
int numEndPos[2 * MAXL + 10];//endposition�ĸ��� 
int transition[2 * MAXL + 10][26];//״̬ת����
int suffixlink[2 * MAXL + 10];//��ǰ��״̬����
int inDegree[2 * MAXL + 10];//ÿ��״̬suffixlink����� 

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

int add_char(char ch, int st) //ch: Ҫ��������ַ�, st: ��һ���ַ���״̬��� 
{
	int c = ch - 'a';
	int z = new_status(maxlen[st] + 1, -1, NULL, -1, true);
	int v = st;
	while(v != -1 && transition[v][c] == -1)
	{
		transition[v][c] = z;
		v = suffixlink[v];
	}
	
	if(v == -1)//��������ǰ��״̬������֮ǰ��û����c״̬ת��ʱ 
	{
		minlen[z] = 1;
		suffixlink[z] = 0;
		return z;
	}
	
	int x = transition[v][c];
	if(maxlen[v] + 1 == maxlen[x])//����һ����ǰ��״̬������֮ǰ����c״̬ת��ʱ, ��������ַ������ȼ�1����״̬ת���Ժ����ַ������� 
	{
		minlen[z] = maxlen[x] + 1;
		suffixlink[z] = x;
		return z;
	}
	//����һ����ǰ��״̬������֮ǰ����c״̬ת��ʱ, ��������ַ������ȼ�1������״̬ת���Ժ����ַ������� 
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
	
	//��ʼ�����ַ��� 
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

	//�����������ÿ��״̬��endPos�ĸ���
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

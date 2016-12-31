#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXL = 100000;
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
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			cout << transition[i][j] << " ";
		}
		cout << endl;
	}
	*/

	/*
	for(int i = n - 1; i >= 0; --i)
	{
		cout << i << " " << numEndPos[i] << endl;
	}
	*/

	string T;
	int n_T;
	bool visited[2 * MAXL + 10];
	long long ans;
	int N;
	cin >> N;
	int u_T, l_T;
	
	for(int i = 0; i < N; ++i)
	{
		ans = 0;
		memset(visited, 0, sizeof(visited));
		T = "";
		cin >> T;
		n_T = T.length();
		T += T.substr(0, n_T - 1);
		u_T = 0;
		l_T = 0;
		//cout << T << endl;
		
		//cout << n_T << endl;
		for(int j = 0; j < T.length(); ++j)
		{
			//cout << j << ": "<< T[j] << u_T << " " << l_T << endl;
			
			while(u_T != 0 && transition[u_T][T[j] - 'a'] == -1)
			{
				u_T = suffixlink[u_T];
				l_T = maxlen[u_T];
			}
			//cout << "sss: " << u_T << " " << l_T << endl;
			if(transition[u_T][T[j] - 'a'] != -1)
			{
				u_T = transition[u_T][T[j] - 'a'];
				++l_T;
			}
			else
			{
				u_T = 0;
				l_T = 0; 
			}
			//cout << u_T << " " << l_T << endl;
			
			if(l_T > n_T)
			{
				while(maxlen[suffixlink[u_T]] >= n_T)
				{
					//cout << "ttt" << maxlen[suffixlink[u_T]] << endl;
					u_T = suffixlink[u_T];
					l_T = maxlen[u_T];
				}
			}
			//cout << u_T << " " << l_T << " " << visited[u_T] << endl;
			if(l_T >= n_T && !visited[u_T])
			{
				visited[u_T] = true;
				ans += numEndPos[u_T];
			}
			//cout << "ans: " << ans << endl;
		}
		
		cout << ans << endl;
	}
	
} 

#include <iostream>
#include <string>

using namespace std;

const int MAXL = 1000000;
string S;//�ַ���S 
int n;//��ǰ��״̬���
int maxlen[2 * MAXL + 10];//ÿ��״̬���ַ�������󳤶� 
int minlen[2 * MAXL + 10];//ÿ��״̬���ַ�������С����
int transition[2 * MAXL + 10][26];//״̬ת����
int suffixlink[2 * MAXL + 10];//��ǰ��״̬����

int new_status(int _maxlen, int _minlen, int* _trans, int _slink)
{
	maxlen[n] = _maxlen;
	minlen[n] = _minlen;
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
	int z = new_status(maxlen[st] + 1, -1, NULL, -1);
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
	int y = new_status(maxlen[v] + 1, -1, transition[x], suffixlink[x]);
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
	long long num = 0;
	for(int i = 1; i < n; ++i)
	{
		num = num + maxlen[i] - minlen[i] + 1;
		//cout << maxlen[i] << " " << minlen[i] << endl;
	}
	cout << num << endl;
	return 0;	
} 

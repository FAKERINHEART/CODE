#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXL = 100000;
string S[2];//�ַ���S 
int n[2];//��ǰ��״̬���
int maxlen[2][2 * MAXL + 10];//ÿ��״̬���ַ�������󳤶� 
int minlen[2][2 * MAXL + 10];//ÿ��״̬���ַ�������С���� 
int transition[2][2 * MAXL + 10][26];//״̬ת����
int suffixlink[2][2 * MAXL + 10];//��ǰ��״̬����
int sg[2][2 * MAXL + 10];//SG����ֵ 
bool has_sg[2][2 * MAXL + 10];//�Ƿ���SGֵ 
int MAX_sg[2] = {-1, -1};
int MIN_sg[2] = {(1 << 30), (1<<30)};


int new_status(int _maxlen, int _minlen, int* _trans, int _slink, bool addOne, int order)
{
	maxlen[order][n[order]] = _maxlen;
	minlen[order][n[order]] = _minlen;
	for(int i = 0; i < 26; ++i)
	{
		if(_trans == NULL)
		{
			transition[order][n[order]][i] = -1;
		}
		else
		{
			transition[order][n[order]][i] = _trans[i];
		}
	}
	suffixlink[order][n[order]] = _slink;
	
	return n[order]++;
}

int add_char(char ch, int st, int order) //ch: Ҫ��������ַ�, st: ��һ���ַ���״̬��� 
{
	int c = ch - 'a';
	int z = new_status(maxlen[order][st] + 1, -1, NULL, -1, true, order);
	int v = st;
	while(v != -1 && transition[order][v][c] == -1)
	{
		transition[order][v][c] = z;
		v = suffixlink[order][v];
	}
	
	if(v == -1)//��������ǰ��״̬������֮ǰ��û����c״̬ת��ʱ 
	{
		minlen[order][z] = 1;
		suffixlink[order][z] = 0;
		return z;
	}
	
	int x = transition[order][v][c];
	if(maxlen[order][v] + 1 == maxlen[order][x])//����һ����ǰ��״̬������֮ǰ����c״̬ת��ʱ, ��������ַ������ȼ�1����״̬ת���Ժ����ַ������� 
	{
		minlen[order][z] = maxlen[order][x] + 1;
		suffixlink[order][z] = x;
		return z;
	}
	//����һ����ǰ��״̬������֮ǰ����c״̬ת��ʱ, ��������ַ������ȼ�1������״̬ת���Ժ����ַ������� 
	int y = new_status(maxlen[order][v] + 1, -1, transition[order][x], suffixlink[order][x], false, order);
	suffixlink[order][y] = suffixlink[order][x];
	
	minlen[order][x] = maxlen[order][y] + 1; 
	suffixlink[order][x] = y;
	minlen[order][z] = maxlen[order][y] + 1;
	suffixlink[order][z] = y;
	
	int w = v;
	while(w != -1 && transition[order][w][c] == x)
	{
		transition[order][w][c] = y;
		w = suffixlink[order][w];
	}
	
	minlen[order][y] = maxlen[order][suffixlink[order][y]] + 1;
	
	return z; 
}

int cal_sg(int i, int order)
{
	bool flag = false;
	for(int j = 0; j < 26; ++j)
	{
		if(transition[order][i][j] != -1)
		{
			flag = true;
			if(has_sg[order][transition[order][i][j]] == false)
			{
				cal_sg(transition[order][i][j], order);
			}
			//cout << i << " " << transition[order][i][j] << " " << sg[order][transition[order][i][j]] << endl;
			MAX_sg[order] = max(sg[order][transition[order][i][j]], MAX_sg[order]);
			MIN_sg[order] = min(sg[order][transition[order][i][j]], MIN_sg[order]);
		}
	}
	
	if(flag == false)
	{
		sg[order][i] = 0;
	}
	else
	{
		if(MIN_sg[order] > 0)
		{
			sg[order][i] = 0;
		}
		else
		{
			sg[order][i] = MAX_sg[order] + 1;
		}
	}
	
	MAX_sg[order] = max(sg[order][i], MAX_sg[order]);
	MIN_sg[order] = min(sg[order][i], MIN_sg[order]);
	has_sg[order][i] = true;
	//cout << i << ": " << sg[order][i] << " " << MAX_sg[order] << " " << MIN_sg[order] << endl;
	
	return 0;
} 

int main()
{ 
	memset(has_sg, false, sizeof(has_sg));
	
	long long K;
	cin >> K;
	
	for(int x = 0; x < 2; ++x)
	{
		cin >> S[x];
	
		//��ʼ�����ַ��� 
		maxlen[x][0] = 0;
		minlen[x][0] = 0;
		for(int i = 0; i < 26; ++i)
		{
			transition[x][0][i] = -1;
		}
		suffixlink[x][0] = -1;
		n[x] = 1;
		
		int st = n[x] - 1;
		for(int i = 0; i < S[x].length(); ++i)
		{
			st = add_char(S[x][i], st, x);
		}
		
		for(int i = 0; i < n[x]; ++i)
		{
			for(int j = 0; j < 26; ++j)
			{
				cout << transition[x][i][j] << " ";
			}
			cout << endl;
		}
		
		cal_sg(0, x);
		
		for(int i = 0; i < n[x]; ++i)
		{
			cout << i << ": " << has_sg[x][i] << " " << sg[x][i] << endl;
		}	
	}

} 

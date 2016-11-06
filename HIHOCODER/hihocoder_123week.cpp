#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>


using namespace std;

//����һ���ַ����������ٳ���K�ε���ظ��Ӵ�����k���Ӵ������ص���
//��ν����K�ξ���������K���ط�����������Ӵ�������Ҫ����K���������ġ�

long long N, K;
long long Array[100001];
long long Rank[100001];//���±��Ϊ��һ���ַ����Ӵ�����ʵ����ӳ��: �±�->���� 
long long height[100001];//��ȫ����׺�ַ����ֵ������, ÿ����׺�ַ�������ǰ��һ����׺�ַ�����������Ӵ�����
long long ans = 1;
long long dp[18][100000];


long long lcp(long long x, long long y)
{
	long long begin, end;
	if(Rank[x] < Rank[y])
	{
		begin = Rank[x] + 1;
		end = Rank[y];
	}
	else
	{
		begin = Rank[y] + 1;
		end = Rank[x];
	}
	int len = int(log((end - begin + 1) * 1.0) / log(2.0));
	
	return min(dp[len][begin - 1], dp[len][end - (1 << len)]);
}

//������׺�ַ���, �������ȫ����׺�ַ����ֵ������, ÿ����׺�ַ�������ǰ��һ����׺�ַ�����������Ӵ����� 
void solve()
{
	long long cntA[100001], cntB[100001];//��ʾÿ�����ֵļ���, �Խ���������ͬ���ֵ���������
	long long sa[N + 1];//cntA���ϸ��������ӳ��:����->�±�
	long long tsa[N + 1];//cntB���ϸ��������ӳ��:����->�±�
	
	memset(cntA, 0, sizeof(cntA));
	for(long long i = 1; i <= N; ++i) ++cntA[Array[i]];
	for(long long i = 1; i < 256; ++i) cntA[i] += cntA[i - 1]; //��С���ֵļ����ۼӵ������ֵļ����� 
	for(long long i = N; i >= 1; --i) sa[cntA[Array[i]]--] = i; //��N��1��ѭ������˼��: �������ͬ������, ������֮�������˳���ǰ������ǳ��ֵ��Ⱥ�˳���ϸ������ 
	//for(long long i = 1; i <= N; ++i) cout << i << ": " << sa[i] << endl;
	
	Rank[sa[1]] = 1;
	for(long long i = 2; i <= N; ++i)
	{
		Rank[sa[i]] = Rank[sa[i - 1]]; //��������sa[i], ������������Ҫô��sa[i-1]������һ��(����һ��), Ҫô��sa[i-1]��Ĵ�1
		if(Array[sa[i]] != Array[sa[i - 1]]) ++Rank[sa[i]];	
	}
	
	
	//��ʼ�������� 
	long long A[N + 1], B[N + 1]; //A[i]��ʾArray���Ե�i������Ϊ��ʼ���Ӵ���Rankֵ, B[i]��ʾArray���Ե�i���ֺ���ĵ�i+l������Ϊ��ʼ���Ӵ���Rankֵ 
	for(long long l = 1; Rank[sa[N]] < N; l <<= 1)//��ѭ��ֻҪ����Ranke[sa[N]] == N, �Ϳ��Խ�����
	{
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		for(long long i = 1; i <= N; ++i)
		{
			++cntA[A[i] = Rank[i]];//����˴�ѭ����cntAֵ, �˴�cntA���±�ֵ��Rankֵ����������ֵ 
			++cntB[B[i] = (i + l <= N)? Rank[i + l]: 0]; //����˴�ѭ����cntBֵ, c�˴���cntB���±�ֵ��Rankֵ����������ֵ 
		}	
		for(long long i = 1; i <= N; ++i) cntB[i] += cntB[i - 1];
		for(long long i = N; i >= 1; --i) tsa[cntB[B[i]]--] = i;//��N��1��ѭ������˼��: �������ͬ��Rank:B[i]ֵ, ������֮�������˳���ǰ������ǳ��ֵ��Ⱥ�˳���ϸ������ 
		for(long long i = 1; i <= N; ++i) cntA[i] += cntA[i - 1];
		for(long long i = N; i >= 1; --i) sa[cntA[A[tsa[i]]]--] = tsa[i];//��N��1��ѭ������˼��: �������ͬ��Rank:A[i]ֵ, ������֮�������˳���ǰ�������sa[i]��ֵ�ϸ������ 
		Rank[sa[1]] = 1;
		for(long long i = 2; i <= N; ++i)
		{
			Rank[sa[i]] = Rank[sa[i - 1]];
			if(A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++Rank[sa[i]];
		}
	}
	
	//���height 
	for (long long i = 1, j = 0; i <= N; ++i)
	{
		if(j) j--;
		while (Array[i + j] == Array[sa[Rank[i] - 1] + j]) ++j;
		height[Rank[i]] = j;
	}
	//cout << endl;
	//for (long long i = 1; i <= N; ++i) cout << sa[i] << ": " << height[i] << endl;
	
	memset(dp, 0, sizeof(dp));
	for(long long i = 0; i < N; i++) dp[0][i] = height[i + 1];
	int rows = int(log(N * 1.0) / log(2.0));
	for(int i = 1; i <= rows; i++) for(int j = 0; j + (1 << i) - 1 < N; j++) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);	
	
	for(long long L = 1; L <= N; L++)
	{
		for(long long i = 1; i + L <= N; i += L)
		{
			long long R = lcp(i, i + L);
			ans = max(R / L + 1, ans);
			if(i >= L - R % L)
			{
				ans = max(lcp(i - L + R % L, i + R % L) / L + 1, ans);
			}
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	char str[100010];
	gets(str);
	N = strlen(str);
	for(long long i = 0; i < N; ++i) Array[i + 1] = str[i] - 'a' + 1;
	solve();
	return 0;
}

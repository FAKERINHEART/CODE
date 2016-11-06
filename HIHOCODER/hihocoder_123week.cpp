#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>


using namespace std;

//给定一个字符串，求至少出现K次的最长重复子串，这k个子串可以重叠。
//所谓出现K次就是在任意K个地方出现了这个子串，并不要求这K个是连续的。

long long N, K;
long long Array[100001];
long long Rank[100001];//以下标的为第一个字符的子串的真实排名映射: 下标->排名 
long long height[100001];//在全部后缀字符串字典排序后, 每个后缀字符串与其前面一个后缀字符串的最长公共子串长度
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

//产生后缀字符串, 并求出在全部后缀字符串字典排序后, 每个后缀字符串与其前面一个后缀字符串的最长公共子串长度 
void solve()
{
	long long cntA[100001], cntB[100001];//表示每个数字的计数, 以解决如果有相同数字的排名问题
	long long sa[N + 1];//cntA的严格递增排名映射:排名->下标
	long long tsa[N + 1];//cntB的严格递增排名映射:排名->下标
	
	memset(cntA, 0, sizeof(cntA));
	for(long long i = 1; i <= N; ++i) ++cntA[Array[i]];
	for(long long i = 1; i < 256; ++i) cntA[i] += cntA[i - 1]; //将小数字的计数累加到大数字的计数上 
	for(long long i = N; i >= 1; --i) sa[cntA[Array[i]]--] = i; //从N到1的循环的意思是: 如果有相同的数字, 则它们之间的排名顺序是按照它们出现的先后顺序严格增大的 
	//for(long long i = 1; i <= N; ++i) cout << i << ": " << sa[i] << endl;
	
	Rank[sa[1]] = 1;
	for(long long i = 2; i <= N; ++i)
	{
		Rank[sa[i]] = Rank[sa[i - 1]]; //对于数字sa[i], 它的真正排名要么和sa[i-1]的排名一样(数字一样), 要么比sa[i-1]真的大1
		if(Array[sa[i]] != Array[sa[i - 1]]) ++Rank[sa[i]];	
	}
	
	
	//开始基数排序 
	long long A[N + 1], B[N + 1]; //A[i]表示Array中以第i个数字为开始的子串的Rank值, B[i]表示Array中以第i数字后面的第i+l个数字为开始的子串的Rank值 
	for(long long l = 1; Rank[sa[N]] < N; l <<= 1)//此循环只要出现Ranke[sa[N]] == N, 就可以结束了
	{
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		for(long long i = 1; i <= N; ++i)
		{
			++cntA[A[i] = Rank[i]];//算出此次循环的cntA值, 此处cntA的下标值是Rank值不再是数字值 
			++cntB[B[i] = (i + l <= N)? Rank[i + l]: 0]; //算出此次循环的cntB值, c此处的cntB的下标值是Rank值不再是数字值 
		}	
		for(long long i = 1; i <= N; ++i) cntB[i] += cntB[i - 1];
		for(long long i = N; i >= 1; --i) tsa[cntB[B[i]]--] = i;//从N到1的循环的意思是: 如果有相同的Rank:B[i]值, 则它们之间的排名顺序是按照它们出现的先后顺序严格增大的 
		for(long long i = 1; i <= N; ++i) cntA[i] += cntA[i - 1];
		for(long long i = N; i >= 1; --i) sa[cntA[A[tsa[i]]]--] = tsa[i];//从N到1的循环的意思是: 如果有相同的Rank:A[i]值, 则它们之间的排名顺序是按照它们sa[i]的值严格增大的 
		Rank[sa[1]] = 1;
		for(long long i = 2; i <= N; ++i)
		{
			Rank[sa[i]] = Rank[sa[i - 1]];
			if(A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++Rank[sa[i]];
		}
	}
	
	//算出height 
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

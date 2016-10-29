#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N, K;
int array[200050];

//产生后缀字符串, 并求出在全部后缀字符串字典排序后, 每个后缀字符串与其前面一个后缀字符串的最长公共子串长度 
void solve()
{
	int cntA[200050], cntB[200050];//表示每个数字的计数, 以解决如果有相同数字的排名问题
	int sa[N + 1];//cntA的严格递增排名映射:排名->下标
	int tsa[N + 1];//cntB的严格递增排名映射:排名->下标
	int rank[N + 1];//以下标的为第一个字符的子串的真实排名映射: 下标->排名 
	int height[N + 1];//在全部后缀字符串字典排序后, 每个后缀字符串与其前面一个后缀字符串的最长公共子串长度
	
	memset(cntA, 0, sizeof(cntA));
	for(int i = 1; i <= N; ++i) ++cntA[array[i]];
	for(int i = 1; i < 256; ++i) cntA[i] += cntA[i - 1]; //将小数字的计数累加到大数字的计数上 
	for(int i = N; i >= 1; --i) sa[cntA[array[i]]--] = i; //从N到1的循环的意思是: 如果有相同的数字, 则它们之间的排名顺序是按照它们出现的先后顺序严格增大的 
	//for(int i = 1; i <= N; ++i) cout << i << ": " << sa[i] << endl;
	
	rank[sa[1]] = 1;
	for(int i = 2; i <= N; ++i)
	{
		rank[sa[i]] = rank[sa[i - 1]]; //对于数字sa[i], 它的真正排名要么和sa[i-1]的排名一样(数字一样), 要么比sa[i-1]真的大1
		if(array[sa[i]] != array[sa[i - 1]]) ++rank[sa[i]];	
	}
	
	
	//开始基数排序 
	int A[N + 1], B[N + 1]; //A[i]表示array中以第i个数字为开始的子串的rank值, B[i]表示array中以第i数字后面的第i+l个数字为开始的子串的rank值 
	for(int l = 1; rank[sa[N]] < N; l <<= 1)//此循环只要出现ranke[sa[N]] == N, 就可以结束了
	{
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		for(int i = 1; i <= N; ++i)
		{
			++cntA[A[i] = rank[i]];//算出此次循环的cntA值, 此处cntA的下标值是rank值不再是数字值 
			++cntB[B[i] = (i + l <= N)? rank[i + l]: 0]; //算出此次循环的cntB值, c此处的cntB的下标值是rank值不再是数字值 
		}	
		for(int i = 1; i <= N; ++i) cntB[i] += cntB[i - 1];
		for(int i = N; i >= 1; --i) tsa[cntB[B[i]]--] = i;//从N到1的循环的意思是: 如果有相同的rank:B[i]值, 则它们之间的排名顺序是按照它们出现的先后顺序严格增大的 
		for(int i = 1; i <= N; ++i) cntA[i] += cntA[i - 1];
		for(int i = N; i >= 1; --i) sa[cntA[A[tsa[i]]]--] = tsa[i];//从N到1的循环的意思是: 如果有相同的rank:A[i]值, 则它们之间的排名顺序是按照它们sa[i]的值严格增大的 
		rank[sa[1]] = 1;
		for(int i = 2; i <= N; ++i)
		{
			rank[sa[i]] = rank[sa[i - 1]];
			if(A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++rank[sa[i]];
		}
	}
	
	//算出height 
	for (int i = 1, j = 0; i <= N; ++i)
	{
		if(j) j--;
		while (array[i + j] == array[sa[rank[i] - 1] + j]) ++j;
		height[rank[i]] = j;
	}
	//cout << endl;
	//for (int i = 1; i <= N; ++i) cout << sa[i] << ": " << height[i] << endl; 
	
	int MAX = 0;
	for(int i = 2; i <= N; ++i)
	{
		if((sa[i - 1] > K && sa[i] < K || sa[i - 1] < K && sa[i] > K) && height[i] > MAX) MAX = height[i];
	}
	cout << MAX << endl;
	
	return;
}

int main()
{
	char str1[100010], str2[100010];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	N = len1 + 1 + len2;
	K = len1 + 1;
	for(int i = 1; i <= len1; ++i) array[i] = str1[i - 1] - 'a' + 2;
	array[K] = 1;
	for(int i = K + 1; i <= N; ++i) array[i] = str2[i - K - 1] - 'a' + 2;
	//for(int i = 1; i <= N; ++i) cout << array[i] << " ";
	solve();	
	return 0;
}


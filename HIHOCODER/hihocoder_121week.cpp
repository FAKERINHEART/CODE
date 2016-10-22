#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>


using namespace std;

//����һ���ַ����������ٳ���K�ε���ظ��Ӵ�����k���Ӵ������ص���
//��ν����K�ξ���������K���ط�����������Ӵ�������Ҫ����K���������ġ�

long long N, K;
long long Array[100001];

bool check(long long len, long long sa[], long long height[])
{
	long long minsa = 1 << 60, maxsa = -1;
	for(long long i = 1; i <= N; ++i)
	{
		if(height[i] < len)
		{
			minsa = sa[i];
			maxsa = sa[i];
		}
		else
		{
			minsa = min(minsa, sa[i]);
			maxsa = max(maxsa, sa[i]);
			if(maxsa - minsa >= len) return true;
		}
	}
	return false;
}

//������׺�ַ���, �������ȫ����׺�ַ����ֵ������, ÿ����׺�ַ�������ǰ��һ����׺�ַ�����������Ӵ����� 
void solve()
{
	long long cntA[100001], cntB[100001];//��ʾÿ�����ֵļ���, �Խ���������ͬ���ֵ���������
	long long sa[N + 1];//cntA���ϸ��������ӳ��:����->�±�
	long long tsa[N + 1];//cntB���ϸ��������ӳ��:����->�±�
	long long rank[N + 1];//���±��Ϊ��һ���ַ����Ӵ�����ʵ����ӳ��: �±�->���� 
	long long height[N + 1];//��ȫ����׺�ַ����ֵ������, ÿ����׺�ַ�������ǰ��һ����׺�ַ�����������Ӵ�����
	
	memset(cntA, 0, sizeof(cntA));
	for(long long i = 1; i <= N; ++i) ++cntA[Array[i]];
	for(long long i = 1; i < 2560; ++i) cntA[i] += cntA[i - 1]; //��С���ֵļ����ۼӵ������ֵļ����� 
	for(long long i = N; i >= 1; --i) sa[cntA[Array[i]]--] = i; //��N��1��ѭ������˼��: �������ͬ������, ������֮�������˳���ǰ������ǳ��ֵ��Ⱥ�˳���ϸ������ 
	//for(long long i = 1; i <= N; ++i) cout << i << ": " << sa[i] << endl;
	
	rank[sa[1]] = 1;
	for(long long i = 2; i <= N; ++i)
	{
		rank[sa[i]] = rank[sa[i - 1]]; //��������sa[i], ������������Ҫô��sa[i-1]������һ��(����һ��), Ҫô��sa[i-1]��Ĵ�1
		if(Array[sa[i]] != Array[sa[i - 1]]) ++rank[sa[i]];	
	}
	
	
	//��ʼ�������� 
	long long A[N + 1], B[N + 1]; //A[i]��ʾArray���Ե�i������Ϊ��ʼ���Ӵ���rankֵ, B[i]��ʾArray���Ե�i���ֺ���ĵ�i+l������Ϊ��ʼ���Ӵ���rankֵ 
	for(long long l = 1; rank[sa[N]] < N; l <<= 1)//��ѭ��ֻҪ����ranke[sa[N]] == N, �Ϳ��Խ�����
	{
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		for(long long i = 1; i <= N; ++i)
		{
			++cntA[A[i] = rank[i]];//����˴�ѭ����cntAֵ, �˴�cntA���±�ֵ��rankֵ����������ֵ 
			++cntB[B[i] = (i + l <= N)? rank[i + l]: 0]; //����˴�ѭ����cntBֵ, c�˴���cntB���±�ֵ��rankֵ����������ֵ 
		}	
		for(long long i = 1; i <= N; ++i) cntB[i] += cntB[i - 1];
		for(long long i = N; i >= 1; --i) tsa[cntB[B[i]]--] = i;//��N��1��ѭ������˼��: �������ͬ��rank:B[i]ֵ, ������֮�������˳���ǰ������ǳ��ֵ��Ⱥ�˳���ϸ������ 
		for(long long i = 1; i <= N; ++i) cntA[i] += cntA[i - 1];
		for(long long i = N; i >= 1; --i) sa[cntA[A[tsa[i]]]--] = tsa[i];//��N��1��ѭ������˼��: �������ͬ��rank:A[i]ֵ, ������֮�������˳���ǰ�������sa[i]��ֵ�ϸ������ 
		rank[sa[1]] = 1;
		for(long long i = 2; i <= N; ++i)
		{
			rank[sa[i]] = rank[sa[i - 1]];
			if(A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++rank[sa[i]];
		}
	}
	
	//���height 
	for (long long i = 1, j = 0; i <= N; ++i)
	{
		if(j) j--;
		while (Array[i + j] == Array[sa[rank[i] - 1] + j]) ++j;
		height[rank[i]] = j;
	}
	//cout << endl;
	//for (long long i = 1; i <= N; ++i) cout << sa[i] << ": " << height[i] << endl; 
	
		
	long long ret = 0;
	long long left = 1, right = N, mid;
	while(left <= right)
	{
		mid = (left + right) >> 1;
		if(check(mid, sa, height))
		{
			left = mid + 1;
			ret = max(ret, mid);
		}
		else right = mid - 1;
	}
	cout << ret << endl;
	
	return;
}

int main()
{
	cin >> N;
	K = 2;
	for(long long i = 1; i <= N; ++i) cin >> Array[i];
	solve();
	return 0;
}

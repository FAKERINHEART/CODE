#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N, K;
int array[200050];

//������׺�ַ���, �������ȫ����׺�ַ����ֵ������, ÿ����׺�ַ�������ǰ��һ����׺�ַ�����������Ӵ����� 
void solve()
{
	int cntA[200050], cntB[200050];//��ʾÿ�����ֵļ���, �Խ���������ͬ���ֵ���������
	int sa[N + 1];//cntA���ϸ��������ӳ��:����->�±�
	int tsa[N + 1];//cntB���ϸ��������ӳ��:����->�±�
	int rank[N + 1];//���±��Ϊ��һ���ַ����Ӵ�����ʵ����ӳ��: �±�->���� 
	int height[N + 1];//��ȫ����׺�ַ����ֵ������, ÿ����׺�ַ�������ǰ��һ����׺�ַ�����������Ӵ�����
	
	memset(cntA, 0, sizeof(cntA));
	for(int i = 1; i <= N; ++i) ++cntA[array[i]];
	for(int i = 1; i < 256; ++i) cntA[i] += cntA[i - 1]; //��С���ֵļ����ۼӵ������ֵļ����� 
	for(int i = N; i >= 1; --i) sa[cntA[array[i]]--] = i; //��N��1��ѭ������˼��: �������ͬ������, ������֮�������˳���ǰ������ǳ��ֵ��Ⱥ�˳���ϸ������ 
	//for(int i = 1; i <= N; ++i) cout << i << ": " << sa[i] << endl;
	
	rank[sa[1]] = 1;
	for(int i = 2; i <= N; ++i)
	{
		rank[sa[i]] = rank[sa[i - 1]]; //��������sa[i], ������������Ҫô��sa[i-1]������һ��(����һ��), Ҫô��sa[i-1]��Ĵ�1
		if(array[sa[i]] != array[sa[i - 1]]) ++rank[sa[i]];	
	}
	
	
	//��ʼ�������� 
	int A[N + 1], B[N + 1]; //A[i]��ʾarray���Ե�i������Ϊ��ʼ���Ӵ���rankֵ, B[i]��ʾarray���Ե�i���ֺ���ĵ�i+l������Ϊ��ʼ���Ӵ���rankֵ 
	for(int l = 1; rank[sa[N]] < N; l <<= 1)//��ѭ��ֻҪ����ranke[sa[N]] == N, �Ϳ��Խ�����
	{
		memset(cntA, 0, sizeof(cntA));
		memset(cntB, 0, sizeof(cntB));
		for(int i = 1; i <= N; ++i)
		{
			++cntA[A[i] = rank[i]];//����˴�ѭ����cntAֵ, �˴�cntA���±�ֵ��rankֵ����������ֵ 
			++cntB[B[i] = (i + l <= N)? rank[i + l]: 0]; //����˴�ѭ����cntBֵ, c�˴���cntB���±�ֵ��rankֵ����������ֵ 
		}	
		for(int i = 1; i <= N; ++i) cntB[i] += cntB[i - 1];
		for(int i = N; i >= 1; --i) tsa[cntB[B[i]]--] = i;//��N��1��ѭ������˼��: �������ͬ��rank:B[i]ֵ, ������֮�������˳���ǰ������ǳ��ֵ��Ⱥ�˳���ϸ������ 
		for(int i = 1; i <= N; ++i) cntA[i] += cntA[i - 1];
		for(int i = N; i >= 1; --i) sa[cntA[A[tsa[i]]]--] = tsa[i];//��N��1��ѭ������˼��: �������ͬ��rank:A[i]ֵ, ������֮�������˳���ǰ�������sa[i]��ֵ�ϸ������ 
		rank[sa[1]] = 1;
		for(int i = 2; i <= N; ++i)
		{
			rank[sa[i]] = rank[sa[i - 1]];
			if(A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) ++rank[sa[i]];
		}
	}
	
	//���height 
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


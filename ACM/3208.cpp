#include <iostream>
#include <cstring> 

using namespace std;
///////////////////////////0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int statusChange[4][10] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, //״̬��ʾ��ǰ����ĩβλ��û��6, �ټ�6������״̬1������������ԭ״̬0 
						   0, 0, 0, 0, 0, 0, 2, 0, 0, 0, //״̬��ʾ��ǰ����ĩβλ����һ��6, �ټ�6������״̬2������������״̬0  
						   0, 0, 0, 0, 0, 0, 3, 0, 0, 0, //״̬��ʾ��ǰ����ĩβλ����������2��6, �ټ�6������״̬3������������״̬0 
						   3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; //״̬��ʾ��ǰ����ĩβλ��������λ���Ѿ�����������6, ���κ����ֶ�����ԭ״̬3
long long dp[15][4];
//����������һ����kλ��ǰ��(k-i)λ��״̬��j����dp[i][j]��ʾ������ǰ��(k-i)λ��״̬Ϊj�������,ʣ�µ�iλ����ɶ��ٸ�����666������
//dp[i][j]���Ը��ݵ�iλ��ͬ����l���е��ӣ����統��iΪ������Ϊl=3ʱ����ǰ��(k-i)��j״̬ת������(k-i+1)��statusChange[j][3]״̬��
//��ˣ�dp[i][j]�ĸ����ǰ���dp[i-1][statusChange[j][3]]�ġ���lȡ��ֵͬʱ���ɵ�dp[i][j] += dp[i-1][statusChange[j][l]]

int main()
{
	memset(dp, 0, sizeof(dp));
	dp[0][3] = 1;
	for(int i = 1; i < 15; i++) for(int j = 0; j < 4; j++) for(int k = 0; k <= 9; k++) dp[i][j] += dp[i - 1][statusChange[j][k]];
	
	int T, n;
	int len, status;
	long long ans;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		len = 0;
		status = 0;
		ans = 0;
		while(dp[len][0] < n) len++;
		for(int j = len - 1; j >= 0; j--)
		{
			int l;
			for(l = 0; l <= 9; l++)
			{
				if(dp[j][statusChange[status][l]] < n) n-= dp[j][statusChange[status][l]]; // ��j+1��lʱһ���м���ȡ�� 
				else break;
			}
			ans = ans * 10 + l;
			status = statusChange[status][l];
		}
		cout << ans << endl;
	}
	
	return 0;
}

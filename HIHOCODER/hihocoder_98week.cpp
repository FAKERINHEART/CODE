#include <iostream>
#include <cstring>

using namespace std;

int num[4];
int num_now[4];
int used[4];
int ops[3];
int opType[6] = {0, 1, 2, 3, 4, 5};
			   //+, -, *, /, ·´-, ·´/  

double cal(double one, double two, int op)
{
	if(op == 0)
	{
		return one + two;
	}
	else if(op == 1)
	{
		return one - two;
	}
	else if(op == 2)
	{
		return one * two;
	}
	else if(op == 3)
	{
		if(two == 0) return 20000;
		return one / two;
	}
	else if(op == 4)
	{
		return two - one;
	}
	else
	{
		if(one == 0) return 20000;
		return two / one;
	}
}

double cal1()
{
	double ret = num_now[0];
	for(int i = 0; i < 3; i++)
	{
		ret = cal(ret, num_now[i + 1], ops[i]);
		if(ret == 20000) return false;
	}
	if(ret == 24) return true;
	else return false;
}

double cal2()
{
	double ret1 = num_now[0];
	double ret2 = num_now[2];
	
	ret1 = cal(ret1, num_now[1], ops[0]);
	if(ret1 == 20000) return false;
	ret2 = cal(ret2, num_now[3], ops[2]);
	if(ret2 == 20000) return false;
	double ret = cal(ret1, ret2, ops[1]);
	if(ret == 20000) return false;
	if(ret == 24) return true;
	else return false;
}

bool dfs_operation(int n)
{
	if(n == 3)
	{
		if(cal1() || cal2()) return true;
		return false;
	} 
	
	for(int i = 0; i < 6; i++)
	{
		ops[n] = opType[i];
		if(dfs_operation(n + 1)) return true;
	}
	return false;
}

bool dfs_num(int n)
{
	if(n == 4)
	{
		return dfs_operation(0);
	}
	
	for(int i = 0; i < 4; i++)
	{
		if(!used[i])
		{
			num_now[n] = num[i];
			used[i] = true;
			
			if(dfs_num(n + 1)) 
			{
				return true;	
			}
			used[i] = false;
		}
	}
	
	return false;
}

int main()
{
	int num_case;
	cin >> num_case;
	while(num_case--)
	{
		for(int i = 0; i < 4; i++) cin >> num[i];
		memset(used, false, sizeof(used));
		bool ret = dfs_num(0);
		if(ret) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

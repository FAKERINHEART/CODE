#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num;
	bool real[12];
	int status[12];
	string left, right, balance;
	string left_sum, right_sum; 
	cin >> num;
	
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < 12; j++) 
		{
			real[j] = false;
			status[j] = 0;
		}
		
		for(int j = 0; j < 3; j++)
		{
			cin >> left >> right >> balance;
			
			if(balance == "even")
			{
				for(int k = 0; k < left.length(); k++)
				{
					real[left[k] - 'A'] = true;
					real[right[k] - 'A'] = true;
				}
				continue;
			}
			else if(balance == "up") left.swap(right);//右边轻转右边重 
			//开始处理右边重
			left_sum.append(left);
			right_sum.append(right);
		}
		
		for(int j = 0; j < left_sum.length(); j++)
		{
			if(!real[left_sum[j] - 'A']) status[left_sum[j] - 'A']--;
			if(!real[right_sum[j] - 'A']) status[right_sum[j] - 'A']++;
		}
		
		int m = 0;
		int m_sub = -1;
		for(int j = 0; j < 12; j++)
		{
			if(status[j] < 0)
			{
				if(-status[j] > m) 
				{
					m = -status[j];
					m_sub = j;
				}
			}
			else
			{
				if(status[j] > m)
				{
					m = status[j];
					m_sub = j;
				}
			}
		}
		cout << char(m_sub + 'A') << " is the counterfeit coin and it is ";
		if(status[m_sub] < 0) cout << "light." << endl;
		else cout << "heavy." << endl;
		
		left_sum.clear();
		right_sum.clear();
	}
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num_case, num, length_c;
	string str;
	bool flag;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		length_c = 0;
		cin >> num >> str;
		char c[num];
		int n[num];
		c[length_c] = str[0];
		n[length_c] = 1;
		for(int j = 1; j < num; j++)
		{
			if(str[j] == c[length_c]) n[length_c]++;
			else
			{
				length_c++;
				c[length_c] = str[j];
				n[length_c] = 1;
			}
		}
		
		//for(int j = 0; j <= length_c; j++) cout << c[j] << " " << n[j] << endl;
		
		flag = false;
		for(int j = 0; j <= length_c - 2; j++)
		{
			if(c[j] + 1 == c[j + 1] && c[j + 1] + 1 == c[j + 2] && n[j] >= n[j + 1] && n[j + 1] <= n[j + 2])
			{
				flag = true;
				break;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;	
} 

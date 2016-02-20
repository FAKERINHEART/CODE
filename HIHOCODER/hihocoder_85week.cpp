#include <iostream>
#include <string>

using namespace std;

						 //0, 1, 2, 3, 4, 5, 6, 7, 8, 9
bool permission[10][10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//0
						   1, 1, 1, 1, 1, 1, 1, 1, 1, 1,//1
						   1, 0, 1, 1, 0, 1, 1, 0, 1, 1,//2
						   0, 0, 0, 1, 0, 0, 1, 0, 0, 1,//3
						   1, 0, 0, 0, 1, 1, 1, 1, 1, 1,//4
						   1, 0, 0, 0, 0, 1, 1, 0, 1, 1,//5
						   0, 0, 0, 0, 0, 0, 1, 0, 0, 1,//6
						   1, 0, 0, 0, 0, 0, 0, 1, 1, 1,//7
						   1, 0, 0, 0, 0, 0, 0, 0, 1, 1,//8
						   0, 0, 0, 0, 0, 0, 0, 0, 0, 1,//9
						  };


string str, res;

bool dfs(int depth, int last, bool below)
{
	if(depth >= str.length()) return true;
	else
	{
		if(below == true)
		{	
			int MAX;
			for(MAX = 9; MAX >= 0; MAX --) if(permission[last][MAX]) break;
			for(int i = depth; i < str.length(); i++) res[i] = MAX + '0';
			return true;
		}
		for(int i = 9; i >= 0; i--)
		{
			if(i <= str[depth] - '0' && permission[last][i])
			{
				if(dfs(depth + 1, i, i < str[depth] - '0')) 
				{
					res[depth] = i + '0';
					return true;
				}
			}
		}
		return false;	
	}
}

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		cin >> str;
		res = str;
		dfs(0, 1, false);	
		cout << res << endl;
	}
	return 0;	
} 

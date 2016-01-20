#include <iostream>

using namespace std;

int Edge[16384][2];
int path[32768]; 
int sub_path;

void dfs(int dot)
{
	int temp;
	for(int i = 0; i < 2; i++)
	{
		if(Edge[dot][i] > -1) 
		{
			temp = Edge[dot][i];
			Edge[dot][i] = -1;
			dfs(temp);
		}
	}
	path[sub_path] = dot;
	sub_path++;
	return;
}


int main()
{
	int num;
	cin >> num;
	if(num == 1)
	{
		cout << "01" << endl;
		return 0;
	
	} 
	int Dot = 1 << (num - 1);
	for(int i = 0; i < Dot; i++)
	{
		Edge[i][0] = (i << 1) & (Dot - 1);
		Edge[i][1] = Edge[i][0] + 1;
	}
	sub_path = 0;
	dfs(0);
	while(1)
	{
		sub_path--;
		cout << (path[sub_path] & 1);
		if(sub_path == 1) break;
	} 
	cout << endl;
	
	return 0;
 } 

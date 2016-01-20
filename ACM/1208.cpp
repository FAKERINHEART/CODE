#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> t[25];

void find(int block, int& location_block, int& layer_block)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < t[i].size(); j++)
		{
			if(t[i][j] == block)
			{
				location_block = i;
				layer_block = j;
				return;	
			}	
		}	
	}	
}

int main()
{
	string str1, str2;
	int from, to, location_from, location_to, layer_from, layer_to;
	
	cin >> n;
	for(int i = 0; i < n; i++) 
	{
		t[i].clear();
		t[i].push_back(i);
	}
	/*
	for(int i = 0; i < n; i++)
	{
		cout << i << ":";
		for(int j = 0; j < t[i].size(); j++) cout << " " << t[i][j];
		cout << endl;
	}
	*/
	while(cin >> str1)
	{
		if(str1 == "quit") break;
		cin >> from >> str2 >> to;
		if(from == to) continue;
		find(from, location_from, layer_from);
		find(to, location_to, layer_to);
		if(location_from == location_to) continue;
		
		//cout << location_from << " " << location_to << " " << layer_from << " " << layer_to << endl;
		if(str1 == "move")
		{
			if(str2 == "onto")
			{
				for(int i = t[location_from].size() - 1; i > layer_from; i--)
				{
					t[t[location_from][i]].push_back(t[location_from][i]);
					t[location_from].pop_back();
				}
				for(int i = t[location_to].size() - 1; i > layer_to; i--)
				{
					t[t[location_to][i]].push_back(t[location_to][i]);
					t[location_to].pop_back();
				}
				t[location_to].push_back(from);
				t[location_from].pop_back();
			}
			else if(str2 == "over")
			{
				for(int i = t[location_from].size() - 1; i > layer_from; i--)
				{
					t[t[location_from][i]].push_back(t[location_from][i]);
					t[location_from].pop_back();
				}
				t[location_to].push_back(from);
				t[location_from].pop_back();
			}
		}
		else if(str1 == "pile")
		{
			if(str2 == "onto")
			{
				for(int i = t[location_to].size() - 1; i > layer_to; i--)
				{
					t[t[location_to][i]].push_back(t[location_to][i]);
					t[location_to].pop_back();
				}
				for(int i = layer_from; i < t[location_from].size(); i++) t[location_to].push_back(t[location_from][i]);
				for(int i = t[location_from].size() - 1; i >= layer_from; i--) t[location_from].pop_back();
			}
			else if(str2 == "over")
			{
				for(int i = layer_from; i < t[location_from].size(); i++) t[location_to].push_back(t[location_from][i]);
				for(int i = t[location_from].size() - 1; i >= layer_from; i--) t[location_from].pop_back();
			}
		}	
	}
	for(int i = 0; i < n; i++)
	{
		cout << i << ":";
		for(int j = 0; j < t[i].size(); j++) cout << " " << t[i][j];
		cout << endl;
	}
	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

bool set_bit[20];
int status[1 << 20];
int answer[20];

int getIndex(bool x[])
{
	int index = 0;
	for(int i = 19; i >= 0; i--)
	{
		if(x[i]) index |= 1;
		index = index << 1;
	}
	return index >> 1;
}

bool dfs(int sub)
{
	bool temp_set_bit[20];
	memcpy(temp_set_bit, set_bit, sizeof(set_bit));
	set_bit[sub] = false;
	for(int i = 1; sub + i + 1 < 20; i++) if(!set_bit[i]) set_bit[sub + i + 1] = false;
	int index = getIndex(set_bit);
	if(status[index] > 0) 
	{
		memcpy(set_bit, temp_set_bit, sizeof(temp_set_bit));
		return true;
	}
	if(status[index] < 0) 
	{
		memcpy(set_bit, temp_set_bit, sizeof(temp_set_bit));
		return false;
	} 
	
	for(int i = 1; i < 20; i++)
	{
		if(set_bit[i] && !dfs(i))
		{
			memcpy(set_bit, temp_set_bit, sizeof(temp_set_bit));
			status[index] = 1;
			return true;
		}
	}
	
	memcpy(set_bit, temp_set_bit, sizeof(temp_set_bit));
	status[index] = -1;
	return false;
}

int main()
{
	int n, num_case = 0, temp, index, count;
	while(cin >> n)
	{
		if(!n) break;
		memset(set_bit, false, sizeof(set_bit));
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			set_bit[temp - 1] = true;
		}
		index = getIndex(set_bit);
		
		count = 0;
		for(int i = 1; i < 20; i++)	if(set_bit[i] && !dfs(i)) answer[count++] = i;
		
		cout << "Test Case #" << ++num_case << endl; 
		if(!count) 
		{
			status[index] = -1;
			cout << "There's no winning move." << endl;
		}
		else
		{
			cout << "The winning moves are: ";
			for(int i = 0; i < count; i++) cout << answer[i] + 1 << " ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

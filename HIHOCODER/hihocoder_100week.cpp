#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

class node
{
public:
	int num;
	int similar;
	int depth;
	node(int one, int two, int three){num = one; similar = two; depth = three;}
};

int factor[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dest_array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int array[9];
bool set[362880];
deque<node> q;

void int2array(int num)
{
	int a[9];
	int used[9];
	for(int i = 8; i >= 0; i--)
	{
		a[8 - i] = num / factor[i];
		num = num % factor[i];
	}
	
	memset(used, false, sizeof(used));
	for(int i = 0; i <= 8; i++)
	{
		int temp_a = a[i] + 1;
		int j = 0;
		while(true)
		{
			if(used[j] == false) temp_a--;
			if(temp_a == 0)
			{
				used[j] = true;
				array[i] = j;
				break;
			}
			j++;
		}
	}
}

int array2int(int* arr)
{
	int num = 0;
	for(int i = 0; i <= 8; i++)
	{
		int more = 0;
		for(int j = i + 1; j <= 8; j++) if(arr[j] < arr[i]) more++;
		num = num + more * factor[8 - i];
	}
	return num;
}

int similar_degree(int* arr)//越往0靠近越好 
{
	int degree = 0;
	for(int i = 0; i < 9; i++) if(arr[i] != dest_array[i]) degree++;
	return degree;
}

void bfs()
{
	int now_num = array2int(array);
	int now_similar = similar_degree(array);
	int now_depth = 0;
	set[now_num] = true;
	q.push_back(node(now_num, now_similar, now_depth));
	
	int temp_num, temp_similar, temp_depth;
	int temp_array[9];
	
	int x0, y0, x1, y1;
	
	while(!q.empty())
	{
		now_num = q.front().num;
		now_similar = q.front().similar;
		now_depth = q.front().depth;
		int2array(now_num);
		if(now_similar == 0) break;
		
		for(int i = 0; i < 9; i++)
		{
			temp_array[i] = array[i];
			if(array[i] == 0)
			{
				x0 = i / 3;
				y0 = i % 3;
			}
		}
		if(x0 > 0)
		{
			x1 = x0 - 1;
			y1 = y0;
			temp_array[x0 * 3 + y0] = temp_array[x1 * 3 + y1];
			temp_array[x1 * 3 + y1] = 0;
			temp_num = array2int(temp_array);
			temp_similar = similar_degree(temp_array);
			temp_depth = now_depth + 1;
			if(set[temp_num] == false)//temp_similar <= now_similar && 
			{
				set[temp_num] = true;
				q.push_back(node(temp_num, temp_similar, temp_depth));
			}
			
			temp_array[x1 * 3 + y1] = temp_array[x0 * 3 + y0];
			temp_array[x0 * 3 + y0] = 0;
		}
		if(x0 < 2)
		{
			x1 = x0 + 1;
			y1 = y0;
			temp_array[x0 * 3 + y0] = temp_array[x1 * 3 + y1];
			temp_array[x1 * 3 + y1] = 0;
			temp_num = array2int(temp_array);
			temp_similar = similar_degree(temp_array);
			temp_depth = now_depth + 1;
			if(set[temp_num] == false)
			{
				set[temp_num] = true;
				q.push_back(node(temp_num, temp_similar, temp_depth));
			}
			
			temp_array[x1 * 3 + y1] = temp_array[x0 * 3 + y0];
			temp_array[x0 * 3 + y0] = 0;
		}
		if(y0 > 0)
		{
			x1 = x0;
			y1 = y0 - 1;
			temp_array[x0 * 3 + y0] = temp_array[x1 * 3 + y1];
			temp_array[x1 * 3 + y1] = 0;
			temp_num = array2int(temp_array);
			temp_similar = similar_degree(temp_array);
			temp_depth = now_depth + 1;
			if(set[temp_num] == false)
			{
				set[temp_num] = true;
				q.push_back(node(temp_num, temp_similar, temp_depth));
			}
			
			temp_array[x1 * 3 + y1] = temp_array[x0 * 3 + y0];
			temp_array[x0 * 3 + y0] = 0;
		}
		if(y0 < 2)
		{
			x1 = x0;
			y1 = y0 + 1;
			temp_array[x0 * 3 + y0] = temp_array[x1 * 3 + y1];
			temp_array[x1 * 3 + y1] = 0;
			temp_num = array2int(temp_array);
			temp_similar = similar_degree(temp_array);
			temp_depth = now_depth + 1;
			if(set[temp_num] == false)
			{
				set[temp_num] = true;
				q.push_back(node(temp_num, temp_similar, temp_depth));
			}
			
			temp_array[x1 * 3 + y1] = temp_array[x0 * 3 + y0];
			temp_array[x0 * 3 + y0] = 0;
		}
		
		
		q.pop_front();
	}
	
	if(similar_degree(array) == 0) cout << now_depth << endl;
	else cout << "No Solution!" << endl;
	q.clear();
}

int main()
{
	int num_case;
	cin >> num_case;
	while(num_case--)
	{
		for(int i = 0; i < 9; i++) cin >> array[i];
		
		memset(set, false, sizeof(set));
		bfs();
	}
	return 0;
}

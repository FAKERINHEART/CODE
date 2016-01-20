#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

class V
{
public:
	int B;
	int P;
	int order;	
};

V value[10000];

bool cmp(V one, V two)
{
	if(one.B == two.B)
	{
		if(one.P == two.P) return one.order < two.order;
		return one.P < two.P;
	}
	return one.B < two.B;
}

int main()
{
	int num_test, num_requirement, num_manufacture, num;
	cin >> num_test;
	for(int i = 0; i < num_test; i++)
	{
		num = 0;
		cin >> num_requirement;
		bool* visited = new bool[num_requirement];
		int* max_value_B = new int[num_requirement];
		
		for(int j = 0; j < num_requirement; j++)
		{
			max_value_B[j] = -1;
			cin >> num_manufacture;
			for(int k = 0; k < num_manufacture; k++)
			{
				cin >> value[num].B >> value[num].P;
				value[num].order = j;
				if(max_value_B[j] < value[num].B) max_value_B[j] = value[num].B;
				num++;
			}
		}
		sort(value, value + num, cmp);
		
		double sum_P, B_P = 0;
		bool flag = false;
		int count;
		
		for(int j = 0; j <= num - num_requirement; j++)
		{
			memset(visited, false, num_requirement * sizeof(bool));
			visited[value[j].order] = true;
			sum_P = value[j].P;
			count = 1;
			
			for(int k = j + 1; k < num; k++)
			{
				if(value[j].B > max_value_B[value[k].order])
				{
					flag = true;
					break;
				} 
				if(visited[value[k].order]) continue;
				visited[value[k].order] = true;
				sum_P += value[k].P;
				count++;	
			}
			if(flag || count < num_requirement) break;
			
			if(B_P < value[j].B / sum_P) B_P = value[j].B / sum_P;
		}
		
		cout << fixed << setprecision(3) << B_P << endl; 
		
		delete[] visited; 
		delete[] max_value_B;
	}
	return 0;	
} 

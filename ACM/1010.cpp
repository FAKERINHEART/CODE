#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int value[100];
int size;
int customer;
int solution[100];
int best_solution[100];
int num_best_solution;

int num_best;
int kind_best;
int MAX_BEST;

void test(int sub, int temp_customer, int remained)
{
	if(temp_customer < customer)
	{
		if(remained == 0) return;
		else
		{
			remained--;
			
			for(int i = sub; i < size; i++)
			{
				solution[i]++;
				test(i, temp_customer + value[i], remained);
				solution[i]--;
			} 
			remained++;	
			return;
		}
	}
	else if(temp_customer == customer)
	{		
		if(!memcmp(solution, best_solution, size * sizeof(int))) return;
		
		int kind = 0, num = 0, MAX = 0;
		for(int i = 0; i < size; i++)
		{
			if(solution[i] != 0)
			{
				kind++;
				num += solution[i];
				if(value[i] > MAX) MAX = value[i];
			}
		}
		
		if(num_best_solution == 0)
		{
			kind_best = kind;
			num_best = num;
			MAX_BEST = MAX;
			for(int i = 0; i < size; i++) best_solution[i] = solution[i];
			num_best_solution = 1;
		}
		else
		{
			if(kind > kind_best || kind == kind_best && num < num_best || kind == kind_best && num == num_best && MAX > MAX_BEST)
			{
				kind_best = kind;
				num_best = num;
				MAX_BEST = MAX;
				for(int i = 0; i < size; i++) best_solution[i] = solution[i];
				num_best_solution = 1;
			}
			else if(kind == kind_best && num == num_best && MAX == MAX_BEST) num_best_solution++;
		}
		return;
	}
	else return;
}

int main()
{
	int temp_value;
	size = 0;
	
	while(cin >> temp_value)
	{
		value[size] = temp_value;
		size++;
		
		if(!temp_value)
		{	
			size--;
			sort(value, value + size);		
			while(cin >> customer)
			{
				memset(solution, 0, size * sizeof(int));
				memset(best_solution, 0, size * sizeof(int));
				num_best_solution = 0;
				
				if(!customer) break;
				for(int i = 0; i < size; i++ ) test(i, 0, 4);
				
				if(num_best_solution == 0) cout << customer << " ---- none" << endl;
				else if(num_best_solution == 1)
				{
					cout << customer << " (" << kind_best << "): ";
					for(int i = 0; i < size; i++) for(int j = 0; j < best_solution[i]; j++) cout << value[i] << " ";	
					cout << endl;
				}
				else cout << customer << " (" << kind_best << "): tie" << endl;		
			}
			size = 0;
		}
	}
	return 0;
}

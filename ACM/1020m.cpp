#include <iostream>
#include <cstring>

using namespace std;

int requirement[11];
int value_col[40];
int length_side;
int num_person;

bool test2(int one, int two)
{
	for(int i = one; i <= one + two - 1; i++) if(value_col[one] < value_col[i]) return false;
	return true;
}

bool test(int num_found)
{
	if(num_found == num_person) return true;
	
	int temp;
	for(int i = 1; i <= 10; i++)
		if(requirement[i])
		{
			temp = i;
			break;
		}
	
	int Min = 100, Sub_Min;
	for(int i = 0; i < length_side; i++)
	{
		if(Min > value_col[i] && test2(i, temp))
		{
			Min = value_col[i];
			Sub_Min = i;
		}
	}
	
	if(Min == 100) return false;
	
	for(int i = 10; i >= 1; i--)
	{
		if(!requirement[i]) continue;
		
		if(value_col[Sub_Min] + i <= length_side && Sub_Min + i <= length_side)
		{
			int temp_width = 0;
			for(int j = Sub_Min; j <= Sub_Min + i - 1; j++)
			{
				if(value_col[j] == value_col[Sub_Min]) temp_width++;
				else break;
			}
			
			if(temp_width == i)
			{
				requirement[i]--;
				for(int j = Sub_Min; j <= Sub_Min + i - 1; j++) value_col[j] += i;
				if(test(num_found + 1)) return true;
				requirement[i]++;
				for(int j = Sub_Min; j <= Sub_Min + i - 1; j++) value_col[j] -= i;
			}
		}
	}
	
	return false;
}


int main()
{
	int num_case, temp;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		memset(requirement, 0, 11 * sizeof(int));
		memset(value_col, 0, 40 * sizeof(int));
		cin >> length_side >> num_person;
		int num_more_than_half_of_size = 0, sum_requirement_area = 0;
		for(int j = 0; j < num_person; j++)
		{	
			cin >> temp;
			requirement[temp]++;
			if(temp > length_side / 2) num_more_than_half_of_size++;
			sum_requirement_area += (temp * temp);
		} 
		
		if(num_more_than_half_of_size > 1 || sum_requirement_area > length_side * length_side) cout << "HUTUTU!" << endl;
		else if(test(0)) cout << "KHOOOOB!" << endl;
		else cout << "HUTUTU!" << endl;
	}
	return 0;
}

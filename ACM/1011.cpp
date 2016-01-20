#include <iostream>

using namespace std;

int parts[64][3];//Сľ����Ϣ[0]Ϊ����,[1]Ϊ�Ƿ�ʹ�ù�,[2]Ϊ������ֵ��С����һ������λ��,��û�и�С����ֵ��Ϊ-1 
int num_parts;//Сľ��ĸ��� 
int max_parts;//Сľ�����󳤶� 
int sum_length_stick;//���д�ľ�����ܳ��� 
int unused_num_parts;//δʹ�õ�Сľ����� 
int test_length_stick;//���Եĵ���ľ������ 
int sub_head_part_of_stick;//һ��ľ����ͷһ��ľ���±� 

bool compute_arrangement(int substract, int sub_now_part)
{
	unused_num_parts--;
	parts[sub_now_part][1] = 1;
	if(parts[sub_now_part][0] < substract)
	{
		substract -= parts[sub_now_part][0];
		for(int i = sub_now_part + 1; i < num_parts;)
		{
			if(parts[i][1] == 0 && parts[i][0] <= substract)
			{
				if(compute_arrangement(substract, i)) return true;
				else
				{
					i = parts[i][2];
					if(i == -1) break;
				}
			}
			else
			{
				if(parts[i][0] > substract)
				{
					i = parts[i][2];
					if(i == -1) break;
				}
				else i++;
			}
		}
		unused_num_parts++;
		parts[sub_now_part][1] = 0;
		return false;
	}
	else if(parts[sub_now_part][0] == substract)
	{
		if(unused_num_parts == 0) return true;
		else 
		{
			substract = test_length_stick;
			int temp = sub_head_part_of_stick;
			for(int i = sub_head_part_of_stick + 1; i < num_parts;)
			{
				if(parts[i][1] == 0)
				{
					sub_head_part_of_stick = i;
					if(compute_arrangement(substract, i)) return true;
					else
					{
						sub_head_part_of_stick = temp;
						unused_num_parts++;
						parts[sub_now_part][1] = 0;
						return false;
					}
				}
				else i++;
			}
			sub_head_part_of_stick = temp;
			unused_num_parts++;
			parts[sub_now_part][1] = 0;
			return false; 
		}
	}
}

int main()
{
	while(cin >> num_parts)
	{
		if(!num_parts) break;
		sum_length_stick = 0;
		int temp;
		for(int i = 0; i < num_parts; i++)
		{
			cin >> temp;
			sum_length_stick += temp;//����Сľ���ܳ� 
			
			//���� 
			if(i == 0) parts[i][0] = temp;
			else
			{
				int j;
				for(j = 0; j < i; j++)
				{
					if(temp > parts[j][0])
					{
						for(int k = i; k >= j + 1; k--) parts[k][0] = parts[k - 1][0];
						break;
					}
				}		
				parts[j][0] = temp;					
			}
		}
		
		//����Сľ����ֵ�����仯ʱ,λ�õ���Ծ��С
		temp = -1;
		for(int i = num_parts - 1; i >= 0; i--)
		{
			parts[i][2] = temp;
			if(i && parts[i - 1][0] > parts[i][0]) temp = i;
		}		 
		
		unused_num_parts = num_parts;//ȫ��Сľ�鶼δ��ʹ�ù� 
		for(int j = 0; j < num_parts; j++) parts[j][1] = 0;//Сľ��δ��ʹ�ù� 
		
		//��ʼ���� 
		max_parts = parts[0][0];
		for(int i = max_parts; i <= sum_length_stick; i++)
		{
			if(sum_length_stick % i == 0)
			{
				test_length_stick = i;
				sub_head_part_of_stick = 0;
				if(compute_arrangement(i, 0))
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}

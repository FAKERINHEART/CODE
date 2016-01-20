#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <string>

using namespace std;

void mutiply(int* &result, int &size_result, int* int_str, int size_str)
{
	int* new_result = new int[size_str + size_result];
	memset(new_result, 0, sizeof(int) * (size_str + size_result));
	
	int carry = 0;//乘法的进位信息 
	for(int i = size_str - 1; i >= 0; i--)
	{
		for(int j = size_result - 1; j >= 0; j--)
		{
			int temp = (int_str[i] * result[j] + carry) % 10 + new_result[i + j + 1];
			carry = (int_str[i] * result[j] + carry) / 10;
			new_result[i + j + 1] = temp % 10;
			new_result[i + j] += temp / 10;
			if(j == 0) new_result[i] += carry % 10;
		}
		carry = 0;
	}	
	
	//测算新的结果共有几位,从左边起第一个不为0的数 
	for(int i = 0; i < size_str + size_result; i++) 
	{
		if(new_result[i]) 
		{
			//此行要删除原有的result,并new新的result
			delete[] result;
			result = new int[size_str + size_result - i];
			for(int j = 0; j < size_str + size_result - i; j++) result[j] = new_result[i + j];
			size_result = size_str + size_result - i;
			break;
		}
		if(i == size_str + size_result - 1 && !new_result[i])//新的result为0
		{
			delete[] result;
			result = new int[1];
			result[0] = 0;
			size_result = 1;
			break;
		}
	}
	delete[] new_result; 
}

void ExponentiationOperation(string str, int int_num)
{
	bool dot_existed = false;//小数点是否存在
	int dot_sub = 0;//小数点位置
	for(int i = 0; i < str.length(); i++) 
		if(str[i] == '.') 
		{
			dot_existed = true;
			break;
		}
	//去掉小数点最后面的0
	if(dot_existed)
	{
		for(int i = str.length() - 1; i >= 0; i--)
		{
			if(str[i] == '0') str.erase(i);
			else break;
		}
		
		for(int i = 0; i < str.length(); i++) 
		{
			if(str[i] == '.') 
			{	
				dot_sub = str.length() - 1 - i;
				break;
			}
		}	
	}
	
	dot_sub *= int_num;
	int* int_value;
	int size_value;
	if(dot_existed) size_value = str.length() - 1;
	else size_value = str.length();
	int_value = new int[size_value];
	
	for(int i = 0, j = 0; i < size_value; i++)
	{
		if(str[i] == '.') j = 1;
		int_value[i] = str[i + j] - '0';
	}
	
	int size_result = size_value;
	int* result = new int[size_result];
	for(int j = 0; j < size_result; j++) result[j] = int_value[j];
    
	for(int i = 1; i <= int_num - 1; i++) mutiply(result, size_result, int_value, size_value);

	string output = "";
	if(dot_sub >= size_result)
	{
		output.append(1, '.');
		for(int i = 1; i <= dot_sub - size_result; i++) output.append(1, '0');
		for(int j = 0; j < size_result; j++) output.append(1, '0' + result[j]);
	}
	else
	{
		for(int j = 0; j < size_result; j++)
		{
			if(j == size_result - dot_sub) output.append(1, '.');
			output.append(1, '0' + result[j]);
		}
	}
	
	cout << output << endl;
	
	delete[] result;
	delete[] int_value;
}

int main()
{
	char temp[6]; 
	int n;
	while(cin >> temp >> n)
	{
		ExponentiationOperation(temp, n); 
	}
	return 0;
}

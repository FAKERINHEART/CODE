#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int num_String, num_charOfString;
	cin >> num_charOfString >> num_String;
	string str[num_String], temp_str;
	int unsortedness[num_String], temp_int;
	for(int i = 0; i < num_String; i++)
	{
		unsortedness[i] = 0;
		cin >> str[i];
		for(int j = 0; j < num_charOfString; j++) for(int k = j + 1; k < num_charOfString; k++) if(str[i][j] > str[i][k]) unsortedness[i]++;
	}
	for(int i = 0; i < num_String; i++)
	{
		for(int j = i + 1; j < num_String; j++)
		{
			if(unsortedness[i] > unsortedness[j])
			{
				temp_str = str[i];
				str[i] = str[j];
				str[j] = temp_str;
				temp_int = unsortedness[i];
				unsortedness[i] = unsortedness[j];
				unsortedness[j] = temp_int;
			}
		}
	}
	for(int i = 0; i < num_String; i++) cout << str[i] << endl;
	
	return 0;
}

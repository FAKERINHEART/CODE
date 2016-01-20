#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char object[1000010], pattern[10010];

int KMP()
{
	int length_object = strlen(object), length_pattern = strlen(pattern);
	if(!length_object || !length_pattern) return 0;
	int next[length_pattern + 1];
	int count = 0;
	
	int i = 0, j = -1;
	next[0] = -1;
	while(i < length_pattern)
	{
		if(j == -1 || pattern[j] == pattern[i])
		{
			j++;
			i++;
			next[i] = j;
		}
		else j = next[j];
	}
	
	i = 0, j = 0;
	while(i < length_object)
	{
		if(j == -1 || pattern[j] == object[i])
		{
			j++;
			i++;
		}
		else j = next[j];
		if(j == length_pattern) count++;
	}
	return count;
}

int main()
{
	int num;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		scanf("%s", pattern);
		scanf("%s", object);
		cout << KMP() << endl;	
	}
	return 0;
} 

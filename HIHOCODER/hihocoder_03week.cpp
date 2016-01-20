#include <iostream>
#include <string>

using namespace std;

string object, pattern;

int KMP()
{
	int length_object = object.length(), length_pattern = pattern.length();
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
		cin >> pattern >> object;
		cout << KMP() << endl;	
	}
	return 0;
} 

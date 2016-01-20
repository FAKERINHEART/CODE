#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char pattern[1000010];
int next[1000010];

void KMP()
{
	int length_pattern = strlen(pattern);
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
	
	if(length_pattern % (length_pattern - next[length_pattern]) == 0) cout << length_pattern / (length_pattern - next[length_pattern]) << endl;
	else cout << 1 << endl;
	return;
}

int main()
{
	while(scanf("%s", pattern))
	{
		if(!strcmp(pattern, ".")) break;
		KMP();
	}
	return 0;
} 

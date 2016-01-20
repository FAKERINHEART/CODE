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
	return;
}

int main()
{
	int num;
	int num_case = 0; 
	while(1)
	{
		scanf("%d", &num);
		if(!num) break;
		num_case++;
		scanf("%s", pattern);
		KMP();
		cout << "Test case #" << num_case << endl;
		for(int i = 1; i <= num; i++) if(next[i] && i % (i - next[i]) == 0) cout << i << " " << i / (i - next[i]) << endl;
		cout << endl;
	}
	return 0;
} 

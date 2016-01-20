#include <iostream>
#include <string>

using namespace std;

string pattern;
int next[400001];
int a[400001];

void KMP()
{
	int length_pattern = pattern.length();
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
	while(cin >> pattern)
	{
		KMP(); 
		int sub = 1, i = next[pattern.length()];
		a[0] = pattern.length();
		while(i > 0)
		{
			a[sub++] = i;
			i = next[i];
		}
		for(int j = sub - 1; j >= 0; j--) cout << a[j] << " ";
		cout << endl;
	}
	return 0;
} 

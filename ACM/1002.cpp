#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	long int num;
	cin >> num;
	string s[100000];
	for(long int i = 0; i < num; i++) 
	{
		cin >> s[i]; 
		for(long int j = 0; j < s[i].length(); j++)
		{
			switch(s[i][j])
			{
			case 'A': case 'B': case 'C': s[i][j] = '2'; break;
			case 'D': case 'E': case 'F': s[i][j] = '3'; break;
			case 'G': case 'H': case 'I': s[i][j] = '4'; break;
			case 'J': case 'K': case 'L': s[i][j] = '5'; break;
			case 'M': case 'N': case 'O': s[i][j] = '6'; break;
			case 'P': case 'R': case 'S': s[i][j] = '7'; break;
			case 'T': case 'U': case 'V': s[i][j] = '8'; break;
			case 'W': case 'X': case 'Y': s[i][j] = '9'; break;
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': break;
			default: s[i].erase(j, 1); j--; break; 
			}
		}
	}
	
	sort(s, s + num);
	
	long int index = 1;
	long int shown = 0;
	for(long int i = 1; i < num; i++)
	{
		if(s[i] == s[i - 1]) index++;
		else
		{
			if(index > 1)
			{
				shown = 1;
				s[i - 1].insert(3, 1, '-');
				cout << s[i - 1] << " " << index << endl;
			}
			index = 1;
		}
	}
	if(index > 1)
	{
		shown = 1;
		s[num - 1].insert(3, 1, '-');
		
		cout << s[num - 1] << " " << index << endl;
	}
	if(shown == 0) cout << "No duplicates." << endl;
	
	return 0;
}

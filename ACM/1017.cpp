#include <iostream>

using namespace std;

int main()
{
	int n1, n2, n3, n4, n5, n6;
	int num;
	while(cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6)
	{
		num = 0;
		if(!n1 && !n2 && !n3 && !n4 && !n5 && !n6) break;
		num += n6;
		num += n5;
		num += n4;
					
		if(n5 * 11 >= n1) n1 = 0;	
		else n1 -= (n5 * 11);
		
		if(n4 * 5 >= n2)
		{
			if((n4 * 5 - n2) * 4 >= n1) n1 = 0;
			else n1 -= ((n4 * 5 - n2) * 4);
			n2 = 0;
		} 
		else n2 -= (n4 * 5);
		
		num += (n3 / 4);
		if(n3 % 4)
		{
			num += 1;
			if(n3 % 4 == 3)
			{
				if(1 >= n2)
				{
					if(9 - n2 * 4 >= n1) n1 = 0;
					else n1 -= (9 - n2 * 4);
					n2 = 0;
				}
				else
				{
					if(5 >= n1) n1 = 0;
					else n1 -= 5;
					n2 -= 1;
				} 
			}
			else if(n3 % 4 == 2)
			{
				if(3 >= n2)
				{
					if(18 - n2 * 4 >= n1) n1 = 0;
					else n1 -= (18 - n2 * 4);
					n2 = 0;
				}
				else 
				{
					if(6 >= n1) n1 = 0;
					else n1 -= 6;
					n2 -= 3;
				}
			}
			else if(n3 % 4 == 1)
			{
				if(5 >= n2)
				{
					if(27 - n2 * 4 >= n1) n1 =0;
					else n1 -= (27 - n2 * 4);
					n2 = 0;
				}
				else
				{
					if(7 >= n1) n1 =0;
					else n1 -= 7;
					n2 -= 5;
				} 
			} 
			
		}
		
		num += (n2 / 9);
		if(n2 % 9) 
		{
			num += 1;
			if(36 - (n2 % 9) * 4 >= n1) n1 = 0;
			else n1 -= (36 - (n2 % 9)* 4);
		}
		
		num += (n1 / 36);
		if(n1 % 36) num += 1;
		
		cout << num << endl;
	}
	return 0;
}

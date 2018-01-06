#include <iostream>

using namespace std;

char maze[20][20];
int dir[4][2]={{0, 1}, {1, 1}, {1, 0}, {1, -1}};

bool isSucc(char c)
{
    for (int i = 1; i <= 15; ++i)
    {
        for (int j = 1; j <= 15; ++j)
        {			
            for(int d = 0; d < 4; ++d)
            {
                int temp_i = i, temp_j = j;
                int count = 0;
                while (maze[temp_i][temp_j] == c)
				{
					if (++count > 5)
					{
						break;	
					}
					temp_i += dir[d][0];
					temp_j += dir[d][1];
                }
                
                if (count == 5)
				{
					return true;	
				}
            }
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        for (int i = 1; i <= 15; ++i)
        {
            for (int j = 1; j <= 15; ++j)
            {
            	cin >> maze[i][j];
			}
        }

        bool w = isSucc('W');
        bool b = isSucc('B');
        
        if(w == true && b == true)
        {
            cout << "Both" << endl;
        }
        else if (w == true)
		{
			cout << "White" << endl;
		}
        else if (b == true)
		{
			cout << "Black" << endl;
		}
        else
		{
			cout << "None" << endl;
		}
    }
    
    return 0;
}

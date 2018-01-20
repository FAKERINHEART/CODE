#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

int main()
{
    int N, M;
    string str;
    vector<int> words;
    unordered_map<int, pair<int, long long>> m;
    cin >> N >> M;
    
    while (cin >> str)
    {
    	words.push_back(str.length());
	}

	//每一个循环结束的位置, 还没开始输入时结束位置在1行, -1列 
    long long x = 1;
    int y = -1;
    
    for (int i = 1; i <= N; ++i)
	{
		//模拟单次循环 
        for (int j = 0; j < words.size(); ++j)
        {
        	//如果上次单词的结束的位置正好满行, 则换行 
        	if (y == M)
        	{
        		y = 0;
        		++x;
			}
			//无论如何, 单词开始之前都要加一个空格
			++y;
			//如果这次的单词长度加上上次的位置超过一行的长度了, 则换行
			
			if (y + words[j] > M)
			{
				y = 0;
				++x;	
			}
			
			//加长度
			y += words[j];
		}
		
		//寻找是否在map里面已经有相同的循环结束
        if (m.find(y) != m.end())
		{
			//(i - m[y].first)为不用模拟的循环数目, main为剩下需要模拟的循环数目 
            long long remain = (N - i) % (i - m[y].first);
            //计算remain起始的行数 
            x += (N - i) / (i - m[y].first) * (x - m[y].second);
            
            for (int k = 0; k < remain; ++k)
            {
            	for (int j = 0; j < words.size(); ++j)
		        {
		        	//如果上次单词的结束的位置正好满行, 则换行 
		        	if (y == M)
		        	{
		        		y = 0;
		        		++x;
					}
					//无论如何, 单词开始之前都要加一个空格
					++y;
					//如果这次的单词长度加上上次的位置超过一行的长度了, 则换行
					
					if (y + words[j] > M)
					{
						y = 0;
						++x;	
					}
					
					//加长度
					y += words[j];
				}
			}
            break;
        }
        //将此次的循环结束位置插入map里面 
        m[y] = pair<int, long long>(i, x);
    }    
    cout << x << " " << y << endl; 
    
    return 0;
}  

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

	//ÿһ��ѭ��������λ��, ��û��ʼ����ʱ����λ����1��, -1�� 
    long long x = 1;
    int y = -1;
    
    for (int i = 1; i <= N; ++i)
	{
		//ģ�ⵥ��ѭ�� 
        for (int j = 0; j < words.size(); ++j)
        {
        	//����ϴε��ʵĽ�����λ����������, ���� 
        	if (y == M)
        	{
        		y = 0;
        		++x;
			}
			//�������, ���ʿ�ʼ֮ǰ��Ҫ��һ���ո�
			++y;
			//�����εĵ��ʳ��ȼ����ϴε�λ�ó���һ�еĳ�����, ����
			
			if (y + words[j] > M)
			{
				y = 0;
				++x;	
			}
			
			//�ӳ���
			y += words[j];
		}
		
		//Ѱ���Ƿ���map�����Ѿ�����ͬ��ѭ������
        if (m.find(y) != m.end())
		{
			//(i - m[y].first)Ϊ����ģ���ѭ����Ŀ, mainΪʣ����Ҫģ���ѭ����Ŀ 
            long long remain = (N - i) % (i - m[y].first);
            //����remain��ʼ������ 
            x += (N - i) / (i - m[y].first) * (x - m[y].second);
            
            for (int k = 0; k < remain; ++k)
            {
            	for (int j = 0; j < words.size(); ++j)
		        {
		        	//����ϴε��ʵĽ�����λ����������, ���� 
		        	if (y == M)
		        	{
		        		y = 0;
		        		++x;
					}
					//�������, ���ʿ�ʼ֮ǰ��Ҫ��һ���ո�
					++y;
					//�����εĵ��ʳ��ȼ����ϴε�λ�ó���һ�еĳ�����, ����
					
					if (y + words[j] > M)
					{
						y = 0;
						++x;	
					}
					
					//�ӳ���
					y += words[j];
				}
			}
            break;
        }
        //���˴ε�ѭ������λ�ò���map���� 
        m[y] = pair<int, long long>(i, x);
    }    
    cout << x << " " << y << endl; 
    
    return 0;
}  

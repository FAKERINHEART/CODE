#include <iostream>
#include <map>

using namespace std;

int width, height;//图像宽度,高度 
int pairs[1001][2];//数据数组
int row; //数据行数 

int Compute_Value(int num)
{
	for(int i = 1; i < row; i++) if(num <= pairs[i][0]) return pairs[i][1];	
}

int Compute_EDV(int x, int y)
{
	int max = 0;
	int abstract = Compute_Value((y - 1) * width + x);
	
	int temp;
	for(int i = x - 1; i <= x + 1; i++)
	{
		for(int j = y - 1; j <= y + 1; j++)
		{
			if(i >= 1 && i <= width && j >= 1 && j <= height)
			{
				temp = Compute_Value((j - 1) * width + i) - abstract;
				if(temp < 0) temp = -temp;
				if(temp > max) max = temp;
			}
		}	
	}
	return max;
}

int main()
{
	int pair_value, pair_num;//数据
	int num_allpixels;//元素总个数
	map<int, int> EDV;
	while(cin >> width)
	{
		if(!width) break;
		
		cout << width << endl;
		pairs[0][0] = 0;
		pairs[0][1] = -1;
		num_allpixels = 0;
		row = 1;
		
		while(cin >> pair_value >> pair_num)
		{
			if(!pair_value && !pair_num) break;
			num_allpixels += pair_num;
			pairs[row][0] = num_allpixels;
			pairs[row][1] = pair_value;
			++row;
		}
		
		//开始 		
		height = num_allpixels / width;//计算图像高度
		
		for(int i = 0; i < row; i++) 
		{
			
			int x;//x坐标从1~width
			int y;//y坐标从1~height
			
			if((pairs[i][0] + 1) % width == 0)
			{
				x = width;
				y = (pairs[i][0] + 1) / width;
			}
			else
			{
				x = (pairs[i][0] + 1) % width;
				y = (pairs[i][0] + 1) / width + 1;
			}
			
			for(int j = x - 1; j <= x + 1; j++)
			{
				for(int k = y - 1; k <= y + 1; k++) 
				{
					if(j >= 1 && j <= width && k >= 1 && k <= height) EDV.insert(make_pair((k - 1) * width + j, Compute_EDV(j, k)));
				}	
			}	
		}
		
		map<int, int>::const_iterator iter_EDV = EDV.begin();
		map<int, int>::const_iterator iter2_EDV = EDV.begin();
		while(iter_EDV != EDV.end())
		{
			++iter2_EDV;
			while(iter2_EDV != EDV.end() && iter2_EDV->second == iter_EDV->second) ++iter2_EDV;
			if(iter2_EDV == EDV.end()) break;
			cout << iter_EDV->second << " " << iter2_EDV->first - iter_EDV->first << endl;
			iter_EDV = iter2_EDV;
		}
		cout << iter_EDV->second << " " << num_allpixels - iter_EDV->first + 1 << endl;
		//结束 
		cout << "0 0" << endl;
		EDV.clear();
	}
	cout << "0" << endl;
	return 0;
}

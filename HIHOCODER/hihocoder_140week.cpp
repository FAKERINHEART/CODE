#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Rect
{
	int x1, y1;//×óÏÂ 
	int x2, y2; //ÓÒÉÏ 
};

bool check_point_internal(int x, int y, Rect& r)
{
	return (x > r.x1 && x < r.x2) && (y > r.y1 && y < r.y2);
} 

bool check_rect_internal(Rect& p1, Rect& p2)
{
    if (p1.x1 < p2.x1) 
	{
        if (p1.x2 > p2.x1 && p1.y1 < p2.y2 && p1.y2 > p2.y1) return true;
    } 
	else 
	{
        if (p1.x1 < p2.x2 && p1.y1 < p2.y2 && p1.y2 > p2.y1) return true;
    }
    return false;
}

int main()
{
	int W, H, N;
	cin >> W >> H >> N;
	Rect rect[N + 1];
	bool point_internal[N + 1][5];
	bool rect_internal[N + 1][N + 1];
	memset(point_internal, false, sizeof(point_internal));
	memset(rect_internal, false, sizeof(rect_internal));
	
	for(int i = 1; i <= N; i++) cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
	
	for(int i = N; i >= 1; i--)
	{
		rect_internal[i][i] = 1;
		for(int j = i + 1; j <= N; j++)
		{
			if(check_point_internal(rect[i].x1, rect[i].y1, rect[j])) point_internal[i][1] = true;
			if(check_point_internal(rect[i].x2, rect[i].y1, rect[j])) point_internal[i][2] = true;
			if(check_point_internal(rect[i].x2, rect[i].y2, rect[j])) point_internal[i][3] = true;
			if(check_point_internal(rect[i].x1, rect[i].y2, rect[j])) point_internal[i][4] = true;
			if(check_rect_internal(rect[i], rect[j]))
			{
				rect_internal[i][j] = true;
				for(int k = j + 1; k <= N; k++) if (rect_internal[j][k]) rect_internal[i][k] = true;
			}
		}
	}
	
	int MAX_NUM = 0, MAX_INDEX = 0;
	int flag;
	int temp_NUM;
	for(int i = 1; i <= N; i++)
	{
		flag = true;
		for(int j = 1; j <= 4; j++) flag &= point_internal[i][j];
		if(flag) continue;
		temp_NUM = 0;
		for(int j = 1; j <= N; j++) if(rect_internal[i][j])	temp_NUM++;
		if(temp_NUM > MAX_NUM)
		{
			MAX_NUM = temp_NUM;
			MAX_INDEX = i;
		}
	}
	cout << MAX_NUM << " " << MAX_INDEX << endl;
	return 0;
} 

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct point
{
	int x;
	int y;
	int sub;
	int L;	
	double ans;
};

bool comp1(point one, point two) {return one.x > two.x; }
bool comp2(int x, int y){return x < y; }
bool comp3(point one, point two) {return one.sub < two.sub; }

int main()
{
	int N;
	cin >> N;
	
	point ps[N];
	int sort_y[N];
	double sort_t[N], temp;
	for(int i = 0; i < N; i++)
	{
		cin >> ps[i].x >> ps[i].y >> ps[i].L;
		ps[i].sub = i;
		
		sort_y[i] = ps[i].y;
		sort_t[i] = 0;
	}
	sort(ps, ps + N, comp1);
	sort(sort_y, sort_y + N, comp2);
	
	for(int i = 0; i < N; i++)
	{
		temp = 0;
		int temp_position = ps[i].x;
		for(int j = 0; j < N; j++)
		{
			if(sort_y[j] > ps[i].x)
			{
				temp += ((sort_y[j] - temp_position) * 1.0 / ps[i].L);
				temp = max(temp, sort_t[j]);
				sort_t[j] = temp;
				if(sort_y[j] == ps[i].y)
				{
					ps[i].ans = temp;
					break;
				}	
				temp_position = sort_y[j];
			} 
		}
	}
	sort(ps, ps + N, comp3);
	for(int i = 0; i < N; i++) cout << fixed << setprecision(2) << ps[i].ans << endl;
	return 0;
}

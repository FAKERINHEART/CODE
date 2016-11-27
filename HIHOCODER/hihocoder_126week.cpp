#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
long long const r = 6000000;//地球半径 
double const PI = 3.14159265;//PI 
int const PRECISION = 6;

struct point
{
	double x;
	double y;
	point(double _x, double _y): x(_x), y(_y){}
};

struct box
{
	double min_x, max_x;
	double min_y, max_y;
};

map<string, vector<point> > m;


void Encode(double latitude, double longitude, int precision, string& geohash, box& b) 
{
	double latitudeInterval[2] = {-90, 90};
	double longitudeInterval[2] = {-180, 180};
	double mid;
	int length = precision * 5;
	int bits = 0;

	if(longitude > longitudeInterval[1]) longitude -= 360;
	if(longitude < longitudeInterval[0]) longitude += 360;
	if(latitude > latitudeInterval[1]) latitude = 180 - latitude;
	if(latitude < latitudeInterval[0]) latitude = -180 - latitude;

	for(int i = 1; i <= length; ++i) 
	{
		if(i & 1) 
		{
			mid = (longitudeInterval[0] + longitudeInterval[1]) / 2;
			if(longitude > mid) 
			{
				bits = bits * 2 + 1;
				longitudeInterval[0] = mid;
			} 
			else 
			{
				bits = bits * 2;
				longitudeInterval[1] = mid;
			}
		} 
		else 
		{
			mid = (latitudeInterval[0] + latitudeInterval[1]) / 2;
			if(latitude > mid) 
			{
				bits = bits * 2 + 1;
				latitudeInterval[0] = mid;
			} 
			else 
			{
				bits = bits * 2;
				latitudeInterval[1] = mid;
			}
		}

		if(i % 5 == 0) 
		{
			geohash += base32[bits];
			bits = 0;
		}
	}
	b.min_x = latitudeInterval[0];
	b.max_x = latitudeInterval[1];
	b.min_y = longitudeInterval[0];
	b.max_y = longitudeInterval[1];
	return;
}

int caculate(string str, double x, double y)
{
	int count = 0;
	map<string, vector<point> >::iterator iter = m.find(str);
	if(iter != m.end())
	{
		for(int j = 0; j < (iter->second).size(); ++j)
		{
			double value = cos(x * PI / 180) * cos((iter->second)[j].x * PI / 180) * cos((y - (iter->second)[j].y) * PI / 180)
			 				+ sin(x * PI / 180) * sin((iter->second)[j].x * PI / 180);
			if(value > 1) value = 1;
			if(value < -1) value = -1;
			if(r * acos(value) <= 500) 
			{
				++count;
			}
		}
	}
	return count;
}

int main()
{
	int N, M;
	double x, y;
	double min_x, max_x, min_y, max_y;
	box b;
	string str;
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		str = "";
		Encode(x, y, PRECISION, str, b);
		//cout << str << endl;
		map<string, vector<point> >::iterator iter = m.find(str);
		if(iter == m.end())
		{
			m[str] = vector<point>();
			m[str].push_back(point(x, y));
		}
		else
		{
			(iter->second).push_back(point(x, y));
		}
	}

	for(int i = 0; i < M; ++i)
	{
		int count = 0;
		cin >> x >> y;
		
		str = "";
		Encode(x, y, PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		min_x = b.min_x, max_x = b.max_x, min_y = b.min_y, max_y = b.max_y;//所在框的上下边缘 
		
		//右 
		str = "";
		Encode((min_x + max_x) / 2, (min_y + max_y) / 2 + (max_y - min_y), PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		
		//左
		str = "";
		Encode((min_x + max_x) / 2, (min_y + max_y) / 2 - (max_y - min_y), PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		
		//上
		str = "";
		Encode((min_x + max_x) / 2 + (max_x - min_x), (min_y + max_y) / 2, PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y); 
		
		//下 
		str = "";
		Encode((min_x + max_x) / 2 - (max_x - min_x), (min_y + max_y) / 2, PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y); 
		
		//右上 
		str = "";
		Encode((min_x + max_x) / 2 + (max_x - min_x), (min_y + max_y) / 2 + (max_y - min_y), PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		
		//左上 
		str = "";
		Encode((min_x + max_x) / 2 + (max_x - min_x), (min_y + max_y) / 2 - (max_y - min_y), PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		
		//右下 
		str = "";
		Encode((min_x + max_x) / 2 - (max_x - min_x), (min_y + max_y) / 2 + (max_y - min_y), PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		
		//左下 
		str = "";
		Encode((min_x + max_x) / 2 - (max_x - min_x), (min_y + max_y) / 2 - (max_y - min_y), PRECISION, str, b);
		//cout << str << endl;
		count += caculate(str, x, y);
		
		cout << count << endl;
	}

	return 0;
}

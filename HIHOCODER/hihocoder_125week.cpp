#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

char base32[32] = {
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'j', 'k', 'm', 'n', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};
map<char, int> indexBase32 {
	{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
	{'8', 8}, {'9', 9}, {'b', 10}, {'c', 11}, {'d', 12}, {'e', 13}, {'f', 14}, {'g', 15},
	{'h', 16}, {'j', 17}, {'k', 18}, {'m', 19}, {'n', 20}, {'p', 21}, {'q', 22}, {'r', 23},
	{'s', 24}, {'t', 25}, {'u', 26}, {'v', 27}, {'w', 28}, {'x', 29}, {'y', 30}, {'z', 31}
};

void Encode(double latitude, double longitude, int precision, string& geohash) {
	double latitudeInterval[2] = {-90, 90};
	double longitudeInterval[2] = {-180, 180};
	double mid;
	int length = precision * 5;
	int bits = 0;

	for(int i = 1; i <= length; ++i) {
		if(i & 1) {
			mid = (longitudeInterval[0] + longitudeInterval[1]) / 2;
			if(longitude > mid) {
				bits = bits * 2 + 1;
				longitudeInterval[0] = mid;
			} else {
				bits = bits * 2;
				longitudeInterval[1] = mid;
			}
		} else {
			mid = (latitudeInterval[0] + latitudeInterval[1]) / 2;
			if(latitude > mid) {
				bits = bits * 2 + 1;
				latitudeInterval[0] = mid;
			} else {
				bits = bits * 2;
				latitudeInterval[1] = mid;
			}
		}

		if(i % 5 == 0) {
			geohash += base32[bits];
			bits = 0;
		}
	}
	return;
}

void Decode(string geohash, double& x, double& y) 
{
	bool odd = true;
	double latitudeInterval[2] = {-90, 90};
	double longitudeInterval[2] = {-180, 180};
	double mid;
	int bits, bit;
	for(int i = 0; i <= geohash.length() - 1; ++i) 
	{
		bits = indexBase32[geohash[i]];
		for(int j = 4; j >= 0; --j)
		{
			bit = (bits >> j) & 1;
			if(odd)
			{
				mid = (longitudeInterval[0] + longitudeInterval[1]) / 2;
				longitudeInterval[1 - bit] = mid;
			}
			else
			{
				mid = (latitudeInterval[0] + latitudeInterval[1]) / 2;
				latitudeInterval[1 - bit] = mid;
			}
			odd = !odd;
		}
		x = (latitudeInterval[0] + latitudeInterval[1]) / 2;
		y = (longitudeInterval[0] + longitudeInterval[1]) / 2;
	}
	return;
}

int main() {
	int N, M;
	double x, y;
	string str;
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> x >> y;
		str = "";
		Encode(x, y, 10, str);
		cout << str << endl;
	}

	for(int i = 0; i < N; ++i) {
		cin >> str;
		x = 0;
		y = 0;
		Decode(str, x, y);
		cout << setiosflags(ios::fixed) << setprecision(6) << x << " " << y << endl;
	}

	return 0;
}

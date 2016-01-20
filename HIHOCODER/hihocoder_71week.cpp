#include <iostream>

using namespace std;

class points
{
public:
	int x[20];
	int y[20];
	int cnt;
	bool existed;
	int H;
	int W;	
};

int main()
{
	int K;
	int N, M;
	char ch;
	
	cin >> K;
	points p[K];
	for(int i = 0; i < K; i++)
	{
		p[i].cnt = 0;
		cin >> p[i].H >> p[i].W;
		for(int j = 0; j < p[i].H; j++)
		{
			for(int l = 0; l < p[i].W; l++)
			{
				cin >> ch;
				if(ch == '#')
				{
					p[i].x[p[i].cnt] = j;
					p[i].y[p[i].cnt] = l;
					p[i].cnt++;
				}
			}
		}
	}
	
	cin >> N >> M;
	char sky[N][M];
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> sky[i][j];
	
	for(int i = 0; i < K; i++)
	{
		p[i].existed = false;
		for(int j = -p[i].H; j < N && p[i].existed == false; j++)
		{
			for(int l = -p[i].W; l < M && p[i].existed == false; l++)
			{
				int n;
				for(n = 0; n < p[i].cnt; n++) if(j + p[i].x[n] < 0 || j + p[i].x[n] >= N || l + p[i].y[n] < 0 || l + p[i].y[n] >= M || sky[j + p[i].x[n]][l + p[i].y[n]] != '#') break;
				if(n == p[i].cnt) p[i].existed = true;
			}
		}
		if(p[i].existed) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

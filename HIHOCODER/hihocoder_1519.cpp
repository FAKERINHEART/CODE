#include <iostream>
#include <string>
#include <deque>

int N, M;
std::string maze[500];
int dist[500][500];
bool visited[500][500];

int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs(int x, int y)
{
    std::deque<int> q;
    q.push_back(x);
    q.push_back(y);
    visited[x][y] = true;

    while (q.empty() == false)
    {
        int temp_x = q.front();
        q.pop_front();
        int temp_y = q.front();
        q.pop_front();

        for (int i = 0 ; i < 4; ++i)
        {
            int temp_nx = temp_x + direction[i][0];
            int temp_ny = temp_y + direction[i][1];

            if (temp_nx >= 0 && temp_nx < N && temp_ny >= 0 && temp_ny < M && maze[temp_nx][temp_ny] != '#')
            {
                if (maze[temp_nx][temp_ny] == 'T')
                {
                    dist[temp_nx][temp_ny] = dist[temp_x][temp_y] + 1;
                    return;
                }

                while (temp_nx + direction[i][0] >= 0 && temp_nx + direction[i][0] < N && temp_ny + direction[i][1] >= 0
                       && temp_ny + direction[i][1] < M && maze[temp_nx + direction[i][0]][temp_ny + direction[i][1]] != '#')
                {
                    temp_nx += direction[i][0];
                    temp_ny += direction[i][1];

                    if (maze[temp_nx][temp_ny] == 'T')
                    {
                        dist[temp_nx][temp_ny] = dist[temp_x][temp_y] + 1;
                        return;
                    }
                }

                if (visited[temp_nx][temp_ny] == false)
                {
                    q.push_back(temp_nx);
                    q.push_back(temp_ny);
                    dist[temp_nx][temp_ny] = dist[temp_x][temp_y] + 1;
                    visited[temp_nx][temp_ny] = true;
                }
            }
        }

    }

    return;
}

int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> maze[i];
    }

    int tx, ty;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (maze[i][j] == 'S')
            {
                bfs(i, j);
            }
            else if (maze[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }

    std::cout << dist[tx][ty] - 1 << std::endl;

    return 0;
}

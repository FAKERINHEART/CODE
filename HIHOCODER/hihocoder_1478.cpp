#include <iostream>
#include <cstring>
#include <deque>
#include <string>

using namespace std;

int dx[] ={0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool visited[810][810];
int dist[810][810];
bool source[810][810];

struct Node
{
    int x, y;
};

int main()
{
    int N, M;
    std::cin >> N >> M;

    deque<Node> deq;
    deq.clear();

    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin >> str;

        for (int j = 0; j < M; ++j)
        {
            source[i][j] = str[j] - '0';

            if(source[i][j] == false)
            {
                deq.push_back(Node{i, j});
            }
        }
    }

    while (deq.empty() == false)
    {
        Node node = deq.front();
        deq.pop_front();

        for (int i = 0; i <= 3; ++i)
        {
            int node_x = node.x + dx[i];
            int node_y = node.y + dy[i];

            if(node_x >= 0 && node_x < N && node_y >= 0 && node_y < M && visited[node_x][node_y] == false && source[node_x][node_y] == true)
            {
                dist[node_x][node_y] = dist[node.x][node.y] + 1;
                visited[node_x][node_y] = true;
                deq.push_back(Node{node_x, node_y});
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cout << dist[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}


#include <iostream>
#include <utility>
#include <queue>
#include <set>

int n, m, k, q;
std::pair<int,int> Q[10], S, T;
int d[8][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int dis(std::pair<int,int> P)
{
    return abs(P.first - T.first) + abs(P.second - T.second);
}

bool ok(std::pair<int,int> P)
{
    if (P.first < 0 || P.first > n || P.second < 0 || P.second > m)
    {
        return false;
    }

    for (int i = 0; i < q; ++i)
    {
        if (abs(P.first - Q[i].first) + abs(P.second - Q[i].second) < k) 
        {
            return false;
        }
    }

    return true;
}

bool bfs()
{
    std::priority_queue<std::pair<int, std::pair<int, int> > > que;

    if (ok(S) == false || ok(T) == false)
    {
        return false;
    }

    if (S == T)
    {
        return true;
    }

    std::set<std::pair<int, int> > visited;

    que.push(std::make_pair(-dis(S), S));
    visited.insert(S);

    int count = 0;

    while (que.empty() == false)
    {
        std::pair<int, std::pair<int, int> > tm = que.top();
        que.pop();

        ++count;

        if (count > 5e4)
        {
            return false;
        }

        for(int i = 0; i < 8; ++i)
        {
            std::pair<int, int> next = std::make_pair(tm.second.first + d[i][0], tm.second.second + d[i][1]);

            if (ok(next) == true)
            {
                if (visited.find(next) != visited.end())
                {
                    continue;
                }

                if (next == T)
                {
                    return true;
                }

                visited.insert(next);
                que.push(std::make_pair(-dis(next), next));
            }
        }
    }

    return false;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n >> m >> k >> q;
        ++q;

        for (int i = 0;i < q; ++i) 
        {
            std::cin >> Q[i].first >> Q[i].second;
        }

        std::cin >> S.first >> S.second >> T.first >> T.second;

        if (bfs() == true)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

struct MODULE
{
    int V, P, T;

    bool operator<(const MODULE &other) const
    {
        return V > other.V;
    }
};


int main()
{
    int T, N, M, K;
    int C[100005];
    std::vector<int> CS[100005];
    std::vector<int> JARVIS;
    MODULE MODU[100005];

    std::cin >> T;

    while (T--)
    {
        std::cin >> N >> M >> K;

        for (int i = 1; i <= N; ++i)
        {
            CS[i].clear();
            std::cin >> MODU[i - 1].V >> MODU[i - 1].P >> MODU[i - 1].T;
        }

        for (int i = 1; i <= M; ++i)
        {
            std::cin >> C[i];
        }

        std::sort(MODU, MODU + N);

        long long ans = 0;

        for (int i = 0; i < N; ++i)
        {
            if (MODU[i].T != 0)
            {
                continue;
            }
            
            if ((int)CS[MODU[i].P].size() < C[MODU[i].P])
            {
                CS[MODU[i].P].push_back(MODU[i].V);
                ans += MODU[i].V;
            }
        }

        JARVIS.clear();

        for (int i = 0; i < N; ++i)
        {
            if (MODU[i].T == 0)
            {
                continue;
            }

            if ((int)CS[MODU[i].P].size() < C[MODU[i].P])
            {
                JARVIS.push_back(MODU[i].V);
            }
            else if (C[MODU[i].P] > 0)
            {
                JARVIS.push_back(MODU[i].V - CS[MODU[i].P][C[MODU[i].P] - 1]);
            }
                
            --C[MODU[i].P];
        }

        sort(JARVIS.begin(), JARVIS.end());

        for (int i = JARVIS.size() - 1, cnt = 0; i >= 0 && cnt < K; --i, ++cnt)
        {
            if (JARVIS[i] <= 0)
            {
                break;
            }

            ans += JARVIS[i];
        }

        std::cout << ans << std::endl;
    }

    return 0;
}

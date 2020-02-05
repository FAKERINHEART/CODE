#include <iostream>
#include <cstring>

int N, M, T, K1, K2;
int l[1000001], r[1000001];
bool work[1000001];

int main()
{
    memset(work, false, sizeof(work));

    std::cin >> N >> M >> T >> K1 >> K2;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> l[i] >> r[i];

        for (int j = l[i]; j < r[i]; ++j)
        {
            work[j] = true;
        }

        if ((r[i] - l[i]) * K1 > M)
        {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    int ans = 0;
    int crt = 0;

    for (int i = 0; i < T; i++)
    {
        if (work[i] == true)
        {
            if (crt < K1) 
            {
                crt = M - K1;
                ans++;
            }
            else 
            {
                crt -= K1;
            }
        }
        else
        {
            if (crt < K2) 
            {
                crt = M - K2;
                ans++;
            } 
            else 
            {
                crt -= K2;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}


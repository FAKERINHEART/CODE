#include <iostream>
#include <set>

int main()
{
    int N, K, X;
    std::set<int> s;

    std::cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> X;
        s.insert(X);

        std::set<int>::iterator iter = s.find(X);

        int pre, post;

        if (iter != s.begin())
        {
            --iter;
            pre = X - *iter - 1;
            ++iter;
        }
        else
        {
            pre = X - 1;
        }

        ++iter;

        if (iter != s.end())
        {
            post = *iter - X - 1;
        }
        else
        {
            post = N - X;
        }
        if (pre == K || post == K)
        {

            std::cout << i + 1 << std::endl;
            break;
        }
    }

    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>

struct Range
{
    int index_;
    bool is_begin_;
    Range(){}
    Range(int index, bool is_begin): index_(index), is_begin_(is_begin){}

    bool operator<(const Range &one) const
    {
        if (index_ == one.index_)
        {
            return is_begin_ < one.is_begin_;
        }

        return index_ < one.index_;
    }
};

int main()
{
    int N, M, S, E, Q;
    
    std::cin >> N >> M;

    Range ranges[N * 2];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> S >> E;
        ranges[i * 2] = Range(S, true);
        ranges[i * 2 + 1] = Range(E, false);
    }

    std::sort(ranges, ranges + N * 2);

    int count = 0;
    std::vector<int> v;

    for (int i = 0; i < N * 2; ++i)
    {
        if (ranges[i].is_begin_ == false)
        {
            --count;
        }
        else if (++count == M)
        {
            v.push_back(ranges[i].index_);
            v.push_back(ranges[i + 1].index_);
        }
    }

    std::cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        std::cin >> S >> E;

        std::vector<int>::iterator iter_end = std::lower_bound(v.begin(), v.end(), E);

        if (S >= v[v.size() - 1] || E <= v[0] || ((iter_end - v.begin()) % 2 == 0 && *(iter_end - 1) <= S))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

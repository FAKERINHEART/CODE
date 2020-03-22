#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    
    struct num
    {
        int one_;
        int three_;
        num(int one, int three): one_(one), three_(three){}
    };
    
    std::vector<num> v;
    int one_num = 0;
    int three_num = 0;
    int value;
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> value;
        
        if (value == 1)
        {
            ++one_num;
        }
        else if (value == 3)
        {
            ++three_num;
        }
        else
        {
            v.push_back(num(one_num, three_num));
        }
    }

    long long statistics_num = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        statistics_num += v[i].one_ * (three_num - v[i].three_);
    }

    std::cout << statistics_num << std::endl;

    return 0;
}

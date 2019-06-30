
#include <iostream>

int cnt[3][10];
int k1, k2;

bool ok1_sub(int dep)
{
    if (dep > 4)
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (cnt[k1][i] >= 2)
            {
                return true;
            }
        }

        for (int i = 1; i <= 9; ++i)
        {
            if (cnt[k2][i] >= 2)
            {
                return true;
            }
        }

        return false;
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (cnt[k1][i] >= 3)
        {
            cnt[k1][i] -= 3;
            
            if (ok1_sub(dep + 1) == true)
            {
                return true;
            }

            cnt[k1][i] += 3;
        }
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (cnt[k2][i] >= 3)
        {
            cnt[k2][i] -= 3;

            if (ok1_sub(dep+1) == true)
            {
                return true;
            }

            cnt[k2][i] += 3;
        }
    }

    for (int i = 1; i <= 7; ++i)
    {
        if (cnt[k1][i] > 0 && cnt[k1][i + 1] > 0 && cnt[k1][i + 2] > 0)
        {
            --cnt[k1][i];
            --cnt[k1][i + 1];
            --cnt[k1][i + 2];

            if (ok1_sub(dep+1) == true)
            {
                return true;
            }

            ++cnt[k1][i];
            ++cnt[k1][i + 1];
            ++cnt[k1][i + 2];
        }
    }

    for (int i = 1; i <= 7; ++i)
    {
        if (cnt[k2][i] > 0 && cnt[k2][i + 1] > 0 && cnt[k2][i + 2] > 0)
        {
            --cnt[k2][i];
            --cnt[k2][i + 1];
            --cnt[k2][i + 2];

            if (ok1_sub(dep + 1) == true)
            {
                return true;
            }

            ++cnt[k2][i];
            ++cnt[k2][i + 1];
            ++cnt[k2][i + 2];
        }
    }

    return false;
}

bool ok1()
{
    for (k1 = 0; k1 <= 2; ++k1)
    {
        for(k2 = k1; k2 <= 2; ++k2)
        {
            if (ok1_sub(1) == true)
            {
                return true;
            }
        }
    }

    return false;
}

bool ok2()
{
    int num[3];

    for (int i = 0; i <= 2; ++i)
    {
        num[i] = 0;
        
        for(int j = 1; j <= 9; ++j)
        {
            num[i] += cnt[i][j] / 2;
        }
    }

    if (num[0] + num[1] >= 7 || num[2] + num[1] >= 7 || num[2] + num[0] >= 7)
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    std::cin>>n;

    char ss[4];

    for (int i=1; i<=14; i++)
    {
        std::cin >> ss;
        ++cnt[ss[0] - 'a'][ss[1] - '0'];
    }

    if (ok1() == true || ok2() == true)
    {
        std::cout << 0 << std::endl;
        return  0;
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> ss;
        ++cnt[ss[0] - 'a'][ss[1] - '0'];

        if (ok1() == true || ok2() == true)
        {
            std::cout << i << std::endl;
            return 0;
        }
    }

    std::cout << "-1" << std::endl;
    
    return 0;
}


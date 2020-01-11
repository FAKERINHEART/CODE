#include <iostream>
#include <vector>

int n, A[100001][5], dp[100001][121];
int facts[]={1 , 1, 2, 6, 24, 120, 720};
std::vector<int> trans[121];
std::vector<int> lis[121];

std::vector<int> reverse_kangtuo(int n, int k)
{
    int t, vst[8] = {0};
    std::vector<int> s;
    --k;

    for (int i = 0; i < n; ++i)
    {
        t = k/facts[n - i - 1];

        int j;

        for (j = 1; j<=n; j++)
        {
            if (!vst[j])
            {
                if (t == 0) break;
                --t;
            }
            s.push_back(j);
        }

        vst[j] = 1;
        k %= facts[n-i-1];
    }

    return s;
}

int kangtuo(int n, std::vector<int> a)
{
    int i,j,t,sum;
    sum=0;
    for (int i=0; i<n ;++i)
    {
        t=0;
        for(j=i+1;j<n;++j)
            if( a[i]>a[j] )
                ++t;
        sum+=t*facts[n-i-1];
    }
    return sum+1;
}

void prep()
{
    for(int i = 1; i <= 120; ++i)
    {
        std::vector<int> st1 = reverse_kangtuo(5, i);
        lis[i]=st1;
        std::vector <int> st2(5);
        st2.assign(st1.begin()+1,st1.begin()+5);st2.push_back(0);
        for(int j=0;j<4;j++)
            if(st2[j]>st1[0]) st2[j]--;
        std::vector <int> st3;
        for(int k=1;k<=5;k++)
        {
            st3=st2;
            st3[4]=k;
            for(int j=0;j<4;j++)
                if(st3[j]>=k) st3[j]++;
            trans[kangtuo(5,st3)].push_back(i);
        }
    }
}

int main()
{
    prep();

    for (int i = 0; i <= 120; ++i)
    {
        for (int j = 0; j < trans[i].size(); ++j)
        {
            std::cout << trans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int T;
    std::cin >> T;
/*
    while(T--)
    {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> z[i][0] >> z[i][1] >> z[i][2] >> z[i][3] >> z[i][4];
        }

        int ans = 1 << 30;

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= 120; ++j)
            {
                dp[i][j] = 1 << 30;
            }
        }

        for (int  j = 1; j <= 120; ++j)
        {
            if (lis[j][3] > 3 && lis[j][4] > 3)
            {
                dp[0][j]=0;
            }
        }

        for(i=1;i<=n;++i)
            for(j=1;j<=120;++j)
                for(k=0;k<5;++k)
                {
                    f[i][j]=min(f[i][j],f[i-1][trans[j][k]]+z[i][5-lis[j][2]]);
                    if(i==n&&lis[j][3]<3&&lis[j][4]<3)
                        ans=min(ans,f[i][j]);
                }
        std::cout << ans << endl;
    }
    */
    return 0;
}


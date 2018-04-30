#include <iostream>

using namespace std;

int main()
{
    int even_num = 0, odd_num = 0;
    
    int N;
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int A;
        
        cin >> A;
        
        if (A & 1)
        {
            ++odd_num;
        }
        else
        {
            ++even_num;
        }
        
    }
    
    int diff = even_num - odd_num;
    
    if (diff < 0)
    {
        diff *= (-1);
    }
    
    std::cout << diff << std::endl;
    
    return 0;
}

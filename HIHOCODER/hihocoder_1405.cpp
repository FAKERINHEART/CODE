#include <iostream>

using namespace std;

int findmin(int A[], int size)
{
    int min = 0;
    
    for (int i = 1; i < size; i++)
    {
    	if (A[i] < A[min])
    	{
    		min = i;	
		} 
	}

    return min;
}

void bheap(int A[], int size)
{
    int minpos = findmin(A, size);
    
	cout << A[minpos] << " ";
    
    if (minpos != 0)
    {
    	bheap(A, minpos);
	}
        
    if (minpos != size - 1)
    {
    	bheap(A + minpos + 1, size - minpos - 1);
	}
    
    return;
}

int main()
{
	int N;
    int A[N];
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
		cin >> A[i];
	}
        
    bheap(A, N);
    
    return 0;
}

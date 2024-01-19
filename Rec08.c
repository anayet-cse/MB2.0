// Print N-digit hexadecimal numbers
#include<stdio.h>
int N, A[100];
void print()
{
    int i;
    for (i=0; i<N; i++)
        if(A[i]>9)
            printf("%X ", A[i]);
        else
            printf("%d ", A[i]);
    printf("\n");
}
void solve(int i)
{
    if (i == N)
    {
        print();
        return;
    }
    for (int j=0; j<16; j++)
    {
        A[i] = j;
        solve(i+1);
    }
}
int main()
{
    scanf("%d", &N);
    solve(0);
    return 0;
}


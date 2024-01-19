// Print all subset
#include<stdio.h>
int N, A[100];
int Set[100];
void print()
{
    int i,flag=-1;
    printf("{");
    for (i=0; i<N; i++)
    {
        if(A[i]==1)
        {
            if(flag==0)
                printf(",");
            printf("%d",Set[i]);
            flag=0;
        }

    }

    printf("}");
    printf("\n");
}
void solve(int i)
{
    if (i == N)
    {
        print();
        return;
    }
    for (int j=0; j<2; j++)
    {
        A[i] = j;
        solve(i+1);
    }
}
int main()
{
    int i;
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (i=0; i<N; i++)
        scanf("%d", &Set[i]);
    solve(0);
    return 0;
}

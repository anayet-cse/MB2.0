#include<stdio.h>
int N, A[100];
int Set[100];
int Total;
int Low;
int absDif(int a, int b) {
    if (a > b)
        return a - b;
    else
        return b - a;
}
void solve(int i) {
    if (i == N) {
        int sum1 = 0, sum2 = 0;
        int j;
        for (j=0; j<N; j++) {
            if (1 == A[j])
                sum1 += Set[j];
        }
        //printf("%d %d\n", sum1, Total - sum1);
        //printf("%d\n", absDif(sum1, Total-sum1));
        int dif = absDif(sum1, Total-sum1);
        if (dif < Low)
            Low = dif;
        return;
    }
    A[i] = 0;
    solve(i+1);
    A[i] = 1;
    solve(i+1);
}
int main() {
    int i;
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    Total = 0;
    for (i=0; i<N; i++) {
        scanf("%d", &Set[i]);
        Total += Set[i];
    }
    Low = Total;
    solve(0);
    printf("%d\n", Low);
    return 0;
}

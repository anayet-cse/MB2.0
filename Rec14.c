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
void solve(int i, int sum1) {
    if (i == N) {
        int sum2 = Total - sum1;
        int dif = absDif(sum1, sum2);
        if (dif < Low)
            Low = dif;
        return;
    }
    solve(i+1, sum1);
    solve(i+1, sum1+Set[i]);
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
    solve(0, 0);
    printf("%d\n", Low);
    return 0;
}

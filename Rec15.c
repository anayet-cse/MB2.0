#include<stdio.h>
int N;
int Set[100];
int Total;
int absDif(int a, int b) {
    if (a > b)
        return a - b;
    else
        return b - a;
}
int solve(int i, int sum1) {
    if (i == N) {
        int sum2 = Total - sum1;
        int dif = absDif(sum1, sum2);
        return dif;
    }
    int left = solve(i+1, sum1);
    int right = solve(i+1, sum1+Set[i]);
    if (left < right)
        return left;
    else
        return right;
}
int main() {
    int T;
    int Case;
    int i;
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (Case = 1; Case<=T; Case++) {
        scanf("%d", &N);
        Total = 0;
        for (i=0; i<N; i++) {
            scanf("%d", &Set[i]);
            Total += Set[i];
        }
        printf("%d\n", solve(0, 0));
    }
    return 0;
}

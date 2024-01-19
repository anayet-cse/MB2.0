#include<stdio.h>
int N, A[100];
int Set[100];
void solve(int i) {
    if (i == N) {
        int sum1 = 0, sum2 = 0;
        int j;
        for (j=0; j<N; j++) {
            if (1 == A[j]) sum1 += Set[j];
            else sum2 += Set[j];
        }
        printf("%d %d\n", sum1, sum2);
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
    for (i=0; i<N; i++)
        scanf("%d", &Set[i]);
    solve(0);
    return 0;
}

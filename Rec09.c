#include<stdio.h>
int N, A[100];
int Set[100];
/*void print() {
    int i;
    int sum = 0;
    for (i=0; i<N; i++)
        printf("%d ", A[i]);
    for (i=0; i<N; i++) if (1 == A[i])
        sum += Set[i];
    printf("= %d\n", sum);
}*/
void solve(int i) {
    if (i == N) {
        int sum = 0;
        int j;
        for (j=0; j<N; j++) if (1 == A[j])
            sum += Set[j];
        printf("%d\n", sum);
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

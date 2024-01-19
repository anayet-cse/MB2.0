#include<stdio.h>
int N, A[100];
void print() {
    int i;
    for (i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void solve(int i) {
    printf("solve(%d) start\n", i);
    if (i == N) {
        print();
        return;
    }
    A[i] = 0;
    solve(i+1);
    A[i] = 1;
    solve(i+1);
    printf("solve(%d) end\n", i);
}
int main() {
    scanf("%d", &N);
    solve(0);
    return 0;
}

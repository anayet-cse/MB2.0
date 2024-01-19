// Print N-digit binary numbers
#include<stdio.h>
int N, A[100];
void print() {
    int i;
    for (i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void solve(int i) {
    if (i == N) {
        print();
        return;
    }
    for (int j=0; j<2; j++) {
        A[i] = j;
        solve(i+1);
    }
}
int main() {
    scanf("%d", &N);
    solve(0);
    return 0;
}

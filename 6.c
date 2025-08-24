#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int N, M;
    scanf("%d", &N);

    long long *A = (long long*)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    qsort(A, N, sizeof(long long), compare);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        long long x;
        scanf("%lld", &x);
        if (bsearch(&x, A, N, sizeof(long long), compare))
            printf("1\n");
        else
            printf("0\n");
    }

    free(A);
    return 0;
}

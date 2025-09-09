#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int cmp_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int A[55], B[55];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);

   
    qsort(A, n, sizeof(int), cmp_asc);

    int B_sorted[55];
    for (int i = 0; i < n; i++) B_sorted[i] = B[i];
    qsort(B_sorted, n, sizeof(int), cmp_desc);

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += A[i] * B_sorted[i];
    }

    printf("%d\n", result);
    return 0;
}



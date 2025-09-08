#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int compare(const void* a, const void* b) {
    Pair* x = (Pair*)a;
    Pair* y = (Pair*)b;
    if (x->value == y->value) return x->index - y->index;
    return x->value - y->value;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[50], P[50];
    Pair arr[50];

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        arr[i].value = A[i];
        arr[i].index = i;
    }

    
    qsort(arr, N, sizeof(Pair), compare);

    
    for (int i = 0; i < N; i++) {
        P[arr[i].index] = i;
    }

    
    for (int i = 0; i < N; i++) {
        printf("%d ", P[i]);
    }
    return 0;
}



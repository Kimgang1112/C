#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int P[N];
    for (int i = 0; i < N; i++) scanf("%d", &P[i]);

    
    qsort(P, N, sizeof(int), cmp);

    int total = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += P[i];      
        total += sum;     
    }

    printf("%d\n", total);
    return 0;
}
     


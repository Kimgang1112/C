#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    else if (x > y) return 1;
    else return 0;
}


int lower_bound(int *arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right)/2;
        if (arr[mid] >= target) right = mid;
        else left = mid +1;
    }
    return left;
}


int upper_bound(int *arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right)/2;
        if (arr[mid] > target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int N, M;
    scanf("%d", &N);
    int *cards = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) scanf("%d", &cards[i]);
    qsort(cards, N, sizeof(int), compare);

    scanf("%d", &M);
    int query;
    for (int i=0; i<M; i++) {
        scanf("%d", &query);
        int lb = lower_bound(cards, N, query);
        int ub = upper_bound(cards, N, query);
        printf("%d ", ub - lb);
    }
    free(cards);
    return 0;
}






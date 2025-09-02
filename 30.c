#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char **not_heard = malloc(sizeof(char*) * N);
    char **not_seen = malloc(sizeof(char*) * M);

    for (int i = 0; i < N; i++) {
        not_heard[i] = malloc(21);
        scanf("%s", not_heard[i]);
    }

    for (int i = 0; i < M; i++) {
        not_seen[i] = malloc(21);
        scanf("%s", not_seen[i]);
    }


    qsort(not_heard, N, sizeof(char*), cmp);

    char **both = malloc(sizeof(char*) * (N < M ? N : M));
    int count = 0;


    for (int i = 0; i < M; i++) {
        if (bsearch(&not_seen[i], not_heard, N, sizeof(char*), cmp) != NULL) {
            both[count] = not_seen[i];
            count++;
        }
    }


    qsort(both, count, sizeof(char*), cmp);

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", both[i]);
    }

    for (int i = 0; i < N; i++) free(not_heard[i]);
    for (int i = 0; i < M; i++) free(not_seen[i]);
    free(not_heard);
    free(not_seen);
    free(both);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int num;
} Pokemon;

int cmp(const void *a, const void *b) {
    return strcmp(((Pokemon*)a)->name, ((Pokemon*)b)->name);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char **num_to_name = malloc(sizeof(char*) * (N + 1));
    for (int i = 1; i <= N; i++) {
        num_to_name[i] = malloc(sizeof(char) * 21);
        scanf("%s", num_to_name[i]);
    }

    Pokemon *arr = malloc(sizeof(Pokemon) * N);
    for (int i = 1; i <= N; i++) {
        strcpy(arr[i-1].name, num_to_name[i]);
        arr[i-1].num = i;
    }
    qsort(arr, N, sizeof(Pokemon), cmp);

    for (int i = 0; i < M; i++) {
        char input[21];
        scanf("%s", input);


        if (input[0] >= '0' && input[0] <= '9') {
            int idx = atoi(input);
            printf("%s\n", num_to_name[idx]);
        } else {
            Pokemon key;
            strcpy(key.name, input);
            Pokemon *res = bsearch(&key, arr, N, sizeof(Pokemon), cmp);
            printf("%d\n", res->num);
        }
    }

    for (int i = 1; i <= N; i++) free(num_to_name[i]);
    free(num_to_name);
    free(arr);

    return 0;
}



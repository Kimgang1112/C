#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20000
#define MAX_LEN 51

char* arr[MAX_N];
int cmp(const void* a, const void* b) {
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 != len2) return len1 - len2;
    return strcmp(s1, s2);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        arr[i] = malloc(MAX_LEN);
        scanf("%s", arr[i]);
    }

    
    qsort(arr, n, sizeof(char*), cmp);

    
    printf("%s\n", arr[0]);
    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[i - 1]) != 0) {
            printf("%s\n", arr[i]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int age;
    char name[101];
    int index; 
} Member;

void merge(Member *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Member *L = (Member *)malloc(n1 * sizeof(Member));
    Member *R = (Member *)malloc(n2 * sizeof(Member));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].age < R[j].age || 
           (L[i].age == R[j].age && L[i].index < R[j].index)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(Member *arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int N;
    scanf("%d", &N);

    Member *members = (Member *)malloc(N * sizeof(Member));

    for (int i = 0; i < N; i++) {
        scanf("%d %s", &members[i].age, members[i].name);
        members[i].index = i; 
    }

    merge_sort(members, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", members[i].age, members[i].name);
    }

    free(members);
    return 0;
}


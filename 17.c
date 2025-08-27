#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[1000];
    for (int i = 0; i < N; i++) arr[i] = i + 1;

    int index = 0;
    printf("<");

    for (int i = 0; i < N; i++) {
        index = (index + K - 1) % (N - i);
        printf("%d", arr[index]);

        for (int j = index; j < N - i - 1; j++) {
            arr[j] = arr[j + 1];
        }

        if (i != N - 1) printf(", ");
    }

    printf(">\n");
    return 0;
}



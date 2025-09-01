#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y);
}

int main() {
    int N;
    scanf("%d", &N);

    int *arr = (int*)malloc(sizeof(int) * N);
    int freq[8001] = {0}; // -4000 ~ 4000
    long long sum = 0;
    int i = 0;

    while (i < N) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        freq[arr[i] + 4000]++;
        i++;
    }


    qsort(arr, N, sizeof(int), compare);


    double avg = (double)sum / N;
    int mean = (int)round(avg);
    if (mean == -0) mean = 0;

 
    int median = arr[N / 2];

    int maxFreq = 0;
    int mode = 0;
    int count = 0;
    for (i = 0; i < 8001; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    for (i = 0; i < 8001; i++) {
        if (freq[i] == maxFreq) {
            mode = i - 4000;
            count++;
            if (count == 2) break;
        }
    }


    int range = arr[N - 1] - arr[0];

    printf("%d\n", mean);
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    free(arr);
    return 0;
}



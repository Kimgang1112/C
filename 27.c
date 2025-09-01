#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int freq[31] = {0};
    int i;
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }

    int cut = (int)round(n * 0.15);
    int total = 0;
    int count = 0;


    i = 1;
    int rem = cut;
    while (rem > 0 && i <= 30) {
        if (freq[i] <= rem) {
            rem -= freq[i];
            freq[i] = 0;
        } else {
            freq[i] -= rem;
            rem = 0;
        }
        i++;
    }


    i = 30;
    rem = cut;
    while (rem > 0 && i >= 1) {
        if (freq[i] <= rem) {
            rem -= freq[i];
            freq[i] = 0;
        } else {
            freq[i] -= rem;
            rem = 0;
        }
        i--;
    }


    for (i = 1; i <= 30; i++) {
        total += freq[i] * i;
        count += freq[i];
    }

    double avg = (double)total / count;
    int result = (int)round(avg);
    printf("%d\n", result);

    return 0;
}



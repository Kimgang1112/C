#include <stdio.h>

int main() {
    int N, bag = 0;
    scanf("%d", &N);

    while (N >= 0) {
        if (N % 5 == 0) {
            bag += N / 5;
            printf("%d\n", bag);
            return 0;
        }
        N -= 3;
        bag++;
    }

    printf("-1\n");
    return 0;
}



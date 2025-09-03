#include <stdio.h>

int main() {
    int N;
    long K;
    scanf("%d %ld", &N, &K);

    long coins[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &coins[i]);
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) { 
        if (coins[i] <= K) {
            count += K / coins[i];  
            K %= coins[i];           
        }
        if (K == 0) break;          
    }

    printf("%d\n", count);
    return 0;
}



#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    bool prime[N + 1];
    for (int i = 0; i <= N; i++) prime[i] = true;
    prime[0] = false;
    prime[1] = false;

    int limit = (int)sqrt(N);
    for (int i = 2; i <= limit; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (prime[i]) printf("%d\n", i);
    }

    return 0;
}



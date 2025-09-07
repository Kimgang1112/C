#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int score[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d", &score[i]);
    }

    int dp[n+1];

    dp[0] = 0;
    dp[1] = score[1];
    if(n >= 2) dp[2] = score[1] + score[2];

    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }

    printf("%d\n", dp[n]);
    return 0;
}



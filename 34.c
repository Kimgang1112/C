#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int dp[N+1];
    dp[1] = 0; 

    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1] + 1; 
        if(i % 2 == 0 && dp[i/2] + 1 < dp[i])
            dp[i] = dp[i/2] + 1;
        if(i % 3 == 0 && dp[i/3] + 1 < dp[i])
            dp[i] = dp[i/3] + 1;
    }

    printf("%d\n", dp[N]);

    return 0;
}



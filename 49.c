#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int min_package = 1001, min_single = 1001;

    for (int i = 0; i < M; i++) {
        int p, s;
        scanf("%d %d", &p, &s);
        if (p < min_package) min_package = p;
        if (s < min_single) min_single = s;
    }

    
    int cost1 = (N / 6) * min_package + (N % 6) * min_single;
    
    int cost2 = ((N / 6) + 1) * min_package;
    
    int cost3 = N * min_single;

    int answer = cost1;
    if (cost2 < answer) answer = cost2;
    if (cost3 < answer) answer = cost3;

    printf("%d\n", answer);
    return 0;
}



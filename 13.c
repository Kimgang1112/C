#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

char board[50][51];


int repaintCount(int x, int y) {
    int whiteStart = 0;
    int blackStart = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char current = board[x + i][y + j];
           
            char expectedW = ((i + j) % 2 == 0) ? 'W' : 'B';
            char expectedB = ((i + j) % 2 == 0) ? 'B' : 'W';

            if (current != expectedW) whiteStart++;
            if (current != expectedB) blackStart++;
        }
    }

    return MIN(whiteStart, blackStart);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);


    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int minPaint = 64;


    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int count = repaintCount(i, j);
            if (count < minPaint) {
                minPaint = count;
            }
        }
    }

    printf("%d\n", minPaint);
    return 0;
}



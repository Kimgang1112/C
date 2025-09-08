#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    int num = 1;
 
   
    for (int diag = 0; diag < n + m - 1; diag++) {
        int row_start = (diag < n) ? diag : n - 1;
        int col_start = diag - row_start;

        while (row_start >= 0 && col_start < m) {
            arr[row_start][col_start] = num++;
            row_start--;
            col_start++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *sequence = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    int *stack = (int *)malloc(sizeof(int) * n);
    int top = -1;
    int current = 1; 
    int idx = 0;    
    int *result = (int *)malloc(sizeof(int) * n * 2); 
    int res_idx = 0;

    while (idx < n) {
        if (current <= sequence[idx]) {
        
            stack[++top] = current++;
            result[res_idx++] = +1;  
        } else {
           
            if (top == -1 || stack[top] != sequence[idx]) {
                printf("NO\n");
                free(sequence);
                free(stack);
                free(result);
                return 0;
            }
            top--;
            result[res_idx++] = -1;  
            idx++;
        }
    }

    for (int i = 0; i < res_idx; i++) {
        if (result[i] == +1)
            printf("+\n");
        else
            printf("-\n");
    }

    free(sequence);
    free(stack);
    free(result);
    return 0;
}


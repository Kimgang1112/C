#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int targets[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &targets[i]);
    }

    int queue[55]; 
    for (int i = 0; i < n; i++) {
        queue[i] = i + 1; 
    }
    int size = n;   
    int count = 0;  

    for (int t = 0; t < m; t++) {
        int target = targets[t];
        int idx = 0;

        
        for (int i = 0; i < size; i++) {
            if (queue[i] == target) {
                idx = i;
                break;
            }
        }

        
        if (idx <= size / 2) {
            
            count += idx;
            while (idx--) {
                int first = queue[0];
                for (int i = 0; i < size - 1; i++) {
                    queue[i] = queue[i + 1];
                }
                queue[size - 1] = first;
            }
        } else {
            
            count += size - idx;
            int times = size - idx;
            while (times--) {
                int last = queue[size - 1];
                for (int i = size - 1; i > 0; i--) {
                    queue[i] = queue[i - 1];
                }
                queue[0] = last;
            }
        }

        
        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
    }

    printf("%d\n", count);
    return 0;
}



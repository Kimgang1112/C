#include <stdio.h>
#include <string.h>

#define MAX 100


typedef struct {
    char name[30];
    char phone[20];
} Employee;

int main() {
    int N, Q;
    Employee arr[MAX];
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %s", arr[i].name, arr[i].phone);
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        char query[30];
        int found = 0;
        scanf("%s", query);
        
        for (int j = 0; j < N; j++) {
            if (strcmp(arr[j].name, query) == 0) {
                printf("%s\n", arr[j].phone);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Not found\n");
        }
    }

    return 0;
}

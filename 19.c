#include <stdio.h>

typedef struct {
    int priority;
    int index;
} Document;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Document queue[100];
        int front = 0, rear = N;
        for (int i = 0; i < N; i++) {
            int p;
            scanf("%d", &p);
            queue[i].priority = p;
            queue[i].index = i;
        }

        int print_order = 0;

        while (front < rear) {
            int max_priority = 0;
            for (int i = front; i < rear; i++) {
                if (queue[i].priority > max_priority) max_priority = queue[i].priority;
            }

            if (queue[front].priority < max_priority) {
                              Document temp = queue[front];
                for (int i = front; i < rear - 1; i++) {
                    queue[i] = queue[i + 1];
                }
                queue[rear - 1] = temp;
            } else {
       
                print_order++;
                if (queue[front].index == M) {
                    printf("%d\n", print_order);
                    break;
                }
                front++;
            }
        }
    }

    return 0;
}


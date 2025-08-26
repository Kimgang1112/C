#include <stdio.h>

int stack[100000];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int K, num;
    long long sum = 0;

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        scanf("%d", &num);
        if (num == 0) {
            sum -= pop();
        } else {
            push(num);
            sum += num;
        }
    }

    printf("%lld\n", sum);

    return 0;
}



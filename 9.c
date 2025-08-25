#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    int num = 666;

    while (1) {
        char str[20];
        sprintf(str, "%d", num);

        if (strstr(str, "666") != NULL) {
            count++;
            if (count == n) {
                printf("%d\n", num);
                break;
            }
        }
        num++;
    }

    return 0;
}


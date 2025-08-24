#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char str[55];
        scanf("%s", str);

        int count = 0;
        int valid = 1;  

        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(') {
                count++;
            } else {
                count--;
                if (count < 0) {  
                    valid = 0;
                    break;
                }
            }
        }

        if (count != 0) valid = 0;

        if (valid) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

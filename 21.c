#include <stdio.h>
#include <string.h>

int main(void){
    char ch[100];
    scanf("%s",ch);

    int sum=0;

    for (int i=0; i<strlen(ch); i++){
        if (ch[i]-'0'>=0 && ch[i]-'0'<=9){
            sum+=ch[i]-'0';
        }
    }

    printf("%d",sum);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(void){
    char ch[100];
    fgets(ch,100,stdin);
    for (int i=0; i<strlen(ch); i++){
        if (ch[i]!=' '){
            printf("%c",ch[i]);
        }
    }





    return 0;
}
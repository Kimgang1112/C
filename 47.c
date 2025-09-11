#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    int n;
    scanf("%d",&n);
    if (n>10) n=10;
    int max_idx=0;

    char **ch=(char**)malloc(sizeof(char *)*n);
    for (int i=0; i<n; i++){
        ch[i]=(char*)malloc(sizeof(char)*100);
    }

    for (int i=0; i<n; i++){
        scanf("%s",ch[i]);
    }

    for (int i=1; i<n; i++){
        if (strlen(ch[max_idx])<strlen(ch[i])){
            max_idx=i;
        }
    }

    printf("%s",ch[max_idx]);


}
#include <stdio.h>
#include <string.h>

typedef struct Employee{
    char name[20];
    char phone[14];
} E;


int main(void){
    int n;
    int st=0;
    char ch[15];
    scanf("%d",&n);
    E list[n];
    for (int i=0; i<n; i++){
        scanf("%s %s",list[i].name, list[i].phone);

    }
    
    scanf("%s",ch);
    for (int i=0; i<n; i++){
        if (!strcmp(list[i].name,ch)){
            printf("%s",list[i].phone);
            st=1;
            break;
        }
    }

    if (!st){
        printf("Not found");
    }


    
}
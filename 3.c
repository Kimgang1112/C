#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int cnt_2=0;
    int cnt_5=0;
    
    for (int i=1; i<=n; i++){
        int temp=i;
        while (temp%2==0){
            cnt_2++;
            temp/=2;
        }
        while (temp%5==0){
            cnt_5++;
            temp/=5;
        }
    }
    
    if (cnt_2<cnt_5){
        printf("%d",cnt_2);
    } else{
        printf("%d",cnt_5);
    }
}


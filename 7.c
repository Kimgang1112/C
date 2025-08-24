#include <stdio.h>
#include <string.h>

int main() {
    int n,num;
    int real_idx=0;
    scanf("%d",&n);
    char str1[6];
    int arr[n];
    
    for (int i=0; i<n; i++){
        scanf("%s",str1);
        if (strcmp(str1,"push")==0){
            scanf("%d",&num);
            arr[real_idx]=num;
            real_idx++;
        } else if (strcmp(str1,"pop")==0){
            if (real_idx!=0){
                num=arr[real_idx-1];
                real_idx--;
                printf("%d\n",num);
            } else {
                printf("-1\n");
                
            }
                        
        } else if (strcmp(str1,"size")==0){
            printf("%d\n",real_idx);
        } else if (strcmp(str1,"empty")==0){
            if (real_idx==0){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(str1,"top")==0){
            if (real_idx!=0){
                printf("%d\n",arr[real_idx-1]);
            } else {
                printf("-1\n");
            }
        }
    }
    
    
    
   
}


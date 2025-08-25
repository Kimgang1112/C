#include <stdio.h>
#include <string.h>

int main() {
    int n,num;
    int start_idx=0;
    int end_idx=0;
    scanf("%d",&n);
    char str1[6];
    int arr[n];
    
    for (int i=0; i<n; i++){
        scanf("%s",str1);
        if (strcmp(str1,"push")==0){
            scanf("%d",&num);
            arr[end_idx]=num;
            end_idx++;
        } else if (strcmp(str1,"pop")==0){
            if (end_idx-start_idx!=0){
                num=arr[start_idx];
                start_idx++;
                printf("%d\n",num);
            } else {
                printf("-1\n");
                
            }
                        
        } else if (strcmp(str1,"size")==0){
            printf("%d\n",end_idx-start_idx);
        } else if (strcmp(str1,"empty")==0){
            if (end_idx-start_idx==0){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(str1,"front")==0){
            if (end_idx-start_idx!=0){
                printf("%d\n",arr[start_idx]);
            } else {
                printf("-1\n");
            }
        } else if (strcmp(str1,"back")==0){
            if (end_idx-start_idx!=0){
                printf("%d\n",arr[end_idx-1]);
            } else {
                printf("-1\n");
            }
        }
    }
    
    
    
   
}


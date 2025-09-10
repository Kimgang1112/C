#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int arr2_idx=0;
    scanf("%d",&n);
    if (n>15) n=15;
    int* arr=(int*)malloc(n*sizeof(int));
    int* arr2=(int*)malloc(n*sizeof(int));

    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);

    }

    for (int i=0; i<n; i++){
        if (arr[i]%2==0){
            arr2[arr2_idx++]=arr[i];
        }
    }

    arr2=(int *)realloc(arr2, sizeof(int)*arr2_idx);
    for (int i=0; i<arr2_idx; i++){
        printf("%d\n",arr2[i]);
    }







    return 0;
}
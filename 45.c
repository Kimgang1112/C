#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int arr2_idx=0;
    scanf("%d",&n);
    int a=0;

    int *arr;
    int *arr2;
    

    arr=(int *)malloc(n*sizeof(int));
    arr2=(int *)malloc(n*sizeof(int));

    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for (int i=0; i<n; i++){
        a=0;
        for (int j=0; j<arr2_idx; j++){
            if (arr2[j]==arr[i]){
                a=1;

            }
        }

        if (!a){
            arr2[arr2_idx++]=arr[i];
        }


    }

    arr2=(int *)realloc(arr2,sizeof(int)*arr2_idx);
    for (int i=0; i<arr2_idx; i++){
        printf("%d\n",arr2[i]);
    }

    free(arr);
    free(arr2);
}
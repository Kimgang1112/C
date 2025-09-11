#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d",&n);

    int *arr;
    int sum=0;

    arr=(int *)malloc(n*sizeof(int));

    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    for (int i=0; i<n; i++){
        sum+=arr[i];
    }

    printf("%d",sum);

    free(arr);


}
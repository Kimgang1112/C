#include <stdio.h>


void merge_sort(int *arr,int n){
    
    if (n<=1){
        return;
    }
    int mid=n/2;
    
    int g1[mid];
    int g2[n-mid];
    for (int i=0; i<mid; i++){
        g1[i]=arr[i];
    }
    
    for (int i=0; i<n-mid; i++){
        g2[i]=arr[mid+i];
    }
    
    
    merge_sort(g1,mid);
    merge_sort(g2,n-mid);
    
    
    int i1=0;
    int i2=0;
    int ia=0;
    
    while (i1<mid && i2<n-mid){
        if (g1[i1]<g2[i2]){
            arr[ia]=g1[i1];
            ia++;
            i1++;
        } else{
            arr[ia]=g2[i2];
            ia++;
            i2++;
        }
    }
    
    
    while (i1<mid){
        arr[ia]=g1[i1];
        ia++;
        i1++;
    }
    
    while (i2<n-mid){
        arr[ia]=g2[i2];
        ia++;
        i2++;
    }
    
}



int main(){
    int n;
    scanf("%d",&n);
    int arr[1000000];
    
    
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    
    merge_sort(arr,n);
    
    
    
    
    
    
    for (int i=0; i<n; i++){
        printf("%d\n",arr[i]);
    }
}


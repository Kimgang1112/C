#include <stdio.h>

int blue=0;
int white=0;

int arr[128][128];


void count(int row, int col, int len){
    int blue_cnt=0;
    for (int i=row; i<row+len; i++){
        for (int j=col; j<col+len; j++){
            if (arr[i][j]){
                blue_cnt+=1;
            }
        }
    }
    
    if (blue_cnt==len*len){
        blue+=1;
        return;
    } else if(blue_cnt==0){
        white+=1;
        return;
    }
    
    count(row,col,len/2);
    count(row,col+len/2,len/2);
    count(row+len/2,col,len/2);
    count(row+len/2,col+len/2,len/2);
}

int main(){
    int n;
    scanf("%d",&n);
    
    
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){ 
            scanf("%d",&arr[i][j]);
        }
    }
    count(0,0,n);
    printf("%d\n%d",white,blue);
    
    
}


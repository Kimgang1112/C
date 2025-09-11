 #include <stdio.h>
#include <string.h>
#include <math.h>

int slice(char *input,int start, int end){
    int i=0;
    int sub=0;
    
    
    for (i=start; i<=end; i++){
        sub=sub*10+(input[i]-'0');
    }
    
    return sub;
}

int main(){
    int arr[50];
    char ch[50];
    int minus=1;
    int d_sum=0;
    char input[50];
    int start=0;
    int end=0;
    int sub=0;
    int i;

    int arr_idx=0;
    
    
    scanf("%s",input);
    
    for (i=0; i<strlen(input); i++){
        if (input[i]=='+' || input[i]=='-'){
            sub=slice(input,start,i-1);
            arr[arr_idx]=sub;
            ch[arr_idx++]=input[i];
            start=i+1;
            
            
            
        }
    }
    
    sub=slice(input,start,i-1);
    arr[arr_idx]=sub;
    ch[arr_idx]='\0';
    
    
    
    int sum=arr[0];
    for (int i=0; i<strlen(ch); i++){
        if (ch[i]=='+' && minus){
            sum+=arr[i+1];
        
        } else if (!minus && ch[i]=='+') {
            d_sum+=arr[i+1];
        } else {
            sum-=d_sum;
            d_sum=arr[i+1];
            minus=0;
        }
    }
    
    if (!minus){
        sum-=d_sum;
    }
    
    printf("%d",sum);
    
}


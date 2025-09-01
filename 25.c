#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int n,j;
    scanf("%d",&n);
    int *arr;
    arr = (int *)malloc(sizeof(int)*n);
    
    char *ch;
    ch = (char  *)malloc(sizeof(char)*(n*2)+1);
    int result=0;
    
    
    
    
    
    
    
    int real_idx=0,real_v=1;
    int real_chidx=0;
    
    while (real_chidx<n*2){
        scanf("%d",&j);
        while (real_idx>=1){
            if (arr[real_idx-1]==j){
                ch[real_chidx++]='-';
                real_idx--;
                if (real_chidx==n*2){
                    break;
                }
                scanf("%d",&j);
            } else{
                break;
            }
        }
        if (real_chidx==n*2){
                    break;
                }
        if (j<real_v){
            result=1;
            break;
        }
        
        while (real_v!=j && real_chidx<n*2){
            ch[real_chidx++]='+';
            arr[real_idx++]=real_v++;
        }
        ch[real_chidx++]='+';
        ch[real_chidx++]='-';
        real_v++;
        
        
        
    }
    
   
    
    if (result){
        printf("NO");
    } else {
        for (int i=0; i<n*2; i++){
            printf("%c\n",ch[i]);
        }
    }
    
    
    
    
    return 0;
}


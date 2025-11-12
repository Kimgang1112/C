#include<stdio.h>
void preorder(Node* node){
    if (node=NULL) return ;
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
}


int main(void){




}
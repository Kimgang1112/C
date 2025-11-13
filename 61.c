#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;


void inorder(Node* root){

    Node* stack[100];
    int top=-1;

    Node* current=root;

    while (current!=NULL || top!=-1){
        while (current!=NULL){
            stack[++top]=current;
            current=current->left;
        }
        printf("%d",stack[top]->data);
        current=stack[top--]->right;
        
    }

}




int main(void){

    Node N7 = {7,NULL,NULL};
    Node N6 = {6,NULL,NULL};
    Node N5 = {5,NULL,NULL};
    Node N4 = {4,NULL,NULL};
    Node N3 = {3,&N6,&N7};
    Node N2 = {2,&N4,&N5};
    Node N1 = {1,&N2,&N3};

    inorder(&N1);



    return 0;
}
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


void insert_data(Node * root, int d){
    
    if (root->data==d){
        return ;
    } else if(root->data>d){
        if (root->left==NULL){
            Node* newNode=(Node*)malloc(sizeof(Node));
            newNode->data=d;
            newNode->left=NULL;
            newNode->right=NULL;
            root->left=newNode;
        
        } else {
            insert_data(root->left,d);

        }
        return;
    } else if (root->data<d){
        if (root->right==NULL){
            Node* newNode=(Node*)malloc(sizeof(Node));
            newNode->data=d;
            newNode->left=NULL;
            newNode->right=NULL;
            root->right=newNode;
        
        } else {
            insert_data(root->right,d);

        }
        return ;
    }

    return ;
}

int main(void){
    Node N7={70,NULL,NULL};
    Node N6={50,NULL,NULL};
    Node N5={30,NULL,NULL};
    Node N4={10,NULL,NULL};
    Node N3={60,&N6,&N7};
    Node N2={20,&N4,&N5};
    Node N1={40,&N2,&N3};

    insert_data(&N1,5);
    printf("%d",N1.left->left->left->data);











    return 0;
}
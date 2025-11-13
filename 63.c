#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* findparent(Node* root, int parent){
    if (root==NULL) return NULL;
    else if (root->data==parent) return root;
    else if(findparent(root->left,parent)!=NULL){
        return findparent(root->left,parent);
    }
    else if (findparent(root->right,parent)!=NULL){
        return findparent(root->right,parent);
    }
    return NULL;
}


void preorder(Node* root){
    if (root==NULL) return ;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void){
    int count;
    printf("노드 개수 입력:");
    scanf("%d",&count);

    
    int parent;
    char lr;

    Node* root=(Node *)malloc(sizeof(Node));
    printf("루트 노드 데이터 입력:");
    scanf("%d",&root->data);
    root->left=NULL;
    root->right=NULL;
    


    for (int i=2; i<=count; i++){
        Node *newNode=(Node *)malloc(sizeof(Node));
        printf("삽입 데이터 입력: ");
        scanf("%d",&newNode->data);
        newNode->left=NULL;
        newNode->right=NULL;
        printf("부모 노드 데이터 입력: ");
        scanf("%d",&parent);
        printf("왼쪽(l) or 오른쪽(r) 입력: ");
        scanf(" %c",&lr);
        Node *parentNode=findparent(root,parent);
        if (parentNode==NULL){
            printf("해당 데이터의 부모 노드가 존재X\n");
        } else{
            if (lr=='l'){
                if (parentNode->left==NULL){
                    parentNode->left=newNode;
                } else {
                    printf("해당 위치에 노드가 이미 존재\n");
                }
            } if (lr=='r'){
                if (parentNode->right==NULL){
                    parentNode->right=newNode;
                } else {
                    printf("해당 위치에 노드가 이미 존재\n");
                }
            }
        }




        
    }



    preorder(root);





    



    return 0;
}
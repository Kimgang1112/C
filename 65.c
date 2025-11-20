#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* search_data(Node * root, int d){
    if (root==NULL){
        return NULL;
    }
    if (root->data==d){
        return root;
    } else if(root->data>d){
        return search_data(root->left,d);
    } else if (root->data<d){
        return search_data(root->right,d);
    }

    return NULL;
}

int main(void){
    Node N7={70,NULL,NULL};
    Node N6={50,NULL,NULL};
    Node N5={30,NULL,NULL};
    Node N4={10,NULL,NULL};
    Node N3={60,&N6,&N7};
    Node N2={20,&N4,&N5};
    Node N1={40,&N2,&N3};

    printf("%d",search_data(&N1,30)->data);











    return 0;
}
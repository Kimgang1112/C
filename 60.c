#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
    element data;
    struct Node* left;
    struct Node* right;
} Node;


void preorder(Node* root) { 
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) { 
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) { 
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void) {
    

    Node N7 = {70, NULL, NULL};
    Node N6 = {60, NULL, NULL};
    Node N5 = {50, NULL, NULL};
    Node N4 = {40, NULL, NULL};
    Node N3 = {30, &N6, &N7};
    Node N2 = {20, &N4, &N5};
    Node N1 = {10, &N2, &N3}; 

    Node* root = &N1;

    
    preorder(root);
    

    
    

    
    postorder(root);
    

    return 0;
}

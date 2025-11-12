#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
    element data;
    struct Node* left;
    struct Node* right;
} Node;


void inorder(Node* root) {
    Node* stack[100]; 
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
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

    
    inorder(root);
    

    return 0;
}

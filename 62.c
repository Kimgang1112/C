#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *head = NULL;
Node *tree[1000];  


void createNode(Node *newNode, int index) {
    if (head == NULL) {
        head = newNode; 
        tree[index] = newNode;
    } else {
        if (index % 2 == 0) { 
            tree[index / 2]->left = newNode;
            tree[index] = newNode;
        } else { 
            tree[index / 2]->right = newNode;
            tree[index] = newNode;
        }
    }
}


void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root) { 
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(void) {
    int n;
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            
            return 1;
        }
        
        scanf("%d", &newNode->data); 
        newNode->left = NULL;
        newNode->right = NULL;
        createNode(newNode, i);
    }

    int choice;
    
    printf("1. 전위 순회\n2. 중위 순회(반복문)\n3. 후위 순회\n");
    scanf("%d", &choice);

    
    switch (choice) {
        case 1:
            preorder(head);
            break;
        case 2:
            inorder(head);
            break;
        case 3:
            postorder(head);
            break;
        default:
            printf("잘못된 선택\n");
            break;
    }

    printf("\n");
    return 0;
}

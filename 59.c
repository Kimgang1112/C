#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *head = NULL;
Node *tree[1000];
void createNode(Node *newNode, int index)
{
    if (head == NULL)
    {
        head = newNode; 
        tree[index] = newNode;
    }
    else
    {
        if (index % 2 == 0)
        {
            tree[index / 2]->left = newNode; 
            tree[index] = newNode;           
        }
        else
        {
            tree[index / 2]->right = newNode; 
            tree[index] = newNode;            
        }
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i =1; i <= n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        scanf("%d", newNode->data);
        newNode->left = NULL;
        newNode->right = NULL;
        create_node(newNode, i);
    }
}
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    
    for (int i = 1; i <= 4; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }

        
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {  
            head = newNode;
            tail = newNode;
        } else {             
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    
    Node* cur = head;
    
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
        
    }

    
    cur = head;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


Node* reverseList(Node* head) {
    Node* prev;
    prev=NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }

    return prev; 
}

int main() {
    int n, data;
    Node* head = NULL;
    Node* newNode;
    Node* temp;

    printf("노드의 개수를 입력하세요: ");
    scanf("%d", &n);

   
    for(int i = 0; i < n; i++) {
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &data);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

   
    
    head = reverseList(head);

    
    printList(head);

 
    temp = head;
    while(temp != NULL) {
        Node* del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}

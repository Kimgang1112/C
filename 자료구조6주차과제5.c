#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void printReverse(Node* head) {
    if (head == NULL)
        return;
    printReverse(head->next); 
    printf("%d -> ", head->data); 
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

    printf("\n역순 출력: ");
    printReverse(head);
    printf("NULL\n");

   
    temp = head;
    while(temp != NULL) {
        Node* del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}

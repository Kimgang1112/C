#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int middlePosition(int count) {
    return count / 2; 
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data, choice;
    Node* head = NULL;
    Node* newNode;
    Node* temp;

    printf("노드의 개수를 입력하세요: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &data);

        printf("삽입 위치 선택 (1: 처음, 2: 가운데): ");
        scanf("%d", &choice);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if(choice == 1) {
            
            newNode->next = head;
            head = newNode;
        } else if(choice == 2) {
            int mid = middlePosition(countNodes(head));
            if(mid == 0) { 
                newNode->next = head;
                head = newNode;
            } else {
                temp = head;
                for(int j = 0; j < mid - 1; j++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        
    }

    
    printList(head);

    
    temp = head;
    while(temp != NULL) {
        Node* del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}

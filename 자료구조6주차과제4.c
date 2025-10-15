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


int listLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, data, delPos;
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

    printf("\n생성된 연결 리스트: ");
    printList(head);

    
    printf("\n삭제할 노드 위치 입력: ");
    scanf("%d", &delPos);

    int length = listLength(head);
    if(delPos < 1 || delPos > length) {
        printf("잘못된 위치입니다! 리스트 길이는 %d입니다.\n", length);
    } else {
        Node* del;
        if(delPos == 1) {
            del = head;
            head = head->next;
            free(del);
        } else {
            temp = head;
            for(int i = 1; i < delPos - 1; i++)
                temp = temp->next;
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
        printf("삭제 후 리스트: ");
        printList(head);
    }

    
    temp = head;
    while(temp != NULL) {
        Node* del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}

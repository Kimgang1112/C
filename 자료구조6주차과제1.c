#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int n, i, searchNum, pos = 1;
    Node *head = NULL, *temp = NULL, *newNode = NULL;

    
    printf("노드의 개수를 입력하세요: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }
        printf("%d번째 노드의 데이터를 입력하세요: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    
    printf("찾을 정수를 입력하세요: ");
    scanf("%d", &searchNum);

    
    temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == searchNum) {
            printf("%d는 %d번째 노드에 있습니다.\n", searchNum, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("%d는 리스트에 없습니다.\n", searchNum);
    }

    
    temp = head;
    while (temp != NULL) {
        Node* del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}

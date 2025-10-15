#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    char input[100];
    Node *head = NULL, *tail = NULL, *newNode = NULL;

    
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    int len = strlen(input);

    
    for (int i = 0; i < len; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }
        newNode->data = input[i];
        newNode->next = NULL;

        if (head == NULL) {  
            head = newNode;
            tail = newNode;
        } else {             
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    printf("\n저장된 문자 출력:\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    
    temp = head;
    while (temp != NULL) {
        Node *del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}

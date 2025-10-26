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

        printf("삽입 위치 선택: ");
        scanf("%d", &choice);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if(choice == 1) {
            
            newNode->next = head;
            head = newNode;
        } else if(choice == 2) {
            int ins_idx;
            Node* prev;
            prev=head;
            
            printf("삽입할 위치 다시 입력: ");
            scanf("%d",&ins_idx);
            for (int i=0; i<ins_idx-1; i++){
                prev=prev->next;
                

            }
            temp=prev->next;
            prev->next=newNode;
            newNode->next=temp;
        } else if (choice==3){
            temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        } else if (choice==4){
            temp=head;
            head=head->next;
            free(temp);
        } else if (choice==5){
            printf("삭제할 위치 다시 입력: ");
            int del_idx;
            Node* prev=head;
            scanf("%d",&del_idx);
            for (int i=0; i<del_idx-1; i++){
                prev=prev->next;
                

            }
            temp=prev->next;
            prev->next=temp->next;
            free(temp);

        } else if (choice==6){
            Node* prev=head;
            while (prev->next->next!=NULL){
                prev=prev->next;
            }
            temp=prev->next;
            prev->next=NULL;
            free(temp);


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

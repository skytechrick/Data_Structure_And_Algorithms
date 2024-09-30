#include <stdio.h>
#include <stdlib.h>
typedef struct ll {
    int data;
    struct ll *next;
} Node;
void Insert(Node **head, int data) {
    Node *temp = *head;
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    New_Node->next = NULL;
    if (temp == NULL){
        *head = New_Node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = New_Node;
}
void Traverse(Node *head) {
    Node *temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    };
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    };
    printf("NULL\n");
}
int main(){
    Node *head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 4);
    Traverse(head);
    return 0;
}

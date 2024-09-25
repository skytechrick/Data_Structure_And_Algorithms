#include <stdio.h>
#include <stdlib.h>
typedef struct dll{
    struct dll *prev;
    int data;
    struct dll *next;
}Node;

void create(Node **head,int data){
    Node *temp = *head;
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    if(temp == NULL){
        New_Node->prev = New_Node;
        New_Node->next = New_Node;
        *head = New_Node;
        return;
    };
    New_Node->next = *head;
    (*head)->prev = New_Node;
    while(temp->next != *head){
        temp = temp->next;
    };
    New_Node->prev = temp;
    temp->next = New_Node;
};
void traverse(Node *head){
    Node *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    };
    do{
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("NULL\n");
};
int main (){
    Node *head = NULL;

    create(&head,11);
    create(&head,22);
    create(&head,33);
    create(&head,44);

    traverse(head);

    return 0;
};
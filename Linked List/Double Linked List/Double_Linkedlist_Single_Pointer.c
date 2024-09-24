#include <stdio.h>
#include <stdlib.h>
typedef struct dll {
    struct dll *prev;
    int data;
    struct dll *next;
}Node;

Node *Create(Node *head,int data){
    Node *temp = head;
    Node *New_Node = NULL;
    New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    New_Node->next = NULL;
    if(temp == NULL){
        New_Node->prev = NULL;
        return New_Node;
    };
    while(temp->next != NULL){
        temp = temp->next;
    };
    New_Node->prev = temp;
    temp->next = New_Node;
    return head;  
};
void traverse(Node *head){
    Node *temp = head;
    if(temp == NULL){
        printf("Double linked list is empty.");
        return;
    };
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    };
    printf("NULL\n");
}
void reverse(Node *head){
    Node *temp = head;
    if(temp == NULL){
        printf("Double linked list is empty.");
        return;
    };
    while(temp->next != NULL){
        temp = temp->next;
    };
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->prev;
    };
    printf("NULL");
};
int main(){
    Node *head = NULL;
    head = Create(head,11);
    head = Create(head,22);
    head = Create(head,33);
    head = Create(head,44);
    head = Create(head,55);
    traverse(head);
    reverse(head);
    return 0;
}
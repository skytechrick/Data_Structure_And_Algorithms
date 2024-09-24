#include <stdio.h>
#include <stdlib.h>
typedef struct dll {
    struct dll *prev;
    int data;
    struct dll *next;
}Node;
void Create(Node **head, int data){
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->next = NULL;
    New_Node->data = data;
    Node *temp = *head;
    if(temp == NULL){
        New_Node->prev = NULL;
        *head = New_Node;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    };
    New_Node->prev = temp;
    temp->next = New_Node;

};

void Traverse(Node *head){
    if(head == NULL){
        printf("List is empty.");
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main(){
    Node *head = NULL;

    Create(&head, 11);
    Create(&head, 22);
    Create(&head, 33);
    Create(&head, 44);
    Traverse(head);

    return 0;
}
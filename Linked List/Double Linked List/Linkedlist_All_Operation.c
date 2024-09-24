#include <stdio.h>
#include <stdlib.h>
typedef struct ll {
    struct ll *prev;
    int data;
    struct ll *next;
} Node;
void InsertBeg(Node **head, int data){
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->prev = NULL;
    New_Node->data = data;

    Node *temp = *head;
    if(temp == NULL){
        New_Node->next = NULL;
        *head = New_Node;
        return;
    };
    New_Node->next = temp;
    temp->prev = New_Node;
    *head = New_Node;
};
void InsertEnd(Node **head, int data){
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    New_Node->next = NULL;
    Node *temp = *head;
    if(temp == NULL){
        New_Node->prev = NULL;
        *head = New_Node;
        return;
    };
    while(temp->next != NULL){
        temp = temp->next;
    };
    New_Node->prev = temp;
    temp->next = New_Node;
};
void Traverse(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    };
    printf("NULL\n");
};
int main(){
    Node *head = NULL;
    int a = 1,ch, data;
    while(a == 1){
        printf("1. Add data to end\n2. Add data to beg\n3. Traverse\n4. Delete\n5. Search\n6. Count\n0. Exit\nChoose a number...:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter data to insert(Beg)..:");
                scanf("%d",&data);
                InsertBeg(&head, data);
                break;
            case 2:
                printf("Enter data to insert(End)..:");
                scanf("%d",&data);
                InsertEnd(&head, data);
                break;
            case 3:
                Traverse(head);
                break;
            case 0:
                a = 99;
                break;
            default:
                printf("Invalid input");
                break;
        }
    };

    return 0;
}
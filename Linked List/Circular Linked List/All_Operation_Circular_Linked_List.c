#include<stdio.h>
#include<stdlib.h>
typedef struct dll {
    struct dll *prev;
    int data;
    struct dll *next;
}Node;
void InsertBeg (Node **head, int data) {
    Node *temp = *head;
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    if(temp == NULL){
        New_Node->prev = New_Node;
        New_Node->next = New_Node;
        *head = New_Node;
        return;
    };
    while (temp->next != *head){
        temp=temp->next;          
    };
    New_Node->next = *head;
    New_Node->prev = temp;
    temp->next = New_Node;
    (*head) = New_Node;
};
void InsertEnd(Node **head, int data){
    Node *temp = *head;
    Node *New_Node = (Node*) malloc(sizeof(Node));
    New_Node->data = data;
    if(temp == NULL){
        New_Node->prev = New_Node;
        New_Node->next = New_Node;
        *head = New_Node;
        return;
    };
    while(temp->next != *head){
        temp = temp->next;
    };
    New_Node->prev = temp;
    New_Node->next = *head;
    temp->next = New_Node;
    (*head)->prev = New_Node;
};
void Traverse(Node *head){
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

void Reverse(Node *head){
    Node *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    };
    do{
        temp = temp->prev;
        printf("%d -> ",temp->data);
    }while(temp != head);
    printf("NULL\n");
};

void Delete(Node **head,int del){
    Node *temp = *head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    };
    if(temp->data == del && temp->prev == temp && temp->next == temp){
        printf("Deleted successful.\n");
        free(temp);
        *head = NULL;
        return;
    };
    Node *ptr = NULL;
    do{
        if(temp->data == del && ptr == NULL){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            *head = temp->next;
            free(temp);
            printf("Deleted successful.\n");
            return;
        };
        if(temp->data == del){
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
            printf("Deleted successful.\n");
            return;
        };
        ptr = temp;
        temp = temp->next;
    }while(temp != *head);
    printf("Data not found for deletion.\n");

};


void Count(Node *head){
    Node *temp = head;
    int c = 0;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    };
    do{
        c++;
        temp = temp->next;
    }while(temp != head);
    printf("Count = %d\n", c);
};
void Search(Node *head, int data){
    Node *temp = head;
    int c = 0;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    };
    do{
        c++;
        if(temp->data == data){
            printf("Data found\n");
            return;
        };
        temp = temp->next;
    }while(temp != head);
    printf("Data not found\n");
    
};
void main(){
    Node *head = NULL;
    int a = 1, ch, data;
    system("clear");
    while(a==1){
        printf("1. Insert data to Insert(Beg).\n2. Insert data to Insert(End).\n3. Traverse\n4. Count\n5. Search\n6. Reverse\n7. Delete\n0. Exit\nEnter your choice..: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to insert(Beg)..: ");
                scanf("%d", &data);
                InsertBeg(&head, data);
                break;
            case 2:
                printf("Enter data to insert(End)..: ");
                scanf("%d", &data);
                InsertEnd(&head, data);
                break;
            case 3:
                Traverse(head);
                break;
            case 4:
                Count(head);
                break;
            case 5:
                printf("Enter data to Search..: ");
                scanf("%d", &data);
                Search(head, data);
                break;
            case 6:
                Reverse(head);
                break;
            case 7:
                printf("Enter data to Delete..: ");
                scanf("%d", &data);
                Delete(&head, data);
                break;
            case 0:
                a = 34;
                break;
            default:
                printf("Invalid input\n");
                break;
        };
    };
};
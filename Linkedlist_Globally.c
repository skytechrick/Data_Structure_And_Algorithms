#include <stdio.h>
#include <stdlib.h>
typedef struct ll {
    int data;
    struct ll *next;
} Node;

Node *head = NULL;


void Insert(int data){
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    New_Node->next = NULL;

    if (head == NULL)
    {
        head = New_Node;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = New_Node;
}

void Traverse (){
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    };
    printf("NULL\n");
};



int main(){
    int choice, a = 1, data;
    while(a==1){
        printf(" \n1. Enter data to add ..: \n2. Traverse linked list..: \n0. Exit..:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                Insert(data);
                break;
            case 2:
                Traverse();
                break;
            case 0:
                a = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        };
    };


    return 0;
}
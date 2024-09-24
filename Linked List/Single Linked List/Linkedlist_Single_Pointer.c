#include <stdio.h>
#include <stdlib.h>
typedef struct ll {
    int data;
    struct ll* next;
} Node;


Node *Insert(Node *head , int data){              // Function type is Node* because we are returning head
    Node *New_Node = (Node*)malloc(sizeof(Node)); // Allocat memory for new node
    New_Node->data = data;                        // Assign data to new node
    New_Node->next = NULL;                        // Assign NULL to next of new node

    if (head == NULL)                             // If head is NULL then assign new node to head (In case of First Node)
    {
        return New_Node;                          // Return new node as head
    }
    Node *temp = head;                            // Assign head to temp (To temporary store head)
    while (temp->next != NULL)                    // Traverse till last node
    {
        temp = temp->next;                        // Move to next node
    }
    temp->next = New_Node;                        // Assign new node to next of last node
    return head;                                  // Returning head
}

void Traverse (Node *head){                       // Function to traverse linked list
    Node *temp = head;                            // Assign head to temp (To temporary store head)
    while (temp != NULL)                          // Traverse till last node
    {
        printf("%d -> ", temp->data);             // Print data of node
        temp = temp->next;                        // Move to next node
    };
    printf("NULL\n");
};

int main()                                        // Main function - You know about main function I am not going to add comments.
{
    Node *head = NULL;
    int choice, a = 1, data;
    while(a==1){
        printf(" \n1. Enter data to add ..: \n2. Traverse linked list..: \n0. Exit..:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = Insert(head, data);
                break;
            case 2:
                Traverse(head);
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

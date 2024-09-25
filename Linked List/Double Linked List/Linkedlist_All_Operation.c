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
    if(temp == NULL){
        printf("Double linked list is empty.\n");
        return;
    };
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    };
    printf("NULL\n");
};
void Reverse(Node *head){
    Node *temp = head;
    if(temp == NULL){
        printf("Double linked list is empty.\n");
        return;
    };
    while(temp->next != NULL){
        temp = temp->next;
    };
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->prev;
    }; 
    printf("NULL\n");
};

void Search(Node *head, int val){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == val){
            printf("Data found.\n");
            return;
        };
        temp = temp->next;
    };
    printf("No data found.\n");
    
}

void Count(Node *head){
    Node *temp = head;
    int c = 0;
    while(temp != NULL){
        c++;
        temp = temp->next;
    };
    printf("Number of elements = %d\n", c);
    
}
void Delete(Node **head,int del){
    Node *temp = *head;
    if(temp == NULL){
        printf("Double linked list is empty.\n");
        return;
    };

    if(temp ->next == NULL && temp->data == del){
        *head = NULL;
        free(temp);
        printf("Data deleted successfully.\n");
        return;
    };

    Node *ptr = NULL;
    while(temp != NULL){
        if(temp->data == del){
            if(ptr == NULL){
                *head = temp->next;
                free(temp);
                printf("Data deleted successfully.\n");
                return;
            };
            if(temp->next == NULL){
                ptr->next = NULL;
                free(temp);
                printf("Data deleted successfully.\n");
                return;
            };
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
            printf("Data deleted successfully.\n");
            return;
        };
        ptr = temp;
        temp = temp->next;
    };
    printf("Data not present.\n");
};
int main(){
    Node *head = NULL;
    int a = 1,ch, data;
    while(a == 1){
        printf("\n1. Add data to end\n2. Add data to beg\n3. Traverse\n4. Delete\n5. Search\n6. Count\n7. Reverse \n0. Exit\nChoose a number...:");
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
            case 5:
                printf("Enter data to search..:");
                scanf("%d",&data);
                Search(head, data);
                break;
            case 4:
                printf("Enter data to delete..:");
                scanf("%d",&data);
                Delete(&head, data);
                break;
            case 6:
                Count(head);
                break;
            case 7:
                Reverse(head);
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
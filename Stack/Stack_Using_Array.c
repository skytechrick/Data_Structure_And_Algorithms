#include <stdio.h>
#include <stdbool.h>
#define MAX 10
int top = -1;

bool IsEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool IsFull(){
    if(top == MAX-1){
        return true;
    }
    return false;
}
void Push(int stack[], int data){
    if(IsFull()){
        printf("Stack is full\n");
        return;
    }
    stack[++top] = data;
}
int pop(int stack[]){
    if(IsEmpty()){
        printf("Stack is empty\n");
        return -999;
    }
    return stack[top--];
}
int Peek(int stack[]){
    if(IsEmpty()){
        printf("Stack is empty\n");
        return -999;
    }
    return stack[top];
}
void Display(int stack[]){
    if(IsEmpty()){
        printf("Stack is empty\n");
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("\n%d\n", stack[i]);
    }
}

void main(){
    // Create the menu driven program by yourself
    int stack[MAX];
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);
    Display(stack);
    printf("Peek: %d\n", Peek(stack));
    printf("Pop: %d\n", pop(stack));
    Display(stack);
}

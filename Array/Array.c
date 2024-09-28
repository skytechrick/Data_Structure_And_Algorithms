#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 100
int n;

bool IsEmpty(int b){
    if(b == 0)
    return true;
    return false;
};
bool IsFull(int c){
    if(c == max)
    return true;
    return false;
};
void create(int a[], int nn){
    int i;
    if(nn>max){
        printf("Elements cannot be greater then: %d\n", max);
        return;
    };
    for(i = 0; i<nn;i++){
        printf("Enter %d element..: ", i+1);
        scanf("%d", &a[i]);
    };
    printf("Created successfully.\n");
};
void display(int a[]){
    if(IsEmpty(n)){
        printf("Array is empty.\n");
        return;
    }
    for(int i = 0;i<n;i++){
        printf("A[%d] = %d\n",i, a[i]);
    };
};
void delete(int a[],int del){
    if (IsEmpty(n)) {
        printf("Array is empty.\n");
        return;
    }
    
    int i, j;
    bool found = false;

    for (i = 0; i < n; i++) {
        if (a[i] == del) {
            found = true;
            for (j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }

    if (found) {
        printf("Data deleted successfully.\n");
    } else {
        printf("Data not found.\n");
    }
}

int main(){
    int ch, a = 1, Array[max], data;
    while(a==1){
        printf("1. Create \n2. Display\n3. Delete\n0. Exit \nEnter your choice..:");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter the number of elements for initialization of array..:");
                scanf("%d", &n);
                create(Array, n);
                break;
            case 2:
                display(Array);
                break;
            case 3:
                printf("Enter the data to delete..:");
                scanf("%d", &data);
                delete(Array, data);
                break;
            case 0:
                a = 23;
                break;
            default:
                printf("Invalid input.\n");
                break;
        };
    };
    
    return 0;
};
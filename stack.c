/* Stack implementation using linked list
Functions: push(), pop(), peek(), display(), isempty()
*/

#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node* next;
    int data;
}*top = NULL;

void push(int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    if(top == NULL){
        newNode -> next = NULL;
        top = newNode;
    }
    else{
        newNode -> next = top;
        top = newNode;
    }
}

void pop(){
    if(top==NULL){
        printf("The stack is empty");
    }
    else{
        struct Node* temp;
        temp = top;
        top = top -> next;
        free(temp);
    }
}

void peek(){
    if(top==NULL){
        printf("The stack is empty");
    }
    else{
        printf("\n%d", top->data);
    }
}

void isempty(){
    if(top==NULL)
        printf("\nThe stack is empty");
    else
        printf("\nThe stack is not empty");
}

void display(){
    struct Node* temp=top;
    if(top==NULL){
        printf("The stack is empty");
    }
    else{
        printf("Stack: \n");
        while(temp!=NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        push(value);
    }
    display();
    peek();
    pop();
    isempty();
    return 0;
}

// balancing symbols 
// {[()]} -> balanced
// {[(])} -> not balanced

void balance(){
    char string[6] = "{[()]}";
    char *ptr;
    ptr = string;
    for(int i=0; i<6; i);
}
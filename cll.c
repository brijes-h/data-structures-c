// circular linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
} *head = NULL;

struct Node* create(){
    struct Node* newNode; int value;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter an element: ");
    scanf("%d", &value);
    newNode -> data = value;
    newNode -> next = NULL;
    return (newNode);
}

void insert(){
    struct Node* temp, *newNode;
    newNode = create();
    if(head==NULL){
        head = newNode;
        head -> next = head;
    }    
    else{
        temp = head;
        while(temp->next!=head){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
    }
}

void display(){
    struct Node* temp;
    if(head==NULL){
        printf("The list is empty.");
    }
    else{
        temp = head;
        while(temp->next != head){
            printf("%d ", temp->data);
            temp = temp -> next;
        }
        printf("%d", temp->data);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        insert();
    }
    display();
    return 0;
}
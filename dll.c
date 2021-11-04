//doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} *head = NULL, *last = NULL;

struct Node* create(){
    struct Node* newNode; int value;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter an element: ");
    scanf("%d", &value);
    newNode -> data = value;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return (newNode);
}

void InsertatBeginning(){
    struct Node* newNode, *temp;
    newNode = create();
    if(head==NULL){
        head = newNode;
        last = head;
    }
    else{
        temp = newNode;
        temp -> prev = NULL;
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void InsertatEnd(){
    struct Node* newNode;
    newNode = create();
    if(head==NULL){
        head = newNode;
        last = head;
    }
    else{

    }
    
    last -> next = newNode;
    newNode -> prev = last;
    last = newNode;
}
void InsertinMiddle(){
    int loc;
    struct Node* temp1=head, *temp2, *newNode;
    newNode = create();
    printf("Enter the position to enter: ");
    scanf("%d", &loc);
    for(int i=1; i<loc; i++){
        temp2 = temp1;
        temp1 = temp1 -> next;
    }
    temp2 -> next = newNode -> prev;
}

void Maximum(){
    struct Node* i, *j;
    for(i=head; i->next!=NULL; i=i->next){
        for(j=head; j->next!=NULL; j=j->next){
            if(j->data > j->next->data){
                int temp = j -> data;
                j -> data = j -> next -> data;
                j->next->data = temp;
            } 

        }
    }
    printf("\n Maximum value = %d", last->data);
}

void display(){
    struct Node* temp;
    if(head==NULL){
        printf("\nThe ll is empty");
    }
    else{
        temp = last;
        while(temp->prev!=NULL){
            printf("%d ", temp->data);
            temp = temp -> prev;
        }
        printf("%d ", temp->data);

        // temp = head;
        // while (temp != NULL) {
        //     printf("%d ", temp->data);
        //     temp = temp->next;
        // }
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        InsertatBeginning();
    }
    display();
    Maximum();
    return 0;
}
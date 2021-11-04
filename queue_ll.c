#include <stdio.h>
#include <stdlib.h>
/* the queue looks like this:
                _____________________________________
    dequeue <---       |       |        |      |       <---- enqueue
                _______|_______|_______|______|_____
*/
struct Node{
    int data;
    struct Node* next;
}*front = NULL, *rear=NULL;

void enqueue(int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL;
    if (front == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        rear -> next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if (front==NULL){
        printf("The queue is empty.");
    }
    else 
    {
        struct Node* temp = front;
        front = front -> next;
        free(temp);
    }
}

void display(){
    if (front==NULL){
        printf("The queue is empty.");
    }
    else{
        struct Node* temp = front;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp -> next;
        }
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    printf("\n");
    display();
    return 0;
}
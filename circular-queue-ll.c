#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *front = NULL, *rear = NULL;

Node* create (int val)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return (newNode);
}

void enqueue (int val)
{
    Node *newNode = create (val);
    
    if (front == NULL && rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear -> next = newNode;
        rear = newNode;
        rear -> next = front;
    }
}

void dequeue ()
{
    if (front == NULL && rear == NULL) {
        printf ("The queue is empty.");
    }

    else if (front == rear) { 
        Node* temp = front;
        front = rear = NULL;
        free (temp);
    }

    else {
        Node* temp = front;
        front = front -> next;
        rear -> next = front;  // update the link btw rear and front
        free (temp);
    }
}

void display ()
{
    if (front == NULL && rear == NULL)
    printf("The queue is empty.");
    else {
        Node* temp = front;
        while (temp -> next != front) {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf ("%d", temp -> data);
    }
}

int main ()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    display();
    return 0;
}
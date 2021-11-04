#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coef, pow;
    struct Node* next;
}*head = NULL;

void insertatEnd(int coef, int pow){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> coef = coef;
    newNode -> pow = pow;
    if(head == NULL){
        newNode -> next = NULL;
        head = newNode;
    }
    else{
        struct Node* temp=head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}


void polynomialAddition(){
    
}


void display(){
    if(head==NULL){
        printf("\nList is Empty\n");
    }
    else{
        printf("Linked List: \n");
        struct Node *temp = head;
        while(temp!=NULL){
            printf("%d %d  ", temp->coef, temp->pow);
            temp = temp -> next;
        }
    }
}

int main()
{
    int n, coeff, power;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the val and coeff: ");
        scanf("%d", &coeff);
        scanf("%d", &power);
        insertatEnd(coeff, power);
    }
    display();
    return 0;
}
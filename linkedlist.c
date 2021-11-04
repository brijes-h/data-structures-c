/* Singly linked list - Creation, traverse, display
1. Insert at Beginning
2. Insert at End
3. Insert in between
4. Linear Search
5. Middle element
6. Deleting node using key(element)
7. Deletion of Last node 
8. Sorting 
9. Reversing the linked list*/

#include <stdio.h>
#include <stdlib.h>

struct Node{  // creation of node
    int data;
    struct Node *next;
} *head = NULL;

void insertatBeginning(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL){
        newNode -> next = NULL;
        head = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
}

void insertatEnd(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
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

void insertMiddle(){
    struct Node *newNode, *temp1=head, *temp2;
    int value, loc;
    printf("Enter the location to insert the element: ");
    scanf("%d", &loc);
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL){
        newNode -> next = head;
        head = newNode;
    }
    else{
        for(int i=1; i<loc; i++){
            temp2 = temp1;
            temp1 = temp1 -> next;
        }
        temp2 -> next = newNode;
        newNode -> next = temp1;
    }
    
}

void linearSearch(){
    struct Node* temp=head;
    int key;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    while(temp != NULL){
        if(temp -> data == key){
            printf("\n%d is present in the linked list\n", key);
            return;
        }
        temp = temp -> next;
    }
    printf("\n%d is not present in the linked list", key);
}

void delValue(){
    struct Node* temp1 = head, *temp2;
    int val;
    printf("Enter the value to delete: "); scanf("%d", &val);
    while(temp1 -> data != val){
        if(temp1 -> next == NULL){
            printf("\nThe element is not found.");
        }
        else{
            temp2 = temp1;
            temp1 = temp1 -> next;
        }
    }
    temp2 -> next = temp1 -> next;
    free(temp1);
}

void delLast(){
    struct Node* temp1=head, *temp2;
    if(head == NULL){
        printf("The list is empty");
    }
    else{
        while(temp1->next != NULL){
            temp2 = temp1;
            temp1 = temp1 -> next;
        }
        temp2 -> next = NULL;
        free(temp1);
    }
}

void sort(){  //bubble sort
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
}


void middleNode(){
    struct Node *head1=head, *head2=head;
    while(head2 != NULL && head2->next != NULL){
        head1 = head1 -> next;
        head2 = head2 -> next -> next;
    }
    printf("The middle element is %d", head1->data);
}

void display(){
    if(head==NULL){
        printf("\nList is Empty\n");
    }
    else{
        printf("Linked List: \n");
        struct Node *temp = head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp -> next;
        }
    }
}

void reverse(){
    struct Node* prev_ptr=NULL, *cur_ptr=head, *next_ptr=NULL;
    while(cur_ptr != NULL){
        next_ptr = cur_ptr -> next;
        cur_ptr -> next = prev_ptr;
        prev_ptr = cur_ptr;
        cur_ptr = next_ptr;
    }
    head = prev_ptr;
}

int main(){
    int i, value, n, option;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        insertatBeginning(value);
    }
    display();
    printf("\nChoose any operation below\n1. Middle Element\n2. Linear Search\n3. Delete node using value\n4. Insert in between\n5. Delete Last Node\n6. Sort\n7. Reverse");
    printf("\nOption: "); 
    scanf("%d", &option);
    
    switch(option){
        case 1:
        middleNode();
        break;
        case 2:
        linearSearch();
        break;
        case 3:
        delValue();
        display();
        break;
        case 4:
        insertMiddle();
        display();
        break;
        case 5:
        delLast();
        display();
        break;
        case 6:
        sort(n);
        break;
        case 7:
        reverse();
        display();
        break;
        default:
        printf("Enter a valid option");
    }
    return 0;
}
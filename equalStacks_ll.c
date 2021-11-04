// Equal Stacks problem using Linked lists

#include <stdio.h>
#include <stdlib.h>

int h1 = 0, h2 = 0, h3 = 0;

struct Node
{
    struct Node* next;
    int data;
}*top1=NULL, *top2=NULL, *top3=NULL;  // 3 top pointers for accessing the 3 stacks

struct Node* create(int val)  // Create function that creates and initializes the newNode
{
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return (newNode);
}

void push(int val, int stkno)
{  // special push function which pushes elements into the 3 stacks using their 
  // stack numbers (1, 2, 3)
    struct Node* newNode = create(val);
    switch (stkno) 
    {
    case 1:  // for stack 1
        if(top1 == NULL){
            newNode -> next = NULL;
            top1 = newNode;
        }
        else{
            newNode -> next = top1;
            top1 = newNode;
        }
        break;

    case 2:  // for stack 2
        if(top2 == NULL){
            newNode -> next = NULL;
            top2 = newNode;
        }
        else{
            newNode -> next = top2;
            top2 = newNode;
        }
        break;
    
    case 3:  // for stack 3
        if(top3 == NULL){
            newNode -> next = NULL;
            top3 = newNode;
        }
        else{
            newNode -> next = top3;
            top3 = newNode;
        }
    }
}

int stkno(int a, int b, int c)  
{
// stkno() compares the SUM values of the 3 stacks and returns the stkno with
// highest SUM value
    if (a>b && a>c)
        return 1;
    else if (b>c && b>c)
        return 2;
    else
        return 3;
}

int pop(int num)  // special pop function that pops and retruns the element based on stkNo
{
    switch (num)
    {
    case 1:
        if(top1==NULL){
            printf("The stack is empty");
        }
        else{
            struct Node* temp;
            temp = top1;
            int x = temp -> data;
            top1 = top1 -> next;
            free(temp);
            return (x);
        }
        break;
    
    case 2:
        if(top2==NULL){
            printf("The stack is empty");
        }
        else{
            struct Node* temp;
            temp = top2;
            int y = temp -> data;
            top2 = top2 -> next;
            free(temp);
            return (y);
        }
        break;

    case 3:
        if(top3==NULL){
            printf("The stack is empty");
        }
        else{
            struct Node* temp;
            temp = top3;
            int z = temp -> data;
            top3 = top3 -> next;
            free(temp);
            return (z);
        }
        break;
    }
}

int eqStack(int h1, int h2, int h3){
    while(!(h1==h2 && h2==h3)){
        int stkNo = stkno(h1, h2, h3);
        if (stkNo==1)
            h1 = h1 - pop(1);
        else if (stkNo==2)
            h2 = h2 - pop(2);
        else 
            h3 = h3 - pop(3);
    }
    return (h1);
}

int main()
{
    int n1, n2, n3;
    // for stack 1
    printf("Enter the number of elements in Stack 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        int val1;
        printf("Enter the element %d: ", i+1);
        scanf("%d", &val1);
        push(val1, 1);
        h1 += val1;
    }
    // for stack 2
    printf("Enter the number of elements in Stack 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        int val2;
        printf("Enter the element %d: ", i+1);
        scanf("%d", &val2);
        push(val2, 2);
        h2 += val2;
    }
    // for stack 3
    printf("Enter the number of elements in Stack 3: ");
    scanf("%d", &n3);
    for (int i = 0; i < n3; i++)
    {
        int val3;
        printf("Enter the element %d: ", i+1);
        scanf("%d", &val3);
        push(val3, 3);
        h3 += val3;
    }

    int ans = eqStack(h1, h2, h3);
    printf("\n The answer is %d", ans);
    return 0;
}


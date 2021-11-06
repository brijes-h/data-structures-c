// Equal Stacks problem using Linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    int data;
};

// global declarations
typedef struct Node Node;  // using typedef to fix alias name to Node
Node *top1=NULL, *top2=NULL, *top3=NULL;  // 3 top pointers for accessing the 3 stacks
int h1 = 0, h2 = 0, h3 = 0;  // inital sum of the 3 stacks initialized as 0

Node* create(int val)  // Create function that creates and initializes the newNode
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = val;
    return (newNode);
}

void push(int val, Node* top)
{  // special push function which pushes elements into the 3 stacks using their 
  // stack numbers (1, 2, 3)
    Node* newNode = create(val);
    if(top == NULL){
        newNode -> next = NULL;
        top = newNode;
    }
    else{
        newNode -> next = top;
        top = newNode;
    }
}

Node* stkno(int a, int b, int c)  
{
// stkno() compares the SUM values of the 3 stacks and returns the corresponding top pointer with
// highest SUM value
    if (a>b && a>c)
        return top1;
    else if (b>c && b>c)
        return top2;
    else
        return top3;
}

int pop(Node* top)  // special pop function that pops and retruns the element based on top pointer
{
    if(top==NULL){
        printf("The stack is empty.");
        return 0;
    }
    else{
        Node* temp = top;
        int x = temp -> data;
        top = top -> next;
        free(temp);
        return x;
    }
}

int eqStack(int h1, int h2, int h3){
    while(!(h1==h2 && h2==h3)){
        Node* stkNo = stkno(h1, h2, h3);
        if (stkNo==top1)
            h1 = h1 - pop(stkNo);
        else if (stkNo==top2)
            h2 = h2 - pop(stkNo);
        else 
            h3 = h3 - pop(stkNo);
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
        push(val1, top1);
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
        push(val2, top2);
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
        push(val3, top3);
        h3 += val3;
    }

    int ans = eqStack(h1, h2, h3);
    printf("\n The answer is %d", ans);
    return 0;
}


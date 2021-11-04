#include <stdio.h>

int stkno(int a, int b, int c){ // this function returns the stack number with highest sum value
    if (a>b && a>c)
        return 1;
    else if (b>a && b>c)
        return 2;
    else 
        return 3;
}

int eqStack(int h1, int h2, int h3, int stk1[], int stk2[], int stk3[], int top1, int top2, int top3){
    while (!(h1==h2 && h2==h3)){
        int stkNo = stkno(h1, h2, h3);
        if (stkNo==1)
            h1 = h1 - stk1[top1--];
        else if (stkNo==2)
            h2 = h2 - stk2[top2--];
        else 
            h3 = h3 - stk3[top3--];
    }
    return h1;
}

int main(){
    int n1, n2, n3; // sizes of the stacks
    int h1=0, h2=0, h3=0; // sums of stack elements
    // for stack 1
    printf("Enter the number of elements in Stack 1: ");
    scanf("%d", &n1);
    int stk1[n1];
    int top1 = n1 - 1;
    for(int i=0; i<n1; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &stk1[i]);
        h1 += stk1[i];
    }
    // for stack 2
    printf("Enter the number of elements in Stack 2: ");
    scanf("%d", &n2);
    int stk2[n2];
    int top2 = n2 - 1;
    for(int i=0; i<n2; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &stk2[i]);
        h2 += stk2[i];
    }
    // for stack 3
    printf("Enter the number of elements in Stack 3: ");
    scanf("%d", &n3);
    int stk3[n3];
    int top3 = n3 - 1;
    for(int i=0; i<n3; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &stk3[i]);
        h3 += stk3[i];
    }
    
    int ans = eqStack(h1, h2, h3, stk1, stk2, stk3, top1, top2, top3);
    printf("The answer is %d", ans);
    return 0;
}

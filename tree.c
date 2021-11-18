#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int data;
    struct Node* right, *left;
};

typedef struct Node Node;

Node* create ()
{
    int value;
    printf("Enter data (-1 for no data): ");
    scanf ("%d", &value);

    if (value == -1)
        return NULL;

    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;

    printf("Enter the left child for %d\n", value);
    newNode -> left = create();

    printf("Enter the right child for %d\n", value);
    newNode -> right = create();

    return newNode;
}

void preorder (Node* root)  // traversal order: ROOT -> Left -> Right
{
    if (root != NULL)
    {
        printf("%d  ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

int main ()
{
    Node* root;
    root = create();
    preorder (root);
    return 0;
}
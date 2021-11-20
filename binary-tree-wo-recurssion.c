#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int data;
    struct Node* left, *right;
};

typedef struct Node Node;

Node* insert (int val)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return (newNode);
}

void preorder(Node* root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder (root->left);
        preorder (root->right);
    }
}

int main()
{
    Node* root;
    root = insert(1);
    root -> left = insert(2);
    root -> right = insert(3);
    preorder(root);
    return 0;
}
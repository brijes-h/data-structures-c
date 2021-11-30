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

int height (Node* root)  // recursive function to find height of the tree
{
    if (root == NULL);
        return -1;
    
    int lt = height (root -> left);
    int rt = height (root -> right);
    
    if (lt > rt)
        return lt + 1;
    else
        return rt + 1;
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

void inorder (Node* root)
{
    if (root != NULL)
    {
        inorder (root -> left);
        printf("%d  ", root -> data);
        inorder (root -> right);
    }
}

void postorder (Node* root)
{
    if (root != NULL)
    {
        postorder (root -> left);
        postorder (root -> right);
        printf("%d  ", root -> data);
    }
}

void levelOrder (Node* root, int level)
{
    if (level == 1)
        printf ("%d ", root -> data);
    else if (level > 1)
    {
        levelOrder(root -> left, level-1);
        levelOrder(root -> right, level-1);
    }
}

int main ()
{
    Node* root;
    root = create();
    inorder (root);
    levelOrder(root, 2); // to print the 2nd level of the binary tree
    return 0;
}

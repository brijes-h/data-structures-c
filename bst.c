/* Binary Search Tree implementation - To create the following BST
              50
           /     \
          20      60
         /  \    
       10   32  
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left, *right;
};

typedef struct Node Node;
// newNode creation fn
Node* create (int value)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode ->right = newNode ->left = NULL;
    return newNode;
}

// function to insert a nodeNode with given key in BST
Node* insert (Node* node, int key)
{
    if (node == NULL)
        return create(key);
    
    if (key < node -> data)
        node -> left = insert(node->left, key); 
    else if (key > node -> data)
        node -> right = insert(node->right, key);
    
    return node;
}   

// Binary search function
Node* search(Node* root, int key)
{
    if (root == NULL || root -> data == key)
        return root;
    
    if (key > root->data)
        return search(root->right, key);
    
    return search(root->left, key);
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

int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 60);
    insert(root, 10);
    insert(root, 32);
  
    printf("Inorder traversal of the BST:\n"); 
    inorder(root);

    printf ("\nEnter element to be searched: ");
    scanf ("%d", &value);
    // calling search function
    if (search(root, value))
        printf("%d is found in the BST!\n", value);
    else
        printf("%d is not found in the BST!", value);
   
    return 0;
}

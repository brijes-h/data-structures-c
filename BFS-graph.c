#include<stdio.h>
#include<stdlib.h>

int n,visited[100],G[100][100], queue[100], front = -1,rear = -1;

void enqueue(int value)
{
    if(rear == 100-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1) 
            front = 0;
        queue[++rear] = value ;
    }
}
 
int isEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
 
int dequeue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}
 
void BFS(int x)
{
    int i;
    
    enqueue(x);
    visited[x] = -2;
    
    while(!isEmpty())
    {
        x = dequeue( );
        printf("%d ",x);
        visited[x] = -1;
        
        for(i=0; i<n; i++)
        {
            if(G[x][i] == 1 && visited[i] == 0) 
            {
                enqueue(i);
                visited[i] = -2;
            }
        }
    }
    printf("\n");
}

int main()
{
    int i,j,x;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matix of the graph: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }

    printf("Enter the starting vertex: ");
    scanf("%d",&x);

    for(i=0;i<n;i++) 
        visited[i] = 0;

    printf("\nBFS Traversal of the graph is: ");
    BFS(x);
    return 0;
}

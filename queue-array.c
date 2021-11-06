#include <stdio.h>
#define MAXSIZE 50
// declaring queue, front and rear as global variables
int q_arr[MAXSIZE];
int rear = -1, front = -1; 

void enqueue()
{
    int val;
    if (rear==MAXSIZE-1) // Checking if the queue is full
        printf("Queue Overflow.\n");
    else
    {
        if(front==-1) 
            front = 0;

        printf("Enter the value to insert: ");
        scanf("%d", &val);
        rear = rear + 1;
        q_arr[rear] = val;
    }
}

void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue Underflow.\n");
        return;
    }
    else
    {
        printf("One element deleted from the queue!\n");
        front = front + 1;
    }
}

void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty.\n");
    else
    {
        printf("Queue: \n");
        for(i = front; i <= rear; i++)  // displaying the queue from to q[fornt] to q[rear]
        {
            printf("%d  ", q_arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int option, val;
    while (1)
    {
        printf("1. Insert an element to the queue\n");
        printf("2. Delete an element from the queue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;        
        default:
            printf("Wrong option!\n");
            break;
        }
    }
    return 0;
}
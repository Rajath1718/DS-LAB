#include <stdio.h>
#define maxsize 4
int q[maxsize];
int front = -1;
int rear = -1;
void insert(int item, int q[])
{
    if (rear == maxsize - 1)
        printf("Queue full\n");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        q[rear] = item;
    }
    else
    {
        rear = rear + 1;
        q[rear] = item;
    }
}
int pop(int q[])
{
    int item;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (front == rear)
    {
        item = q[front];
        front = -1;
        rear = -1;
        printf("Queue empty\n");
        return item;
    }
    else
    {
        item = q[front];
        front = front + 1;
        printf("Queue after deletion is:\n");
        for (int i = front; i <= rear; i++)
            printf("%d\n", q[i]);
        return item;
    }
}
void display(int q[])
{
    if (front == -1)
        printf("Queue is empty\n");
    else
        for (int i = front; i <= rear; i++)
            printf("%d\n", q[i]);
}
int main()
{
    int ch, item;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element:");
            scanf("%d", &item);
            insert(item, q);
            break;
        case 2:
            pop(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
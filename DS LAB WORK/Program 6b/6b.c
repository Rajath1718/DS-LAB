#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *next;
};
struct node *push(struct node *top){
    int element;
    printf("Enter element to be pushed: ");
    scanf("%d", &element);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = element;
    p->next = top;
    top = p;
    return top;
}

struct node *pop(struct node *top){
    if (top == NULL){
        printf("Stack is empty\n");
        return top;
    }
    struct node *temp = top;
    printf("The element deleted is: %d\n", temp->info);
    top = top->next;
    free(temp);
    return top;
}

void displaystack(struct node *top){
    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements:\n");
    while (temp != NULL){
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}



struct node *enqueue(struct node *front){
    int element;
    printf("Enter element to be enqueued: ");
    scanf("%d", &element);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = element;
    p->next = NULL;
    if (front == NULL){
        front = p;
        return front;
    }
    struct node *temp = front;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p;
    return front;
}

struct node *dequeue(struct node *front){
    if (front == NULL){
        printf("Queue is empty\n");
        return front;
    }
    struct node *temp = front;
    printf("The deleted element is: %d\n", temp->info);
    front = front->next;
    free(temp);
    return front;
}

void displayqueue(struct node *front){
    if (front == NULL){
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements:\n");
    while (temp != NULL){
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}
int main(){
    struct node *stack = NULL;
    struct node *queue = NULL;
    int choice;
    while (1){
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                stack = push(stack);
                break;
            case 2:
                stack = pop(stack);
                break;
            case 3:
                displaystack(stack);
                break;
            case 4:
                queue = enqueue(queue);
                break;
            case 5:
                queue = dequeue(queue);
                break;
            case 6:
                displayqueue(queue);
                break;
            case 7:
                exit(0);
            default:
               printf("Invalid choice\n");
        }
    }
}

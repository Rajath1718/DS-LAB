#define MAXSIZE 5
int q[MAXSIZE];
int front=-1;
int rear=-1;
#include<stdio.h>
void insert(int item){
    if(front==(rear+1)%MAXSIZE){
        printf("Queue is full\n");
    }
    else if(front==-1){
        front=0;
        rear=0;
        q[rear]=item;
    }
    else{
        rear=(rear+1)%MAXSIZE;
        q[rear]=item;
    }
}
void deletion(){
    int item;
    if(front==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        item=q[front];
        front=-1;
        rear=-1;
        printf("Item deleted is %d",item);
    }
    else{
        item=q[front];
        front=(front+1)%MAXSIZE;
        printf("\nItem deleted is %d",item);
    }
}
void display(){
    if(front==-1){
        printf("\nQueue is empty");
    }
    int i=front;
    while(1){
        printf("%d\n",q[i]);
        if(i==rear){
            break;
        }
        i=(i+1)%MAXSIZE;
    }
}
void main(){
    int choice;
    int element;
    while(1){
        printf("\nEnter you choice:(1-Insertion,2-deletion,3-display):");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("\nEnter element to be inserted:");
            scanf("%d",&element);
            insert(element);
            break;

        case 2:
            deletion();
            break;

        case 3:
            display();
            break;
        }
    }
}

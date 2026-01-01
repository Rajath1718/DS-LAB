#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *createsll(){
    struct node *start=NULL;
    struct node *last;
    struct node *p;
    int item;
    printf("Enter the elements of the linked list.To stop enter -999:");
    scanf("%d",&item);
    while(item!=-999){
        p = (struct node *)malloc(sizeof(struct node));
        p->info =item;
        if(start==NULL){
            p->next=NULL;
            start=p;
            last=p;
        }
        else{
            last->next=p;
            last=p;
            last->next=NULL;
        }
        scanf("%d",&item);
    }
    return start;
}
struct node *insertbeg(struct node *start,int item){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->info=item;
    if(start==NULL){
        p->next=NULL;
        start=p;

    }
    else{
        p->next=start;
        start=p;
    }
    return start;
}
struct node *insertend(struct node *start,int item){
    struct node *temp;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info=item;
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        p->next=NULL;
        temp->next=p;

    }
    return start;
}
struct node *insertatpos(struct node *start,int item){
    int elem;
    printf("Enter the element after which you want to insert the item:");
    scanf("%d",&elem);
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->info=item;
    struct node *temp=start;
    while(temp!=NULL && temp->info!=elem){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found");
    }
    else{
        if(temp->next==NULL){
            p->next==NULL;
            temp->next=p;
        }
        p->next = temp->next;
        temp->next=p;
    }
    return start;
}
void display(struct node *start){
    struct node *temp=start;
    if(start==NULL){
        printf("LL is empty");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}
int main(){
    int choice;
    struct node *h1=NULL;
    while(1){
        printf("\n1.for creation\n2.for insertion at beginning\n3.for insertion at end\n4.insertion at any position\n5.for display\n6.to exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){

            case 1:
               h1=createsll();
               break;
            case 2:
                h1=insertbeg(h1,9);
                printf("\nItem inserted at beginning..");
                break;
            case 3:
                h1=insertend(h1,50);
                printf("\nItem inserted at end");
                break;
            case 4:
                h1=insertatpos(h1,100);
                printf("\nItem inserted at desired position.");
                break;
            case 5:
                display(h1);
                break;
            case 6:
                return 0;
            
        }
    }
}
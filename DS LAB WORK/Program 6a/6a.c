#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *createsll(){
    struct node *start=NULL;
    struct node *last;
    struct node *p;
    int item;
    printf("Enter the elements.To stop enter -999:\n");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *)malloc(sizeof(struct node));
        p->info=item;
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
struct node *reversesll(struct node *start){
    struct node *cur=NULL;
    struct node *temp;
    temp=start;
    while(temp!=NULL){
        start=temp->next;
        temp->next=cur;
        cur=temp;
        temp=start;
    }
    return cur;
}

struct node *sortsll(struct node *start){
    struct node *temp,*i,*j;
    int temp2;
    if(start==NULL){
        printf("Only one element.Already sorted.\n");
    }
    else{
        for(i=start;i->next!=NULL;i=i->next){
            temp=i;
            for(j=i->next;j!=NULL;j=j->next){
                if(j->info<temp->info){
                    temp=j;
                }
            }
            temp2=i->info;
            i->info=temp->info;
            temp->info=temp2;
        }
    }
    return start;
}
struct node *concatenate(struct node *head1, struct node *head2){
    struct node *temp;
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    else{
        temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head2;
        return head1;
    }
}
void display(struct node *start){
    struct node *temp=start;
    while(temp!=NULL){
        printf("%d\n",temp->info);
        temp=temp->next;
    }
}
int main(){
    int choice;
    struct node *h1=NULL;
    struct node *h2=NULL;
    while(1){
        printf("1.creation of h1.\n2.creation of h2\n3.reversing\n4.sorting\n5.merging.\n6.Display.\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                h1=createsll();
                break;
            case 2:
                h2=createsll();
                break;
            case 3:
                h1=reversesll(h1);
                break;
            case 4:
                h1=sortsll(h1);
                break;
            case 5:
                h1=concatenate(h1,h2);
                break;
            case 6:
                display(h1);
                break;
        }
    }
}
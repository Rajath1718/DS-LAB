#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *createsll()
{
    struct node *start = NULL;
    struct node *last;
    struct node *p;
    int item;
    printf("Enter the elements of the linked list.To stop enter -999:");
    scanf("%d", &item);
    while (item != -999)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->info = item;
        if (start == NULL)
        {
            p->next = NULL;
            start = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
            last->next = NULL;
        }
        scanf("%d", &item);
    }
    return start;
}
struct node *deletebeg(struct node *start)
{
    
    if (start == NULL)
    {
        printf("Linked list is empty.");
    }
    else
    {
        struct node *temp=start;
        start=start->next;
        free(temp);
    }
    return start;
}
struct node *deleteend(struct node *start)
{
    struct node *temp,*follow;
    if (start == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            follow=temp;
            temp = temp->next;
        }
        follow->next=NULL;
        free(temp);
        
    }
    return start;
}
struct node *deleteitem(struct node *start)
{
    int elem;
    printf("Enter the element you want to delete:");
    scanf("%d", &elem);
    struct node *temp = start;
    struct node *follow;
    while (temp != NULL && temp->info != elem)
    {
        follow=temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Element not found");
    }
    else if(temp->next==NULL){
        follow->next=NULL;
        free(temp);
    }
    else
    {
        follow->next=temp->next;
        free(temp);
    }
    return start;
}
void display(struct node *start)
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
    struct node *h1 = NULL;
    while (1)
    {
        printf("\n1.for creation\n2.for deletion at beginning\n3.for deletion at end\n4.deletion at any position\n5.for display\n6.to exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            h1 = createsll();
            break;
        case 2:
            h1 = deletebeg(h1);
            printf("\nItem deleted at beginning..");
            break;
        case 3:
            h1 = deleteend(h1);
            printf("\nItem deleted at end");
            break;
        case 4:
            h1 = deleteitem(h1);
            printf("\nItem deleted at desired position.");
            break;
        case 5:
            display(h1);
            break;
        case 6:
            return 0;
        }
    }
}
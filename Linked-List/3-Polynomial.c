#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *link;
};
struct node *start1=NULL, *start2=NULL;
struct node *create(struct node *start)
{
    int n, c, e, i;
    struct node *temp, *ptr;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("Insufficient Memory");
            return 0;
        }
        printf("Enter Coefficient for term %d:", i);
        scanf("%d", &c);
        printf("Enter Exponent for term %d:", i);
        scanf("%d", &e);

        temp->coeff=c;
        temp->expo=e;
        if(start==NULL||e>start->expo)
        {
            temp->link=start;
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->link!=NULL&&ptr->link->expo>=e)
            {
                ptr=ptr->link;
            }
            temp->link=ptr->link;
            ptr->link=temp;
        }
    }
    return start;
}
void display(struct node *ptr)
{
     if(ptr==NULL)
    {
        printf("No Node in Linked List to Display");
        return ;
    }
    while(ptr!=NULL)
    {
        printf("%d->", ptr->coeff);
        printf("%d->", ptr->expo);
        ptr = ptr->link;
    }
    printf("NULL");
}
int main(void)
{
    int choice, item;
    while(1)
    {
        printf("\n1. Enter 1st Polynomial");
        printf("\n2. Enter 2nd Polynomial");
        printf("\n3. Addition of 1st polynomial and 2nd polynomial");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            start1=create(start1);
            printf("start1->");
            display(start1);
            break;

        case 2:
           start2=create(start2);
            printf("start2->");
            display(start2);
            break;

        case 6:
            exit(0);

        default:
            printf("Wrong Input!!!");
            printf("Please provide correct option next time Onwards");
        }
    }
    return 0;
}


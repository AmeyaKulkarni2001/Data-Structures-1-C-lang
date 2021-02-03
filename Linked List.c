#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int len(struct node*);
struct node *head, *nnode, *head1, *head2;

void create(struct node *head)
{
    struct node *temp, *curr;
    temp=head;
    int ch=0;
    do
    {
        curr=(struct node*)malloc(sizeof(struct node));
        printf("Enter data in node: ");
        scanf("%d", &curr->data);
        curr->next=NULL;
        temp->next=curr;
        temp=temp->next;
        printf("====MENU====\n1.Add more nodes\n2.End list\n" );
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if(ch<1||ch>2)
        {
            printf("wrong choice\n");
        }
    }while(ch!=2);
    head=temp;
}

void display(struct node *head)
{
    struct node *curr;
    if(head->next==NULL)
        printf("List is Empty");
    else
    {
        curr=head->next;
        printf("List is:\n");
        while(curr!=NULL)
        {
            printf("\t%d", curr->data);
            printf("\n");
            curr=curr->next;
        }
    }
    
}

void atBeg(struct node *head)
{
    nnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to add in new node\n");
    scanf("%d", &nnode->data);
    nnode->next=head->next;
    head->next=nnode;
}

void atEnd(struct node *head)
{
    struct node *last;
    last=head;
    nnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to add in new node\n");
    scanf("%d", &nnode->data);
    nnode->next=NULL;
    while(last->next!=NULL)
        last=last->next;
    last->next=nnode;
}

void InBet(struct node *head)
{
    struct node *curr;
    curr=head;
    int k; 
    k=len(head);
    int pos;
    int i=1;
    nnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Position you want to insert the new node in\n");
    scanf("%d", &pos);
    printf("Enter data to add in new node\n");
    scanf("%d", &nnode->data);
    if(pos>k&&pos<k+1)
        atEnd(head);
    else if(pos>k+1)
    {
        printf("Error: Position out of bounds\nPlease choose a Position lower than: %d\n", k+2);
    }
    else
    {
        while(i<pos)
        {
            i++;
            curr=curr->next;
        }
        nnode->next=curr->next;
        curr->next=nnode;
    }
}

void delete(struct node *head)
{
    int pos,k;
    int i=1;
    k=len(head);
    struct node *prev, *curr;
    prev=head;
    curr=head->next;
    printf("Enter the Position you want to delete the node on: ");
    scanf("%d", &pos);
    if(pos>k)
        printf("Error: Position out of bounds\nPlease choose a Position lower than: %d\n", k+1);
    else
    {
        while(i<pos)
        {
            i++;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
    }
}

void sort(struct node *head)
{
    struct node *curr, *prev, *front;
    int i,j,l;
    l=len(head);
    for(i=1;i<l-1;i++)
    {
        prev=head;
        curr=head->next;
        for (j=0;j<l-1;j++)
        {
            front=curr->next;
            if(curr->data > front->data)
            {
                prev->next=front;
                curr->next=front->next;
                front->next=curr;
                prev=front;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        
    }
}

int len(struct node *head)
{
    struct node *last;
    last=head;
    int ctr=0;
    while(last->next!=NULL)
    {
        last=last->next;
        ctr++;
    }
    return ctr;
}

void reverse(struct node *head)
{
    struct node *prev, *curr, *front;
    prev=NULL;
    curr=head->next;
    while(curr!=NULL)
    {
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    head->next=prev;
}

void merge(struct node *head1, struct node *head2)
{
    struct node *curr1, *curr2, *temp;
    int flag;
    curr1=head1->next;
    curr2=head2->next;
    if(curr1->data<curr2->data)
    {
        temp=head1;
        flag=1;
    }
    else
    {
        temp=head2;
        flag=0;
    }
    while(curr1!=NULL&&curr2!=NULL)
    {
        if(curr1->data<curr2->data)
        {
            temp->next=curr1;
            temp=curr1;
            curr1=curr1->next;
        }
        else
        {
            temp->next=curr2;
            temp=curr2;
            curr2=curr2->next;
        }
    }
    if(curr1==NULL)
        temp->next=curr2;
    if(curr2==NULL)
        temp->next=curr1;
    if(flag==1)
        display(head1);
    else
        display(head2);
}

int main()
{
    int ch=0;
    head=(struct node*)malloc(sizeof(struct node));
    do
    {
        printf("++++++++++++++++++++MENU++++++++++++++++++++\n1.Create List\n2.Display List\n3.Insert a node\n4.Delete a node\n5.Sort the list\n6.Reverse a List\n7.Merge two Lists\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            if(head->next==NULL)
                printf("You need to create a list first\n");
            else
            {
                int ch2=0;
                printf("Where do you want to add the node?\n1.At Beggining\n2.At End\n3.In Between\n");
                printf("Enter your choice: ");
                scanf("%d", &ch2);
                switch(ch2)
                {
                    case 1:
                        atBeg(head);
                        break;
                    case 2:
                        atEnd(head);
                        break;
                    case 3:
                        InBet(head);
                        break;
                    default:
                        printf("wrong choice\n");
                }
            }
            break;
        case 4:
            delete(head);
            break;
        case 5:
            sort(head);
            break;
        case 6:
            reverse(head);
            break;
        case 7:
            
            head1=(struct node*)malloc(sizeof(struct node));
            head2=(struct node*)malloc(sizeof(struct node));
            printf("Enter data of first list\n");
            create(head1);
            printf("Enter data of second list\n");
            create(head2);
            printf("List 1 is:\n");
            display(head1);
            printf("List 2 is:\n");
            display(head2);
            merge(head1, head2);
            break;
        case 8:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }while(ch!=8);
    return 0;
}

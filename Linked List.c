#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head, *nnode, *head1, *head2;

void create(struct node *head) {
    struct node *temp, *curr;
    temp=head;
    int ch=0;
    do {
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
}

int length(struct node *head) {
    struct node *last;
    last=head;
    int ctr=0;
    while(last->next!=NULL) {
        last=last->next;
        ctr++;
    }
    return ctr;
}

void display(struct node *head) {
    struct node *curr;
    if(head->next==NULL)
        printf("List is Empty");
    else {
        curr=head->next;
        printf("List is:\n");
        while(curr!=NULL) {
            printf("%d -> ", curr->data);
            curr=curr->next;
        }
        printf("NULL");
    }
}

void insert(struct node *head) {
    struct node *curr;
    curr=head;
    int k = length(head), pos, i = 0;
    nnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Position you want to insert the new node in\n");
    scanf("%d", &pos);
    if(pos > k && pos < 0) {
        printf("Position out of bounds\nPlease choose a Position lower than: %d\n", k);
        return;
    }
    printf("Enter data to add in new node\n");
    scanf("%d", &nnode->data);
    if(pos == k) {
        nnode->next=NULL;
        while(curr->next!=NULL)
            curr=curr->next;
            
        curr->next=nnode;
    } else {
        while(i<pos) {
            i++;
            curr=curr->next;
        }
        nnode->next=curr->next;
        curr->next=nnode;
    }
    //0 -> 1 -> 2 -> 10 -> 3 -> 4 -> 5 -> NULL 
}

int delete(struct node *head) {
    struct node *curr, *temp;
    curr=head;
    int k;
    k=length(head);
    int pos, i = 0;
    printf("\nEnter the pos at which you want to delete\n");
    scanf("%d", &pos);
    if(pos == 0) {
        temp = head->next;
        head->next = head->next->next;
        return temp->data;
        //head -> 0 -> 1 -> 2 -> 3
    } else if(pos == k - 1) {
        while(curr->next->next != NULL) {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = NULL;
        return temp->data;
    } else if(pos < 0 && pos >= k) {
        printf("\nInvalid position.");
        return -1;
    } else {
        while(i < pos) {
            curr = curr->next;
            i++;
        }
        temp = curr->next;
        curr->next = curr->next->next;
        return temp->data;
    }
}
//head -> 0 -> <- 1  2 -> 3 -> -> 4 -> 5 -> NULL
void reverse(struct node *head) {
    struct node *prev = head->next, *curr = head->next->next;
    while(curr != NULL) {
        struct node *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head->next->next = NULL;
    head->next = prev;
}

void sort(struct node *head) {
    struct node *curr, *prev, *front;
    int i, j, l = length(head);
    for(i=0; i<l-1; i++) {
        prev = head;
        curr = head->next;
        for(j=0; j<l-1; j++) {
            front = curr->next;
            if(curr->data > front->data) {
                curr->next = front->next;
                front->next = curr;
                prev->next = front;
                prev = front;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void create1(struct node *last, int x) {
    struct node *curr;
    curr=(struct node*)malloc(sizeof(struct node));
    curr->next = NULL;
    curr->data = x;
    last->next = curr;
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

int main() {
    int ch=0, deleted = 0;
    head=(struct node*)malloc(sizeof(struct node));
    do {
        printf("\n++++++++++++++++++++MENU++++++++++++++++++++\n1.Create List\n2.Display List\n3.Insert\n4.Delete\n5.Reverse\n6.Sort\n7.Merge\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            create(head);
            printf("\nfirst element: %d", head->next->data);
            break;
        case 2:
            display(head);
            break;
        case 3:
            insert(head);
            break;
        case 4:
            deleted = delete(head);
            printf("\nDeleted element is: %d", deleted);
            break;
        case 5:
            reverse(head);
            break;
        case 6: 
            sort(head);
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

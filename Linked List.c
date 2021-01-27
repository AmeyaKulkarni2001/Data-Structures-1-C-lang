// work in progress
// merge doesn't work
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

void merge(struct node *head1, struct node *head2) {
    printf("\nin merge");
    struct node *temp1 = head1 -> next, *temp2 = head2 -> next, *head3, *temp3 = head3;
    head3=(struct node*)malloc(sizeof(struct node));
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data <= temp2->data) {
            create1(temp3, temp1->data);
            temp1 = temp1->next;
        } else if(temp2->data <= temp1->data){
            create1(temp3, temp2->data);
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }
    if(temp1 == NULL) {
        while(temp2 != NULL) {
            create1(temp3, temp2->data);
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    } else if(temp2 == NULL) {
        while(temp1 != NULL) {
            create1(temp3, temp1->data);
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
    }
    display(head3);
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
            printf("\nEnter first linked list: \n");
            create(head1);
            printf("\nEnter second linked list: \n");
            create(head2);
            printf("\nbefore merge");
            merge(head1->next, head2->next);
            printf("\nafter merge.");
            break;
        case 8:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }while(ch!=8);
    return 0;
}

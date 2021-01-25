#include<stdio.h>
#include<stdlib.h>
#define MAX 3

struct Pizza
{
    int id;
    char name[30];
    char address[50];
    int qty;
};
struct Pizza p[3];
int rear=0,front=0,id=1;

int is_full()
{
    if((rear+1)%MAX==front)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if(front == rear)
        return 1;
    else
        return 0;
}

void insert1()
{
    if(is_full())
    {
        printf("Queue Overflow \n");
    }

    else
    {
        {
            if (front == 0) front = 1;
            rear=(rear+1);
            p[rear].id = id;
            printf("Enter Name: ");
            scanf("%s",p[rear].name);
            printf("Enter Address: ");
            scanf("%s",p[rear].address);
            printf("Enter Quantity: ");
            scanf("%d",&p[rear].qty);
            p[rear].id=id++;
        }
    }
}


void display()
{
    if(front == 0)
    {
      printf("No pending orders!") ;
        
    }
    else
    {
        printf("Pending Orders are: ");
        printf("\n\nID\t\t\t\tNAME\t\t\t\tADDRESS\t\t\t\tQUANTITY");
        printf("\n------------------------------------------------------------------------------------------");
        for(int i = front; i <= rear; i++)
        {
            printf("\n%d\t\t\t\t%s\t\t\t\t%s\t\t\t\t\t%d\n",p[i].id,p[i].name,p[i].address,p[i].qty);
            
        }
    }
}



int deQueue1() 
{
  int element;
  if (front == 0)
    {
    printf("\n Queue is empty !! \n");
    }

    else
    {
        printf("Element dispatched is :\n");
        printf("ID: %d\n", p[front].id);
        printf("Name: %s\n", p[front].name);
        printf("Address: %s\n", p[front].address);
        printf("Quantity: %d\n", p[front].qty);
    }
    if(front == rear)
    {
        front = 0;
        rear=0;
    }
    else
    {
        if(front == MAX)
        front = 0;
        else
        front = front+1;
    }
}

int main()
{
    int item;
    int choice;
    while (1)
    {
        printf("\nMENU\n");
        printf("1.Place Order\n");
        printf("2.Dispatch Order \n");
        printf("3.Display Pending Orders \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert1();
                    break;
            case 2: deQueue1();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nWrong choice!");
        }
    }
}

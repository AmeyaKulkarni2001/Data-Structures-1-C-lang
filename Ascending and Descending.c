#include <stdio.h>
struct number{
    int digit;
};

void accept(struct number s[],int n) 
{
	for(int i=0;i<n;i++) {
		
		printf("Enter the number:");
		scanf("%d",&s[i].digit);
		
	}
	
}
void displayall(struct number s[],int n)
{
    for(int i=0;i<n;i++) {
        printf("%d",s[i].digit);
    }
}
void bubbleSort(struct number s[],int n)
{
    int i,j;
    struct number temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].digit>s[j+1].digit)
            {
              temp=s[j];
              s[j]=s[j+1];
              s[j+1]=temp;
            }
        }
    }
    printf("\nArray in Ascending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",s[i].digit);
    }
    
}

void descBubbleSort(struct number s[],int n)
{
    int i,j;
    struct number temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].digit<s[j+1].digit)
            {
              temp=s[j];
              s[j]=s[j+1];
              s[j+1]=temp;
            }
        }
    }
    printf("\nArray in Descending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",s[i].digit);
    }
    
}

int main(){
    struct number s[20];
    int n;
    printf("\nEnter no of digits");
    scanf("%d",&n);
    printf("\nAscending order");
    accept(s, n);
	bubbleSort(s, n);
	printf("\nThe sorted data is: \n");
	displayall(s, n);
	
	printf("\nDescending order\n");
    accept(s, n);
	descBubbleSort(s, n);
	printf("\nThe sorted data is: \n");
	displayall(s, n);
}

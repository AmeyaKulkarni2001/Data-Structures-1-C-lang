#include<stdio.h>
void accept(int a[][50],int m,int n)
{
    int i,j;
    printf("\nEnter elements:");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[][50],int m,int n)
{
    int i,j;
    printf("\nMatrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void displaySparse(int matrix[40][3])
{
       int column = matrix[0][2];
        printf("\nCompact Matrix\n\n");
        for (int i=0; i<=column; i++)
        { 
            printf("%d\t%d\t%d\n", matrix[i][0],matrix[i][1], matrix[i][2]);
        }
}
void compact(int a[50][50],int m,int n,int b[50][3])
{
    b[0][0]=m;
    b[0][1]=n;
    int i,j;
    int k=1;
    display(a,m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
        b[0][2]=k-1;
    }
    displaySparse(b);
}
void Transpose(int b[50][3],int c[50][3])
{ 
	int t=b[0][2];
	
	int m=b[0][0];
	
	
	int n=b[0][1];
	
	c[0][0]=n;
	
	c[0][1]=m;
	
	c[0][2]=t;
	
	

	int q=1,col,p;
	for(col=0;col<n;col++)
	{
		for(p=1;p<=t;p++)
		{
			if(b[p][1]==col)
			{
				c[q][0]=b[p][1];
				c[q][1]=b[p][0];
				c[q][2]=b[p][2];
				q=q+1;
			}
		}
	}
	int column=c[0][2],i;
	printf("Transpose of Sparse Matrix Formed is\n");
   for(i=0;i<=column;i++)
   {
   	printf("%d\t%d\t%d\n",c[i][0],c[i][1],c[i][2]);
   }
	
}

void FastTranspose(int b[50][3],int d[50][3])
{
		int m=b[0][0];
		int n=b[0][1];
		int t=b[0][2];
		
		int s[n],t1[n];
		
	    d[0][0]=n;
        d[0][1]=m;
	    d[0][2]=t;
	    int i;
	    for(i=0;i<n;i++)
	    {
	    	s[i]=0;
		}
		for(i=1;i<=t;i++)
		{
			s[b[i][1]] = s[b[i][1]]+1;
		}
		
		t1[0]=1;
		for(i=1;i<=n;i++)
	    { 
	    	t1[i]=t1[i-1]+s[i-1];
		}
		int j;
		for(i=1;i<=t;i++)
		{
			j=b[i][1];
			d[t1[j]][0]=b[i][1];
			d[t1[j]][1]=b[i][0];
			d[t1[j]][2]=b[i][2];
			t1[j]=t1[j]+1;
		}
	int column=d[0][2];
   printf("Fast Transpose of Sparse Matrix Formed:\n");
   for(i=0;i<=column;i++)
   {
   	printf("%d\t%d\t%d\n",d[i][0],d[i][1],d[i][2]);
   }
		
}

int main()
{
    int a[50][50],b[50][3],c[50][3],d[50][3],i,j,m,n;
    int choice;
    do
    {
    printf("MENU");
    printf("\n1Accept");
    printf("\n2Display");
    printf("\n3Compact Matrix");
    printf("\n4Transpose");
    printf("\n5Fast Transpose");
    printf("\n6Exit");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:  printf("Enter row:");
                 scanf("%d",&m);
                 printf("Enter column:");
                 scanf("%d",&n);
                 accept(a,m,n);
                 break;
        case 2: display(a,m,n);
                 break;
        case 3: compact(a,m,n,b);
                 break;
        case 4: Transpose(b,c);
                break;
        case 5: FastTranspose(b,d);
                break;
        case 6: printf("\nExiting");
                 break;
        default: printf("\nWrong choice");
    }
    }while(choice!=6);
    return 0;
    
}
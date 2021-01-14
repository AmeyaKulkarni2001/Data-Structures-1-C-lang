#include <stdio.h>
struct student 
{
	char name[20];
	int rollno;
	float marks;
	char div[1];
};
void accept(struct student s[],int n) 
{
	for(int i=0;i<n;i++) {
		printf("\nEnter the name of the student:");
		scanf("%s",s[i].name);
		printf("Enter the roll number:");
		scanf("%d",&s[i].rollno);
		printf("Enter the marks:");
		scanf("%f",&s[i].marks);
		printf("Enter the division:");
		scanf("%s",s[i].div);
	}
	
}

void displayall(struct student s[],int n)
{
    printf("\nStudent details:");
    printf("\nName\t\tRollno\t\tMarks\t\tDivision\n");
    for(int i=0;i<n;i++) {
        printf("%s\t\t  %d\t\t%f\t\t%s\t\t\n",s[i].name,s[i].rollno,s[i].marks,s[i].div);
    }
}

void display(struct student s[],int x)
{
    printf("\nStudent details:");
    printf("\nName\t\tRollno\t\tMarks\t\tDivision\n");
    printf("%s\t\t  %d\t\t%f\t\t%s\t\t",s[x].name,s[x].rollno,s[x].marks,s[x].div);
}

void linear(struct student s[20], int n)
{
	int key, flag = 0, i = 0;
	printf("Enter the roll no: ");
	scanf("%d", &key);
	for (i = 0; i < n; i++) {
		if (s[i].rollno == key) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		printf("\nstudent is present.");
		display(s, i);
	}
	else {
		printf("\nnot present");
	}
}
void binary(struct student s[20], int n)
{
	int key, start = 0, end = n-1, mid, flag = 0;
	printf("\nEnter roll number: ");
	scanf("%d", &key);
	while (start <= end) {
		mid = (start + end) / 2;
		printf("mid: %d, s[mid]: %d", mid, s[mid].rollno);
		if (key == s[mid].rollno) {
			flag = 1;
			printf("\nRoll number found.");
			display(s, mid);
			break;
		}
		else if (s[mid].rollno < key) {
			start = mid + 1;
		}
		else if (s[mid].rollno > key) {
			end = mid - 1;
		}
	}
	if(flag == 0) {
		printf("\nNot Found!");
	}
}

int recBinary(struct student s[],int low,int high,int key)
{
    int mid;
    if(low<=high) {
        mid=(low+high)/2;
        if(s[mid].rollno==key) {
            return mid;
        }
        else {
            if(key<s[mid].rollno) {
                return recBinary(s,low,mid-1,key);
            }
            else {
                return recBinary(s,mid+1,high,key);
            }            
        }
    }
    return -1;
}

void bubbleSort(struct student s[], int n) 
{ 
   int i, j;
   struct student temp; 
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
           if (s[j].rollno > s[j+1].rollno) {
               temp=s[j];
               s[j]=s[j+1];
               s[j+1]=temp;
               displayall(s,n);
           }   
       } 
   }
}

void insertionSort(struct student s[], int n) {
	for(int i=1; i<n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(s[j].rollno > s[j+1].rollno) {
				struct student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				displayall(s,n);
			} else {
				break;
			}
		}
	}
}

void selectionSort(struct student s[], int n) {
	printf("\nSorting on the basis of marks: ");
	for(int i=0; i<n - 1; i++) {
		int small = i;
		for(int j=i; j<n; j++) {
			if(s[j].marks < s[small].marks) {
				small = j;
				displayall(s,n);
			}
			struct student temp = s[i];
			s[i] = s[small];
			s[small] = temp;
		}
	}
}

int main() {
    struct student s[20];
    int n, choice;
    printf("\nEnter no of students:");
    scanf("%d",&n);
    do {
    printf("\nMENU \n1)Accept \n2)Display all \n3)Linear search \n4)Binary search \n5)Recursive Binary \n6)Bubble Sort \n7)Insertion Sort \n8)Selection Sort \n9)Exit");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice) {
        case 1: accept(s,n);
                break;
        case 2: displayall(s,n);
                break;
        case 3: linear(s,n);
                break;
        case 4: binary(s,n);
                break;
        case 5: 
		{	
			int key;
			printf("\nEnter the Roll Number: ");
			scanf("%d", &key);
			if(recBinary(s, 0, n-1, key) == -1) {
				printf("\nNot found.");
			} else {
				display(s, recBinary(s, 0, n-1, key));
			}
			break;
		}
		case 6: accept(s, n);
		        bubbleSort(s, n);
				printf("\nThe sorted data is: \n");
				displayall(s, n);
				break;
		case 7: accept(s, n);
		        insertionSort(s,n);
				displayall(s,n);
				break;
		case 8: accept(s, n);
		        selectionSort(s,n);
				displayall(s,n);
                break;
		case 9: printf("\nExiting..");
                break;
        default: printf("\nWrong choice");
    }
    
    } while(choice!=9);    
    return 0;    
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 30
int top = -1, stack[size],i;
char postfix[30];
char stacks[30][30], stack1[30];

int IsFull()
{
    if (top == size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


char pop() 
{
    char temp;
   if(!IsEmpty()) 
   {
       temp=stack[top];
       top=top-1;
       return(temp);
      
   } 
   else 
   {
      printf("\nUnderflow");
   }
}
void * pop1(){
    char *temp = stacks[top];
    top--;
    return(temp);
}

void push(char data) 
{

   if(IsFull()) 
   {
       printf("\nOverflow");
   } 
   else 
   {
       top++;   
      stack[top] = data;
     
   }
}
void push1(char str1[20]){
    top++;
    strcpy(stacks[top], str1);
}

void Display()
{
    if(IsEmpty())
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack:\n");
        for(int i = top; i >= 0; i--)
        {
            printf("%c\n", stack[i]);
        }
    }
}


int Icp(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '*' || ch == '/')
    {
        return 2;
    }
    if(ch == '^')
    {
        return 4;
    }
    if(ch == '(')
    {
        return 5;
    }
    else
    {
        return 0;
    } 
}

int Isp(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '*' || ch == '/')
    {
        return 2;
    }
    if(ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    } 
}

void ToPostfix(char infix[10])
{
    int i = 0, j = 0;
    char temp;
    while(infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while ((temp = pop()) != '(')
            {
                postfix[j] = temp;
                j++;
            }
        }
        else if(!IsEmpty() && Isp(stack[top]) >= Icp(infix[i]))
        {
            postfix[j] = pop();
            j++;
            push(infix[i]);
        }
        else
        {
            push(infix[i]);
        }
        i++;
    }
    while(!IsEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j]='\0';
    printf("The Postfix expression is: ");
    printf("%s",postfix);
}
void post_in(char exp[30]){
    char str[20], str1[20], op1[20],op2[20],str2[20];
    int i, l;
    for(i=0; exp[i]!= '\0'; i++){
        if(exp[i]=='+'|| exp[i]=='-'|| exp[i]=='*'|| exp[i]=='/' ||exp[i]=='^'){
            strcpy(op1, pop1());
            strcpy(op2, pop1());
            str2[0] = '\0';
            str2[0] = '(';
            str2[1] = '\0';
            strcat(str2, op2);
            l = strlen(str2);
            str2[l] = exp[i];
            str2[l+1] = '\0';
            strcat(str2, op1);
            l = strlen(str2);
            str2[l] = ')';
            str2[l+1] = '\0';
            push1(str2);
        }
        else{
            str1[0] = '\0';
            str1[0] = exp[i];
            str1[1] = '\0';
            push1(str1);
        }
    }
    strcpy(str1,pop1());
    printf("\ninfix expression is: ");
    printf("\t%s", str1);
}


int main()
{   
    char infixexp[10], data;
    char exp[20];
    int choice;
    do
    {
        printf("\nMENU");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Convert Infix to Postfix");
        printf("\n5.Convert Postfix to Infix");
        printf("\n6. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter Element to pushed:");
                    scanf(" %c",&data);
                    push(data);
                    break;
            
            case 2: pop();
                    break;
            
            case 3: Display();
                    break;
                
            case 4: printf("\nEnter an Infix expression: ");
                    scanf("%s",infixexp);
                    ToPostfix(infixexp);
                    break;

            case 5: printf("\nEnter the postfix expression: ");
                    scanf("%s", exp);
                    printf("\nThe postfix expression is: ");
                    printf("\t%s", exp); 
                    post_in(exp);
                    break;
                    
            case 6: printf("\nExiting");
                    break;
            
            default: printf("Enter a valid choice.");
        }
    } while (choice != 6);
    return 0;
}
#include<stdio.h>
#include<string.h>
void accept(char s[])
{
    printf("Enter the string:\n");
    scanf("%s", s);
}
int length(char s[])
{
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}
int plength(char* p1)
{
    int count = 0;
    while((*p1) != '\0') {
        count++;
        p1++;
    }
    return count;
}
void copy(char s1[], char s2[])
{
    int i = 0;
    while(s1[i] != '\0') {
        s2[i] = s1[i];
        i++;
    }
}
void pcopy(char *p1, char *p2)
{
    while(*p1 != '\0') {
        *p2 = *p1;
        *p2++;
        *p1++;
    }
    *p2 = '\0';
}
void display(char s[])
{
    printf("\nString: %s", s);
}
void concat(char s1[], char s2[])
{
    int i=0, l = strlen(s1);
    while(s2[i] != '\0') {
        s1[l] = s2[i];
        i++;
        l++;
    }
    s1[l] = '\0';
    printf("\nString after concat: %s", s1);
}
void pconcat(char *p1, char *p2)
{
    int i = 0, l = strlen(p1);
    while(*p1){
        p1++;
    }
    while(*p2){
        *p1 = *p2;
        p2++;
        p1++;
    }
    *p1 = '\0';
}
void reverse (char s[])
{
    char temp;
    for(int i=0, j=strlen(s) - 1; i<=j; i++) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
    printf("\nString reversed: %s", s);
}
void preverse(char *str)
{
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(str);
   begin  = str;
   end    = str;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
void sub (char str1[10], char str2[10])
{
    int count1 = 0, count2 = 0, flag, m = 0, k = 0, i,j;
    count1 = strlen(str1);
    count2 = strlen(str2);
    for(i = 0;i<=count1;i++)
    {
        for(j =i,k=0; j<i+count2; j++,k++)
        {
            if(str1[j] == str2[k])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            m++;
        }
    }
    if(m!=0)
    {
        printf("The substring was found\n");
        printf("The string occurs %d times\n",m);
    }
    else
    {
        printf("Substring not found\n");
        
    }
}   
int main()
{
    char str1[10], str2[10], str3[10];
    int choice;
    do {
        printf("\nChoose one option: \n1)length, \n2)copy, \n3)concat, \n4)reverse, \n5)Substing, \n6)pointer lenght, \n7)pointer copy, \n8)pointer concat, \n9)pointer reverse");
        int c;
        scanf("\n%d", &c);
        switch (c)
        {
        case 1: printf("\nlength of str1: %d", length(str1));
                printf("\nlength of str2: %d", length(str2));
            break;
        case 2: display(str3); 
                copy(str1, str3);
                printf("string after: \n");
                display(str3);
            break;
        case 3: accept(str1);
                accept(str2);
                concat(str1, str2);
            break;
        case 4: reverse(str1);
            break;        
        case 5: accept(str1);
                accept(str2);
                sub(str1, str2);
            break;
        case 6: accept(str1);
                printf("\nlenght of string is: %d", lenght(str1));
            break;
        case 7: accept(str1);
                pcopy(str1, str2);
                display(str2);
            break;
        case 8: accept(str1);
                accept(str2);
                pconcat(str1,str2);
                display(str2);
            break;
        case 9: accept(str1);
                preverse(str1);
            break;
        default: printf("\nwrong choice.");
            break;
        }
        printf("\nDo you want to continue?(1/0)\n");
        scanf("%d", &choice);
    }while(choice == 1);
}
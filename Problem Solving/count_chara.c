//Count how many times a character has occured in the given array.

#include<stdio.h>
#include<stdlib.h>
#define maxsz 50

int count(char a[],int n,char key)
{
    int i;
    int count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
        count++;
        }
    }
    return count;
}

int countstr(char *str, char key)          //for string
{
    int count=0;
    while(*str != '\0')
    {
        if(*str==key)
        {
            count++;
        }
        str++;
    }
    return count;
}


int main()
{
    // char a[8]={'a','b','a','d','a','f','g'};
    // char key='a';
    // int n=8;
    // int res=count(a,n,key);
    // printf("The count is %d\n",res);
    // return 0;

    int n;
    char a[maxsz];
    printf("Enter sizer of array: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&a[i]);
    }
    char key;
    printf("Enter ele to search: ");
    scanf(" %c",&key);
    int res=count(a,n,key);
    printf("The element has occured %d times.\n",res);
    return 0;
}

// int main()               //for string
// {
//     char *a="Channveer";
//     char key='n';
//     int res=countstr(a,key);
//     printf("The element has occured %d times.\n",res);
//     return 0;
// }
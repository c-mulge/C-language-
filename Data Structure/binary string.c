// recursive function on binary search using string in array

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsz 500

int binary(char *a[],int lb,int ub,char key[])
{
    int mid;
    if(lb>ub)
        return -1;
    mid=(lb+ub)/2;
    if(strcmp(a[mid],key)==0)
        return mid;
    else if(strcmp(a[mid],key)>0)
        return binary(a,lb,mid-1,key);
    else
        return binary(a,mid+1,ub,key);
}

void display(char *a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s\n",a[i]);
    }
}

void insert(char *a[],int n)
{
    int i,j;
    char *hold;
    for(i=0;i<n;i++)
    {
        hold=a[i];
        for(j=i-1;j>=0 && strcmp(a[j],hold)>0;j--)
            a[j+1]=a[j];
        a[j+1]=hold;
    }
}

int main()
{
    int choice;
    char *a[maxsz]={0};
    char line[maxsz];
    char key[maxsz];
    int n;
    while(1)
    {
        printf("\nOpertaions are: ");
        printf("\n1.Insert");
        printf("\n2.Serach");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Size of Array: ");
                scanf("%d",&n);
                printf("Enter %d strings:\n", n);
                for (int i = 0; i < n; i++) 
                {
                    scanf("%s", line);
                    int len=strlen(line);
                    a[i]=(char *)malloc((sizeof(char *)*len)+1);
                    strcpy(a[i],line);
                }
                insert(a,n);
                break;
            case 2:
                printf("Enter string to search: ");
                scanf("%s",key);
                int res=binary(a,0,n-1,key);
                if(res!=-1)
                {
                    printf("\nThe %s is at %d index.",key,res);
                }
                else
                    printf("\nThe %s is not in the given array.",key);
                break;
            case 3:
                printf("\nThe elements are: \n");
                display(a,n);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid choice!!!");
        }
    }return 0;
}


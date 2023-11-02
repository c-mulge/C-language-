#include<stdio.h>
#define maxsz 10

void bubblesort(int a[],int n)
{
    int temp;
    int i,j,swapping=1;
        for(i=1;i<n && swapping;i++)
        {
            swapping=0;
            for(j=0;j<n-i;j++)
            {
                if(a[j]>a[j+1])             //change the sign to make the code in descending order
                {
                    swapping=1;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
}
int main()
{
    int a[maxsz];
    int n,i;
        printf("How many numbers: ");
        scanf("%d",&n);

        printf("Enter %d numbers: \n",n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        bubblesort(a,n);
        printf("Sorted: \n");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    return 0;
}
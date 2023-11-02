#include<stdio.h>
#define maxsz 50
int partition(int a[],int lb, int ub)
{
    int pivot=a[lb],temp;
    int down=lb;
    int up=ub;

    while(down<up)
    {
        while(pivot>=a[down]&& down <=ub) //change the sign of pivot >=a[down]
        down++;
        while(pivot < a[up]) //change the sign of pivot >=a[up]
        up--;
        if(down < up)
        {
            temp=a[down];
            a[down]=a[up];
            a[up]=temp;
        }
    }
    a[lb]=a[up];
    a[up]=pivot;
    return up;
}
void quicksort(int a[],int lb, int ub)
{
    int pass;
    if(lb<ub)
    {
        pass=partition(a,lb,ub);
        quicksort(a,lb,pass-1);
        quicksort(a,pass+1,ub);
    }
}
int main() {
    int n,i;
    int a[maxsz];
    printf("How many number: ");
    scanf("%d", &n);
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
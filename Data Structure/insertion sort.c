//Insertion Sort

#include <stdio.h>
#define maxsz 10
void insertionsort(int a[], int n) 
{
    int i, j;
    int hold;

    for (i = 1; i < n; i++) 
    {
        hold = a[i];
        for(j = i - 1; j >= 0 && a[j] > hold; j--) //change the sign of a[j] > hold;j--
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = hold;
    }
}

int main() 
{
    int a[maxsz];
    int n,i;
    printf("How many numbers: ");
    scanf("%d", &n);
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    
    insertionsort(a, n);

    printf("\nSorted number: ");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
printf("\n");
    return 0;
}

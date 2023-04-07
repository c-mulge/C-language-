//Exercise 1 
//Set B
//Q.1
#include <stdio.h>

void bubble(int arr[], int n) //function bubble for sorting
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int n, i;
    printf("How many numbers are: "); //counting of how many no. to be executed
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    bubble(arr, n);
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

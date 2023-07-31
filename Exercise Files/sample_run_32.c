//Insertion Sort

#include <stdio.h>
void insertionsort(int arr[], int n) 
{
    int i, j;
    int hold;

    for (i = 1; i < n; i++) 
    {
        hold = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > hold; j--) 
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = hold;
    }
}

int main() {
    int n;
    printf("How many numbers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Original number: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    insertionsort(arr, n);

    printf("\nSorted number: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

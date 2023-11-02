//In ascending order

// #include <stdio.h>
// #define maxsz 50

// /*max function is used to find the maximum element 
// in an array 'a' of size 'n'.*/
// int getmax(int a[], int n) 
// {
//   int max = a[0];
//   for (int i = 1; i < n; i++)
//     if (a[i] > max)
//       max = a[i]; //it keeps track of the maximum value encountered
//   return max;
// }

// /*countingsort function is an implementation of the
// counting sort algorithm.*/

// void countingSort(int a[], int size, int pos) 
// {
//   int output[size + 1];
//   int max = (a[0] / pos) % 10;

//   for (int i = 1; i < size; i++) 
//   {
//     if (((a[i] / pos) % 10) > max)
//       max = a[i];
//   }

//   int count[max + 1]; /*It initializes a count array with zeros to 
//                       count the occurrences of each 
//                       digit at the given position.*/

//   for (int i = 0; i <= max; ++i)
//     count[i] = 0;
//   for (int i = 0; i < size; i++) //It counts the occurrences of each digit by extracting the digit at the pos position and incrementing the corresponding count in the count array.
//     count[(a[i] / pos) % 10]++;
//   for (int i = 1; i < 10; i++)  //It modifies the count array to represent the positions of the digits in the sorted output.
//     count[i] += count[i - 1];
//   for (int i = size - 1; i >= 0; i--) //It uses the count array to place elements in their correct positions in the output array, effectively sorting the input array based on the specified digit position.
//   {
//     output[count[(a[i] / pos) % 10] - 1] = a[i];
//     count[(a[i] / pos) % 10]--;
//   }

//   for (int i = 0; i < size; i++)
//     a[i] = output[i];  //it copies the sorted elements from the output array back to the original array a.
// }
// void radixsort(int a[], int size)  //implementing radixsort algorithm
// {
//   int max = getmax(a, size);
//   for (int pos = 1; max / pos > 0; pos *= 10)
//     countingSort(a, size, pos);
// }

// void display(int *a,int n)   // display function to printf the array
// {
//     for(int i = 0; i < n; i++)
//     {
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

// void accept(int *a,int n)   // accept function is used to accept the numbers from user and store them in array
// {
//     int i;
//     printf("Enter %d numbers: \n",n);
//         for(i=0;i<n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
// }

// int main()
// {
//     int a[maxsz];
//     int n;
//         printf("How many numbers: ");
//         scanf("%d",&n);

//         accept(a,n);
//         radixsort(a,n);

//         printf("\nSorted list is: ");
//         display(a,n);

//     return 0;
// }


//in descending order
#include <stdio.h>
#define maxsz 50

int getmax(int a[], int n) 
{
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

void countingSort(int a[], int size, int pos) 
{
  int output[size + 1];
  int max = (a[0] / pos) % 10;

  for (int i = 1; i < size; i++) 
  {
    if (((a[i] / pos) % 10) > max)
      max = a[i];
  }

  int count[max + 1];
  for (int i = 0; i <= max; ++i) // Changed the loop limit to 'max'
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(a[i] / pos) % 10]++;

  for (int i = max - 1; i >= 0; i--) // Changed the loop limit to 'max - 1'
    count[i] += count[i + 1];

  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[(a[i] / pos) % 10] - 1] = a[i];
    count[(a[i] / pos) % 10]--;
  }

  for (int i = 0; i < size; i++)
    a[i] = output[i];
}

void radixsort(int a[], int size) 
{
  int max = getmax(a, size);
  for (int pos = 1; max / pos > 0; pos *= 10)
    countingSort(a, size, pos);
}

void display(int *a, int n) 
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void accept(int *a, int n) 
{
  int i;
  printf("Enter %d numbers: \n", n);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int main() 
{
  int a[maxsz];
  int n;
  printf("How many numbers: ");
  scanf("%d", &n);

  accept(a, n);
  radixsort(a, n);

  printf("\nSorted list in descending order: ");
  display(a, n);

  return 0;
}

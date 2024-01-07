//Hourglass Sum
// https://www.hackerrank.com/challenges/2d-array/problem         
// ctrl + click to visit website 


#include <stdio.h>
#define row 6
#define col 6

int hourglassSum(int arr[row][col]) 
{
    int maxSum = -64; // Minimum possible sum for a single hourglass (-9 * 7)

    for (int i = 0; i <= row - 3; i++) 
    {
        for (int j = 0; j <= col - 3; j++) 
        {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2]           //first row
                    + arr[i + 1][j + 1]                    //middle row
                    + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];     //last row

            maxSum = (sum > maxSum) ? sum : maxSum;         //works as if-else
        }
    }

    return maxSum;
}

int main() {
    int arr[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int maxSum = hourglassSum(arr);
    printf("%d\n", maxSum);

    return 0;
}

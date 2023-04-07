//Exercise 1 
//Set B
//Q.3
#include <stdio.h>

#define MAX_SIZE 100

void findIntersection(int set1[], int set2[], int size1, int size2, int intersection[]);
void printArray(int arr[], int size);

int main() 
{
    int set1[MAX_SIZE], set2[MAX_SIZE], intersection[MAX_SIZE];
    int size1, size2, interSize;

    printf("Enter size of set1: ");
    scanf("%d", &size1);

    printf("Enter elements of set1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &set1[i]);
    }

    printf("Enter size of set2: ");
    scanf("%d", &size2);

    printf("Enter elements of set2: ");
    for (int i = 0; i < size2; i++) 
    {
        scanf("%d", &set2[i]);
    }

    findIntersection(set1, set2, size1, size2, intersection);
    interSize = sizeof(intersection) / sizeof(intersection[0]);

    printf("Intersection of set1 and set2: ");
    printArray(intersection, interSize);

    return 0;
}

void findIntersection(int set1[], int set2[], int size1, int size2, int intersection[]) {
    int interIndex = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                intersection[interIndex] = set1[i];
                interIndex++;
            }
        }
    }
}

void printArray(int arr[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

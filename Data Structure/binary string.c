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
    else if(strcmp(a[mid],key)<0)
        return binary(a,lb,mid-1,key);
    else
        return binary(a,mid+1,ub,key);
}

int main()
{
    //char *a[]={0};
    char line[maxsz];
    int n;
    printf("Size of Array: ");
    scanf("%d",&n);
    char **a = (char **)malloc(sizeof(char *) * n);
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", line);
        int len=strlen(line);
        a[i]=(char *)malloc(sizeof(char *)*len+1);
        strcpy(a[i],line);
    }
    // int i,j;
    // char *hold;              
    // for (i = 1; i < n; i++) 
    // {
    //     hold = a[i];
    //     for(j = i - 1; j >= 0 && strcmp(a[j], hold)>0; j--)        //change sign to a[j] < hold
    //     {
    //         a[j + 1] = a[j];
    //     }
    //         a[j + 1] = hold;
    // }

    char key[maxsz];
    printf("Enter the string to search: ");
    scanf("%s", key);

    int result = binary(a, 0, n - 1, key);

    if (result != -1) {
        printf("String %s found at index %d.\n", key, result);
    } else {
        printf("String %s not found in the array.\n", key);
    }
    for (int i = 0; i < n; i++) 
    {
        free(a[i]);
    }
    free(a);

    return 0;
}





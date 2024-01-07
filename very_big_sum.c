/* In this challenge, you are required to calculate and 
print the sum of the elements in an array, keeping in mind that some of those integers may be quite large.*/

#include<stdio.h>
#include<limits.h>
#define maxsz 50
int main()
{
    int n;
    scanf("%d", &n);
    long long int a[maxsz],sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    printf("%lld ",sum);
    return 0;
}
//count the simple intrest of the input taken
#include<stdio.h>
int main()
{
    int p,n,count;
    float r,si;
    for (count=2;count<=3;count++)  //loop's here!!!
    // here count act as iterartor
    {
        printf("Enter value of p,n, and r:\n");
        scanf("%d %d %f",&p,&n,&r);
        si=p*n*r/100;    //formula for simple intrest
        printf("Simple Intrest= Rs.%f\n",si);  //showing the last result 
    }
    return 0;
}
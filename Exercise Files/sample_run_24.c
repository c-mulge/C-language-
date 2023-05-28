//if the length and breadth of a reactangle is given find its area and perimeter
//and also find whether the area of rectangle is greater than its perimeter
//area=l*b and perimeter=2(l+b)
#include<stdio.h>
int main()
{
    int l,b,area,peri;
        printf("\nEnter the length of the rectangle:");    
        scanf("%d",&l);
        printf("\nEnter the breadth of the rectangle:");
        scanf("%d",&b);

        area=l*b;
        peri=2*(l+b);
            printf("\nArea of reactangle: %d\n",area);
            printf("Perimeter of reactangle: %d\n",peri);

        if(area>peri)
            {printf("\nArea of reactangle is greater than perimeter of reactangle\n");}
        else
        printf("\nArea of reactangle is lesser than perimeter of reactangle\n");
    return 0;
}
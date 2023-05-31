//take marks from the user and get the correct division.

//Method-1
#include<stdio.h>
int main()
{
    int m1,m2,m3,m4,m5,per;
    printf("Enter marks in five subjects: ");
    scanf("%d %d %d %d %d",&m1, &m2, &m3, &m4, &m5);
        per=(m1+m2+m3+m4+m5)*100/500;

        if(per>=60)
            printf("First Division\n");
        else{
            if(per>=50)
                printf("Second Division\n");
            else{
                if (per>=40)
                    printf("Third Division\n");
                else
                    printf("Fail");
                }
        }


    return 0;
}


// //method-2
// #include<stdio.h>
// int main()
// {
//     int m1,m2,m3,m4,m5,per;

//         printf("Enter marks in five subjects: ");
//         scanf("%d %d %d %d %d",&m1, &m2, &m3, &m4, &m5);

//         per=(m1+m2+m3+m4+m5)/100*500;

//             if(per>=60)
//                 printf("First Division\n");
//             if((per>=50) && (per<60))
//                 printf("Second Division\n");
//             if((per>=40) && (per<50))
//                 printf("Third Division\n");
//             if(per<40)
//                 printf("Fail\n");
//     return 0;
// }
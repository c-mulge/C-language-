//C program- take input from user where you take the input like- name, age and salary and print them n number of times
#include <stdio.h>
#include <stdlib.h>

struct Employee 
{
    char name[50];
    int age;
    double salary;
    };

int main()
{
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee* employees = (struct Employee*)malloc(n * sizeof(struct Employee));

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf(" %s", employees[i].name);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }


    printf("\nEmployee Details:\n");
    printf("--------------------------------------------------------\n");
    printf("Name\t\tAge\t\tSalary\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%.2lf\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    free(employees);
    return 0;
}

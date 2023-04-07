//Calculate length of string
#include <stdio.h>
int length(char str[]) 
{
    int i = 0;
    while (str[i] != '\0') 
    {
        i++;
    }
    return i;
}

int main() {
    char a[] = "Hello, World!";
    int len = length(a);
    printf("Length of string: %d", len);
    return 0;
}//sucessfully runs

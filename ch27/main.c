#include <stdio.h>


void print_out(const char* p, const int x)
{
    printf("p is\"%s\" and x is %i\n", p, x);
}

int main(){
    //1.
    printf("Hello, World!\n");

    //2.
    char str1[] = "Hello ";
    char str2[] = "World!";

    printf("%s %s\n", str1, str2);

    //3.
    print_out("VAZ-2101", 1967);
    print_out("VAZ-2105", 1980);

    return 0;
}
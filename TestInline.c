#include<stdio.h>

inline int fun(int a)
{
    return a*2;
}

int main()
{
    printf("%d",fun(5));
    return 0;
}
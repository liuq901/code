#include <cstdio>
#include <cctype>
int main()
{
    char ch;
    while (scanf("%c",&ch)==1)
        printf("%c",toupper(ch));
    return(0);
}


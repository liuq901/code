#include <cstdio>
#include <cctype>
int main()
{
    char ch;
    while ((ch=getchar())!=EOF)
        printf("%c",toupper(ch));
    return(0);
}


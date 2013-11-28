#include <cstdio>
int main()
{
    char ch;
    scanf("%c",&ch);
    if (ch=='E')
        printf("Excellent\n");
    else if (ch=='C')
        printf("Cheer\n");
    else if (ch=='N')
        printf("Nice\n");
    else if (ch=='U')
        printf("Ultimate\n");
    else if (ch=='A')
        printf("Accept\n");
    else
        printf("Error\n");
    return(0);
}


#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d\n",(2*n-1)*4);
    }
    return(0);
}


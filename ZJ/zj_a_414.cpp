#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d\n",__builtin_ctz(~n));
    }
    return(0);
}


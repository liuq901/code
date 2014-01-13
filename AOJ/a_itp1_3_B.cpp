#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        static int id=0;
        printf("Case %d: %d\n",++id,n);
    }
    return(0);
}


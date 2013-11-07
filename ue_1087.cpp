#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,L;
        scanf("%d%d",&n,&L);
        printf("%d.28\n",n*L+6);
    }
    return(0);
}


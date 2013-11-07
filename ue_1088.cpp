#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,x;
        scanf("%d%d%d",&n,&m,&x);
        printf("%s\n",n%x==0 || m%x==0?"YES":"NO");
    }
    return(0);
}


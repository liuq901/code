#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x%=10000;
        int ret=1;
        for (;y;y>>=1)
        {
            if (y&1)
                ret=ret*x%10000;
            x=x*x%10000;
        }
        printf("%04d\n",ret);
    }
    return(0);
}


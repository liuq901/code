#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int now=0;
        for (int i=1;;i++)
        {
            now=(now*10+m)%n;
            if (now==0)
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i);
                break;
            }
        }
    }
    return(0);
}


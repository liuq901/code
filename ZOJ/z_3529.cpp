#include <cstdio>
int sg[5000010],a[5000010],p[5000010];
bool f[5000010];
void init()
{
    for (int i=2;i*i<=5000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=5000000;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    for (int i=2;i<=5000000;i++)
        if (!f[i])
            p[i]=i;
    for (int i=2;i<=5000000;i++)
    {
        int x=i;
        while (x!=1)
        {
            sg[i]++;
            x/=p[x];
        }
    }
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
    {
        int x=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            x^=sg[a[i]];
        }
        static int id=0;
        printf("Test #%d: %s",++id,x!=0?"Alice":"Bob");
        if (x!=0)
        {
            int ans;
            for (int i=1;i<=n;i++)
                if (sg[a[i]]>(x^sg[a[i]]))
                {
                    ans=i;
                    break;
                }
            printf(" %d",ans);
        }
        printf("\n");
    }
    return(0);
}


#include <cstdio>
int a[110],b[110];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        int sum=0,tot=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
            tot+=b[i];
        }
        int x=1000000,y=1000000;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int p=a[i],q=b[j];
                if (sum-p+q==tot-q+p && p+q<x+y)
                    x=p,y=q;
            }
        if (x==1000000)
            printf("-1\n");
        else
            printf("%d %d\n",x,y);
    }
    return(0);
}


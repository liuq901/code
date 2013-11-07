#include <cstdio>
#include <cstring>
int a[30];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]+=y;
        }
        double ans=0;
        for (int i=1;i<=25;i++)
        {
            if (i*a[i]>=n)
            {
                ans+=double(n)/i;
                break;
            }
            ans+=a[i];
            n-=i*a[i];
        }
        printf("%.2f\n",ans);
    }
    return(0);
}


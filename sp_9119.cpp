#include <cstdio>
#include <cstring>
int q[10010],d[10010],b[10010],a[100010][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            d[y]++;
        }
        int l=1,r=0,sum=0;
        for (int i=1;i<=n;i++)
            if (!d[i])
            {
                q[++r]=i;
                sum++;
            }
        bool flag=sum>1;
        while (l<=r)
        {
            int x=q[l++];
            sum--;
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                d[y]--;
                if (!d[y])
                {
                    q[++r]=y;
                    sum++;
                    if (sum>1)
                        flag=true;
                }
            }
        }
        if (r!=n)
            printf("recheck hints\n");
        else if (flag)
            printf("missing hints\n");
        else
            for (int i=1;i<=n;i++)
                printf("%d%c",q[i],i==n?'\n':' ');
    }
    return(0);
}


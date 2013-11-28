#include <cstdio>
#include <cstring>
int b[110],q[110],d[110],f[110],a[10010][2];
int main()
{
    int n,m;
    bool first=true;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            d[y]++;
        }
        int l=1,r=0;
        for (int i=1;i<=n;i++)
            if (!d[i])
            {
                q[++r]=i;
                f[i]=1;
            }
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                d[y]--;
                if (!d[y])
                {
                    f[y]=f[x]+1;
                    q[++r]=y;
                }
            }
        }
        if (!first)
            printf("\n");
        first=false;
        if (r!=n)
            printf("Impossible\n");
        else
            printf("%d\n",f[q[r]]);
    }
    return(0);
}


#include <cstdio>
#include <cstring>
const int N=100010;
double f[N],p[N];
int to[N];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(to,0,sizeof(to));
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            to[x]=y;
        }
        p[0]=1;
        for (int i=0;i<n;i++)
            if (!to[i])
                for (int j=1;j<=6;j++)
                {
                    f[i+j]+=(f[i]+p[i])/6;
                    p[i+j]+=p[i]/6;
                }
            else
            {
                f[to[i]]+=f[i];
                p[to[i]]+=p[i];
            }
        double ans=0;
        for (int i=n;i<=n+5;i++)
            ans+=f[i];
        printf("%.4f\n",ans);
    }
    return(0);
}


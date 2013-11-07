#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[60][60];
int n,in[30],out[30],flag[60],f[60][60],sum[60][60];
int calc(int l,int r)
{
    if (sum[l][r]==1)
        return(0);
    if (vis[l][r])
        return(f[l][r]);
    vis[l][r]=true;
    int &ret=f[l][r];
    ret=1<<30;
    for (int i=1;i<=n;i++)
    {
        int now=-1,x=in[i],y=out[i],u,v;
        u=max(l,x+1),v=min(r,y-1);
        if (u<=v && (u>l || v<r) && sum[u][v]>=1)
            now=max(now,calc(u,v)+1);
        u=max(l,y),v=r;
        if (u<=v && (u>l || v<r) && sum[u][v]>=1)
            now=max(now,calc(u,v)+1);
        u=l,v=min(r,x-1);
        if (u<=v && (u>l || v<r) && sum[u][v]>=1)
            now=max(now,calc(u,v)+1);
        if (now!=-1)
            ret=min(ret,now);
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(in,0,sizeof(in));
        memset(flag,0,sizeof(flag));
        for (int i=1;i<=2*n;i++)
        {
            int x;
            scanf("%d",&x);
            if (!in[x])
                in[x]=i;
            else
            {
                out[x]=i;
                flag[i]=true;
            }
        }
        for (int i=1;i<=2*n;i++)
        {
            sum[i][i-1]=0;
            for (int j=i;j<=2*n;j++)
                sum[i][j]=sum[i][j-1]+flag[j];
        }
        memset(vis,0,sizeof(vis));
        static int id=0;
        printf("Case #%d: %d\n",++id,calc(2,2*n));
    }
    return(0);
}


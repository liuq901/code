#include <cstdio>
#include <cstring>
bool f[110][110];
int q[110],d[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int id,K;
        scanf("%d%d",&id,&K);
        for (int j=1;j<=K;j++)
        {
            int x;
            scanf("%d",&x);
            f[id][x]=true;
        }
    }
    int l,r;
    q[l=r=1]=1;
    memset(d,-1,sizeof(d));
    d[1]=0;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=1;i<=n;i++)
            if (f[x][i] && d[i]==-1)
            {
                q[++r]=i;
                d[i]=d[x]+1;
            }
    }
    for (int i=1;i<=n;i++)
        printf("%d %d\n",i,d[i]);
    return(0);
}


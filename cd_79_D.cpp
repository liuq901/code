#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
queue <int> Q;
int pos[30],a[30][30],b[110],d[10010],f[1100000];
bool on[10010];
int main()
{
    int len,K,L;
    scanf("%d%d%d",&len,&K,&L);
    for (int i=1;i<=K;i++)
    {
        int x;
        scanf("%d",&x);
        on[x]=true;
    }
    for (int i=1;i<=L;i++)
        scanf("%d",&b[i]);
    int n=0;
    for (int i=0;i<=len;i++)
        if (on[i]!=on[i+1])
            pos[++n]=i;
    memset(f,63,sizeof(f));
    int limit=1<<n,inf=f[0];
    for (int i=1;i<=n;i++)
    {
        memset(d,63,sizeof(d));
        d[pos[i]]=0;
        Q.push(pos[i]);
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            for (int j=1;j<=L;j++)
            {
                int y1=x+b[j],y2=x-b[j];
                if (y1<=len && d[x]+1<d[y1])
                {
                    d[y1]=d[x]+1;
                    Q.push(y1);
                }
                if (y2>0 && d[x]+1<d[y2])
                {
                    d[y2]=d[x]+1;
                    Q.push(y2);
                }
            }
        }
        for (int j=i+1;j<=n;j++)
            a[i][j]=d[pos[j]];
    }
    f[0]=0;
    for (int i=0;i<limit;i++)
    {
        if (f[i]==inf)
            continue;
        for (int j=1;j<=n;j++)
        {
            if (i>>j-1&1)
                continue;
            for (int k=j+1;k<=n;k++)
            {
                if (i>>k-1&1)
                    continue;
                f[i|1<<j-1|1<<k-1]=min(f[i|1<<j-1|1<<k-1],f[i]+a[j][k]);
            }
        }
    }
    if (f[limit-1]==inf)
        f[limit-1]=-1;
    printf("%d\n",f[limit-1]);
    return(0);
}


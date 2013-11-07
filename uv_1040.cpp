#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef int array[(1<<10)+10][30];
int inf,n,m,b[30],a[1010][3],bit[(1<<20)+10];
array f,g,pre;
bool in[30];
queue <int> Q;
vector <int> ans[30];
void spfa(int s)
{
    for (int i=1;i<=m;i++)
        if (f[s][i]!=inf)
        {
            Q.push(i);
            in[i]=true;
        }
    while (!Q.empty())
    {
        int x=Q.front();
        in[x]=false;
        Q.pop();
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (f[s][x]+a[i][1]<f[s][y])
            {
                f[s][y]=f[s][x]+a[i][1];
                g[s][y]=g[s][x]|1<<m-y;
                pre[s][y]=x;
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
            else if (f[s][x]+a[i][1]==f[s][y])
            {
                int t=g[s][x]|1<<m-y;
                if (bit[t]<bit[g[s][y]] || bit[t]==bit[g[s][y]] && t>g[s][y])
                {
                    g[s][y]=t;
                    pre[s][y]=x;
                    if (!in[y])
                    {
                        in[y]=true;
                        Q.push(y);
                    }
                }
            }
        }
    }
}
void print(int x,int y)
{
    if (y==0)
        return;
    if (pre[x][y]>=0)
    {
        for (int i=1;i<=n;i++)
            if (x>>i-1&1)
                ans[i].push_back(y);
        print(x,pre[x][y]);
    }
    else
    {
        int z=-pre[x][y];
        print(z/10000,y);
        print(z%10000,y);
    }
}
int main()
{
    bit[0]=0;
    for (int i=1;i<=1<<20;i++)
        bit[i]=bit[i&i-1]+1;
    while (1)
    {
        scanf("%d",&m);
        if (m==-1)
            break;
        int target,K;
        scanf("%d%d",&target,&K);
        memset(b,0,sizeof(b));
        for (int i=1;i<=K;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+K][0]=x,a[i+K][1]=z,a[i+K][2]=b[y],b[y]=i+K;
        }
        scanf("%d",&n);
        memset(f,63,sizeof(f));
        inf=f[0][0];
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            f[1<<i-1][x]=0;
            g[1<<i-1][x]=1<<m-x;
            pre[1<<i-1][x]=0;
        }
        int limit=(1<<n)-1;
        for (int i=1;i<=limit;i++)
        {
            spfa(i);
            for (int j=1;j<=m;j++)
            {
                if (f[i][j]==inf)
                    continue;
                int p=limit^i;
                for (int x=p;x;x=x-1&p)
                    if (f[i][j]+f[x][j]<f[i|x][j])
                    {
                        f[i|x][j]=f[i][j]+f[x][j];
                        g[i|x][j]=g[i][j]|g[x][j];
                        pre[i|x][j]=-(i*10000+x);
                    }
                    else if (f[i][j]+f[x][j]==f[i|x][j])
                    {
                        int t=g[i][j]|g[x][j];
                        if (bit[t]<bit[g[i|x][j]] || bit[t]==bit[g[i|x][j]] && t>g[i|x][j])
                        {
                            g[i|x][j]=t;
                            pre[i|x][j]=-(i*10000+x);
                        }
                    }
            }
        }
        static int id=0;
        printf("Case %d: distance = %d\n",++id,f[limit][target]);
        for (int i=1;i<=n;i++)
            ans[i].clear();
        print(limit,target);
        for (int i=1;i<=n;i++)
        {
            reverse(ans[i].begin(),ans[i].end());
            printf("   %d",ans[i][0]);
            for (int j=1;j<ans[i].size();j++)
                printf("-%d",ans[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return(0);
}


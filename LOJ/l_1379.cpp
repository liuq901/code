#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int d[10010],f[10010],b[10010],rb[10010],a[50010][3],ra[50010][3];
bool in[10010];
void spfa(int S,int a[][3],int b[])
{
    queue <int> Q;
    memset(d,63,sizeof(d));
    d[S]=0;
    Q.push(S);
    in[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        in[x]=false;
        Q.pop();
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[x]+a[i][1]<d[y])
            {
                d[y]=d[x]+a[i][1];
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,S,T,limit;
        scanf("%d%d%d%d%d",&n,&m,&S,&T,&limit);
        memset(b,0,sizeof(b));
        memset(rb,0,sizeof(rb));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            ra[i][0]=x,ra[i][1]=z,ra[i][2]=rb[y],rb[y]=i;
        }
        spfa(S,a,b);
        memcpy(f,d,sizeof(d));
        spfa(T,ra,rb);
        int ans=-1;
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][2])
            {
                int x=a[j][0];
                if (f[i]+d[x]+a[j][1]<=limit)
                    ans=max(ans,a[j][1]);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}


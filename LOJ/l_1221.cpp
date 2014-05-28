#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
bool in[110];
int cnt[110],d[110],b[110],a[10010][3];
bool spfa(int n)
{
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(d));
    queue <int> Q;
    for (int i=1;i<=n;i++)
    {
        Q.push(i);
        in[i]=true;
    }
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
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
                    if (++cnt[y]>n)
                        return(true);
                }
            }
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,P;
        scanf("%d%d%d",&n,&m,&P);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,I,O;
            scanf("%d%d%d%d",&x,&y,&I,&O);
            x++,y++;
            int z=O*P-I;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,spfa(n)?"YES":"NO");
    }
    return(0);
}


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int inf,no1,no2,d[1010],b[1010],pre[1010],p[1010],q[10010],a[100010][3];
bool in[1010];
void spfa(bool first)
{
    memset(d,63,sizeof(d));
    inf=d[0];
    int l=0,r=1;
    q[1]=1,d[1]=0,in[1]=true;
    while (l!=r)
    {
        l=l==10000?1:l+1;
        int x=q[l];
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            if (i==no1 || i==no2)
                continue;
            int y=a[i][0];
            if (d[x]+a[i][1]<d[y])
            {
                d[y]=d[x]+a[i][1];
                if (first)
                {
                    pre[y]=x;
                    p[y]=i;
                }
                if (!in[y])
                {
                    in[y]=true;
                    r=r==10000?1:r+1;
                    q[r]=y;
                    int k=l==10000?1:l+1;
                    if (d[q[r]]<d[q[k]])
                        swap(q[r],q[k]);
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
        int n,m;
        scanf("%d%d",&n,&m);
        int tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
            a[++tot][0]=x,a[tot][1]=z,a[tot][2]=b[y],b[y]=tot;
        }
        no1=no2=-1;
        spfa(true);
        if (d[n]==inf)
            printf("-1\n");
        else
        {
            int ans=0;
            for (int i=n;i!=1;i=pre[i])
            {
                int x=p[i];
                no1=x,no2=x^1;
                spfa(false);
                ans=max(ans,d[n]);
            }
            if (ans==inf)
                ans=-1;
            printf("%d\n",ans);
        }
    }
    return(0);
}


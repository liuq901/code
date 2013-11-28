#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int K,n,X,Y,a[110],b[110],c[110],d[110],p[110],change[130][130],best[130],f[110][110][130];
void update(int &x,int y)
{
    x=max(x,y);
}
void dp()
{
    memset(f,-63,sizeof(f));
    memset(best,-63,sizeof(best));
    memset(change,0,sizeof(change));
    f[0][0][0]=0;
    int L=1<<K;
    for (int i=0;i<L;i++)
        for (int j=0;j<L;j++)
            for (int k=0;k<K;k++)
                if (!(i>>k&1) && j>>k&1)
                    change[i][j]+=c[k]+d[k]*(b[k]==1);
    for (int i=1;i<=n;i++)
        for (int j=0;j<=Y;j++)
            for (int k=0;k<L;k++)
            {
                update(f[i][j][k],f[i-1][j][k]);
                if (j<Y)
                    update(f[i][j+1][k|p[i]],f[i-1][j][k]+change[k][p[i]]+a[i]);
                update(best[k],f[i][j][k]);
            }
}
int now[110];
int work(int state)
{
    int t=X,ret=0;
    for (int i=0;i<K;i++)
        if (state>>i&1)
        {
            int delta=b[i]-now[i];
            t-=delta;
            now[i]=b[i];
            if (delta!=0)
                ret+=c[i]*delta+d[i];
        }
    if (t<0)
        return(0);
    while (t)
    {
        int p=-1;
        for (int i=0;i<K;i++)
        {
            if (b[i]==now[i])
                continue;
            if (p==-1 || c[i]>c[p])
                p=i;
        }
        if (p==-1)
            break;
        int delta=min(t,b[p]-now[p]);
        now[p]+=delta;
        t-=delta;
        ret+=c[p]*delta+d[p]*(b[p]==now[p]);
    }
    return(ret);
}
int calc()
{
    int L=1<<K,ans=0;
    for (int i=0;i<L;i++)
    {
        if (best[i]<0)
            continue;
        for (int j=0;j<L;j++)
        {
            for (int k=0;k<K;k++)
                now[k]=i>>k&1;
            update(ans,work(j)+best[i]);
        }
    }
    return(ans);
}
int main()
{
    while (scanf("%d%d",&K,&n)==2)
    {
        for (int i=0;i<K;i++)
            scanf("%d%d%d",&b[i],&c[i],&d[i]);
        memset(p,0,sizeof(p));
        for (int i=1;i<=n;i++)
        {
            int cnt;
            scanf("%d%d",&a[i],&cnt);
            for (int j=1;j<=cnt;j++)
            {
                int x;
                scanf("%d",&x);
                p[i]|=1<<x-1;
            }
        }
        scanf("%d%d",&X,&Y);
        dp();
        printf("%d\n",calc());
    }
    return(0);
}


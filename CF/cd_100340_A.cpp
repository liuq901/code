#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
struct state
{
    bool p;
    int x,y,z;
    state(bool p,int x,int y,int z):p(p),x(x),y(y),z(z){}
};
inline bool operator !=(const state &a,const state &b)
{
    return(a.p!=b.p || a.x!=b.x || a.y!=b.y || a.z!=b.z);
}
int final[35],to[35],f[5010][35][35],g[5010][35][35];
pair <int,int> a[35];
int main()
{
    freopen("cookies.in","r",stdin);
    freopen("cookies.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    memset(f,63,sizeof(f));
    memset(g,63,sizeof(g));
    m-=n;
    g[m][n][0]=0;
    int ans=1<<30;
    state best(false,0,0,0);
    for (int i=m;i>=0;i--)
        for (int j=n;j;j--)
        {
            int delta=n-j+1;
            for (int k=0;k<=n;k++)
            {
                if (i>=delta)
                {
                    if (f[i][j][k]<f[i-delta][j][k])
                        f[i-delta][j][k]=f[i][j][k];
                    if (g[i][j][k]<f[i-delta][j][k])
                        f[i-delta][j][k]=g[i][j][k];
                }
                if (j>1)
                {
                    if (f[i][j][k]+a[j-1].first*delta<g[i][j-1][delta])
                        g[i][j-1][delta]=f[i][j][k]+a[j-1].first*delta;
                    if (g[i][j][k]+a[j-1].first*k<g[i][j-1][k])
                        g[i][j-1][k]=g[i][j][k]+a[j-1].first*k;
                }
                if (i==0 && j==1)
                {
                    if (f[i][j][k]<ans)
                    {
                        ans=f[i][j][k];
                        best=state(false,i,j,k);
                    }
                    if (g[i][j][k]<ans)
                    {
                        ans=g[i][j][k];
                        best=state(true,i,j,k);
                    }
                }
            }
        }
    printf("%d\n",ans);
    while (best!=state(true,m,n,0))
    {
        int i=best.x,j=best.y,k=best.z;
        if (!best.p)
        {
            int delta=n-j+1;
            to[j]++;
            if (f[i+delta][j][k]==f[i][j][k])
                best=state(false,i+delta,j,k);
            else
                best=state(true,i+delta,j,k);
        }
        else if (g[i][j+1][k]+a[j].first*k==g[i][j][k])
            best=state(true,i,j+1,k);
        else
        {
            int delta=n-j;
            for (int l=0;l<=n;l++)
                if (f[i][j+1][l]+a[j].first*delta==g[i][j][k])
                {
                    best=state(false,i,j+1,l);
                    break;
                }
        }
    }
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        int x=a[i].second;
        sum+=to[i];
        final[x]=sum+1;
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",final[i],i==n?'\n':' ');
    return(0);
}


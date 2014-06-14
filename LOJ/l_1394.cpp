#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[40],b[40],f[31][31][31][3][7],g[31][31][31][3][7];
ll F[31][31][31][3][7],G[31][31][31][3][7];
void get(int x,int a[])
{
    for (int i=30;i;i--)
    {
        a[i]=x&1;
        x>>=1;
    }
}
ll dp(int x,int n,int m,int K)
{
    if (x<0)
        return(0);
    get(x,a);
    get(m,b);
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(F,0,sizeof(F));
    memset(G,0,sizeof(G));
    g[0][0][0][0][0]=1;
    for (int i=1;i<=30;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=K;k++)
                for (int u=0;u<3;u++)
                    for (int v=0;v<7;v++)
                        for (int t=0;t<=1;t++)
                        {
                            int p=j+(t==1),q=k+(t!=b[i]),r=(u<<1|t)%3,s=(v<<1|t)%7;
                            f[i][p][q][r][s]+=f[i-1][j][k][u][v];
                            F[i][p][q][r][s]+=F[i-1][j][k][u][v]*2+t*f[i-1][j][k][u][v];
                            if (t==a[i])
                            {
                                g[i][p][q][r][s]+=g[i-1][j][k][u][v];
                                G[i][p][q][r][s]+=G[i-1][j][k][u][v]*2+t*g[i-1][j][k][u][v];
                            }
                            if (t<a[i])
                            {
                                f[i][p][q][r][s]+=g[i-1][j][k][u][v];
                                F[i][p][q][r][s]+=G[i-1][j][k][u][v]*2+t*g[i-1][j][k][u][v];
                            }
                        }
    ll ans=0;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=K;j++)
            for (int k=1;k<7;k++)
                ans+=F[30][i][j][0][k]+G[30][i][j][0][k];
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int l,r,one,x,K;
        scanf("%d%d%d%d%d",&l,&r,&one,&x,&K);
        one=min(one,30);
        K=min(K,30);
        static int id=0;
        printf("Case %d: %lld\n",++id,dp(r,one,x,K)-dp(l-1,one,x,K));
    }
    return(0);
}


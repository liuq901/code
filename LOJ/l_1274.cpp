#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double f[2][5010][2],p[2][5010][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        m=3*n-m;
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        p[0][0][1]=1;
        for (int i=0;i<n;i++)
        {
            int u=i&1,v=u^1,tot=n-i;
            for (int j=0;j<=min(m,i);j++)
            {
                int zero=m-j,one=tot-zero;
                if (one<0)
                    continue;
                for (int k=0;k<=1;k++)
                {
                    if (zero)
                    {
                        f[v][j+1][0]+=(f[u][j][k]+(k!=0)*p[u][j][k])*double(zero)/tot;
                        p[v][j+1][0]+=p[u][j][k]*zero/tot;
                    }
                    if (one)
                    {
                        f[v][j][1]+=(f[u][j][k]+(k!=1)*p[u][j][k])*double(one)/tot;
                        p[v][j][1]+=p[u][j][k]*one/tot;
                    }
                    f[u][j][k]=p[u][j][k]=0;
                }
            }
        }
        static int id=0;
        double ans=0;
        for (int i=0;i<=1;i++)
            ans+=f[n&1][m][i];
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}


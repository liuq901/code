#include <cstdio>
#include <algorithm>
using namespace std;
double f[2][5010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        double ans=0,tot=0;
        int m=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (y==1)
                ans+=x;
            else
            {
                tot+=x;
                m++;
            }
        }
        if (m!=0)
        {
            tot/=m;
            f[0][0]=0;
            for (int i=1;i<=n;i++)
            {
                int u=i&1,v=u^1;
                for (int j=0;j<=min(i,m);j++)
                {
                    int k=i-j;
                    if (k>n-m)
                        continue;
                    f[u][j]=(k*f[v][j]+m*tot+j*f[v][max(0,j-1)])/i;
                }
            }
            ans+=f[n&1][m];
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}


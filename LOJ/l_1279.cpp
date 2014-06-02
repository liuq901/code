#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int power(int x,int y,int mod)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int *a[110],c[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        memset(c,0,sizeof(c));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            c[x][y]++;
            c[y][x]++;
        }
        for (int i=1;i<=n;i++)
        {
            c[i][i]=p-1;
            a[i]=c[i];
        }
        int t=1;
        for (int i=1;i<=n;i++)
        {
            bool flag=false;
            for (int j=t;j<=n;j++)
                if (a[j][i])
                {
                    swap(a[t],a[j]);
                    flag=true;
                    break;
                }
            if (!flag)
                continue;
            int s=power(a[t][i],p-2,p);
            for (int j=i;j<=n;j++)
                a[t][j]=ll(a[t][j])*s%p;
            for (int j=t+1;j<=n;j++)
            {
                int u=a[j][i];
                for (int k=i;k<=n;k++)
                    a[j][k]=(a[j][k]-ll(u)*a[t][k]%p+p)%p;
            }
            t++;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,power(p,n-t+1,mod));
    }
    return(0);
}


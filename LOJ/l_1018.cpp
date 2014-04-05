#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int x[20],y[20],f[66000],on[20][20];
bool check(int i,int j,int k)
{
    return((x[i]-x[k])*(y[j]-y[k])==(y[i]-y[k])*(x[j]-x[k]));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        memset(on,0,sizeof(on));
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    if (check(i,j,k))
                        on[i][j]|=1<<k-1;
        memset(f,63,sizeof(f));
        int inf=f[0],limit=(1<<n)-1;
        f[0]=0;
        for (int i=0;i<=limit;i++)
        {
            if (f[i]==inf)
                continue;
            for (int j=1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                for (int k=j+1;k<=n;k++)
                    f[i|on[j][k]]=min(f[i|on[j][k]],f[i]+1);
                break;
            }
        }
        int ans=f[limit];
        for (int i=1;i<=n;i++)
            ans=min(ans,f[limit^1<<i-1]+1);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}


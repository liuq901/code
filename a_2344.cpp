#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1000010;
typedef long long ll;
int l[N],r[N],dep[N],sum[N];
ll f[N][2];
int main()
{
    int n;
    scanf("%d",&n);
    int tot=n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x==n)
            x=tot++;
        if (y==n)
            y=tot++;
        l[i]=x,r[i]=y;
    }
    for (int i=n;i<tot;i++)
        sum[i]=1;
    for (int i=n-1;i;i--)
        sum[i]=sum[l[i]]+sum[r[i]];
    dep[1]=0;
    for (int i=1;i<n;i++)
    {
        dep[l[i]]=dep[i]+1;
        dep[r[i]]=dep[i]+1;
    }
    for (int i=tot-1;i;i--)
    {
        if (i>=n)
        {
            f[i][0]=f[i][1]=dep[i];
            continue;
        }
        f[i][0]=f[l[i]][0]+f[r[i]][0];
        f[i][1]=min(f[l[i]][1]+f[r[i]][1],f[l[i]][0]+f[r[i]][0]-ll(dep[i])*(sum[i]-1));
        f[i][1]=min(f[i][1],min(f[l[i]][0]+f[r[i]][1]-ll(dep[i])*sum[l[i]],f[l[i]][1]+f[r[i]][0]-ll(dep[i])*sum[r[i]]));
    }
    printf("%lld\n",f[1][1]);
    return(0);
}


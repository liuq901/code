#include <cstdio>
#include <algorithm>
using namespace std;
int Log[50010],a[50010],f[20][50010],g[20][50010];
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Log[1]=0;
    for (int i=2;i<=n;i++)
    {
        Log[i]=Log[i-1];
        if ((i&i-1)==0)
            Log[i]++;
    }
    for (int i=1;i<=n;i++)
        f[0][i]=g[0][i]=a[i];
    for (int i=1;i<=Log[n];i++)
        for (int j=1;j<=n;j++)
        {
            if (j+(1<<i)-1>n)
                break;
            f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
            g[i][j]=min(g[i-1][j],g[i-1][j+(1<<i-1)]);
        }
    while (Q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int t=Log[r-l+1];
        printf("%d\n",max(f[t][l],f[t][r-(1<<t)+1])-min(g[t][l],g[t][r-(1<<t)+1]));
    }
    return(0);
}

